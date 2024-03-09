#pragma once

#include <cstdint>


/**
 * @brief ���ø� ����� 4���� �����Դϴ�.
 */
template <typename T>
struct TVec4
{
	/**
	 * @brief 4���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	TVec4() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	TVec4(T&& xx, T&& yy, T&& zz, T&& ww) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	TVec4(const T& xx, const T& yy, const T& zz, const T& ww) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	TVec4(T&& e) noexcept
	{
		x = e;
		y = e;
		z = e;
		w = e;
	}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	TVec4(const T& e) noexcept
	{
		x = e;
		y = e;
		z = e;
		w = e;
	}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	TVec4(TVec4<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	TVec4(const TVec4<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}


	/**
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec4<T>& operator=(TVec4<T>&& v) noexcept
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
	TVec4<T>& operator=(const TVec4<T>& v) noexcept
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
	TVec4<T> operator-() const
	{
		return TVec4<T>(-x, -y, -z, -w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TVec4<T> operator+(TVec4<T>&& v) const
	{
		return TVec4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TVec4<T> operator+(const TVec4<T>& v) const
	{
		return TVec4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	TVec4<T> operator-(TVec4<T>&& v) const
	{
		return TVec4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	TVec4<T> operator-(const TVec4<T>& v) const
	{
		return TVec4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
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
	TVec4<T> operator*(TVec4<T>&& v) const
	{
		return TVec4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
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
	TVec4<T> operator*(const TVec4<T>& v) const
	{
		return TVec4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec4<T>& operator+=(TVec4<T>&& v) noexcept
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
	TVec4<T>& operator+=(const TVec4<T>& v) noexcept
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
	TVec4<T>& operator-=(TVec4<T>&& v) noexcept
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
	TVec4<T>& operator-=(const TVec4<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 4���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline T Dot(const TVec4<T>& lhs, const TVec4<T>& rhs);


	/**
	 * @brief 4���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	static inline T LengthSq(const TVec4<T>& v);


	/**
	 * @brief 4���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static inline float Length(const TVec4<T>& v);


	/**
	 * @brief 4���� ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ �� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	static inline TVec4<T> Normalize(const TVec4<T>& v);


	/**
	 * @brief �� 4���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 4���� ���� ������ ���� ������ ��ȯ�մϴ�.
	 */
	static inline float Radian(const TVec4<T>& lhs, const TVec4<T>& rhs);


	/**
	 * @brief �� 4���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 4���� ���� ������ ���ʺй� ������ ��ȯ�մϴ�.
	 */
	static inline float Degree(const TVec4<T>& lhs, const TVec4<T>& rhs);


	/**
	 * @brief 4���� ������ �پ��� ���� �����Դϴ�.
	 */
	union
	{
		struct
		{
			T x;
			T y;
			T z;
			T w;
		};
		T data[4];
	};
};


/**
 * @brief int32_t Ÿ���� 4���� �����Դϴ�.
 */
using Vec4i = TVec4<int32_t>;


/**
 * @brief float Ÿ���� 4���� �����Դϴ�.
 */
using Vec4f = TVec4<float>;


#include "Vec4.inl"