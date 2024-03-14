#include "MathModule.h"

#include "Assertion.h"
#include "GLTFLoader.h"
#include "TransformTrack.h"

cgltf_data* GLTFLoader::LoadFromFile(const std::string& path)
{
	cgltf_result result = cgltf_result_success;
	cgltf_options options = {};
	cgltf_data* data = nullptr;

	result = cgltf_parse_file(&options, path.c_str(), &data);
	ASSERT(result == cgltf_result_success, "failed to parse %s file", path.c_str());

	result = cgltf_load_buffers(&options, data, path.c_str());
	ASSERT(result == cgltf_result_success, "failed to load %s file", path.c_str());

	result = cgltf_validate(data);
	ASSERT(result == cgltf_result_success, "invalid %s gltf file", path.c_str());

	return data;
}

std::vector<GLTFLoader::StaticMeshData> GLTFLoader::LoadStaticMeshData(cgltf_data* data)
{
	std::vector<StaticMeshData> meshes;

	cgltf_node* begin = data->nodes;
	cgltf_node* end = data->nodes + data->nodes_count;

	for (cgltf_node* node = begin; node != end; ++node)
	{
		if (!node->mesh) continue;
		
		cgltf_primitive* beginPrimitive = node->mesh->primitives;
		cgltf_primitive* endPrimitive = node->mesh->primitives + node->mesh->primitives_count;
		
		for (cgltf_primitive* primitive = beginPrimitive; primitive != endPrimitive; ++primitive)
		{
			meshes.push_back(StaticMeshData());
			StaticMeshData& mesh = meshes.back();

			cgltf_attribute* beginAttribute = primitive->attributes;
			cgltf_attribute* endAttribute = primitive->attributes + primitive->attributes_count;

			for (cgltf_attribute* attribute = beginAttribute; attribute != endAttribute; ++attribute)
			{
				cgltf_attribute_type type = attribute->type;
				cgltf_accessor* accessor = attribute->data;
				uint32_t componentCount = static_cast<uint32_t>(accessor->type);

				std::vector<float> buffer(accessor->count * componentCount);
				for (cgltf_size index = 0; index < accessor->count; ++index)
				{
					cgltf_accessor_read_float(accessor, index, &buffer[index * componentCount], componentCount);
				}

				for (uint32_t i = 0; i < accessor->count; ++i)
				{
					int32_t index = i * componentCount;

					switch (type)
					{
					case cgltf_attribute_type_position:
					{
						Vec3f position = Vec3f(buffer[index + 0], buffer[index + 1], buffer[index + 2]);
						mesh.positions.push_back(position);
					}
					break;

					case cgltf_attribute_type_normal:
					{
						Vec3f normal = Vec3f(buffer[index + 0], buffer[index + 1], buffer[index + 2]);
						mesh.normals.push_back(Vec3f::Normalize(normal));
					}
					break;

					case cgltf_attribute_type_texcoord:
					{
						Vec2f texCoords = Vec2f(buffer[index + 0], buffer[index + 1]);
						mesh.texCoords.push_back(texCoords);
					}
					break;
					}
				}
			}

			if (primitive->indices)
			{
				uint32_t indexCount = static_cast<uint32_t>(primitive->indices->count);
				mesh.indices.resize(indexCount);

				for (uint32_t index = 0; index < indexCount; ++index)
				{
					mesh.indices[index] = static_cast<uint32_t>(cgltf_accessor_read_index(primitive->indices, index));
				}
			}
		}
	}

	return meshes;
}

std::vector<GLTFLoader::SkinnedMeshData> GLTFLoader::LoadSkinnedMeshData(cgltf_data* data)
{
	std::vector<SkinnedMeshData> meshes;

	cgltf_node* begin = data->nodes;
	cgltf_node* end = data->nodes + data->nodes_count;

	for (cgltf_node* node = begin; node != end; ++node)
	{
		if (!node->mesh || !node->skin) continue;

		cgltf_primitive* beginPrimitive = node->mesh->primitives;
		cgltf_primitive* endPrimitive = node->mesh->primitives + node->mesh->primitives_count;

		for (cgltf_primitive* primitive = beginPrimitive; primitive != endPrimitive; ++primitive)
		{
			meshes.push_back(SkinnedMeshData());
			SkinnedMeshData& mesh = meshes.back();

			cgltf_attribute* beginAttribute = primitive->attributes;
			cgltf_attribute* endAttribute = primitive->attributes + primitive->attributes_count;

			for (cgltf_attribute* attribute = beginAttribute; attribute != endAttribute; ++attribute)
			{
				cgltf_attribute_type type = attribute->type;
				cgltf_accessor* accessor = attribute->data;
				uint32_t componentCount = static_cast<uint32_t>(accessor->type);

				std::vector<float> buffer(accessor->count * componentCount);
				for (cgltf_size index = 0; index < accessor->count; ++index)
				{
					cgltf_accessor_read_float(accessor, index, &buffer[index * componentCount], componentCount);
				}

				for (uint32_t i = 0; i < accessor->count; ++i)
				{
					int32_t index = i * componentCount;

					switch (type)
					{
					case cgltf_attribute_type_position:
					{
						Vec3f position = Vec3f(buffer[index + 0], buffer[index + 1], buffer[index + 2]);
						mesh.positions.push_back(position);
					}
					break;

					case cgltf_attribute_type_normal:
					{
						Vec3f normal = Vec3f(buffer[index + 0], buffer[index + 1], buffer[index + 2]);
						mesh.normals.push_back(Vec3f::Normalize(normal));
					}
					break;

					case cgltf_attribute_type_texcoord:
					{
						Vec2f texCoords = Vec2f(buffer[index + 0], buffer[index + 1]);
						mesh.texCoords.push_back(texCoords);
					}
					break;

					case cgltf_attribute_type_joints:
					{
						Vec4i joint(
							static_cast<int32_t>(buffer[index + 0] + 0.5f),
							static_cast<int32_t>(buffer[index + 1] + 0.5f),
							static_cast<int32_t>(buffer[index + 2] + 0.5f),
							static_cast<int32_t>(buffer[index + 3] + 0.5f)
						);

						joint.x = MathModule::Max<int32_t>(0, GetNodeIndex(node->skin->joints[joint.x], data->nodes, data->nodes_count));
						joint.y = MathModule::Max<int32_t>(0, GetNodeIndex(node->skin->joints[joint.y], data->nodes, data->nodes_count));
						joint.z = MathModule::Max<int32_t>(0, GetNodeIndex(node->skin->joints[joint.z], data->nodes, data->nodes_count));
						joint.w = MathModule::Max<int32_t>(0, GetNodeIndex(node->skin->joints[joint.w], data->nodes, data->nodes_count));

						mesh.joints.push_back(joint);
					}
					break;

					case cgltf_attribute_type_weights:
					{
						Vec4f weight = Vec4f(buffer[index + 0], buffer[index + 1], buffer[index + 2], buffer[index + 3]);
						mesh.weights.push_back(weight);
					}
					break;
					}
				}
			}

			if (primitive->indices)
			{
				uint32_t indexCount = static_cast<uint32_t>(primitive->indices->count);
				mesh.indices.resize(indexCount);

				for (uint32_t index = 0; index < indexCount; ++index)
				{
					mesh.indices[index] = static_cast<uint32_t>(cgltf_accessor_read_index(primitive->indices, index));
				}
			}
		}
	}

	return meshes;
}

Pose GLTFLoader::LoadRestPose(cgltf_data* data)
{
	cgltf_node* begin = data->nodes;
	cgltf_node* end = data->nodes + data->nodes_count;

	Pose result(static_cast<uint32_t>(data->nodes_count));
	uint32_t currentIndex = 0;

	for (cgltf_node* node = begin; node != end; ++node, ++currentIndex)
	{
		Transform transform = GetLocalTransform(node);
		result.SetLocalTransform(currentIndex, transform);

		int32_t parent = GetNodeIndex(node->parent, data->nodes, data->nodes_count);
		result.SetParent(currentIndex, parent);
	}

	return result;
}

void GLTFLoader::Free(cgltf_data* data)
{
	if (data)
	{
		cgltf_free(data);
		data = nullptr;
	}
}

int32_t GLTFLoader::GetNodeIndex(cgltf_node* target, cgltf_node* nodes, uint32_t numNodes)
{
	if (target == nullptr)
	{
		return -1;
	}

	int32_t index = 0;
	cgltf_node* begin = nodes;
	cgltf_node* end = nodes + numNodes;

	for (cgltf_node* node = begin; node != end; ++node, ++index)
	{
		if (target == node)
		{
			return index;
		}
	}

	return -1;
}

Transform GLTFLoader::GetLocalTransform(cgltf_node* node)
{
	Transform result;

	if (node->has_matrix)
	{
		Mat4x4 m(
			node->matrix[0],  node->matrix[1],  node->matrix[2],  node->matrix[3],
			node->matrix[4],  node->matrix[5],  node->matrix[6],  node->matrix[7],
			node->matrix[8],  node->matrix[9],  node->matrix[10], node->matrix[11],
			node->matrix[12], node->matrix[13], node->matrix[14], node->matrix[15]
		);

		result = Transform::ToTransform(m);
	}

	if (node->has_translation)
	{
		result.position = Vec3f(node->translation[0], node->translation[1], node->translation[2]);
	}

	if (node->has_rotation)
	{
		result.rotate = Quat(node->rotation[0], node->rotation[1], node->rotation[2], node->rotation[3]);
	}

	if (node->has_scale)
	{
		result.scale = Vec3f(node->scale[0], node->scale[1], node->scale[2]);
	}

	return result;
}
