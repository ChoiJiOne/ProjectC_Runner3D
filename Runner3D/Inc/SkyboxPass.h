#pragma once

#include "Shader.h"

class Skybox;


/**
 * @brief 스카이 박스 렌더링을 수행합니다.
 */
class SkyboxPass : public Shader
{
public:
	/**
	 * @brief 스카이 박스 렌더링을 수행하는 셰이더의 생성자입니다.
	 */
	SkyboxPass();


	/**
	 * @brief 스카이 박스 렌더링을 수행하는 셰이더의 가상 소멸자입니다.
	 */
	virtual ~SkyboxPass();


	/**
	 * @brief 스카이 박스 렌더링을 수행하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(SkyboxPass);


	/**
	 * @brief 셰이더 내부에서 할당된 리소스의 할당을 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 스카이 박스 그리기를 수행합니다.
	 *
	 * @param view 바인딩된 프레임 버퍼에 그릴 시 참조할 시야 행렬입니다.
	 * @param projection 바인딩된 프레임 버퍼에 그릴 시 참조할 투영 행렬입니다.
	 * @param skybox 바인딩된 프레임 버퍼에 그릴 스카이 박스입니다.
	 */
	void DrawSkybox(const Mat4x4& view, const Mat4x4& projection, const Skybox* skybox);


private:
	/**
	 * @brief 스카이 박스의 정점 목록의 오브젝트입니다.
	 */
	uint32_t vertexArrayObject_ = 0;


	/**
	 * @brief 스카이 박스의 정점 버퍼 오브젝트입니다.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief 스카이 박스 정점의 수입니다.
	 */
	uint32_t vertexCount_ = 0;
};