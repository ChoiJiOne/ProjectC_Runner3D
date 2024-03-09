#pragma once

#include <cstdint>


/**
 * @brief 템플릿 기반의 3차원 벡터입니다.
 */
template <typename T>
struct TVec3
{
	/**
	 * @brief 3차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	TVec3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	TVec3(T&& xx, T&& yy, T&& zz) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	TVec3(const T& xx, const T& yy, const T& zz) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	TVec3(T&& e) noexcept
	{
		x = e;
		y = e;
		z = e;
	}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	TVec3(const T& e) noexcept
	{
		x = e;
		y = e;
		z = e;
	}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	TVec3(TVec3<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	TVec3(const TVec3<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	TVec3<T>& operator=(TVec3<T>&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	TVec3<T>& operator=(const TVec3<T>& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 3차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	TVec3<T> operator-() const
	{
		return TVec3<T>(-x, -y, -z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	TVec3<T> operator+(TVec3<T>&& v) const
	{
		return TVec3<T>(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	TVec3<T> operator+(const TVec3<T>& v) const
	{
		return TVec3<T>(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	TVec3<T> operator-(TVec3<T>&& v) const
	{
		return TVec3<T>(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	TVec3<T> operator-(const TVec3<T>& v) const
	{
		return TVec3<T>(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	TVec3<T> operator*(TVec3<T>&& v) const
	{
		return TVec3<T>(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	TVec3<T> operator*(const TVec3<T>& v) const
	{
		return TVec3<T>(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief 두 3차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(TVec3<T>&& v) const
	{
		T d = (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z);
		return static_cast<float>(d) < 1.192092896e-07F;
	}


	/**
	 * @brief 두 3차원 벡터가 동일한지 검사합니다.
	 * 
	 * @param v 검사를 수행할 피연산자입니다.
	 * 
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const TVec3<T>& v) const
	{
		T d = (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z);
		return static_cast<float>(d) < 1.192092896e-07F;
	}


	/**
	 * @brief 두 3차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(TVec3<T>&& v) const
	{
		return !(*this == v);
	}


	/**
	 * @brief 두 3차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const TVec3<T>& v) const
	{
		return !(*this == v);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	TVec3<T>& operator+=(TVec3<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	TVec3<T>& operator+=(const TVec3<T>& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	TVec3<T>& operator-=(TVec3<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	TVec3<T>& operator-=(const TVec3<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 3차원 백터의 내적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 내적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 내적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 내적 연산 결과를 반환합니다.
	 */
	static inline T Dot(const TVec3<T>& lhs, const TVec3<T>& rhs);


	/**
	 * @brief 3차원 벡터의 외적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 외적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 외적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 외적 연산 결과를 반환합니다.
	 */
	static inline TVec3<T> Cross(const TVec3<T>& lhs, const TVec3<T>& rhs);


	/**
	 * @brief 3차원 백터의 크기 제곱 값을 계산합니다.
	 *
	 * @param v 크기 제곱을 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 제곱 값을 반환합니다.
	 */
	static inline T LengthSq(const TVec3<T>& v);


	/**
	 * @brief 3차원 벡터의 크기를 얻습니다.
	 *
	 * @param v 크기를 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 값을 반환합니다.
	 */
	static inline float Length(const TVec3<T>& v);


	/**
	 * @brief 3차원 벡터를 정규화합니다.
	 *
	 * @param v 정규화 할 벡터입니다.
	 *
	 * @return 정규화된 벡터를 반환합니다.
	 */
	static inline TVec3<T> Normalize(const TVec3<T>& v);


	/**
	 * @brief 두 3차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 3차원 벡터 사이의 라디안 각도를 반환합니다.
	 */
	static inline float Radian(const TVec3<T>& lhs, const TVec3<T>& rhs);


	/**
	 * @brief 두 3차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 3차원 벡터 사이의 육십분법 각도를 반환합니다.
	 */
	static inline float Degree(const TVec3<T>& lhs, const TVec3<T>& rhs);


	/**
	 * @brief Base 3차원 벡터에 Target 3차원 벡터를 투영합니다.
	 *
	 * @param target 투영 대상에 투영할 벡터입니다.
	 * @param base 투영 대상이 되는 벡터입니다.
	 *
	 * @return base에 투영된 target 벡터를 반환합니다.
	 */
	static inline TVec3<T> Project(const TVec3<T>& target, const TVec3<T>& base);


	/**
	 * @brief Base 3차원 벡터에 Target 3차원 벡터를 투영한 벡터에 수직인 벡터를 계산합니다.
	 *
	 * @param target 투영 대상에 투영할 벡터입니다.
	 * @param base 투영 대상이 되는 벡터입니다.
	 *
	 * @return 투영된 벡터의 수직인 벡터를 반환합니다.
	 */
	static inline TVec3<T> Reject(const TVec3<T>& target, const TVec3<T>& base);


	/**
	 * @brief 두 벡터를 선형 보간한 벡터를 계산합니다.
	 *
	 * @param s 보간의 시작 벡터입니다.
	 * @param e 보간의 끝 벡터입니다.
	 * @param t 두 벡터의 보간 비율입니다.
	 *
	 * @return 보간된 벡터를 반환합니다.
	 */
	static inline TVec3<T> Lerp(const TVec3<T>& s, const TVec3<T>& e, const float& t);


	/**
	 * @brief 두 벡터를 구면 선형 보간한 벡터를 계산합니다.
	 *
	 * @param s 보간의 시작 벡터입니다.
	 * @param e 보간의 끝 벡터입니다.
	 * @param t 두 벡터의 보간 비율입니다.
	 *
	 * @return 보간된 벡터를 반환합니다.
	 */
	static inline TVec3<T> Slerp(const TVec3<T>& s, const TVec3<T>& e, const float& t);


	/**
	 * @brief 3차원 벡터의 다양한 원소 형식입니다.
	 */
	union
	{
		struct
		{
			T x;
			T y;
			T z;
		};
		T data[3];
	};
};


/**
 * @brief int32_t 타입의 3차원 벡터입니다.
 */
using Vec3i = TVec3<int32_t>;


/**
 * @brief float 타입의 3차원 벡터입니다.
 */
using Vec3f = TVec3<float>;


#include "Vec3.inl"