#pragma once

#include "Mat4x4.h"
#include "MathModule.h"
#include "Vec3.h"


/**
 * @brief ���ʹϾ��Դϴ�.
 */
struct Quat
{
	/**
	 * @brief ���ʹϾ��� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Quat() noexcept : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 *
	 * @param xx ���ʹϾ��� x �����Դϴ�.
	 * @param yy ���ʹϾ��� y �����Դϴ�.
	 * @param zz ���ʹϾ��� z �����Դϴ�.
	 * @param ww ���ʹϾ��� w �����Դϴ�.
	 */
	Quat(float&& xx, float&& yy, float&& zz, float&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 *
	 * @param xx ���ʹϾ��� x �����Դϴ�.
	 * @param yy ���ʹϾ��� y �����Դϴ�.
	 * @param zz ���ʹϾ��� z �����Դϴ�.
	 * @param ww ���ʹϾ��� w �����Դϴ�.
	 */
	Quat(const float& xx, const float& yy, const float& zz, const float& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 *
	 * @param vv i,j,k ���� ���� ����Դϴ�.
	 * @param ww ȸ���� �������� �����ϴ� w �����Դϴ�.
	 */
	Quat(Vec3f&& vv, float&& ww) noexcept : v(vv), w(ww) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 *
	 * @param vv i,j,k ���� ���� ����Դϴ�.
	 * @param ww ȸ���� �������� �����ϴ� w �����Դϴ�.
	 */
	Quat(const Vec3f& vv, const float& ww) noexcept : v(vv), w(ww) {}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 *
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Quat(Quat&& q) noexcept : x(q.x), y(q.y), z(q.z), w(q.w) {}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 *
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Quat(const Quat& q) noexcept : x(q.x), y(q.y), z(q.z), w(q.w) {}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 *
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator=(Quat&& q) noexcept
	{
		if (this == &q) return *this;

		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;

		return *this;
	}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 *
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator=(const Quat& q) noexcept
	{
		if (this == &q) return *this;

		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;

		return *this;
	}


	/**
	 * @brief ���ʹϾ� -��ȣ�� ���մϴ�.
	 *
	 * @return ���ʹϾ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Quat operator-() const
	{
		return Quat(-x, -y, -z, -w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Quat operator+(Quat&& q) const
	{
		return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Quat operator+(const Quat& q) const
	{
		return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Quat operator-(Quat&& q) const
	{
		return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Quat operator-(const Quat& q) const
	{
		return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
	}


	/**
	 * @brief ���ʹϾ��� ������ ������ �����մϴ�.
	 *
	 * @param s ������ ������ ������ ���Դϴ�.
	 *
	 * @return ������ ������ ������ ����� ��ȯ�մϴ�.
	 */
	Quat operator*(float s) const
	{
		return Quat(x * s, y * s, z * s, w * s);
	}


	/**
	 * @brief ���ʹϾ� ���� ������ �����մϴ�.
	 *
	 * @param q ���� ������ ������ ���ʹϾ� ���Դϴ�.
	 *
	 * @return ���� ������ ������ ����� ��ȯ�մϴ�.
	 */
	Quat operator*(Quat&& q) const
	{
		return Quat(
			+q.x * w + q.y * z - q.z * y + q.w * x,
			-q.x * z + q.y * w + q.z * x + q.w * y,
			+q.x * y - q.y * x + q.z * w + q.w * z,
			-q.x * x - q.y * y - q.z * z + q.w * w
		);
	}


	/**
	 * @brief ���ʹϾ� ���� ������ �����մϴ�.
	 *
	 * @param q ���� ������ ������ ���ʹϾ� ���Դϴ�.
	 *
	 * @return ���� ������ ������ ����� ��ȯ�մϴ�.
	 */
	Quat operator*(const Quat& q) const
	{
		return Quat(
			+q.x * w + q.y * z - q.z * y + q.w * x,
			-q.x * z + q.y * w + q.z * x + q.w * y,
			+q.x * y - q.y * x + q.z * w + q.w * z,
			-q.x * x - q.y * y - q.z * z + q.w * w
		);
	}


	/**
	 * @brief ���ʹϾ�� ������ ���� ������ �����մϴ�.
	 *
	 * @param vec ���� ������ ������ ���� ���Դϴ�.
	 *
	 * @return ���� ������ ������ ����� ��ȯ�մϴ�.
	 */
	Vec3f operator*(Vec3f&& vec) const
	{
		return v * 2.0f * Vec3f::Dot(v, vec) + vec * (w * w - Vec3f::Dot(v, v)) + Vec3f::Cross(v, vec) * 2.0f * w;
	}


	/**
	 * @brief ���ʹϾ�� ������ ���� ������ �����մϴ�.
	 *
	 * @param vec ���� ������ ������ ���� ���Դϴ�.
	 *
	 * @return ���� ������ ������ ����� ��ȯ�մϴ�.
	 */
	Vec3f operator*(const Vec3f& vec) const
	{
		return v * 2.0f * Vec3f::Dot(v, vec) + vec * (w * w - Vec3f::Dot(v, v)) + Vec3f::Cross(v, vec) * 2.0f * w;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator+=(Quat&& q) noexcept
	{
		x += q.x;
		y += q.y;
		z += q.z;
		w += q.w;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator+=(const Quat& q) noexcept
	{
		x += q.x;
		y += q.y;
		z += q.z;
		w += q.w;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator-=(Quat&& q) noexcept
	{
		x -= q.x;
		y -= q.y;
		z -= q.z;
		w -= q.w;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator-=(const Quat& q) noexcept
	{
		x -= q.x;
		y -= q.y;
		z -= q.z;
		w -= q.w;

		return *this;
	}


	/**
	 * @brief ���ʹϾ��� ������ ������ �����մϴ�.
	 *
	 * @param s ������ ������ ������ ���Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator*=(float s) noexcept
	{
		x *= s;
		y *= s;
		z *= s;
		w *= s;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �������� �˻��մϴ�.
	 *
	 * @param  q �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ��� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Quat&& q) const
	{
		return MathModule::Abs(x - q.x) <= MathModule::Epsilon
			&& MathModule::Abs(y - q.y) <= MathModule::Epsilon
			&& MathModule::Abs(z - q.z) <= MathModule::Epsilon
			&& MathModule::Abs(w - q.w) <= MathModule::Epsilon;
	}


	/**
	 * @brief �� ���ʹϾ� �������� �˻��մϴ�.
	 *
	 * @param q �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ��� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Quat& q) const
	{
		return MathModule::Abs(x - q.x) <= MathModule::Epsilon
			&& MathModule::Abs(y - q.y) <= MathModule::Epsilon
			&& MathModule::Abs(z - q.z) <= MathModule::Epsilon
			&& MathModule::Abs(w - q.w) <= MathModule::Epsilon;
	}


	/**
	 * @brief �� ���ʹϾ� �������� ������ �˻��մϴ�.
	 *
	 * @param q �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ��� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Quat&& q) const
	{
		return MathModule::Abs(x - q.x) > MathModule::Epsilon
			|| MathModule::Abs(y - q.y) > MathModule::Epsilon
			|| MathModule::Abs(z - q.z) > MathModule::Epsilon
			|| MathModule::Abs(w - q.w) > MathModule::Epsilon;
	}


	/**
	 * @brief �� ���ʹϾ� �������� ������ �˻��մϴ�.
	 *
	 * @param q �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ��� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Quat& q) const
	{
		return MathModule::Abs(x - q.x) > MathModule::Epsilon
			|| MathModule::Abs(y - q.y) > MathModule::Epsilon
			|| MathModule::Abs(z - q.z) > MathModule::Epsilon
			|| MathModule::Abs(w - q.w) > MathModule::Epsilon;
	}


	/**
	 * @brief ������ ���� �̿��ؼ� ���ʹϾ��� ����ϴ�.
	 *
	 * @parma axis �� �Դϴ�.
	 * @param radian ���� ������ �����Դϴ�.
	 */
	static inline Quat AxisRadian(const Vec3f& axis, float radian)
	{
		Vec3f norm = Vec3f::Normalize(axis);

		float s = MathModule::Sin(radian * 0.5f);
		float c = MathModule::Cos(radian * 0.5f);

		return Quat(norm.x * s, norm.y * s, norm.z * s, c);
	}


	/**
	 * @brief ������ ���� �̿��ؼ� ���ʹϾ��� ����ϴ�.
	 *
	 * @parma axis �� �Դϴ�.
	 * @param angle ���ʺй� ������ �����Դϴ�.
	 */
	static inline Quat AxisAngle(const Vec3f& axis, float angle)
	{
		float radian = MathModule::ToRadian(angle);

		float s = MathModule::Sin(radian * 0.5f);
		float c = MathModule::Cos(radian * 0.5f);
		Vec3f norm = Vec3f::Normalize(axis);

		return Quat(norm.x * s, norm.y * s, norm.z * s, c);
	}


	/**
	 * @brief ���ʹϾ��� ���� ����ϴ�.
	 * 
	 * @param q ���� ���� ���ʹϾ��Դϴ�.
	 * 
	 * @return ���ʹϾ��� ���� ��ȯ�մϴ�.
	 */
	static inline Vec3f Axis(const Quat& q)
	{
		return Vec3f::Normalize(Vec3f(q.x, q.y, q.z));
	}


	/**
	 * @brief ���ʹϾ��� ���� ���� ����ϴ�.
	 *
	 * @param q ���� ������ ���� ���ʹϾ��Դϴ�.
	 *
	 * @return ���ʹϾ��� ���� ���� ��ȯ�մϴ�.
	 */
	static inline float Radian(const Quat& q)
	{
		return 2.0f * MathModule::ACos(q.w);
	}


	/**
	 * @brief ���ʹϾ��� ���ʺй� ���� ����ϴ�.
	 *
	 * @param q ���ʺй� ������ ���� ���ʹϾ��Դϴ�.
	 *
	 * @return ���ʹϾ��� ���ʺй� ���� ��ȯ�մϴ�.
	 */
	static inline float Angle(const Quat& q)
	{
		return MathModule::ToDegree(2.0f * MathModule::ACos(q.w));
	}


	/**
	 * @brief �� ���ʹϾ��� ���� ������ �����մϴ�.
	 * 
	 * @param lhs ���ʹϾ��� ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ���ʹϾ��� ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline float Dot(const Quat& lhs, const Quat& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	/**
	 * @brief ���ʹϾ��� ũ�� ���� ���� ����մϴ�.
	 *
	 * @param q ũ�� ������ ����� ���ʹϾ��Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	static inline float LengthSq(const Quat& q)
	{
		return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
	}


	/**
	 * @brief ���ʹϾ��� ũ�⸦ ����ϴ�.
	 *
	 * @param q ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static inline float Length(const Quat& q)
	{
		float lengthSq = Quat::LengthSq(q);
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief ���ʹϾ��� ����ȭ�մϴ�.
	 *
	 * @param q ����ȭ �� ���ʹϾ��Դϴ�.
	 *
	 * @return ����ȭ�� ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Normalize(const Quat& q)
	{
		float invLength = 1.0f / Quat::Length(q);
		return Quat(q.x * invLength, q.y * invLength, q.z * invLength, q.w * invLength);
	}


	/**
	 * @brief �ӷ� ���ʹϾ��� ����ϴ�.
	 * 
	 * @param q �ӷ� ���� ����� ���ʹϾ��Դϴ�.
	 * 
	 * @return �ӷ� ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Conjugate(const Quat& q)
	{
		return Quat(-q.x, -q.y, -q.z, q.w);
	}


	/**
	 * @brief ���ʹϾ��� ���� ������ ����ϴ�.
	 * 
	 * @param ���� ������ ����� ���ʹϾ��Դϴ�.
	 * 
	 * @return ���ʹϾ��� ���� ������ ��ȯ�մϴ�.
	 */
	static inline Quat Inverse(const Quat& q)
	{
		float invLengthSq = 1.0f / Quat::LengthSq(q);
		return Quat(-q.x * invLengthSq, -q.y * invLengthSq, -q.z * invLengthSq, q.w * invLengthSq);
	}

	
	/**
	 * @brief ��� ���Ұ� 0�� ���ʹϾ��� ����ϴ�.
	 * 
	 * @return ��� ���Ұ� 0�� ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Zero()
	{
		return Quat(0.0f, 0.0f, 0.0f, 0.0f);
	}


	/**
	 * @brief w�� ���� 1�� ���ʹϾ��� ����ϴ�.
	 * 
	 * @return w�� ���� 1�� ���ʹϾ��� ����ϴ�.
	 */
	static inline Quat Identity()
	{
		return Quat(0.0f, 0.0f, 0.0f, 1.0f);
	}


	/**
	 * @brief �� ���� ���� ȸ�� ���ʹϾ��� ����ϴ�.
	 * 
	 * @param s ȸ�� ���� �����Դϴ�.
	 * @param e ȸ�� �� �����Դϴ�.
	 * 
	 * @return �� ���� ���� ȸ�� ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Rotate(const Vec3f& s, const Vec3f& e)
	{
		Vec3f start = Vec3f::Normalize(s);
		Vec3f end = Vec3f::Normalize(e);
		Quat quat;

		if (start == end)
		{
			quat = Quat();
		}
		else if (start == end * -1.0f)
		{
			Vec3f ortho;

			if (MathModule::Abs(start.y) < MathModule::Abs(start.x))
			{
				ortho = Vec3f(0.0f, 1.0f, 0.0f);
			}
			else if (MathModule::Abs(start.z) < MathModule::Abs(start.y) && MathModule::Abs(start.z) < MathModule::Abs(start.x))
			{
				ortho = Vec3f(0.0f, 0.0f, 1.0f);
			}
			else
			{
				ortho = Vec3f(1.0f, 0.0f, 0.0f);
			}

			Vec3f axis = Vec3f::Normalize(Vec3f::Cross(start, ortho));
			quat = Quat(axis, 0.0f);
		}
		else
		{
			Vec3f half = Vec3f::Normalize(start + end);
			Vec3f axis = Vec3f::Cross(start, half);

			quat = Quat(axis, Vec3f::Dot(start, half));
		}

		return quat;
	}


	/**
	 * @brief �� ���ʹϾ��� ���� �����մϴ�.
	 *
	 * @param s ������ ���� ���ʹϾ��Դϴ�.
	 * @param e ������ �� ���ʹϾ��Դϴ�.
	 * @param t �� ���ʹϾ��� ���� �����Դϴ�.
	 *
	 * @return ������ ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Lerp(const Quat& s, const Quat& e, const float& t)
	{
		return s * (1.0f - t) + e * t;
	}


	/**
	 * @brief �� ���ʹϾ��� ����ȭ�� ���� �������� ����մϴ�.
	 *
	 * @param s ������ ���� ���ʹϾ��Դϴ�.
	 * @param e ������ �� ���ʹϾ��Դϴ�.
	 * @param t �� ���ʹϾ��� ���� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���� ���� ���� ��ȯ�մϴ�.
	 */
	static inline Quat Nlerp(const Quat& s, const Quat& e, const float& t)
	{
		return Normalize(Lerp(s, e, t));
	}


	/**
	 * @brief �� ���ʹϾ��� ���� ���� �����մϴ�.
	 *
	 * @param s ������ ���� ���ʹϾ��Դϴ�.
	 * @param e ������ �� ���ʹϾ��Դϴ�.
	 * @param t �� ���ʹϾ��� ���� �����Դϴ�.
	 *
	 * @return ������ ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Slerp(const Quat& s, const Quat& e, const float& t)
	{
		return Pow(Inverse(s) * e, t) * s;
	}


	/**
	 * @brief �� ���ʹϾ��� ����ȭ�� ���� ���� �������� ����մϴ�.
	 *
	 * @param s ������ ���� ���ʹϾ��Դϴ�.
	 * @param e ������ �� ���ʹϾ��Դϴ�.
	 * @param t �� ���ʹϾ��� ���� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���� ���� ���� ��ȯ�մϴ�.
	 */
	static inline Quat Nslerp(const Quat& s, const Quat& e, const float& t)
	{
		return Normalize(Slerp(s, e, t));
	}


	/**
	 * @brief ���ʹϾ��� �ŵ� ������ �����մϴ�.
	 * 
	 * @param q �ŵ� ���� ������ ������ ���ʹϾ��Դϴ�.
	 * @param power �ŵ����� ���Դϴ�.
	 * 
	 * @return �ŵ� ������ ����� ���ʹϾ� ���� ��ȯ�մϴ�.
	 */
	static inline Quat Pow(const Quat& q, const float power)
	{
		float radian = Quat::Radian(q);
		Vec3f axis = Vec3f::Normalize(Quat::Axis(q));

		float c = MathModule::Cos(power * radian * 0.5f);
		float s = MathModule::Sin(power * radian * 0.5f);

		return Quat(axis.x * s, axis.y * s, axis.z * s, c);
	}


	/**
	 * @brief ����� ���� �������� ���ʹϾ��� �����մϴ�.
	 * 
	 * @param direction ���ʹϾ� ������ ����� �����Դϴ�.
	 * @param up  ���ʹϾ� ������ ����� �� �����Դϴ�.
	 * 
	 * @return ������ ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat LookRotate(const Vec3f& direction, const Vec3f& up)
	{
		Vec3f f = Vec3f::Normalize(direction);
		Vec3f u = Vec3f::Normalize(up);
		Vec3f r = Vec3f::Cross(u, f);

		u = Vec3f::Cross(f, r);

		Quat f2d = Quat::Rotate(Vec3f(0.0f, 0.0f, 1.0f), f);
		Vec3f objectUp = f2d * Vec3f(0.0f, 1.0f, 0.0f);
		Quat u2u = Quat::Rotate(objectUp, u);

		return Quat::Normalize(f2d * u2u);
	}


	/**
	 * @brief ���ʹϾ��� ��ķ� ��ȯ�մϴ�.
	 * 
	 * @param q ��ķ� ��ȯ�� ���ʹϾ��Դϴ�.
	 * 
	 * @return ��ȯ�� ����� ��ȯ�մϴ�.
	 */
	static inline Mat4x4 ToMat(const Quat& q)
	{
		Vec3f r = q * Vec3f(1.0f, 0.0f, 0.0f);
		Vec3f u = q * Vec3f(0.0f, 1.0f, 0.0f);
		Vec3f f = q * Vec3f(0.0f, 0.0f, 1.0f);

		return Mat4x4(
			 r.x,  r.y,  r.z, 0.0f,
			 u.x,  u.y,  u.z, 0.0f,
			 f.x,  f.y,  f.z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief ����� ���ʹϾ����� ��ȯ�մϴ�.
	 * 
	 * @param m ���ʹϾ����� ��ȯ�� ����Դϴ�.
	 * 
	 * @return ��ȯ�� ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat ToQuat(const Mat4x4& m)
	{
		Vec3f u = Vec3f::Normalize(Vec3f(m.e10, m.e11, m.e12));
		Vec3f f = Vec3f::Normalize(Vec3f(m.e20, m.e21, m.e22));
		Vec3f r = Vec3f::Cross(u, f);
		u = Vec3f::Cross(f, r);

		return LookRotate(f, u);
	}


	/**
	 * @brief �� ���ʹϾ��� ������ ������ Ȯ���մϴ�.
	 * 
	 * @param lhs ������ ������ ���� ���ʹϾ��Դϴ�.
	 * @param rhs ������ ������ ���� �� �ٸ� ���ʹϾ��Դϴ�.
	 */
	bool IsSameOrientation(const Quat& lhs, const Quat& rhs)
	{
		return (MathModule::Abs(lhs.x - rhs.x) <= MathModule::Epsilon 
			&& MathModule::Abs(lhs.y - rhs.y) <= MathModule::Epsilon 
			&& MathModule::Abs(lhs.z - rhs.z) <= MathModule::Epsilon
			&& MathModule::Abs(lhs.w - rhs.w) <= MathModule::Epsilon
			)
			|| (MathModule::Abs(lhs.x + rhs.x) <= MathModule::Epsilon 
			&& MathModule::Abs(lhs.y + rhs.y) <= MathModule::Epsilon 
			&& MathModule::Abs(lhs.z + rhs.z) <= MathModule::Epsilon 
			&& MathModule::Abs(lhs.w + rhs.w) <= MathModule::Epsilon
			);
	}
	
	
	/**
	 * @brief ���ʹϾ��� �����Դϴ�.
	 */
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct
		{
			Vec3f v; // (x, y, z)
			float w;
		};
		float data[4];
	};
};