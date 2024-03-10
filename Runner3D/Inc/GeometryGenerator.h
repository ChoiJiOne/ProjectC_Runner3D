#pragma once

#include <vector>

#include "Vertex3D.h"


/**
 * @brief 3D ���� ������ �����մϴ�.
 *
 * @note �� Ŭ������ ��� ������ �޼���� ��� static �Դϴ�.
 */
class GeometryGenerator
{
public:
	/**
	 * @brief 3D ť���� ������ �ε��� ����� �����մϴ�.
	 *
	 * @param size 3D ť���� X, Y, Z�� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ť���� ���� ����Դϴ�.
	 * @param outIndices  ������ ť���� �ε��� ����Դϴ�.
	 */
	static void CreateCube(const Vec3f& size, std::vector<VertexPositionNormalUv3D>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 3D ���� ������ �ε��� ����� �����մϴ�.
	 *
	 * @param radius 3D ���� ������ �����Դϴ�.
	 * @param tessellation 3D ���� ���� Ƚ���Դϴ�. ũ��� 3�̻��̿��� �մϴ�.
	 * @param outVertices ������ ���� ���� ����Դϴ�.
	 * @param outIndices  ������ ���� �ε��� ����Դϴ�.
	 */
	static void CreateSphere(float radius, uint32_t tessellation, std::vector<VertexPositionNormalUv3D>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 3D ������� ������ �ε��� ����� �����մϴ�.
	 *
	 * @param radius 3D ������� ������ �����Դϴ�.
	 * @param height 3D ������� �����Դϴ�.
	 * @param tessellation 3D ������� ���� Ƚ���Դϴ�. ũ��� 3�̻��̿��� �մϴ�.
	 * @param outVertices ������ ������� ���� ����Դϴ�.
	 * @param outIndices  ������ ������� �ε��� ����Դϴ�.
	 */
	static void CreateCylinder(float radius, float height, uint32_t tessellation, std::vector<VertexPositionNormalUv3D>& outVertices, std::vector<uint32_t>& outIndices);


private:
	/**
	 * @brief 3D ����� ���/�ϴ��� ������ �ε��� ����� �����մϴ�.
	 *
	 * @param radius 3D ������� ������ �����Դϴ�.
	 * @param height 3D ������� �����Դϴ�.
	 * @param tessellation 3D ������� ���� Ƚ���Դϴ�. ũ��� 3�̻��̿��� �մϴ�.
	 * @param bIsTop ������� �ϴ����� Ȯ���մϴ�.
	 * @param outVertices ������ ����� ���/�ϴ��� ���� ����Դϴ�.
	 * @param outIndices  ������ ����� ���/�ϴ��� �ε��� ����Դϴ�.
	 */
	static void CreateCylinderCap(float radius, float height, uint32_t tessellation, bool bIsTop, std::vector<VertexPositionNormalUv3D>& outVertices, std::vector<uint32_t>& outIndices);
};