#include "MathModule.h"
#include "..\Inc\Quat.h"

inline Quat Quat::AxisRadian(const Vec3f& axis, float radian)
{
	Vec3f norm = Vec3f::Normalize(axis);

	float s = MathModule::Sin(radian * 0.5f);
	float c = MathModule::Cos(radian * 0.5f);

	return Quat(norm.x * s, norm.y * s, norm.z * s, c);
}

inline Quat Quat::AxisAngle(const Vec3f& axis, float angle)
{
	float radian = MathModule::ToRadian(angle);

	float s = MathModule::Sin(radian * 0.5f);
	float c = MathModule::Cos(radian * 0.5f);
	Vec3f norm = Vec3f::Normalize(axis);

	return Quat(norm.x * s, norm.y * s, norm.z * s, c);
}

inline Vec3f Quat::Axis(const Quat& q)
{
	return Vec3f::Normalize(Vec3f(q.x, q.y, q.z));
}

inline float Quat::Radian(const Quat& q)
{
	return 2.0f * MathModule::ACos(q.w);
}

inline float Quat::Angle(const Quat& q)
{
	return MathModule::ToDegree(2.0f * MathModule::ACos(q.w));
}

inline float Quat::Dot(const Quat& lhs, const Quat& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

inline float Quat::LengthSq(const Quat& q)
{
	return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

inline float Quat::Length(const Quat& q)
{
	float lengthSq = Quat::LengthSq(q);
	return std::sqrtf(lengthSq);
}

inline Quat Quat::Normalize(const Quat& q)
{
	float invLength = 1.0f / Quat::Length(q);
	return Quat(q.x * invLength, q.y * invLength, q.z * invLength, q.w * invLength);
}

inline Quat Quat::Conjugate(const Quat& q)
{
	return Quat(-q.x, -q.y, -q.z, q.w);
}

inline Quat Quat::Inverse(const Quat& q)
{
	float invLengthSq = 1.0f / Quat::LengthSq(q);
	return Quat(-q.x * invLengthSq, -q.y * invLengthSq, -q.z * invLengthSq, q.w * invLengthSq);
}

inline Quat Quat::Zero()
{
	return Quat(0.0f, 0.0f, 0.0f, 0.0f);
}

inline Quat Quat::Identity()
{
	return Quat(0.0f, 0.0f, 0.0f, 1.0f);
}

inline Quat Quat::Rotate(const Vec3f& s, const Vec3f& e)
{
	Vec3f start = Vec3f::Normalize(s);
	Vec3f end = Vec3f::Normalize(e);
	Quat quat;

	if (start == end)
	{
		quat = Quat();
	}
	else if (start == end * -1.0f)
	{
		Vec3f ortho;

		if (fabsf(start.y) < fabsf(start.x))
		{
			ortho = Vec3f(0.0f, 1.0f, 0.0f);
		}
		else if (fabsf(start.z) < fabsf(start.y) && fabsf(start.z) < fabsf(start.x))
		{
			ortho = Vec3f(0.0f, 0.0f, 1.0f);
		}
		else
		{
			ortho = Vec3f(1.0f, 0.0f, 0.0f);
		}

		Vec3f axis = Vec3f::Normalize(Vec3f::Cross(start, ortho));
		quat = Quat(axis, 0.0f);
	}
	else
	{
		Vec3f half = Vec3f::Normalize(start + end);
		Vec3f axis = Vec3f::Cross(start, half);

		quat = Quat(axis, Vec3f::Dot(start, half));
	}

	return quat;
}

inline Quat Quat::Lerp(const Quat& s, const Quat& e, const float& t)
{
	return s * (1.0f - t) + e * t;
}

inline Quat Quat::Nlerp(const Quat& s, const Quat& e, const float& t)
{
	return Normalize(Lerp(s, e, t));
}
