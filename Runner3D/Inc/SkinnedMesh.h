#pragma once

#include <vector>

#include "IResource.h"
#include "Vertex3D.h"

class Pose;
class Skeleton;


/**
 * @brief ��Ű�� �޽� ���ҽ��Դϴ�.
 */
class SkinnedMesh : public IResource
{
public:
	/**
	 * @brief �޽� ���ҽ��� �����մϴ�.
	 *
	 * @param vertices �޽��� ���� ����Դϴ�.
	 * @param indices �޽��� �ε��� ����Դϴ�.
	 */
	explicit SkinnedMesh(const std::vector<VertexPositionNormalUvSkin3D>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief �޽��� ���� �Ҹ����Դϴ�.
	 *
	 * @note �޽� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~SkinnedMesh();


	/**
	 * @brief �޽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SkinnedMesh);


	/**
	 * @brief �޽��� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief �޽� ���ҽ��� ���������ο� ���ε��մϴ�.
	 */
	void Bind();


	/**
	 * @brief ���ε��� �޽� ���ҽ��� ���ε� �����մϴ�.
	 */
	void Unbind();


	/**
	 * @brief �޽��� �ε��� ���� ����ϴ�.
	 *
	 * @return �޽��� �ε��� ���� ��ȯ�մϴ�.
	 */
	uint32_t GetIndexCount() const { return static_cast<uint32_t>(indices_.size()); }


	/**
	 * @brief �޽��� ���� �迭 ������Ʈ�� ����ϴ�.
	 *
	 * @return �޽��� ���� �迭 ������Ʈ�� ��ȯ�մϴ�.
	 */
	uint32_t GetVertexArrayObject() const { return vertexArrayObject_; }


	/**
	 * @brief �޽��� ���� ����� ����ϴ�.
	 *
	 * @return �޽��� ���� ��� ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::vector<VertexPositionNormalUvSkin3D>& GetVertices() const { return vertices_; }


	/**
	 * @brief ��Ű�׵� ���� ����� ����ϴ�.
	 * 
	 * @return ��Ű�׵� ���� ��� ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::vector<VertexPositionNormalUvSkin3D>& GetSkinnedVertices() const { return skinnedVertices_; }


	/**
	 * @brief CPU ��Ű���� �����մϴ�.
	 * 
	 * @param skeleton ���� ��Ű���� ������ �� ������ �����Դϴ�.
	 * @param pose ���� ��Ű���� ������ �� ������ �����Դϴ�.
	 */
	void Skin(Skeleton* skeleton, Pose* pose);


private:
	/**
	 * @brief ���� ���� ����Դϴ�.
	 */
	std::vector<VertexPositionNormalUvSkin3D> vertices_;


	/**
	 * @brief ��Ű�׵� ���� ����Դϴ�.
	 */
	std::vector<VertexPositionNormalUvSkin3D> skinnedVertices_;


	/**
	 * @brief ���� ��Ͽ� �����ϴ� �ε��� ����Դϴ�.
	 */
	std::vector<uint32_t> indices_;


	/**
	 * @brief ���� �����͸� �����ϴ� �� �ʿ��� ��� �����Դϴ�.
	 *
	 * @see
	 * - https://www.khronos.org/opengl/wiki/Vertex_Specification#:~:text=has%20the%20details.-,Vertex%20Array%20Object,-Vertex%20Array%20Object
	 * - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGenVertexArrays.xhtml
	 */
	uint32_t vertexArrayObject_ = 0;


	/**
	 * @brief GPU ���� ���� ���� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief GPU ���� �ε��� ���� ������Ʈ�Դϴ�.
	 */
	uint32_t indexBufferObject_ = 0;


	/**
	 * @brief ���� ��� ����Դϴ�.
	 */
	std::vector<Mat4x4> posePalette_;
};