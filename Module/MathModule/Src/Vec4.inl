#include "MathModule.h"
#include "..\Inc\Vec4.h"

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
	return std::sqrtf(lengthSq);
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