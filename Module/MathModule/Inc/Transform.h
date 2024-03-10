#pragma once

#include "Mat4x4.h"
#include "Quat.h"
#include "Vec3.h"


/**
 * @brief SRT(Scale, Rotation, Translation) ��ȯ�� �����մϴ�.
 */
struct Transform
{
	/**
	 * @brief Ʈ�������� �⺻ �������Դϴ�.
	 */
	Transform() noexcept
		: position(0.0f, 0.0f, 0.0f)
		, rotate(0.0f, 0.0f, 0.0f, 1.0f)
		, scale(1.0f, 1.0f, 1.0f) {}


	/**
	 * @brief Ʈ�������� �������Դϴ�.
	 *
	 * @param p �̵� ��ȯ ���� �� �̵��� ��ġ�Դϴ�.
	 * @param r ȸ�� ��ȯ ���� �� ������ ���ʹϾ��Դϴ�.
	 * @param s ũ�� ��ȯ ���� �� ������ ũ���Դϴ�.
	 */
	Transform(Vec3f&& p, Quat&& r, Vec3f&& s) noexcept
		: position(p)
		, rotate(r)
		, scale(s) {}


	/**
	 * @brief Ʈ�������� �������Դϴ�.
	 * 
	 * @param p �̵� ��ȯ ���� �� �̵��� ��ġ�Դϴ�.
	 * @param r ȸ�� ��ȯ ���� �� ������ ���ʹϾ��Դϴ�.
	 * @param s ũ�� ��ȯ ���� �� ������ ũ���Դϴ�.
	 */
	Transform(const Vec3f& p, const Quat& r, const Vec3f& s) noexcept
		: position(p)
		, rotate(r)
		, scale(s) {}


	/**
	 * @brief Ʈ�������� ���� �������Դϴ�.
	 * 
	 * @param instance ������ Ʈ�������� �ν��Ͻ��Դϴ�.
	 */
	Transform(Transform&& instance) noexcept
		: position(instance.position)
		, rotate(instance.rotate)
		, scale(instance.scale) {}


	/**
	 * @brief Ʈ�������� ���� �������Դϴ�.
	 *
	 * @param instance ������ Ʈ�������� �ν��Ͻ��Դϴ�.
	 */
	Transform(const Transform& instance) noexcept
		: position(instance.position)
		, rotate(instance.rotate)
		, scale(instance.scale) {}


	/**
	 * @brief Ʈ�������� ���� �������Դϴ�.
	 * 
	 * @param instance ������ Ʈ�������� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ Ʈ�������� �����ڸ� ��ȯ�մϴ�.
	 */
	Transform& operator=(Transform&& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		rotate = instance.rotate;
		scale = instance.scale;

		return *this;
	}


	/**
	 * @brief Ʈ�������� ���� �������Դϴ�.
	 *
	 * @param instance ������ Ʈ�������� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ Ʈ�������� �����ڸ� ��ȯ�մϴ�.
	 */
	Transform& operator=(const Transform& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		rotate = instance.rotate;
		scale = instance.scale;

		return *this;
	}


	/**
	 * @brief �̵� ��ȯ ���� �� �̵��� ��ġ�Դϴ�.
	 */
	Vec3f position;


	/**
	 * @brief ȸ�� ��ȯ ���� �� ������ ���ʹϾ��Դϴ�.
	 */
	Quat rotate;


	/**
	 * @brief ũ�� ��ȯ ���� �� ������ ũ���Դϴ�.
	 */
	Vec3f scale;
};