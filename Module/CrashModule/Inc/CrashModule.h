#pragma once


/**
 * @brief ���ø����̼� ũ���ÿ� ���� ����� �����մϴ�.
 */
namespace CrashModule
{
	/**
	 * @brief ũ���� ����� ���� �޽����� ����ϴ�.
	 *
	 * @return ũ���� ����� C��Ÿ�� ���� �޽����� ��ȯ�մϴ�.
	 */
	const char* GetErrorMessage();


	/**
	 * @brief �ֻ��� ���� ó���⸦ ����մϴ�.
	 * 
	 * @return �ֻ��� ���� ó���� ��Ͽ� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter
	 */
	bool RegisterExceptionFilter();


	/**
	 * @brief �ֻ��� ���� ó���� ����� �����մϴ�.
	 */
	void UnregisterExceptionFilter();
}