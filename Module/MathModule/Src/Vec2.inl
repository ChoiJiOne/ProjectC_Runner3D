#include "MathModule.h"
#include "..\Inc\Vec2.h"

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