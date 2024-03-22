#pragma once

#include <vector>
#include <string>

#include "IResource.h"


/**
 * @brief ť��� �̹��� ���ϵ��� �ε��ϰ� OpenGL ���������ο� ���ε� ������ ť��� ���ҽ��� �����մϴ�.
 */
class Skybox : public IResource
{
public:
	/**
	 * @brief ť��� �̹��� ������ �а� ��ī�� �� ���ҽ��� �����մϴ�.
	 *
	 * @param rightPath ť��� RIGHT(+X) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param leftPath ť��� LEFT(-X) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param topPath ť��� TOP(+Y) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param bottomPath ť��� BOTTOM(-Y) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param frontPath ť��� FRONT(+Z) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param backPath ť��� BACK(-Z) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 */
	Skybox(
		const std::string& rightPath,
		const std::string& leftPath,
		const std::string& topPath,
		const std::string& bottomPath,
		const std::string& frontPath,
		const std::string& backPath
	);


	/**
	 * @brief ��ī�� �ڽ��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ť��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~Skybox();


	/**
	 * @brief ��ī�� �ڽ��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Skybox);


	/**
	 * @brief ��ī�� �ڽ� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ��ī�� �ڽ��� ť����� Ȱ��ȭ�մϴ�.
	 *
	 * @param unit Ȱ��ȭ �� �ؽ�ó �����Դϴ�.
	 */
	void Active(uint32_t unit) const;


private:
	/**
	 * @brief �ȼ� �����Դϴ�.
	 */
	struct PixelBuffer
	{
		/**
		 * @brief �ȼ� ������ ���� ũ���Դϴ�.
		 */
		int32_t width = 0;


		/**
		 * @brief �ȼ� ������ ���� ũ���Դϴ�.
		 */
		int32_t height = 0;


		/**
		 * @brief �ȼ� ������ ä���Դϴ�.
		 *
		 * @note �ȼ��� ü���� 1~4 ���Դϴ�
		 */
		int32_t channels = 0;


		/**
		 * @brief �ȼ� �����Դϴ�.
		 */
		std::vector<uint8_t> buffer;
	};


	/**
	 * @brief ���Ϸκ��� �ȼ� ���۸� �н��ϴ�.
	 *
	 * @param path �ȼ� ���� ����(�̹��� ����)�� ����Դϴ�.
	 * @param outPixelBuffer �ȼ� �����Դϴ�.
	 * @param bIsVerticallyFlip �ȼ� ���۸� �������� �������� Ȯ���մϴ�. �⺻ ���� false�Դϴ�.
	 */
	static void ReadPixelBufferFromFile(const std::string& path, PixelBuffer& outPixelBuffer, bool bIsVerticallyFlip = false);


private:
	/**
	 * @brief ť��� �ؽ�ó�� ID�Դϴ�.
	 */
	uint32_t cubeMapID_ = 0;
};