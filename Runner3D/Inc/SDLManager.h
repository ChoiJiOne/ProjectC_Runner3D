#pragma once

#include "IManager.h"


/**
 * @brief SDL ���̺귯�� ������ �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class SDLManager : public IManager
{
public:
	/**
	 * @brief SDL ���̺귯�� ������ �����ϴ� �Ŵ����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SDLManager);


	/**
	 * @brief SDL ���̺귯�� ������ �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return SDL ���̺귯�� ������ �����ϴ� �Ŵ����� �����ڸ� ��ȯ�մϴ�.
	 */
	static SDLManager& Get();


	/**
	 * @brief SDL ���̺귯�� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note �� �޼���� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Startup() override;


	/**
	 * @brief SDL ���̺귯�� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - ���ø����̼� ���� ���� �� �޼��带 �ݵ�� ȣ���Ͽ� ���θ� �����ؾ� �մϴ�.
	 * - �� �޼���� �ݵ�� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Shutdown() override;


	/**
	 * @brief SDL ���� �������� �����͸� ����ϴ�.
	 * 
	 * @return SDL ���� �������� �����͸� ��ȯ�մϴ�.
	 */
	void* GetMainWindow() { return mainWindow_; }


private:
	/**
	 * @brief SDL ���̺귯�� ������ �����ϴ� �Ŵ����� ����Ʈ �����ڿ� �� ���� �Ҹ��ڸ� �����մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(SDLManager);


private:
	/**
	 * @brief SDL ���� �������Դϴ�.
	 */
	void* mainWindow_ = nullptr;
};