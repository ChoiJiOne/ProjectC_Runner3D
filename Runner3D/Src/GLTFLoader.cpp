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

		uint32_t numPrimitives = static_cast<uint32_t>(node->mesh->primitives_count);
		for (int32_t index = 0; index < numPrimitives; ++index)
		{
			meshes.push_back(StaticMeshData());
			StaticMeshData& mesh = meshes.back();

			cgltf_primitive* primitive = &node->mesh->primitives[index];

			uint32_t numAttributes = static_cast<uint32_t>(primitive->attributes_count);
			for (uint32_t attrib = 0; attrib < numAttributes; ++attrib)
			{
				cgltf_attribute* attribute = &primitive->attributes[attrib];
				cgltf_attribute_type type = attribute->type;
				cgltf_accessor* accessor = attribute->data;

				std::vector<float> values(accessor->count * accessor->type);
				for (cgltf_size i = 0; i < accessor->count; ++i)
				{
					cgltf_accessor_read_float(accessor, i, &values[i * accessor->type], accessor->type);
				}

				for (uint32_t i = 0; i < accessor->count; ++i)
				{
					int32_t index = i * accessor->type;

					switch (type)
					{
					case cgltf_attribute_type_position:
						mesh.positions.push_back(Vec3f(values[index + 0], values[index + 1], values[index + 2]));
						break;

					case cgltf_attribute_type_normal:
						mesh.normals.push_back(Vec3f(values[index + 0], values[index + 1], values[index + 2]));
						break;

					case cgltf_attribute_type_texcoord:
						mesh.texCoords.push_back(Vec2f(values[index + 0], values[index + 1]));
						break;
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