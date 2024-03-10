#pragma once

#include "Mat4x4.h"
#include "Quat.h"
#include "Vec3.h"


/**
 * @brief SRT(Scale, Rotation, Translation) 변환을 수행합니다.
 */
struct Transform
{
	/**
	 * @brief 트랜스폼의 기본 생성자입니다.
	 */
	Transform() noexcept
		: position(0.0f, 0.0f, 0.0f)
		, rotate(0.0f, 0.0f, 0.0f, 1.0f)
		, scale(1.0f, 1.0f, 1.0f) {}


	/**
	 * @brief 트랜스폼의 생성자입니다.
	 *
	 * @param p 이동 변환 수행 시 이동할 위치입니다.
	 * @param r 회전 변환 수행 시 참조할 쿼터니언입니다.
	 * @param s 크기 변환 수행 시 참조할 크기입니다.
	 */
	Transform(Vec3f&& p, Quat&& r, Vec3f&& s) noexcept
		: position(p)
		, rotate(r)
		, scale(s) {}


	/**
	 * @brief 트랜스폼의 생성자입니다.
	 * 
	 * @param p 이동 변환 수행 시 이동할 위치입니다.
	 * @param r 회전 변환 수행 시 참조할 쿼터니언입니다.
	 * @param s 크기 변환 수행 시 참조할 크기입니다.
	 */
	Transform(const Vec3f& p, const Quat& r, const Vec3f& s) noexcept
		: position(p)
		, rotate(r)
		, scale(s) {}


	/**
	 * @brief 트랜스폼의 복사 생성자입니다.
	 * 
	 * @param instance 복사할 트랜스폼의 인스턴스입니다.
	 */
	Transform(Transform&& instance) noexcept
		: position(instance.position)
		, rotate(instance.rotate)
		, scale(instance.scale) {}


	/**
	 * @brief 트랜스폼의 복사 생성자입니다.
	 *
	 * @param instance 복사할 트랜스폼의 인스턴스입니다.
	 */
	Transform(const Transform& instance) noexcept
		: position(instance.position)
		, rotate(instance.rotate)
		, scale(instance.scale) {}


	/**
	 * @brief 트랜스폼의 대입 연산자입니다.
	 * 
	 * @param instance 복사할 트랜스폼의 인스턴스입니다.
	 * 
	 * @return 대입한 트랜스폼의 참조자를 반환합니다.
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
	 * @brief 트랜스폼의 대입 연산자입니다.
	 *
	 * @param instance 복사할 트랜스폼의 인스턴스입니다.
	 *
	 * @return 대입한 트랜스폼의 참조자를 반환합니다.
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
	 * @brief 트랜스 폼을 행렬로 변환합니다.
	 * 
	 * @param transform 행렬로 변환할 트랜스폼입니다.
	 * 
	 * @return 변환된 행렬을 반환합니다.
	 */
	static inline Mat4x4f ToMat(const Transform& transform);


	/**
	 * @brief 행렬을 트랜스폼으로 변환합니다.
	 * 
	 * @param m 트랜스폼으로 변환할 행렬입니다.
	 * 
	 * @return 변환된 트랜스폼을 반환합니다.
	 */
	static inline Transform ToTransform(const Mat4x4f& m);


	/**
	 * @brief 두 트랜스폼을 결합합니다.
	 * 
	 * @param lhs 결합할 트랜스폼입니다.
	 * @param rhs 결합할 또 다른 트랜스폼입니다.
	 */
	static inline Transform Combine(const Transform& lhs, const Transform& rhs);


	/**
	 * @brief 트랜스폼의 역변환을 얻습니다.
	 * 
	 * @param transform 역변환을 계산할 트랜스폼입니다.
	 * 
	 * @return 계산된 역변환 트랜스폼을 반환합니다.
	 */
	static inline Transform Inverse(const Transform& transform);


	/**
	 * @brief 두 트랜스폼을 보간합니다.
	 * 
	 * @param s 보간의 시작 트랜스폼입니다.
	 * @param e 보간의 끝 트랜스폼입니다.
	 * @param t 두 트랜스폼의 보간 비율입니다.
	 * 
	 * @return 보간된 트랜스폼을 반환합니다.
	 */
	static inline Transform Mix(const Transform& s, const Transform& e, const float& t);


	/**
	 * @brief 이동 변환 수행 시 이동할 위치입니다.
	 */
	Vec3f position;


	/**
	 * @brief 회전 변환 수행 시 참조할 쿼터니언입니다.
	 */
	Quat rotate;


	/**
	 * @brief 크기 변환 수행 시 참조할 크기입니다.
	 */
	Vec3f scale;
};


#include "Transform.inl"