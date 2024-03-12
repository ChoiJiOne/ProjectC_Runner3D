#include "MathModule.h"

template<typename T>
inline T TVec4<T>::Dot(const TVec4<T>& lhs, const TVec4<T>& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

template<typename T>
inline T TVec4<T>::LengthSq(const TVec4<T>& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

template<typename T>
inline float TVec4<T>::Length(const TVec4<T>& v)
{
	float lengthSq = static_cast<float>(TVec4<T>::LengthSq(v));
	return MathModule::Sqrt(lengthSq);
}

template<typename T>
inline TVec4<T> TVec4<T>::Normalize(const TVec4<T>& v)
{
	float invLength = 1.0f / static_cast<float>(TVec4<T>::Length(v));
	
	return TVec4<T>(
		static_cast<T>(static_cast<float>(v.x) * invLength),
		static_cast<T>(static_cast<float>(v.y) * invLength),
		static_cast<T>(static_cast<float>(v.z) * invLength),
		static_cast<T>(static_cast<float>(v.w) * invLength)
	);
}

template<typename T>
inline float TVec4<T>::Radian(const TVec4<T>& lhs, const TVec4<T>& rhs)
{
	float lengthL = TVec4::Length(lhs);
	float lengthR = TVec4::Length(rhs);
	float dot = TVec4::Dot(lhs, rhs);

	return MathModule::ACos(dot / (lengthL * lengthR));
}

template<typename T>
inline float TVec4<T>::Degree(const TVec4<T>& lhs, const TVec4<T>& rhs)
{
	float radian = TVec4::Radian(lhs, rhs);
	return MathModule::ToDegree(radian);
}

template<typename T>
inline TVec4<T> TVec4<T>::Project(const TVec4<T>& target, const TVec4<T>& base)
{
	T dot = TVec4::Dot(target, base);
	T lengthSq = TVec4::LengthSq(base);
	T scale = dot / lengthSq;

	return TVec4<T>(base.x * scale, base.y * scale, base.z * scale, base.w * scale);
}

template<typename T>
inline TVec4<T> TVec4<T>::Reject(const TVec4<T>& target, const TVec4<T>& base)
{
	TVec4<T> project = TVec4<T>::Project(target, base);
	return target - project;
}

template<typename T>
inline TVec4<T> TVec4<T>::Lerp(const TVec4<T>& s, const TVec4<T>& e, const float& t)
{
	return s * (1.0f - t) + e * t;
}

template<typename T>
inline TVec4<T> TVec4<T>::Slerp(const TVec4<T>& s, const TVec4<T>& e, const float& t)
{
	TVec4<T> start = TVec4<T>::Normalize(s);
	TVec4<T> end = TVec4<T>::Normalize(e);

	float theta = TVec4<T>::Radian(start, end);
	float sinTheta = MathModule::Sin(theta);

	float a = MathModule::Sin((1.0f - t) * theta) / sinTheta;
	float b = MathModule::Sin(t * theta) / sinTheta;

	return s * a + e * b;
}