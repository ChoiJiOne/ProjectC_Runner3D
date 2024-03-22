#pragma once

#include "Shader.h"

class Skybox;


/**
 * @brief ��ī�� �ڽ� �������� �����մϴ�.
 */
class SkyboxPass : public Shader
{
public:
	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� �������Դϴ�.
	 */
	SkyboxPass();


	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SkyboxPass();


	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SkyboxPass);


	/**
	 * @brief ���̴� ���ο��� �Ҵ�� ���ҽ��� �Ҵ��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ��ī�� �ڽ� �׸��⸦ �����մϴ�.
	 *
	 * @param view ���ε��� ������ ���ۿ� �׸� �� ������ �þ� ����Դϴ�.
	 * @param projection ���ε��� ������ ���ۿ� �׸� �� ������ ���� ����Դϴ�.
	 * @param skybox ���ε��� ������ ���ۿ� �׸� ��ī�� �ڽ��Դϴ�.
	 */
	void DrawSkybox(const Mat4x4& view, const Mat4x4& projection, const Skybox* skybox);


private:
	/**
	 * @brief ��ī�� �ڽ��� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;


	/**
	 * @brief ��ī�� �ڽ��� ���� ���� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ��ī�� �ڽ� ������ ���Դϴ�.
	 */
	uint32_t vertexCount_ = 0;
};