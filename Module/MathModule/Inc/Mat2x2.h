#pragma once

#include <cstdint>

#include "MathModule.h"


/**
 * @brief 2x2 ����Դϴ�.
 */
struct Mat2x2
{
	/**
	 * @brief 2x2 ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Mat2x2() noexcept
	{
		e00 = 0.0f; e01 = 0.0f;
		e10 = 0.0f; e11 = 0.0f;
	}


	/**
	 * @brief 2x2 ����� �������Դϴ�.
	 *
	 * @param ee00 ����� (0, 0) �����Դϴ�.
	 * @param ee01 ����� (0, 1) �����Դϴ�.
	 * @param ee10 ����� (1, 0) �����Դϴ�.
	 * @param ee11 ����� (1, 1) �����Դϴ�.
	 */
	Mat2x2(
		float&& ee00, float&& ee01,
		float&& ee10, float&& ee11
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
	Mat2x2(
		const float& ee00, const float& ee01,
		const float& ee10, const float& ee11
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
	Mat2x2(float&& e) noexcept
	{
		e00 = e; e01 = e;
		e10 = e; e11 = e;
	}


	/**
	 * @brief 2x2 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Mat2x2(const float& e) noexcept
	{
		e00 = e; e01 = e;
		e10 = e; e11 = e;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param m ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Mat2x2(Mat2x2&& m) noexcept
	{
		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param m ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Mat2x2(const Mat2x2& m) noexcept
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
	Mat2x2& operator=(Mat2x2&& m) noexcept
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
	Mat2x2& operator=(const Mat2x2& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;

		return *this;
	}


	/**
	 * @brief 2x2 ����� ��� ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� -��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Mat2x2 operator-() const
	{
		return Mat2x2(
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
	Mat2x2 operator+(Mat2x2&& m) const
	{
		return Mat2x2(
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
	Mat2x2 operator+(const Mat2x2& m) const
	{
		return Mat2x2(
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
	Mat2x2 operator-(Mat2x2&& m) const
	{
		return Mat2x2(
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
	Mat2x2 operator-(const Mat2x2& m) const
	{
		return Mat2x2(
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
	Mat2x2 operator*(Mat2x2&& m) const
	{
		return Mat2x2(
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
	Mat2x2 operator*(const Mat2x2& m) const
	{
		return Mat2x2(
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
	Mat2x2& operator+=(Mat2x2&& m) noexcept
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
	Mat2x2& operator+=(const Mat2x2& m) noexcept
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
	Mat2x2& operator-=(Mat2x2&& m) noexcept
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
	Mat2x2& operator-=(const Mat2x2& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01;
		e10 -= m.e10; e11 -= m.e11;

		return *this;
	}


	/**
	 * @brief �� 2x2����� �������� �˻��մϴ�.
	 *
	 * @param m �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Mat2x2&& m) const
	{
		return MathModule::Abs(e00 - m.e00) <= MathModule::Epsilon
			&& MathModule::Abs(e01 - m.e01) <= MathModule::Epsilon
			&& MathModule::Abs(e10 - m.e10) <= MathModule::Epsilon
			&& MathModule::Abs(e11 - m.e11) <= MathModule::Epsilon;
	}


	/**
	 * @brief �� 2x2����� �������� �˻��մϴ�.
	 *
	 * @param m �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Mat2x2& m) const
	{
		return MathModule::Abs(e00 - m.e00) <= MathModule::Epsilon
			&& MathModule::Abs(e01 - m.e01) <= MathModule::Epsilon
			&& MathModule::Abs(e10 - m.e10) <= MathModule::Epsilon
			&& MathModule::Abs(e11 - m.e11) <= MathModule::Epsilon;
	}


	/**
	 * @brief �� 2x2����� �������� ������ �˻��մϴ�.
	 *
	 * @param m �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Mat2x2&& m) const
	{
		return MathModule::Abs(e00 - m.e00) > MathModule::Epsilon
			|| MathModule::Abs(e01 - m.e01) > MathModule::Epsilon
			|| MathModule::Abs(e10 - m.e10) > MathModule::Epsilon
			|| MathModule::Abs(e11 - m.e11) > MathModule::Epsilon;
	}


	/**
	 * @brief �� 2x2����� �������� ������ �˻��մϴ�.
	 *
	 * @param m �˻縦 ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �������� �ʴٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Mat2x2& m) const
	{
		return MathModule::Abs(e00 - m.e00) > MathModule::Epsilon
			|| MathModule::Abs(e01 - m.e01) > MathModule::Epsilon
			|| MathModule::Abs(e10 - m.e10) > MathModule::Epsilon
			|| MathModule::Abs(e11 - m.e11) > MathModule::Epsilon;
	}


	/**
	 * @brief 2x2 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2x2 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const float* GetPtr() const { return &data[0]; }


	/**
	 * @brief 2x2 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2x2 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	float* GetPtr() { return &data[0]; }


	/**
	 * @brief 2x2 ����� ��� ���Ұ� 0�� ����� ����ϴ�.
	 * 
	 * @return ��� ���Ұ� 0�� 2x2 ����� ��ȯ�մϴ�.
	 */
	static inline Mat2x2 Zero()
	{
		return Mat2x2(
			0.0f, 0.0f,
			0.0f, 0.0f
		);
	}


	/**
	 * @brief 2x2 ����� ���� ����� ����ϴ�.
	 *
	 * @return 2x2 ����� ���� ��ĸ� ��ȯ�մϴ�.
	 */
	static inline Mat2x2 Identity()
	{
		return Mat2x2(
			1.0f, 0.0f,
			0.0f, 1.0f
		);
	}


	/**
	 * @brief 2x2 ����� ��ġ ����� ����ϴ�.
	 * 
	 * @param m ���ҵ��� ��ġ�� 2x2 ����Դϴ�.
	 * 
	 * @return ���Ұ� ��ġ�� 2x2 ����� ��ȯ�մϴ�.
	 */
	static inline Mat2x2 Transpose(const Mat2x2& m)
	{
		return Mat2x2(
			m.e00, m.e10,
			m.e01, m.e11
		);
	}


	/**
	 * @brief 2x2 ����� ��Ľ� ���� ����ϴ�.
	 * 
	 * @param m ��Ľ� ���� ����� 2x2 ����Դϴ�.
	 * 
	 * @return 2x2 ����� ��Ľ� ���� ��ȯ�մϴ�.
	 */
	static inline float Determinant(const Mat2x2& m)
	{
		return m.e00 * m.e11 - m.e01 * m.e10;
	}


	/**
	 * @brief 2x2 ����� ������� ����ϴ�.
	 * 
	 * @param m ������� ����� 2x2 ����Դϴ�.
	 * 
	 * @return 2x2 ����� ������� ��ȯ�մϴ�.
	 */
	static inline Mat2x2 Inverse(const Mat2x2& m)
	{
		float oneOverDeterminant = 1.0f / Determinant(m);

		return Mat2x2(
			+m.e11 * oneOverDeterminant,
			-m.e01 * oneOverDeterminant,
			-m.e10 * oneOverDeterminant,
			+m.e00 * oneOverDeterminant
		);
	}

	
	/**
	 * @brief 2x2 ����� �����Դϴ�.
	 */
	union
	{
		struct
		{
			float e00; float e01;
			float e10; float e11;
		};
		float data[4];
	};
};