#include "MathModule.h"

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Zero()
{
	return TMat4x4<T>(
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)
		);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Identity()
{
	return TMat4x4<T>(
		static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Transpose(const TMat4x4<T>& m)
{
	return TMat4x4<T>(
		m.e00, m.e10, m.e20, m.e30
		m.e01, m.e11, m.e21, m.e31,
		m.e02, m.e12, m.e22, m.e32,
		m.e03, m.e13, m.e23, m.e33
		);
}

template<typename T>
inline T TMat4x4<T>::Determinant(const TMat4x4<T>& m)
{
	T subFactor00 = m.e22 * m.e33 - m.e32 * m.e23;
	T subFactor01 = m.e21 * m.e33 - m.e31 * m.e23;
	T subFactor02 = m.e21 * m.e32 - m.e31 * m.e22;
	T subFactor03 = m.e20 * m.e33 - m.e30 * m.e23;
	T subFactor04 = m.e20 * m.e32 - m.e30 * m.e22;
	T subFactor05 = m.e20 * m.e31 - m.e30 * m.e21;

	T cof0 = +(m.e11 * subFactor00 - m.e12 * subFactor01 + m.e13 * subFactor02);
	T cof1 = -(m.e10 * subFactor00 - m.e12 * subFactor03 + m.e13 * subFactor04);
	T cof2 = +(m.e10 * subFactor01 - m.e11 * subFactor03 + m.e13 * subFactor05);
	T cof3 = -(m.e10 * subFactor02 - m.e11 * subFactor04 + m.e12 * subFactor05);

	return m.e00 * cof0 + m.e01 * cof1 + m.e02 * cof2 + m.e03 * cof3;
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Inverse(const TMat4x4<T>& m)
{
	T oneOverDeterminant = static_cast<T>(1) / Determinant(m);

	T coef00 = m.e22 * m.e33 - m.e32 * m.e23;
	T coef02 = m.e12 * m.e33 - m.e32 * m.e13;
	T coef03 = m.e12 * m.e23 - m.e22 * m.e13;

	T coef04 = m.e21 * m.e33 - m.e31 * m.e23;
	T coef06 = m.e11 * m.e33 - m.e31 * m.e13;
	T coef07 = m.e11 * m.e23 - m.e21 * m.e13;

	T coef08 = m.e21 * m.e32 - m.e31 * m.e22;
	T coef10 = m.e11 * m.e32 - m.e31 * m.e12;
	T coef11 = m.e11 * m.e22 - m.e21 * m.e12;

	T coef12 = m.e20 * m.e33 - m.e30 * m.e23;
	T coef14 = m.e10 * m.e33 - m.e30 * m.e13;
	T coef15 = m.e10 * m.e23 - m.e20 * m.e13;

	T coef16 = m.e20 * m.e32 - m.e30 * m.e22;
	T coef18 = m.e10 * m.e32 - m.e30 * m.e12;
	T coef19 = m.e10 * m.e22 - m.e20 * m.e12;

	T coef20 = m.e20 * m.e31 - m.e30 * m.e21;
	T coef22 = m.e10 * m.e31 - m.e30 * m.e11;
	T coef23 = m.e10 * m.e21 - m.e20 * m.e11;

	TVec4<T> fac0(coef00, coef00, coef02, coef03);
	TVec4<T> fac1(coef04, coef04, coef06, coef07);
	TVec4<T> fac2(coef08, coef08, coef10, coef11);
	TVec4<T> fac3(coef12, coef12, coef14, coef15);
	TVec4<T> fac4(coef16, coef16, coef18, coef19);
	TVec4<T> fac5(coef20, coef20, coef22, coef23);

	TVec4<T> vec0(m.e10, m.e00, m.e00, m.e00);
	TVec4<T> vec1(m.e11, m.e01, m.e01, m.e01);
	TVec4<T> vec2(m.e12, m.e02, m.e02, m.e02);
	TVec4<T> vec3(m.e13, m.e03, m.e03, m.e03);

	TVec4<T> inv0(vec1 * fac0 - vec2 * fac1 + vec3 * fac2);
	TVec4<T> inv1(vec0 * fac0 - vec2 * fac3 + vec3 * fac4);
	TVec4<T> inv2(vec0 * fac1 - vec1 * fac3 + vec3 * fac5);
	TVec4<T> inv3(vec0 * fac2 - vec1 * fac4 + vec2 * fac5);

	TVec4<T> signA(+static_cast<T>(1), -static_cast<T>(1), +static_cast<T>(1), -static_cast<T>(1));
	TVec4<T> signB(-static_cast<T>(1), +static_cast<T>(1), -static_cast<T>(1), +static_cast<T>(1));

	TVec4<T> col0 = (inv0 * signA) * oneOverDeterminant;
	TVec4<T> col1 = (inv1 * signB) * oneOverDeterminant;
	TVec4<T> col2 = (inv2 * signA) * oneOverDeterminant;
	TVec4<T> col3 = (inv3 * signB) * oneOverDeterminant;

	return TMat4x4<T>(
		col0.x, col0.y, col0.z, col0.w,
		col1.x, col1.y, col1.z, col1.w,
		col2.x, col2.y, col2.z, col2.w,
		col3.x, col3.y, col3.z, col3.w,
		);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Translation(float x, float y, float z)
{		
	return Mat4x4f(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		   x,    y,    z, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Translation(const TVec3<T>& p)
{
	return TMat4x4<T>(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		 p.x,  p.y,  p.z, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Scale(float xScale, float yScale, float zScale)
{
	return TMat4x4<T>(
		xScale,   0.0f,   0.0f, 0.0f,
		  0.0f, yScale,   0.0f, 0.0f,
		  0.0f,   0.0f, zScale, 0.0f,
		  0.0f,   0.0f,   0.0f, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Scale(const Vec3f& scale)
{
	return TMat4x4<T>(
		scale.x,    0.0f,    0.0f, 0.0f,
		   0.0f, scale.y,    0.0f, 0.0f,
		   0.0f,    0.0f, scale.z, 0.0f,
		   0.0f,    0.0f,    0.0f, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::RotateX(float radian)
{
	float c = MathModule::Cos(radian);
	float s = MathModule::Sin(radian);

	return TMat4x4<T>(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f,    c,    s, 0.0f,
		0.0f,   -s,    c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::RotateY(float radian)
{
	float c = MathModule::Cos(radian);
	float s = MathModule::Sin(radian);

	return TMat4x4<T>(
		   c, 0.0f,   -s, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		   s, 0.0f,    c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::RotateZ(float radian)
{
	float c = MathModule::Cos(radian);
	float s = MathModule::Sin(radian);

	return TMat4x4<T>(
		  c,     s, 0.0f, 0.0f,
	   	 -s,     c, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Rotate(float radian, const Vec3f& axis)
{		
	float c = MathModule::Cos(radian);
	float s = MathModule::Sin(radian);
	Vec3f r = Vec3f::Normalize(axis);

	return TMat4x4<T>(
		      c + r.x * r.x * (1.0f - c), r.y * r.x * (1.0f - c) + r.z * s, r.z * r.x * (1.0f - c) - r.y * s, 0.0f,
		r.x * r.y * (1.0f - c) - r.z * s,       c + r.y * r.y * (1.0f - c), r.z * r.y * (1.0f - c) + r.x * s, 0.0f,
		r.x * r.z * (1.0f - c) + r.y * s, r.y * r.z * (1.0f - c) - r.x * s,       c + r.z * r.z * (1.0f - c), 0.0f,
	    	                        0.0f,                             0.0f,                             0.0f, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
{		
	float width = (right - left);
	float sumLR = (right + left);
	float height = (top - bottom);
	float sumTB = (top + bottom);
	float depth = (zFar - zNear);
	float sumNF = (zFar + zNear);

	return TMat4x4<T>(
		  2.0f / width,            0.0f,           0.0f, 0.0f,
		          0.0f,   2.0f / height,           0.0f, 0.0f,
		          0.0f,            0.0f,  -2.0f / depth, 0.0f,
		-sumLR / width, -sumTB / height, -sumNF / depth, 1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::Perspective(float fov, float aspect, float nearZ, float farZ)
{
	float halfFov = fov / 2.0f;
	float tanHalfFovy = MathModule::Sin(halfFov) / MathModule::Cos(halfFov);

	return TMat4x4<T>(
		1.0f / (aspect * tanHalfFovy),                 0.0f,                                    0.0f,  0.0f,
			                     0.0f, 1.0f / (tanHalfFovy),                                    0.0f,  0.0f,
			                     0.0f,                 0.0f,        -(farZ + nearZ) / (farZ - nearZ), -1.0f,
			                     0.0f,                 0.0f, -(2.0f * farZ * nearZ) / (farZ - nearZ),  1.0f
	);
}

template<typename T>
inline TMat4x4<T> TMat4x4<T>::LookAt(const Vec3f& eyePosition, const Vec3f& focusPosition, const Vec3f& upDirection)
{
	Vec3f f = -Vec3f::Normalize(focusPosition - eyePosition);
	Vec3f s = Vec3f::Normalize(Vec3f::Cross(upDirection, f));
	Vec3f u = Vec3f::Cross(f, s);
	Vec3f t = Vec3f(-Vec3f::Dot(s, eyePosition), -Vec3f::Dot(u, eyePosition), -Vec3f::Dot(f, eyePosition));

	return TMat4x4<T>(
		s.x, u.x, f.x, 0.0f,
		s.y, u.y, f.y, 0.0f,
		s.z, u.z, f.z, 0.0f,
		t.x, t.y, t.z, 1.0f
	);
}
