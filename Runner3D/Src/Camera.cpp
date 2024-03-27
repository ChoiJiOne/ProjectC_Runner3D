#include "Assertion.h"
#include "Camera.h"

Camera::Camera(const Vec3f& eyePosition, const Vec3f& eyeDirection, const Vec3f& upDirection, float fov, float aspectRatio, float nearZ, float farZ)
	: eyePosition_(eyePosition)
	, eyeDirection_(eyeDirection)
	, upDirection_(upDirection)
	, fov_(fov)
	, aspectRatio_(aspectRatio)
	, nearZ_(nearZ)
	, farZ_(farZ)
{
	UpdateViewMatrix();
	UpdateProjectionMatrix();

	bIsInitialized_ = true;
}

Camera::~Camera()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Camera::Tick(float deltaSeconds)
{
	// 아무 동작도 수행하지 않습니다.
}

void Camera::Render()
{
	// 아무 동작도 수행하지 않습니다.
}

void Camera::Release()
{
	CHECK(bIsInitialized_);

	bIsInitialized_ = false;
}

void Camera::UpdateViewMatrix()
{
	view_ = Mat4x4::LookAt(eyePosition_, eyePosition_ + eyeDirection_, upDirection_);
}

void Camera::UpdateProjectionMatrix()
{
	projection_ = Mat4x4::Perspective(fov_, aspectRatio_, nearZ_, farZ_);
}