#pragma once

#include <memory>

#include <miniaudio.h>

#include "IManager.h"


/**
 * @brief ���� ���ҽ��� �����ϴ� �Ŵ����Դϴ�.
 *
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class AudioManager : public IManager
{
public:
	/**
	 * @brief ���� ���ҽ� ������ �����ϴ� �Ŵ����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioManager);


	/**
	 * @brief ���� ���ҽ� ������ �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return ���� ���ҽ� ������ �����ϴ� �Ŵ����� �����ڸ� ��ȯ�մϴ�.
	 */
	static AudioManager& Get()
	{
		static AudioManager instance;
		return instance;
	}


	/**
	 * @brief ���� ���ҽ� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note �� �޼���� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Startup() override;


	/**
	 * @brief ���� ���ҽ� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - ���ø����̼� ���� ���� �� �޼��带 �ݵ�� ȣ���Ͽ� ���� ���� ���ҽ��� �����ؾ� �մϴ�.
	 * - �� �޼���� �ݵ�� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Shutdown() override;


	/**
	 * @brief miniaudio ������ ������ ���� ����ϴ�.
	 *
	 * @return miniaudio ������ ������ ���� ����ϴ�.
	 */
	ma_engine* GetAudioEngine() { return audioEngine_.get(); }


private:
	/**
	 * @brief ���� ���ҽ� ������ �����ϴ� �Ŵ����� ����Ʈ �����ڿ� �� ���� �Ҹ��ڸ� �����մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(AudioManager);


private:
	/**
	 * @brief miniaudio �����Դϴ�.
	 */
	std::unique_ptr<ma_engine> audioEngine_ = nullptr;
};