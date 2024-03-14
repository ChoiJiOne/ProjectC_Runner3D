#pragma once

#include <cstdint>

#include "MathModule.h"


/**
 * @brief 원소의 데이터 타입이 정수인 3차원 벡터입니다.
 */
struct Vec4i
{
	/**
	 * @brief 4차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vec4i() noexcept : x(0), y(0), z(0), w(0) {}


	/**
	 * @brief 4차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vec4i(int32_t&& xx, int32_t&& yy, int32_t&& zz, int32_t&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vec4i(const int32_t& xx, const int32_t& yy, const int32_t& zz, const int32_t& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec4i(int32_t&& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec4i(const int32_t& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vec4i(Vec4i&& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}
	

	/**
	 * @brief 4차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vec4i(const Vec4i& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}


	/**
	 * @brief 4차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 4차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 4차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 4차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vec4i operator-() const
	{
		return Vec4i(-x, -y, -z, -w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec4i operator+(Vec4i&& v) const
	{
		return Vec4i(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec4i operator+(const Vec4i& v) const
	{
		return Vec4i(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec4i operator-(Vec4i&& v) const
	{
		return Vec4i(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec4i operator-(const Vec4i& v) const
	{
		return Vec4i(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec4i operator*(Vec4i&& v) const
	{
		return Vec4i(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec4i operator*(const Vec4i& v) const
	{
		return Vec4i(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vec4i&& v) const
	{
		return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
	}


	/**
	 * @brief 두 4차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vec4i& v) const
	{
		return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
	}


	/**
	 * @brief 두 4차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(Vec4i&& v) const
	{
		return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
	}


	/**
	 * @brief 두 4차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const Vec4i& v) const
	{
		return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
	}


	/**
	 * @brief 4차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const int32_t* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	int32_t* GetPtr() { return &data[0]; }


	/**
	 * @brief 4차원 백터의 내적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 내적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 내적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 내적 연산 결과를 반환합니다.
	 */
	static inline int32_t Dot(const Vec4i& lhs, const Vec4i& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	/**
	 * @brief 4차원 백터의 크기 제곱 값을 계산합니다.
	 *
	 * @param v 크기 제곱을 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 제곱 값을 반환합니다.
	 */
	static inline int32_t LengthSq(const Vec4i& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}


	/**
	 * @brief 4차원 벡터의 크기를 얻습니다.
	 *
	 * @param v 크기를 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 값을 반환합니다.
	 */
	static inline float Length(const Vec4i& v)
	{
		float lengthSq = static_cast<float>(LengthSq(v));
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief 두 4차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 4차원 벡터 사이의 라디안 각도를 반환합니다.
	 */
	static inline float Radian(const Vec4i& lhs, const Vec4i& rhs)
	{
		float lengthL = Length(lhs);
		float lengthR = Length(rhs);
		float dot = Dot(lhs, rhs);

		return MathModule::ACos(dot / (lengthL * lengthR));
	}


	/**
	 * @brief 두 4차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 4차원 벡터 사이의 육십분법 각도를 반환합니다.
	 */
	static inline float Degree(const Vec4i& lhs, const Vec4i& rhs)
	{
		float radian = Radian(lhs, rhs);
		return MathModule::ToDegree(radian);
	}


	/**
	 * @brief 4차원 벡터의 다양한 원소 형식입니다.
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
 * @brief 원소의 데이터 타입이 부동 소수점인 4차원 벡터입니다.
 */
struct Vec4f
{
	/**
	 * @brief 4차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vec4f() noexcept : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}



	/**
	 * @brief 4차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vec4f(float&& xx, float&& yy, float&& zz, float&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vec4f(const float& xx, const float& yy, const float& zz, const float& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 4차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec4f(float&& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec4f(const float& e) noexcept : x(e), y(e), z(e), w(e) {}


	/**
	 * @brief 4차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vec4f(Vec4f&& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}


	/**
	 * @brief 4차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vec4f(const Vec4f& v) noexcept : x(v.x), y(v.y), z(v.z), w(v.w) {}


	/**
	 * @brief 4차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 4차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 4차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 4차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vec4f operator-() const
	{
		return Vec4f(-x, -y, -z, -w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec4f operator+(Vec4f&& v) const
	{
		return Vec4f(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec4f operator+(const Vec4f& v) const
	{
		return Vec4f(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec4f operator-(Vec4f&& v) const
	{
		return Vec4f(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec4f operator-(const Vec4f& v) const
	{
		return Vec4f(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec4f operator*(Vec4f&& v) const
	{
		return Vec4f(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec4f operator*(const Vec4f& v) const
	{
		return Vec4f(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 4차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vec4f&& v) const
	{
		return MathModule::Abs(x - v.x) <= MathModule::Epsilon
			&& MathModule::Abs(y - v.y) <= MathModule::Epsilon
			&& MathModule::Abs(z - v.z) <= MathModule::Epsilon
			&& MathModule::Abs(w - v.w) <= MathModule::Epsilon;
	}


	/**
	 * @brief 두 4차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vec4f& v) const
	{
		return MathModule::Abs(x - v.x) <= MathModule::Epsilon
			&& MathModule::Abs(y - v.y) <= MathModule::Epsilon
			&& MathModule::Abs(z - v.z) <= MathModule::Epsilon
			&& MathModule::Abs(w - v.w) <= MathModule::Epsilon;
	}


	/**
	 * @brief 두 4차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(Vec4f&& v) const
	{
		return MathModule::Abs(x - v.x) > MathModule::Epsilon
			|| MathModule::Abs(y - v.y) > MathModule::Epsilon
			|| MathModule::Abs(z - v.z) > MathModule::Epsilon
			|| MathModule::Abs(w - v.w) > MathModule::Epsilon;
	}


	/**
	 * @brief 두 4차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const Vec4f& v) const
	{
		return MathModule::Abs(x - v.x) > MathModule::Epsilon
			|| MathModule::Abs(y - v.y) > MathModule::Epsilon
			|| MathModule::Abs(z - v.z) > MathModule::Epsilon
			|| MathModule::Abs(w - v.w) > MathModule::Epsilon;
	}


	/**
	 * @brief 4차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const float* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	float* GetPtr() { return &data[0]; }


	/**
	 * @brief 4차원 백터의 내적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 내적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 내적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 내적 연산 결과를 반환합니다.
	 */
	static inline float Dot(const Vec4f& lhs, const Vec4f& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	/**
	 * @brief 4차원 백터의 크기 제곱 값을 계산합니다.
	 *
	 * @param v 크기 제곱을 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 제곱 값을 반환합니다.
	 */
	static inline float LengthSq(const Vec4f& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}


	/**
	 * @brief 4차원 벡터의 크기를 얻습니다.
	 *
	 * @param v 크기를 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 값을 반환합니다.
	 */
	static inline float Length(const Vec4f& v)
	{
		float lengthSq = LengthSq(v);
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief 4차원 벡터를 정규화합니다.
	 *
	 * @param v 정규화 할 벡터입니다.
	 *
	 * @return 정규화된 벡터를 반환합니다.
	 */
	static inline Vec4f Normalize(const Vec4f& v)
	{
		float invLength = 1.0f / Length(v);
		return Vec4f(v.x * invLength, v.y * invLength, v.z * invLength, v.w * invLength);
	}


	/**
	 * @brief 두 4차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 4차원 벡터 사이의 라디안 각도를 반환합니다.
	 */
	static inline float Radian(const Vec4f& lhs, const Vec4f& rhs)
	{
		float lengthL = Length(lhs);
		float lengthR = Length(rhs);
		float dot = Dot(lhs, rhs);

		return MathModule::ACos(dot / (lengthL * lengthR));
	}


	/**
	 * @brief 두 4차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 4차원 벡터 사이의 육십분법 각도를 반환합니다.
	 */
	static inline float Degree(const Vec4f& lhs, const Vec4f& rhs)
	{
		float radian = Radian(lhs, rhs);
		return MathModule::ToDegree(radian);
	}


	/**
	 * @brief Base 4차원 벡터에 Target 4차원 벡터를 투영합니다.
	 *
	 * @param target 투영 대상에 투영할 벡터입니다.
	 * @param base 투영 대상이 되는 벡터입니다.
	 *
	 * @return base에 투영된 target 벡터를 반환합니다.
	 */
	static inline Vec4f Project(const Vec4f& target, const Vec4f& base)
	{
		float dot = Dot(target, base);
		float lengthSq = LengthSq(base);
		float scale = dot / lengthSq;

		return Vec4f(base.x * scale, base.y * scale, base.z * scale, base.w * scale);
	}


	/**
	 * @brief Base 4차원 벡터에 Target 4차원 벡터를 투영한 벡터에 수직인 벡터를 계산합니다.
	 *
	 * @param target 투영 대상에 투영할 벡터입니다.
	 * @param base 투영 대상이 되는 벡터입니다.
	 *
	 * @return 투영된 벡터의 수직인 벡터를 반환합니다.
	 */
	static inline Vec4f Reject(const Vec4f& target, const Vec4f& base)
	{
		Vec4f project = Project(target, base);
		return target - project;
	}


	/**
	 * @brief 두 벡터를 선형 보간한 벡터를 계산합니다.
	 *
	 * @param s 보간의 시작 벡터입니다.
	 * @param e 보간의 끝 벡터입니다.
	 * @param t 두 벡터의 보간 비율입니다.
	 *
	 * @return 보간된 벡터를 반환합니다.
	 */
	static inline Vec4f Lerp(const Vec4f& s, const Vec4f& e, const float& t)
	{
		return s * (1.0f - t) + e * t;
	}


	/**
	 * @brief 두 벡터를 구면 선형 보간한 벡터를 계산합니다.
	 *
	 * @param s 보간의 시작 벡터입니다.
	 * @param e 보간의 끝 벡터입니다.
	 * @param t 두 벡터의 보간 비율입니다.
	 *
	 * @return 보간된 벡터를 반환합니다.
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
	 * @brief 4차원 벡터의 다양한 원소 형식입니다.
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