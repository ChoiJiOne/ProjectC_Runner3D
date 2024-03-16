#pragma once

#include <vector>
#include <string>

#include <cgltf.h>

#include "Transform.h"

#include "Clip.h"
#include "Pose.h"
#include "Skeleton.h"
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


	/**
	 * @brief GLTF ��Ű�� �޽� �������Դϴ�.
	 */
	struct SkinnedMeshData
	{
		std::vector<Vec3f> positions;
		std::vector<Vec3f> normals;
		std::vector<Vec2f> texCoords;
		std::vector<Vec4i> joints;
		std::vector<Vec4f> weights;
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
	 * @brief GLTF �����ͷκ��� ��Ű�� �޽� �����͸� �ε��մϴ�.
	 * 
	 * @param data �޽� �����͸� �ε��� GLTF �������Դϴ�.
	 *
	 * @return GLTF ������ ���� �޽� ������ ����� ��ȯ�մϴ�.
	 */
	static std::vector<SkinnedMeshData> LoadSkinnedMeshData(cgltf_data* data);


	/**
	 * @brief GLTF �����ͷκ��� ���� ���� �����͸� �ε��մϴ�.
	 * 
	 * @param data ��� ���� �����͸� �ε��� GLTF �������Դϴ�.
	 * 
	 * @return ��� ���� �����͸� ��ȯ�մϴ�.
	 */
	static Pose LoadRestPose(cgltf_data* data);


	/**
	 * @brief GLTF �����ͷκ��� ���ε� ���� �����͸� �ε��մϴ�.
	 * 
	 * @param data ���ε� ���� �����͸� �ε��� GLTF �������Դϴ�.
	 * 
	 * @return ���ε� ���� �����͸� ��ȯ�մϴ�.
	 */
	static Pose LoadBindPose(cgltf_data* data);


	/**
	 * @brief GLTF �����ͷκ��� ����Ʈ �̸� ����� ����ϴ�.
	 * 
	 * @param data ����Ʈ �̸� ����� �ε��� GLTF �������Դϴ�.
	 * 
	 * @return ����Ʈ �̸� ����� ��ȯ�մϴ�.
	 */
	static std::vector<std::string> LoadJointNames(cgltf_data* data);


	/**
	 * @brief GLTF �����ͷκ��� ���̷��� �����͸� ����ϴ�.
	 * 
	 * @param data ���̷��� �����͸� �ε��� GLTF �������Դϴ�.
	 * 
	 * @return ���̷����� ��ȯ�մϴ�.
	 */
	static Skeleton LoadSkeleton(cgltf_data* data);


	/**
	 * @brief GLTF �����ͷκ��� �ִϸ��̼� Ŭ�� ����� �ε��մϴ�.
	 * 
	 * @param data �ִϸ��̼� Ŭ�� �����͸� �ε��� GLTF �������Դϴ�.
	 * 
	 * @return �ִϸ��̼� Ŭ�� ����� ��ȯ�մϴ�.
	 */
	static std::vector<Clip> LoadAnimationClip(cgltf_data* data);


	/**
	 * @brief GLTF ������ �Ҵ��� �����մϴ�.
	 * 
	 * @param data �Ҵ��� ������ GLTF �������Դϴ�.
	 */
	static void Free(cgltf_data* data);


private:
	/**
	 * @brief ��ü ��� ������κ��� Ÿ�� ����� �ε����� ����ϴ�.
	 * 
	 * @param target �ε����� ���� ����Դϴ�.
	 * @param nodes ��ü ����� ����Դϴ�.
	 * @param numNodes ��ü ����� ���Դϴ�.
	 */
	static int32_t GetNodeIndex(cgltf_node* target, cgltf_node* nodes, uint32_t numNodes);


	/**
	 * @brief ����� ���� Ʈ�������� ����ϴ�.
	 * 
	 * @param node Ʈ������ ���� ���� ����Դϴ�.
	 * 
	 * @return ����� ���� Ʈ�������� ��ȯ�մϴ�.
	 */
	static Transform GetLocalTransform(cgltf_node* node);
};