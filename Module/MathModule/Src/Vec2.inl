#include "MathModule.h"

template<typename T>
inline T TVec2<T>::Dot(const TVec2<T>& lhs, const TVec2<T>& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

template<typename T>
inline T TVec2<T>::Cross(const TVec2<T>& lhs, const TVec2<T>& rhs)
{
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

template<typename T>
inline T TVec2<T>::LengthSq(const TVec2<T>& v)
{
	return v.x * v.x + v.y * v.y;
}

template<typename T>
inline float TVec2<T>::Length(const TVec2<T>& v)
{
	float lengthSq = static_cast<float>(TVec2<T>::LengthSq(v));
	return std::sqrtf(lengthSq);
}

template<typename T>
inline TVec2<T> TVec2<T>::Normalize(const TVec2<T>& v)
{
	float invLength = 1.0f / static_cast<float>(TVec2<T>::Length(v));

	return TVec2<T>(
		static_cast<T>(static_cast<float>(v.x) * invLength),
		static_cast<T>(static_cast<float>(v.y) * invLength)
	);
}

template<typename T>
inline float TVec2<T>::Radian(const TVec2<T>& lhs, const TVec2<T>& rhs)
{
	float lengthL = TVec2::Length(lhs);
	float lengthR = TVec2::Length(rhs);
	float dot = TVec2::Dot(lhs, rhs);
	
	return MathModule::ACos(dot / (lengthL * lengthR));
}

template<typename T>
inline float TVec2<T>::Degree(const TVec2<T>& lhs, const TVec2<T>& rhs)
{
	float radian = TVec2::Radian(lhs, rhs);
	return MathModule::ToDegree(radian);
}

template<typename T>
inline TVec2<T> TVec2<T>::Project(const TVec2<T>& target, const TVec2<T>& base)
{
	T dot = TVec2::Dot(target, base);
	T lengthSq = TVec2::LengthSq(base);
	T scale = dot / lengthSq;
	
	return TVec2<T>(base.x * scale, base.y * scale);
}

template<typename T>
inline TVec2<T> TVec2<T>::Reject(const TVec2<T>& target, const TVec2<T>& base)
{
	TVec2<T> project = TVec2<T>::Project(target, base);
	return target - project;
}

template<typename T>
inline TVec2<T> TVec2<T>::Lerp(const TVec2<T>& s, const TVec2<T>& e, const float& t)
{
	return s * (1.0f - t) + e * t;
}

template<typename T>
inline TVec2<T> TVec2<T>::Slerp(const TVec2<T>& s, const TVec2<T>& e, const float& t)
{
	TVec2<T> start = TVec2<T>::Normalize(s);
	TVec2<T> end = TVec2<T>::Normalize(e);

	float theta = TVec2<T>::Radian(start, end);
	float sinTheta = MathModule::Sin(theta);

	float a = MathModule::Sin((1.0f - t) * theta) / sinTheta;
	float b = MathModule::Sin(t * theta) / sinTheta;

	return s * a + e * b;
}