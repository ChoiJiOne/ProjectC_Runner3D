#include "MathModule.h"

template<typename T>
inline T TVec3<T>::Dot(const TVec3<T>& lhs, const TVec3<T>& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template<typename T>
inline TVec3<T> TVec3<T>::Cross(const TVec3<T>& lhs, const TVec3<T>& rhs)
{
	return TVec3<T>(
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x
		);
}

template<typename T>
inline T TVec3<T>::LengthSq(const TVec3<T>& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

template<typename T>
inline float TVec3<T>::Length(const TVec3<T>& v)
{
	float lengthSq = static_cast<float>(TVec3<T>::LengthSq(v));
	return std::sqrtf(lengthSq);
}

template<typename T>
inline TVec3<T> TVec3<T>::Normalize(const TVec3<T>& v)
{
	float invLength = 1.0f / static_cast<float>(TVec3<T>::Length(v));

	return TVec3<T>(
		static_cast<T>(static_cast<float>(v.x) * invLength),
		static_cast<T>(static_cast<float>(v.y) * invLength),
		static_cast<T>(static_cast<float>(v.z) * invLength)
	);
}

template<typename T>
inline float TVec3<T>::Radian(const TVec3<T>& lhs, const TVec3<T>& rhs)
{
	float lengthL = TVec3::Length(lhs);
	float lengthR = TVec3::Length(rhs);
	float dot = TVec3::Dot(lhs, rhs);

	return MathModule::ACos(dot / (lengthL * lengthR));
}

template<typename T>
inline float TVec3<T>::Degree(const TVec3<T>& lhs, const TVec3<T>& rhs)
{
	float radian = TVec3::Radian(lhs, rhs);
	return MathModule::ToDegree(radian);
}

template<typename T>
inline TVec3<T> TVec3<T>::Project(const TVec3<T>& target, const TVec3<T>& base)
{
	T dot = TVec3::Dot(target, base);
	T lengthSq = TVec3::LengthSq(base);
	T scale = dot / lengthSq;

	return TVec3<T>(base.x * scale, base.y * scale, base.z * scale);
}

template<typename T>
inline TVec3<T> TVec3<T>::Reject(const TVec3<T>& target, const TVec3<T>& base)
{
	TVec3<T> project = TVec3<T>::Project(target, base);
	return target - project;
}
