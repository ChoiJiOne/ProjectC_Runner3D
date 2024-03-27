#pragma once

#include "Mat4x4.h"
#include "Vec3.h"

#include "IEntity.h"


/**
 * @brief 카메라 엔티티입니다.
 * 
 * @note 이 카메라는 움직이지 않습니다.
 */
class Camera : public IEntity
{
public:
	/**
	 * @brief 카메라 엔티티의 생성자입니다.
	 * 
	 * @param eyePosition 카메라의 월드 상 위치입니다.
	 * @param eyeDirection 카메라의 방향입니다.
	 * @param upDirection 카메라의 위 방향입니다.
	 * @param fov 하향식 보기 필드 각도(라디안)입니다.
	 * @param aspectRatio 뷰 공간의 X:Y 비율입니다.
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
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
	 * @brief 카메라 엔티티의 가상 소멸자입니다.
	 */
	virtual ~Camera();


	/**
	 * @brief 카메라 엔티티의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Camera);


	/**
	 * @brief 카메라 엔티티를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Tick(float deltaSeconds) override;


	/**
	 * @brief 카메라 엔티티를 화면에 그립니다.
	 * 
	 * @note 이 메서드는 아무 동작도 수행하지 않습니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 카메라 엔티티 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 카메라의 월드 상 위치를 얻습니다.
	 *
	 * @return 카메라의 월드 상 위치를 반환합니다.
	 */
	const Vec3f& GetEyePosition() const { return eyePosition_; }


	/**
	 * @brief 카메라가 바라보고 있는 방향을 얻습니다.
	 *
	 * @return 카메라가 바라보고 있는 방향을 반환합니다.
	 */
	const Vec3f& GetEyeDirection() const { return eyeDirection_; }


	/**
	 * @brief 카메라의 위 방향을 얻습니다.
	 *
	 * @return 카메라의 위 방향을 반환합니다.
	 */
	const Vec3f& GetUpDirection() const { return upDirection_; }


	/**
	 * @brief 하향식 보기 필드 각도(라디안) 값을 얻습니다.
	 *
	 * @return 하향식 보기 필드 각도(라디안) 값을 반환합니다.
	 */
	const float& GetFov() const { return fov_; }


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율 값을 얻습니다.
	 *
	 * @return 뷰 공간 X:Y의 가로 세로 비율 값을 반환합니다.
	 */
	const float& GetAspectRatio() const { return aspectRatio_; }


	/**
	 * @brief 가까운 클리핑 평면까지의 거리 값을 얻습니다.
	 *
	 * @return 가까운 클리핑 평면까지의 거리 값을 반환합니다.
	 */
	const float& GetNearZ() const { return nearZ_; }


	/**
	 * @brief 원거리 클리핑 평면까지의 거리 값을 얻습니다.
	 *
	 * @return 원거리 클리핑 평면까지의 거리 값을 반환합니다.
	 */
	const float& GetFarZ() const { return farZ_; }


	/**
	 * @brief 시야 행렬을 얻습니다.
	 *
	 * @return 시야 행렬을 반환합니다.
	 */
	const Mat4x4& GetViewMatrix() const { return view_; }


	/**
	 * @brief 투영 행렬을 얻습니다.
	 *
	 * @return 투영 행렬을 반환합니다.
	 */
	const Mat4x4& GetProjectionMatrix() const { return projection_; }


	/**
	 * @brief 카메라의 월드 상 위치를 설정합니다.
	 *
	 * @param eyePosition 설정할 카메라의 월드 상 위치입니다.
	 */
	void SetEyePosition(const Vec3f& eyePosition)
	{
		eyePosition_ = eyePosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief 카메라가 바라보고 있는 위치를 설정합니다.
	 *
	 * @param eyeDirection 설정할 카메라가 바라보고 있는 위치입니다.
	 */
	void SetEyeDirection(const Vec3f& eyeDirection)
	{
		eyeDirection_ = eyeDirection;
		UpdateViewMatrix();
	}


	/**
	 * @brief 카메라의 위 방향을 설정합니다.
	 *
	 * @param upDirection 설정할 카메라의 위 방향입니다.
	 */
	void SetUpDirection(const Vec3f& upDirection)
	{
		upDirection_ = upDirection;
		UpdateViewMatrix();
	}


	/**
	 * @brief 하향식 보기 필드 각도(라디안)를 설정합니다.
	 *
	 * @param fovRadians 설정할 필드 각도(라디안) 입니다.
	 */
	void SetFov(float fov)
	{
		fov_ = fov;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율을 설정합니다.
	 *
	 * @param aspectRatio 설정할 뷰 공간의 가로 세로 비율입니다.
	 */
	void SetAspectRatio(float aspectRatio)
	{
		aspectRatio_ = aspectRatio;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 가까운 클리핑 평면까지의 거리를 설정합니다.
	 *
	 * @param nearZ 설정할 가까운 클리핑 평면까지의 거리입니다.
	 */
	void SetNearZ(float nearZ)
	{
		nearZ_ = nearZ;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 원거리 클리핑 평면까지의 거리를 설정합니다.
	 *
	 * @param farZ 설정할 원거리 클리핑 평면까지의 거리입니다.
	 */
	void SetFarZ(float farZ)
	{
		farZ_ = farZ;
		UpdateProjectionMatrix();
	}


private:
	/**
	 * @brief 시야 행렬을 업데이트합니다.
	 */
	void UpdateViewMatrix();


	/**
	 * @brief 투영 행렬을 업데이트합니다.
	 */
	void UpdateProjectionMatrix();


private:
	/**
	 * @brief 카메라의 월드 상 위치입니다.
	 */
	Vec3f eyePosition_;


	/**
	 * @brief 카메라의 방향입니다.
	 */
	Vec3f eyeDirection_;


	/**
	 * @brief 카메라의 위 방향입니다.
	 */
	Vec3f upDirection_;


	/**
	 * @brief 하향식 보기 필드 각도(라디안)입니다.
	 */
	float fov_ = 0.0f;


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율입니다.
	 */
	float aspectRatio_ = 0.0f;


	/**
	 * @brief 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	float nearZ_ = 0.0f;


	/**
	 * @brief 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	float farZ_ = 0.0f;


	/**
	 * @brief 뷰 행렬입니다.
	 */
	Mat4x4 view_;


	/**
	 * @brief 투영 행렬입니다.
	 *
	 * @note 직교 투영행렬이 아닌 원근 투영 행렬입니다.
	 */
	Mat4x4 projection_;
};