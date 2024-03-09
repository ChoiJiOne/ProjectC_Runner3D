#pragma once

#include <cstdint>


/**
 * @brief ���ø� ����� 2���� �����Դϴ�.
 */
template <typename T>
struct TVec2
{
	/**
	 * @brief 2���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	TVec2() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
	}


	/**
	 * @brief 2���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	TVec2(T&& xx, T&& yy) noexcept
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 2���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	TVec2(const T& xx, const T& yy) noexcept
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 2���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	TVec2(T&& e) noexcept
	{
		x = e;
		y = e;
	}


	/**
	 * @brief 2���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	TVec2(const T& e) noexcept
	{
		x = e;
		y = e;
	}


	/**
	 * @brief 2���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	TVec2(TVec2<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
	}


	/**
	 * @brief 2���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	TVec2(const TVec2<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
	}


	/**
	 * @brief 2���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec2<T>& operator=(TVec2<T>&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;

		return *this;
	}


	/**
	 * @brief 2���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec2<T>& operator=(const TVec2<T>& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;

		return *this;
	}


	/**
	 * @brief 2���� ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return 2���� ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	TVec2<T> operator-() const
	{
		return TVec2<T>(-x, -y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TVec2<T> operator+(TVec2<T>&& v) const
	{
		return TVec2<T>(x + v.x, y + v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TVec2<T> operator+(const TVec2<T>& v) const
	{
		return TVec2<T>(x + v.x, y + v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	TVec2<T> operator-(TVec2<T>&& v) const
	{
		return TVec2<T>(x - v.x, y - v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	TVec2<T> operator-(const TVec2<T>& v) const
	{
		return TVec2<T>(x - v.x, y - v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TVec2<T> operator*(TVec2<T>&& v) const
	{
		return TVec2<T>(x * v.x, y * v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TVec2<T> operator*(const TVec2<T>& v) const
	{
		return TVec2<T>(x * v.x, y * v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec2<T>& operator+=(TVec2<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;

		return *this;
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec2<T>& operator+=(const TVec2<T>& v) noexcept
	{
		x += v.x;
		y += v.y;

		return *this;
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec2<T>& operator-=(TVec2<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TVec2<T>& operator-=(const TVec2<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}


	/**
	 * @brief 2���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 2���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 2���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline T Dot(const TVec2<T>& lhs, const TVec2<T>& rhs);


	/**
	 * @brief 2���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 *
	 * @note �Ϲ����� 3���� ���� ����� �ٸ��ϴ�.
	 */
	static inline T Cross(const TVec2<T>& lhs, const TVec2<T>& rhs);


	/**
	 * @brief 2���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	static inline T LengthSq(const TVec2<T>& v);


	/**
	 * @brief 2���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static inline float Length(const TVec2<T>& v);


	/**
	 * @brief 2���� ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ �� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	static inline TVec2<T> Normalize(const TVec2<T>& v);


	/**
	 * @brief �� 2���� ���� ������ ���� ����մϴ�.
	 * 
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 * 
	 * @return �� 2���� ���� ������ ���� ������ ��ȯ�մϴ�.
	 */
	static inline float Radian(const TVec2<T>& lhs, const TVec2<T>& rhs);


	/**
	 * @brief �� 2���� ���� ������ ���� ����մϴ�.
	 *
	 * @param lhs ���� ������ ���� ����� ���� �ǿ����� �����Դϴ�.
	 * @param rhs ���� ������ ���� ����� ������ �ǿ����� �����Դϴ�.
	 *
	 * @return �� 2���� ���� ������ ���ʺй� ������ ��ȯ�մϴ�.
	 */
	static inline float Degree(const TVec2<T>& lhs, const TVec2<T>& rhs);


	/**
	 * @brief Base 2���� ���Ϳ� Target 2���� ���͸� �����մϴ�.
	 * 
	 * @param target ���� ��� ������ �����Դϴ�.
	 * @param base ���� ����� �Ǵ� �����Դϴ�.
	 * 
	 * @return base�� ������ target ���͸� ��ȯ�մϴ�.
	 */
	static inline TVec2<T> Project(const TVec2<T>& target, const TVec2<T>& base);


	/**
	 * @brief Base 2���� ���Ϳ� Target 2���� ���͸� ������ ���Ϳ� ������ ���͸� ����մϴ�.
	 * 
	 * @param target ���� ��� ������ �����Դϴ�.
	 * @param base ���� ����� �Ǵ� �����Դϴ�.
	 * 
	 * @return ������ ������ ������ ���͸� ��ȯ�մϴ�.
	 */
	static inline TVec2<T> Reject(const TVec2<T>& target, const TVec2<T>& base);


	/**
	 * @brief 2���� ������ �پ��� ���� �����Դϴ�.
	 */
	union
	{
		struct
		{
			T x;
			T y;
		};
		T data[2];
	};
};


/**
 * @brief int32_t Ÿ���� 2���� �����Դϴ�.
 */
using Vec2i = TVec2<int32_t>;


/**
 * @brief float Ÿ���� 2���� �����Դϴ�.
 */
using Vec2f = TVec2<float>;


#include "Vec2.inl"