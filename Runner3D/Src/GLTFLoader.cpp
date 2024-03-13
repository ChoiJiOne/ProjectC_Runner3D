#include "Assertion.h"
#include "GLTFLoader.h"

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

void GLTFLoader::Free(cgltf_data* data)
{
	if (data)
	{
		cgltf_free(data);
		data = nullptr;
	}
}