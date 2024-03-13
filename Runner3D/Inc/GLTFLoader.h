#pragma once

#include <vector>
#include <string>

#include <cgltf.h>

#include "Vertex3D.h"


/**
 * @brief GLTF ���ϰ� ���� ���� ������ �ε��� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ������ �޼���� ��� static �Դϴ�.
 */
class GLTFLoader
{
public:
	/**
	 * @brief GLTF ���� �޽� �������Դϴ�.
	 */
	struct StaticMeshData
	{
		std::vector<Vec3f> positions;
		std::vector<Vec3f> normals;
		std::vector<Vec2f> texCoords;
		std::vector<uint32_t> indices;
	};


public:
	/**
	 * @brief GLTF ������ �ε��մϴ�.
	 * 
	 * @param path GLTF������ ����Դϴ�.
	 * 
	 * @return GLTF �������� �����͸� ��ȯ�մϴ�.
	 * 
	 * @note �� �޼��带 �̿��ؼ� ���� �����ʹ� �ݵ�� Free �޼��带 �̿��ؼ� �����ؾ� �մϴ�.
	 */
	static cgltf_data* LoadFromFile(const std::string& path);


	/**
	 * @brief GLTF �����ͷκ��� ���� �޽� �����͸� �ε��մϴ�.
	 * 
	 * @param data �޽� �����͸� �ε��� GLTF �������Դϴ�.
	 * 
	 * @return GLTF ������ ���� �޽� ������ ����� ��ȯ�մϴ�.
	 */
	static std::vector<StaticMeshData> LoadStaticMeshData(cgltf_data* data);


	/**
	 * @brief GLTF ������ �Ҵ��� �����մϴ�.
	 * 
	 * @param data �Ҵ��� ������ GLTF �������Դϴ�.
	 */
	static void Free(cgltf_data* data);
};