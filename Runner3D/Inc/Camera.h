#pragma once

#include "Mat4x4.h"
#include "Vec3.h"

#include "IEntity.h"


/**
 * @brief ī�޶� ��ƼƼ�Դϴ�.
 * 
 * @note �� ī�޶�� �������� �ʽ��ϴ�.
 */
class Camera : public IEntity
{
public:
	/**
	 * @brief ī�޶� ��ƼƼ�� �������Դϴ�.
	 * 
	 * @param eyePosition ī�޶��� ���� �� ��ġ�Դϴ�.
	 * @param eyeDirection ī�޶��� �����Դϴ�.
	 * @param upDirection ī�޶��� �� �����Դϴ�.
	 * @param fov ����� ���� �ʵ� ����(����)�Դϴ�.
	 * @param aspectRatio �� ������ X:Y �����Դϴ�.
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	explicit Camera(
		const Vec3f& eyePosition, 
		const Vec3f& eyeDirection, 
		const Vec3f& upDirection,
		float fov,
		float aspectRatio,
		float nearZ,
		float farZ
	);


	/**
	 * @brief ī�޶� ��ƼƼ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Camera();


	/**
	 * @brief ī�޶� ��ƼƼ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Camera);


	/**
	 * @brief ī�޶� ��ƼƼ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) override;


	/**
	 * @brief ī�޶� ��ƼƼ�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @note �� �޼���� �ƹ� ���۵� �������� �ʽ��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ī�޶� ��ƼƼ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ī�޶��� ���� �� ��ġ�� ����ϴ�.
	 *
	 * @return ī�޶��� ���� �� ��ġ�� ��ȯ�մϴ�.
	 */
	const Vec3f& GetEyePosition() const { return eyePosition_; }


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ������ ����ϴ�.
	 *
	 * @return ī�޶� �ٶ󺸰� �ִ� ������ ��ȯ�մϴ�.
	 */
	const Vec3f& GetEyeDirection() const { return eyeDirection_; }


	/**
	 * @brief ī�޶��� �� ������ ����ϴ�.
	 *
	 * @return ī�޶��� �� ������ ��ȯ�մϴ�.
	 */
	const Vec3f& GetUpDirection() const { return upDirection_; }


	/**
	 * @brief ����� ���� �ʵ� ����(����) ���� ����ϴ�.
	 *
	 * @return ����� ���� �ʵ� ����(����) ���� ��ȯ�մϴ�.
	 */
	const float& GetFov() const { return fov_; }


	/**
	 * @brief �� ���� X:Y�� ���� ���� ���� ���� ����ϴ�.
	 *
	 * @return �� ���� X:Y�� ���� ���� ���� ���� ��ȯ�մϴ�.
	 */
	const float& GetAspectRatio() const { return aspectRatio_; }


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ� ���� ����ϴ�.
	 *
	 * @return ����� Ŭ���� �������� �Ÿ� ���� ��ȯ�մϴ�.
	 */
	const float& GetNearZ() const { return nearZ_; }


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ� ���� ����ϴ�.
	 *
	 * @return ���Ÿ� Ŭ���� �������� �Ÿ� ���� ��ȯ�մϴ�.
	 */
	const float& GetFarZ() const { return farZ_; }


	/**
	 * @brief �þ� ����� ����ϴ�.
	 *
	 * @return �þ� ����� ��ȯ�մϴ�.
	 */
	const Mat4x4& GetViewMatrix() const { return view_; }


	/**
	 * @brief ���� ����� ����ϴ�.
	 *
	 * @return ���� ����� ��ȯ�մϴ�.
	 */
	const Mat4x4& GetProjectionMatrix() const { return projection_; }


	/**
	 * @brief ī�޶��� ���� �� ��ġ�� �����մϴ�.
	 *
	 * @param eyePosition ������ ī�޶��� ���� �� ��ġ�Դϴ�.
	 */
	void SetEyePosition(const Vec3f& eyePosition)
	{
		eyePosition_ = eyePosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�� �����մϴ�.
	 *
	 * @param eyeDirection ������ ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 */
	void SetEyeDirection(const Vec3f& eyeDirection)
	{
		eyeDirection_ = eyeDirection;
		UpdateViewMatrix();
	}


	/**
	 * @brief ī�޶��� �� ������ �����մϴ�.
	 *
	 * @param upDirection ������ ī�޶��� �� �����Դϴ�.
	 */
	void SetUpDirection(const Vec3f& upDirection)
	{
		upDirection_ = upDirection;
		UpdateViewMatrix();
	}


	/**
	 * @brief ����� ���� �ʵ� ����(����)�� �����մϴ�.
	 *
	 * @param fovRadians ������ �ʵ� ����(����) �Դϴ�.
	 */
	void SetFov(float fov)
	{
		fov_ = fov;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief �� ���� X:Y�� ���� ���� ������ �����մϴ�.
	 *
	 * @param aspectRatio ������ �� ������ ���� ���� �����Դϴ�.
	 */
	void SetAspectRatio(float aspectRatio)
	{
		aspectRatio_ = aspectRatio;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ��� �����մϴ�.
	 *
	 * @param nearZ ������ ����� Ŭ���� �������� �Ÿ��Դϴ�.
	 */
	void SetNearZ(float nearZ)
	{
		nearZ_ = nearZ;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ��� �����մϴ�.
	 *
	 * @param farZ ������ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�.
	 */
	void SetFarZ(float farZ)
	{
		farZ_ = farZ;
		UpdateProjectionMatrix();
	}


private:
	/**
	 * @brief �þ� ����� ������Ʈ�մϴ�.
	 */
	void UpdateViewMatrix();


	/**
	 * @brief ���� ����� ������Ʈ�մϴ�.
	 */
	void UpdateProjectionMatrix();


private:
	/**
	 * @brief ī�޶��� ���� �� ��ġ�Դϴ�.
	 */
	Vec3f eyePosition_;


	/**
	 * @brief ī�޶��� �����Դϴ�.
	 */
	Vec3f eyeDirection_;


	/**
	 * @brief ī�޶��� �� �����Դϴ�.
	 */
	Vec3f upDirection_;


	/**
	 * @brief ����� ���� �ʵ� ����(����)�Դϴ�.
	 */
	float fov_ = 0.0f;


	/**
	 * @brief �� ���� X:Y�� ���� ���� �����Դϴ�.
	 */
	float aspectRatio_ = 0.0f;


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	float nearZ_ = 0.0f;


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	float farZ_ = 0.0f;


	/**
	 * @brief �� ����Դϴ�.
	 */
	Mat4x4 view_;


	/**
	 * @brief ���� ����Դϴ�.
	 *
	 * @note ���� ��������� �ƴ� ���� ���� ����Դϴ�.
	 */
	Mat4x4 projection_;
};