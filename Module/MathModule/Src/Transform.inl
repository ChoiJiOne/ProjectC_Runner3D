#include "MathModule.h"
#include "..\Inc\Transform.h"

Mat4x4f Transform::ToMat(const Transform& transform)
{
	Vec3f x = transform.rotate * Vec3f(1.0f, 0.0f, 0.0f);
	Vec3f y = transform.rotate * Vec3f(0.0f, 1.0f, 0.0f);
	Vec3f z = transform.rotate * Vec3f(0.0f, 0.0f, 1.0f);

	x = x * transform.scale.x;
	y = y * transform.scale.y;
	z = z * transform.scale.z;

	Vec3f p = transform.position;

	return Mat4x4f(
		x.x, x.y, x.z, 0,
		y.x, y.y, y.z, 0,
		z.x, z.y, z.z, 0,
		p.x, p.y, p.z, 1
	);
}

inline Transform Transform::ToTransform(const Mat4x4f& m)
{
	Transform t;

	t.position = Vec3f(m.e30, m.e31, m.e32);
	t.rotate = Quat::ToQuat(m);

	Mat4x4f rotateScale(
		m.e00, m.e01, m.e02, 0.0f,
		m.e10, m.e11, m.e12, 0.0f,
		m.e20, m.e21, m.e22, 0.0f,
		 0.0f,  0.0f,  0.0f, 1.0f
	);

	Mat4x4f invRotateScale = Quat::ToMat(Quat::Inverse(t.rotate));
	Mat4x4f scaleKew = rotateScale * invRotateScale;

	t.scale = Vec3f(scaleKew.e00, scaleKew.e11, scaleKew.e22);

	return t;
}

inline Transform Transform::Combine(const Transform& lhs, const Transform& rhs)
{
	Transform t;

	t.scale = lhs.scale * rhs.scale;
	t.rotate = rhs.rotate * lhs.rotate;

	t.position = lhs.rotate * (lhs.scale * rhs.position);
	t.position = lhs.position + t.position;

	return t;
}
