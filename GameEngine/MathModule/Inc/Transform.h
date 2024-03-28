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
	 * @brief �� Ʈ�������� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 * 
	 * @param transform ���Ұ� ��ġ�ϴ��� Ȯ���� Ʈ�������Դϴ�.
	 * 
	 * @return �� Ʈ�������� ���Ұ� ��ġ�Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Transform&& transform) noexcept
	{
		return position == transform.position && rotate == transform.rotate && scale == transform.scale;
	}


	/**
	 * @brief �� Ʈ�������� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param transform ���Ұ� ��ġ�ϴ��� Ȯ���� Ʈ�������Դϴ�.
	 *
	 * @return �� Ʈ�������� ���Ұ� ��ġ�Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Transform& transform) noexcept
	{
		return position == transform.position && rotate == transform.rotate && scale == transform.scale;
	}


	/**
	 * @brief �� Ʈ�������� ���Ұ� ��ġ�� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param transform ���Ұ� ��ġ���� �ʴ��� Ȯ���� Ʈ�������Դϴ�.
	 *
	 * @return �� Ʈ�������� ���Ұ� ��ġ���� �ʴ´ٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Transform&& transform) noexcept
	{
		return position != transform.position || rotate != transform.rotate || scale != transform.scale;
	}


	/**
	 * @brief �� Ʈ�������� ���Ұ� ��ġ�� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param transform ���Ұ� ��ġ���� �ʴ��� Ȯ���� Ʈ�������Դϴ�.
	 *
	 * @return �� Ʈ�������� ���Ұ� ��ġ���� �ʴ´ٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Transform& transform) noexcept
	{
		return position != transform.position || rotate != transform.rotate || scale != transform.scale;
	}


	/**
	 * @brief Ʈ���� ���� ��ķ� ��ȯ�մϴ�.
	 * 
	 * @param transform ��ķ� ��ȯ�� Ʈ�������Դϴ�.
	 * 
	 * @return ��ȯ�� ����� ��ȯ�մϴ�.
	 */
	static inline Mat4x4 ToMat(const Transform& transform)
	{
		Vec3f x = transform.rotate * Vec3f(1.0f, 0.0f, 0.0f);
		Vec3f y = transform.rotate * Vec3f(0.0f, 1.0f, 0.0f);
		Vec3f z = transform.rotate * Vec3f(0.0f, 0.0f, 1.0f);

		x = x * transform.scale.x;
		y = y * transform.scale.y;
		z = z * transform.scale.z;

		Vec3f p = transform.position;

		return Mat4x4(
			x.x, x.y, x.z, 0,
			y.x, y.y, y.z, 0,
			z.x, z.y, z.z, 0,
			p.x, p.y, p.z, 1
		);
	}


	/**
	 * @brief ����� Ʈ���������� ��ȯ�մϴ�.
	 * 
	 * @param m Ʈ���������� ��ȯ�� ����Դϴ�.
	 * 
	 * @return ��ȯ�� Ʈ�������� ��ȯ�մϴ�.
	 */
	static inline Transform ToTransform(const Mat4x4& m)
	{
		Transform t;

		t.position = Vec3f(m.e30, m.e31, m.e32);
		t.rotate = Quat::ToQuat(m);

		Mat4x4 rotateScale(
			m.e00, m.e01, m.e02, 0.0f,
			m.e10, m.e11, m.e12, 0.0f,
			m.e20, m.e21, m.e22, 0.0f,
			 0.0f,  0.0f,  0.0f, 1.0f
		);

		Mat4x4 invRotateScale = Quat::ToMat(Quat::Inverse(t.rotate));
		Mat4x4 scaleKew = rotateScale * invRotateScale;

		t.scale = Vec3f(scaleKew.e00, scaleKew.e11, scaleKew.e22);

		return t;
	}


	/**
	 * @brief �� Ʈ�������� �����մϴ�.
	 * 
	 * @param lhs ������ Ʈ�������Դϴ�.
	 * @param rhs ������ �� �ٸ� Ʈ�������Դϴ�.
	 */
	static inline Transform Combine(const Transform& lhs, const Transform& rhs)
	{
		Transform t;

		t.scale = lhs.scale * rhs.scale;
		t.rotate = rhs.rotate * lhs.rotate;

		t.position = lhs.rotate * (lhs.scale * rhs.position);
		t.position = lhs.position + t.position;

		return t;
	}


	/**
	 * @brief Ʈ�������� ����ȯ�� ����ϴ�.
	 * 
	 * @param transform ����ȯ�� ����� Ʈ�������Դϴ�.
	 * 
	 * @return ���� ����ȯ Ʈ�������� ��ȯ�մϴ�.
	 */
	static inline Transform Inverse(const Transform& transform)
	{
		Transform inv;

		inv.rotate = Quat::Inverse(transform.rotate);

		inv.scale.x = MathModule::Abs(transform.scale.x) < MathModule::Epsilon ? 0.0f : 1.0f / transform.scale.x;
		inv.scale.y = MathModule::Abs(transform.scale.y) < MathModule::Epsilon ? 0.0f : 1.0f / transform.scale.y;
		inv.scale.z = MathModule::Abs(transform.scale.z) < MathModule::Epsilon ? 0.0f : 1.0f / transform.scale.z;

		Vec3f invTranslation = -transform.position;
		inv.position = inv.rotate * (inv.scale * invTranslation);

		return inv;
	}


	/**
	 * @brief �� Ʈ�������� �����մϴ�.
	 * 
	 * @param s ������ ���� Ʈ�������Դϴ�.
	 * @param e ������ �� Ʈ�������Դϴ�.
	 * @param t �� Ʈ�������� ���� �����Դϴ�.
	 * 
	 * @return ������ Ʈ�������� ��ȯ�մϴ�.
	 */
	static inline Transform Mix(const Transform& s, const Transform& e, const float& t)
	{
		Quat eRotate = e.rotate;

		if (Quat::Dot(s.rotate, eRotate) < 0.0f)
		{
			eRotate = -eRotate;
		}

		return Transform(
			Vec3f::Lerp(s.position, e.position, t),
			Quat::Nlerp(s.rotate, eRotate, t),
			Vec3f::Lerp(s.scale, e.scale, t)
		);
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