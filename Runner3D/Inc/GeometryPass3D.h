#pragma once

#include <array>
#include <vector>

#include "Shader.h"
#include "Vertex3D.h"


/**
 * @brief 3D �⺻ ������ �������ϴ� ���̴��Դϴ�.
 */
class GeometryPass3D : public Shader
{
public:
	/**
	 * @brief 3D �⺻ ������ �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 */
	explicit GeometryPass3D();


	/**
	 * @brief 3D �⺻ ������ �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~GeometryPass3D();


	/**
	 * @brief 3D �⺻ ������ �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GeometryPass3D);



	/**
	 * @brief ���̴��� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ȭ�鿡 3D ������ �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param positions ȭ�� ���� 3D �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 *
	 * @note 3D ������ ������ MAX_VERTEX_SIZE(10000)�� ũ�⸦ ���� �� �����ϴ�.
	 */
	void DrawPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color);


	/**
	 * @brief ȭ�鿡 ������ ������ 3D ���� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param positions ȭ�� ���� 3D �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 *
	 * @note 2D ������ ������ MAX_VERTEX_SIZE(10000)�� ũ�⸦ ���� �� �����ϴ�.
	 */
	void DrawConnectPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color);


	/**
	 * @brief ȭ�鿡 3D ���� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param fromPosition ���� �������Դϴ�.
	 * @param toPosition ���� �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 */
	void DrawLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec3f& toPosition, const Vec4f& color);


	/**
	 * @brief ȭ�鿡 3D ���� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param fromPosition ���� �������Դϴ�.
	 * @param fromColor ���� ������ �����Դϴ�.
	 * @param toPosition ���� �����Դϴ�.
	 * @param toColor ���� ���� �����Դϴ�.
	 */
	void DrawLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec4f& fromColor, const Vec3f& toPosition, const Vec4f& toColor);


	/**
	 * @brief 3D ť�긦 ȭ�鿡 �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param world ���� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param extents ť���� X/Y/Z �� ���������� ũ���Դϴ�.
	 * @param color ť���� �����Դϴ�.
	 */
	void DrawCube3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const Vec3f& extents, const Vec4f& color);


	/**
	 * @brief 3D ���̾� ������ ��(Sphere)�� ȭ�鿡 �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param center ���� �߽� ��ǥ�Դϴ�.
	 * @param radius ���� ������ �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 * @param sliceCount �� ��鿡 �����ϴ� ���� �ѷ� ���� Ƚ���Դϴ�. �⺻ ���� 300�Դϴ�.
	 */
	void DrawSphere3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, float radius, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief ȭ�鿡 XZ ����� ���ڸ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param minX X��ǥ�� �ּҰ��Դϴ�.
	 * @param maxX X��ǥ�� �ִ��Դϴ�.
	 * @param strideX X�� ���������� �����Դϴ�.
	 * @param minZ Z��ǥ�� �ּҰ��Դϴ�.
	 * @param maxZ Z��ǥ�� �ִ��Դϴ�.
	 * @param strideZ Z�� ���������� �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 */
	void DrawGrid3D(const Mat4x4& view, const Mat4x4& projection, float minX, float maxX, float strideX, float minZ, float maxZ, float strideZ, const Vec4f& color);


private:
	/**
	 * @brief �⺻ ������ �׸��� Ÿ���Դϴ�.
	 */
	enum class EDrawType : int32_t
	{
		Points      = 0x0000,
		Lines       = 0x0001,
		LineStrip   = 0x0003,
		Triangles   = 0x0004,
		TriangleFan = 0x0006,
		None        = 0xFFFF,
	};


	/**
	 * @brief 3D �⺻ ���� �׸��⸦ �����մϴ�.
	 *
	 * @param world ���� ����Դϴ�.
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param drawType �׸��� Ÿ���Դϴ�.
	 * @param vertexCount ���� ���Դϴ�.
	 */
	void DrawGeometry3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const EDrawType& drawType, uint32_t vertexCount);


private:
	/**
	 * @brief ���� ���� ����� �ִ� ũ���Դϴ�.
	 */
	static const int32_t MAX_VERTEX_SIZE = 10000;


	/**
	 * @brief ������ ���� ����Դϴ�.
	 */
	std::array<VertexPositionColor3D, MAX_VERTEX_SIZE> vertices_;


	/**
	 * @brief ���� ������ ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ���� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;
};