#pragma once

#include <array>
#include <vector>

#include "Shader.h"
#include "Vertex3D.h"


/**
 * @brief 3D 기본 도형을 렌더링하는 셰이더입니다.
 */
class GeometryPass3D : public Shader
{
public:
	/**
	 * @brief 3D 기본 도형을 렌더링하는 셰이더의 디폴트 생성자입니다.
	 */
	explicit GeometryPass3D();


	/**
	 * @brief 3D 기본 도형을 렌더링하는 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더의 내부에서 할당된 요소를 해제하기 위해서는 반드시 Release를 호출해야 합니다.
	 */
	virtual ~GeometryPass3D();


	/**
	 * @brief 3D 기본 도형을 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GeometryPass3D);



	/**
	 * @brief 셰이더의 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 화면에 3D 점들을 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param positions 화면 상의 3D 점들입니다.
	 * @param color 점들의 색상입니다.
	 *
	 * @note 3D 점들의 개수는 MAX_VERTEX_SIZE(10000)의 크기를 넘을 수 없습니다.
	 */
	void DrawPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color);


	/**
	 * @brief 화면에 점들을 연결한 3D 선을 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param positions 화면 상의 3D 점들입니다.
	 * @param color 점들의 색상입니다.
	 *
	 * @note 2D 점들의 개수는 MAX_VERTEX_SIZE(10000)의 크기를 넘을 수 없습니다.
	 */
	void DrawConnectPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color);


	/**
	 * @brief 화면에 3D 선을 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param fromPosition 선의 시작점입니다.
	 * @param toPosition 선의 끝점입니다.
	 * @param color 선의 색상입니다.
	 */
	void DrawLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec3f& toPosition, const Vec4f& color);


	/**
	 * @brief 화면에 3D 선을 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param fromPosition 선의 시작점입니다.
	 * @param fromColor 선의 시작점 색상입니다.
	 * @param toPosition 선의 끝점입니다.
	 * @param toColor 선의 끝점 색상입니다.
	 */
	void DrawLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec4f& fromColor, const Vec3f& toPosition, const Vec4f& toColor);


	/**
	 * @brief 3D 큐브를 화면에 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param world 월드 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param extents 큐브의 X/Y/Z 축 방향으로의 크기입니다.
	 * @param color 큐브의 색상입니다.
	 */
	void DrawCube3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const Vec3f& extents, const Vec4f& color);


	/**
	 * @brief 3D 와이어 프레임 구(Sphere)를 화면에 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param center 구의 중심 좌표입니다.
	 * @param radius 구의 반지름 길이입니다.
	 * @param color 구의 색상입니다.
	 * @param sliceCount 각 평면에 평행하는 원의 둘레 절단 횟수입니다. 기본 값은 300입니다.
	 */
	void DrawSphere3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, float radius, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief 화면에 XZ 평면의 격자를 그립니다.
	 *
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param minX X좌표의 최소값입니다.
	 * @param maxX X좌표의 최댓값입니다.
	 * @param strideX X축 방향으로의 간격입니다.
	 * @param minZ Z좌표의 최소값입니다.
	 * @param maxZ Z좌표의 최댓값입니다.
	 * @param strideZ Z축 방향으로의 간격입니다.
	 * @param color 격자의 색상입니다.
	 */
	void DrawGrid3D(const Mat4x4& view, const Mat4x4& projection, float minX, float maxX, float strideX, float minZ, float maxZ, float strideZ, const Vec4f& color);


private:
	/**
	 * @brief 기본 도형의 그리기 타입입니다.
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
	 * @brief 3D 기본 도형 그리기를 수행합니다.
	 *
	 * @param world 월드 행렬입니다.
	 * @param view 시야 행렬입니다.
	 * @param projection 투영 행렬입니다.
	 * @param drawType 그리기 타입입니다.
	 * @param vertexCount 정점 수입니다.
	 */
	void DrawGeometry3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const EDrawType& drawType, uint32_t vertexCount);


private:
	/**
	 * @brief 도형 정점 목록의 최대 크기입니다.
	 */
	static const int32_t MAX_VERTEX_SIZE = 10000;


	/**
	 * @brief 도형의 정점 목록입니다.
	 */
	std::array<VertexPositionColor3D, MAX_VERTEX_SIZE> vertices_;


	/**
	 * @brief 정점 버퍼의 오브젝트입니다.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief 정점 버퍼 목록의 오브젝트입니다.
	 */
	uint32_t vertexArrayObject_ = 0;
};