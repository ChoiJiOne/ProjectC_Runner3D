#pragma once

#include <cstdint>


/**
 * @brief ���ø� ����� 2x2 ����Դϴ�.
 */
template <typename T>
struct TMat2x2
{
	/**
	 * @brief 2x2 ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	TMat2x2() noexcept
	{
		e00 = static_cast<T>(0); e01 = static_cast<T>(0);
		e10 = static_cast<T>(0); e11 = static_cast<T>(0);
	}


	/**
	 * @brief 2x2 ����� �������Դϴ�.
	 *
	 * @param ee00 ����� (0, 0) �����Դϴ�.
	 * @param ee01 ����� (0, 1) �����Դϴ�.
	 * @param ee10 ����� (1, 0) �����Դϴ�.
	 * @param ee11 ����� (1, 1) �����Դϴ�.
	 */
	TMat2x2(
		T&& ee00, T&& ee01,
		T&& ee10, T&& ee11
	) noexcept
	{
		e00 = ee00; e01 = ee01;
		e10 = ee10; e11 = ee11;
	}


	/**
	 * @brief 2x2 ����� �������Դϴ�.
	 *
	 * @param e00 ����� (0, 0) �����Դϴ�.
	 * @param e01 ����� (0, 1) �����Դϴ�.
	 * @param e10 ����� (1, 0) �����Դϴ�.
	 * @param e11 ����� (1, 1) �����Դϴ�.
	 */
	TMat2x2(
		const T& ee00, const T& ee01,
		const T& ee10, const T& ee11
	) noexcept
	{
		e00 = ee00; e01 = ee01;
		e10 = ee10; e11 = ee11;
	}


	/**
	 * @brief 2x2 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	TMat2x2(T&& e) noexcept
	{
		e00 = e; e01 = e;
		e10 = e; e11 = e;
	}


	/**
	 * @brief 2x2 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	TMat2x2(const T& e) noexcept
	{
		e00 = e; e01 = e;
		e10 = e; e11 = e;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param m ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	TMat2x2(TMat2x2<T>&& m) noexcept
	{
		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param m ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	TMat2x2(const TMat2x2<T>& m) noexcept
	{
		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param m ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	TMat2x2<T>& operator=(TMat2x2<T>&& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;

		return *this;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param m ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	TMat2x2<T>& operator=(const TMat2x2<T>& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;

		return *this;
	}


	/**
	 * @brief 2x2 ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� -��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator-() const
	{
		return TMat2x2<T>(
			-e00, -e01,
			-e10, -e11
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param m ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator+(TMat2x2<T>&& m) const
	{
		return TMat2x2<T>(
			e00 + m.e00, e01 + m.e01,
			e10 + m.e10, e11 + m.e11
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param m ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator+(const TMat2x2<T>& m) const
	{
		return TMat2x2<T>(
			e00 + m.e00, e01 + m.e01,
			e10 + m.e10, e11 + m.e11
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param m ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator-(TMat2x2<T>&& m) const
	{
		return TMat2x2<T>(
			e00 - m.e00, e01 - m.e01,
			e10 - m.e10, e11 - m.e11
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param m ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator-(const TMat2x2<T>& m) const
	{
		return TMat2x2<T>(
			e00 - m.e00, e01 - m.e01,
			e10 - m.e10, e11 - m.e11
			);
	}


	/**
	 * @brief �� 2x2 ����� ���մϴ�.
	 *
	 * @param m ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator*(TMat2x2<T>&& m) const
	{
		return TMat2x2(
			e00 * m.e00 + e01 * m.e10,
			e00 * m.e01 + e01 * m.e11,
			e10 * m.e00 + e11 * m.e10,
			e10 * m.e01 + e11 * m.e11
		);
	}


	/**
	 * @brief �� 2x2 ����� ���մϴ�.
	 *
	 * @param m ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	TMat2x2<T> operator*(const TMat2x2<T>& m) const
	{
		return TMat2x2(
			e00 * m.e00 + e01 * m.e10,
			e00 * m.e01 + e01 * m.e11,
			e10 * m.e00 + e11 * m.e10,
			e10 * m.e01 + e11 * m.e11
		);
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param m ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	TMat2x2<T>& operator+=(TMat2x2<T>&& m) noexcept
	{
		e00 += m.e00; e01 += m.e01;
		e10 += m.e10; e11 += m.e11;

		return *this;
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param m ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	TMat2x2<T>& operator+=(const TMat2x2<T>& m) noexcept
	{
		e00 += m.e00; e01 += m.e01;
		e10 += m.e10; e11 += m.e11;

		return *this;
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param m ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	TMat2x2<T>& operator-=(TMat2x2<T>&& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01;
		e10 -= m.e10; e11 -= m.e11;

		return *this;
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param m ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	TMat2x2<T>& operator-=(const TMat2x2<T>& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01;
		e10 -= m.e10; e11 -= m.e11;

		return *this;
	}


	/**
	 * @brief 2x2 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2x2 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 2x2 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2x2 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 2x2 ����� ��� ���Ұ� 0�� ����� ����ϴ�.
	 * 
	 * @return ��� ���Ұ� 0�� 2x2 ����� ��ȯ�մϴ�.
	 */
	static inline TMat2x2<T> Zero();


	/**
	 * @brief 2x2 ����� ���� ����� ����ϴ�.
	 *
	 * @return 2x2 ����� ���� ��ĸ� ��ȯ�մϴ�.
	 */
	static inline TMat2x2<T> Identity();


	/**
	 * @brief 2x2 ����� ��ġ ����� ����ϴ�.
	 * 
	 * @param m ���ҵ��� ��ġ�� 2x2 ����Դϴ�.
	 * 
	 * @return ���Ұ� ��ġ�� 2x2 ����� ��ȯ�մϴ�.
	 */
	static inline TMat2x2<T> Transpose(const TMat2x2<T>& m);


	/**
	 * @brief 2x2 ����� ��Ľ� ���� ����ϴ�.
	 * 
	 * @param m ��Ľ� ���� ����� 2x2 ����Դϴ�.
	 * 
	 * @return 2x2 ����� ��Ľ� ���� ��ȯ�մϴ�.
	 */
	static inline T Determinant(const TMat2x2<T>& m);


	/**
	 * @brief 2x2 ����� ������� ����ϴ�.
	 * 
	 * @param m ������� ����� 2x2 ����Դϴ�.
	 * 
	 * @return 2x2 ����� ������� ��ȯ�մϴ�.
	 */
	static inline TMat2x2<T> Inverse(const TMat2x2<T>& m);

	
	/**
	 * @brief 2x2 ����� �����Դϴ�.
	 */
	union
	{
		struct
		{
			T e00; T e01;
			T e10; T e11;
		};
		T data[4];
	};
};


/**
 * @brief int32_t Ÿ���� 2x2 ����Դϴ�.
 */
using Mat2x2i = TMat2x2<int32_t>;


/**
 * @brief float Ÿ���� 2x2 ����Դϴ�.
 */
using Mat2x2f = TMat2x2<float>;


#include "Mat2x2.inl"