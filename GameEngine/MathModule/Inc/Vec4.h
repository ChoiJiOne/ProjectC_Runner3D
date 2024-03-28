#pragma once

#include <cstdint>

#include "MathModule.h"


/**
 * @brief ������ ������ Ÿ���� ������ 3���� �����Դϴ�.
 */
struct Vec4i
{
	/**
	 * @brief 4���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vec4i() noexcept : x(0), y(0), z(0), w(0) {}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vec4i(int32_t&& xx, int32_t&& yy, int32_t&& zz, int32_t&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vec4i(const int32_t& xx, const int32_t& yy, const int32_t& zz, const int32_t& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vec4i(int32_t&& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vec4i(const int32_t& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vec4i(Vec4i&& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}
	

	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vec4i(const Vec4i& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}


	/**
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator=(Vec4i&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}


	/**
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator=(const Vec4i& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}


	/**
	 * @brief 4���� ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return 4���� ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vec4i operator-() const
	{
		return Vec4i(-x, -y, -z, -w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4i operator+(Vec4i&& v) const
	{
		return Vec4i(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4i operator+(const Vec4i& v) const
	{
		return Vec4i(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vec4i operator-(Vec4i&& v) const
	{
		return Vec4i(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vec4i operator-(const Vec4i& v) const
	{
		return Vec4i(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4i operator*(Vec4i&& v) const
	{
		return Vec4i(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4i operator*(const Vec4i& v) const
	{
		return Vec4i(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator+=(Vec4i&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator+=(const Vec4i& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator-=(Vec4i&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator-=(const Vec4i& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vec4i&& v) const
	{
		return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vec4i& v) const
	{
		return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� ������ �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vec4i&& v) const
	{
		return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� ������ �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vec4i& v) const
	{
		return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
	}


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const int32_t* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	int32_t* GetPtr() { return &data[0]; }


	/**
	 * @brief 4���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline int32_t Dot(const Vec4i& lhs, const Vec4i& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	/**
	 * @brief 4���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	static inline int32_t LengthSq(const Vec4i& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}


	/**
	 * @brief 4���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static inline float Length(const Vec4i& v)
	{
		float lengthSq = static_cast<float>(LengthSq(v));
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief �� 4���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 4���� ���� ������ ���� ������ ��ȯ�մϴ�.
	 */
	static inline float Radian(const Vec4i& lhs, const Vec4i& rhs)
	{
		float lengthL = Length(lhs);
		float lengthR = Length(rhs);
		float dot = Dot(lhs, rhs);

		return MathModule::ACos(dot / (lengthL * lengthR));
	}


	/**
	 * @brief �� 4���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 4���� ���� ������ ���ʺй� ������ ��ȯ�մϴ�.
	 */
	static inline float Degree(const Vec4i& lhs, const Vec4i& rhs)
	{
		float radian = Radian(lhs, rhs);
		return MathModule::ToDegree(radian);
	}


	/**
	 * @brief 4���� ������ �پ��� ���� �����Դϴ�.
	 */
	union
	{
		struct
		{
			int32_t x;
			int32_t y;
			int32_t z;
			int32_t w;
		};
		int32_t data[4];
	};
};


/**
 * @brief ������ ������ Ÿ���� �ε� �Ҽ����� 4���� �����Դϴ�.
 */
struct Vec4f
{
	/**
	 * @brief 4���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vec4f() noexcept : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}



	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vec4f(float&& xx, float&& yy, float&& zz, float&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vec4f(const float& xx, const float& yy, const float& zz, const float& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vec4f(float&& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vec4f(const float& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vec4f(Vec4f&& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vec4f(const Vec4f& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}


	/**
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator=(Vec4f&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}


	/**
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator=(const Vec4f& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}


	/**
	 * @brief 4���� ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return 4���� ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vec4f operator-() const
	{
		return Vec4f(-x, -y, -z, -w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4f operator+(Vec4f&& v) const
	{
		return Vec4f(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4f operator+(const Vec4f& v) const
	{
		return Vec4f(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vec4f operator-(Vec4f&& v) const
	{
		return Vec4f(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vec4f operator-(const Vec4f& v) const
	{
		return Vec4f(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4f operator*(Vec4f&& v) const
	{
		return Vec4f(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vec4f operator*(const Vec4f& v) const
	{
		return Vec4f(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator+=(Vec4f&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator+=(const Vec4f& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator-=(Vec4f&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator-=(const Vec4f& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vec4f&& v) const
	{
		return MathModule::Abs(x - v.x) <= MathModule::Epsilon
			&& MathModule::Abs(y - v.y) <= MathModule::Epsilon
			&& MathModule::Abs(z - v.z) <= MathModule::Epsilon
			&& MathModule::Abs(w - v.w) <= MathModule::Epsilon;
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vec4f& v) const
	{
		return MathModule::Abs(x - v.x) <= MathModule::Epsilon
			&& MathModule::Abs(y - v.y) <= MathModule::Epsilon
			&& MathModule::Abs(z - v.z) <= MathModule::Epsilon
			&& MathModule::Abs(w - v.w) <= MathModule::Epsilon;
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� ������ �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vec4f&& v) const
	{
		return MathModule::Abs(x - v.x) > MathModule::Epsilon
			|| MathModule::Abs(y - v.y) > MathModule::Epsilon
			|| MathModule::Abs(z - v.z) > MathModule::Epsilon
			|| MathModule::Abs(w - v.w) > MathModule::Epsilon;
	}


	/**
	 * @brief �� 4���� ���Ͱ� �������� ������ �˻��մϴ�.
	 *
	 * @param v �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ͱ� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vec4f& v) const
	{
		return MathModule::Abs(x - v.x) > MathModule::Epsilon
			|| MathModule::Abs(y - v.y) > MathModule::Epsilon
			|| MathModule::Abs(z - v.z) > MathModule::Epsilon
			|| MathModule::Abs(w - v.w) > MathModule::Epsilon;
	}


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const float* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	float* GetPtr() { return &data[0]; }


	/**
	 * @brief 4���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline float Dot(const Vec4f& lhs, const Vec4f& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	/**
	 * @brief 4���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	static inline float LengthSq(const Vec4f& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}


	/**
	 * @brief 4���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static inline float Length(const Vec4f& v)
	{
		float lengthSq = LengthSq(v);
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief 4���� ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ �� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	static inline Vec4f Normalize(const Vec4f& v)
	{
		float invLength = 1.0f / Length(v);
		return Vec4f(v.x * invLength, v.y * invLength, v.z * invLength, v.w * invLength);
	}


	/**
	 * @brief �� 4���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 4���� ���� ������ ���� ������ ��ȯ�մϴ�.
	 */
	static inline float Radian(const Vec4f& lhs, const Vec4f& rhs)
	{
		float lengthL = Length(lhs);
		float lengthR = Length(rhs);
		float dot = Dot(lhs, rhs);

		return MathModule::ACos(dot / (lengthL * lengthR));
	}


	/**
	 * @brief �� 4���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 4���� ���� ������ ���ʺй� ������ ��ȯ�մϴ�.
	 */
	static inline float Degree(const Vec4f& lhs, const Vec4f& rhs)
	{
		float radian = Radian(lhs, rhs);
		return MathModule::ToDegree(radian);
	}


	/**
	 * @brief Base 4���� ���Ϳ� Target 4���� ���͸� �����մϴ�.
	 *
	 * @param target ���� ��� ������ �����Դϴ�.
	 * @param base ���� ����� �Ǵ� �����Դϴ�.
	 *
	 * @return base�� ������ target ���͸� ��ȯ�մϴ�.
	 */
	static inline Vec4f Project(const Vec4f& target, const Vec4f& base)
	{
		float dot = Dot(target, base);
		float lengthSq = LengthSq(base);
		float scale = dot / lengthSq;

		return Vec4f(base.x * scale, base.y * scale, base.z * scale, base.w * scale);
	}


	/**
	 * @brief Base 4���� ���Ϳ� Target 4���� ���͸� ������ ���Ϳ� ������ ���͸� ����մϴ�.
	 *
	 * @param target ���� ��� ������ �����Դϴ�.
	 * @param base ���� ����� �Ǵ� �����Դϴ�.
	 *
	 * @return ������ ������ ������ ���͸� ��ȯ�մϴ�.
	 */
	static inline Vec4f Reject(const Vec4f& target, const Vec4f& base)
	{
		Vec4f project = Project(target, base);
		return target - project;
	}


	/**
	 * @brief �� ���͸� ���� ������ ���͸� ����մϴ�.
	 *
	 * @param s ������ ���� �����Դϴ�.
	 * @param e ������ �� �����Դϴ�.
	 * @param t �� ������ ���� �����Դϴ�.
	 *
	 * @return ������ ���͸� ��ȯ�մϴ�.
	 */
	static inline Vec4f Lerp(const Vec4f& s, const Vec4f& e, const float& t)
	{
		return s * (1.0f - t) + e * t;
	}


	/**
	 * @brief �� ���͸� ���� ���� ������ ���͸� ����մϴ�.
	 *
	 * @param s ������ ���� �����Դϴ�.
	 * @param e ������ �� �����Դϴ�.
	 * @param t �� ������ ���� �����Դϴ�.
	 *
	 * @return ������ ���͸� ��ȯ�մϴ�.
	 */
	static inline Vec4f Slerp(const Vec4f& s, const Vec4f& e, const float& t)
	{
		Vec4f start = Normalize(s);
		Vec4f end = Normalize(e);

		float theta = Radian(start, end);
		float sinTheta = MathModule::Sin(theta);

		float a = MathModule::Sin((1.0f - t) * theta) / sinTheta;
		float b = MathModule::Sin(t * theta) / sinTheta;

		return s * a + e * b;
	}


	/**
	 * @brief 4���� ������ �پ��� ���� �����Դϴ�.
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
		float data[4];
	};
};