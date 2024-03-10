#include "MathModule.h"

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