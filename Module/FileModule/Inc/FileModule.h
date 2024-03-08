#pragma once

#include <cstdint>
#include <string>
#include <vector>


/**
 * @brief ���� �� ���丮 ���� ����� �����մϴ�.
 */
namespace FileModule
{
	/**
	 * @brief ���� ����� ���� �޽����� ����ϴ�.
	 * 
	 * @return ���� ����� C��Ÿ�� ���� �޽����� ��ȯ�մϴ�.
	 */
	const char* GetErrorMessage();


	/**
	 * @brief ������ �а� ���ۿ� �����մϴ�.
	 *
	 * @param path ������ ����Դϴ�.
	 * @param outBuffer ������ ������ ������ �����Դϴ�.
	 *
	 * @return ������ �о� ���ۿ� �����ϴ� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-readfile
	 */
	bool ReadBufferFromFile(const std::string& path, std::vector<uint8_t>& outBuffer);


	/**
	 * @brief ������ �а� ���ۿ� �����մϴ�.
	 *
	 * @param path ������ ����Դϴ�.
	 * @param outBuffer ������ ������ ������ �����Դϴ�.
	 *
	 * @return ������ �о� ���ۿ� �����ϴ� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-readfile
	 */
	bool ReadBufferFromFile(const std::wstring& path, std::vector<uint8_t>& outBuffer);


	/**
	 * @brief ���۸� ���Ͽ� ���ϴ�.
	 *
	 * @param path ���۸� �� ������ ����Դϴ�.
	 * @param buffer ���Ͽ� �� �����Դϴ�.
	 * 
	 * @return ���۸� ���Ͽ� ���� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-writefile
	 */
	bool WriteBufferToFile(const std::string& path, const std::vector<uint8_t>& buffer);


	/**
	 * @brief ���۸� ���Ͽ� ���ϴ�.
	 *
	 * @param path ���۸� �� ������ ����Դϴ�.
	 * @param buffer ���Ͽ� �� �����Դϴ�.
	 * 
	 * @return ���۸� ���Ͽ� ���� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilew
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-writefile
	 */
	bool WriteBufferToFile(const std::wstring& path, const std::vector<uint8_t>& buffer);


	/**
	 * @brief ���丮�� �����մϴ�.
	 * 
	 * @param path ���丮�� ������ ����Դϴ�.
	 * 
	 * @return ���丮 ������ �����ߴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 * 
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/winbase/nf-winbase-createdirectory
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createdirectoryw
	 */
	bool MakeDirectory(const std::string& path);


	/**
	 * @brief ���丮�� �����մϴ�.
	 *
	 * @param path ���丮�� ������ ����Դϴ�.
	 *
	 * @return ���丮 ������ �����ߴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/winbase/nf-winbase-createdirectory
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createdirectoryw
	 */
	bool MakeDirectory(const std::wstring& path);


	/**
	 * @brief ���� Ȥ�� ���丮�� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param path ��ȿ���� Ȯ���� ���� Ȥ�� ���丮 ����Դϴ�.
	 *
	 * @return ���� Ȥ�� ���丮�� ��ȿ�ϴٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsValidPath(const std::string& path);


	/**
	 * @brief ���� Ȥ�� ���丮�� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param path ��ȿ���� Ȯ���� ���� Ȥ�� ���丮 ����Դϴ�.
	 *
	 * @return ���� Ȥ�� ���丮�� ��ȿ�ϴٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsValidPath(const std::wstring& path);


	/**
	 * @brief ��ο��� �����̳� ���丮 �̸��� ������ ��θ� ����ϴ�.
	 *
	 * @param path �����̳� ���丮 ����Դϴ�.
	 *
	 * @return �����̳� ���丮 �̸��� ������ ��θ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\" �Դϴ�.
	 * - ���丮 ��ΰ� "D:\\AAA\\BBB\\CCC"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\" �Դϴ�.
	 */
	std::string GetBasePath(const std::string& path);


	/**
	 * @brief ��ο��� �����̳� ���丮 �̸��� ������ ��θ� ����ϴ�.
	 *
	 * @param path �����̳� ���丮 ����Դϴ�.
	 *
	 * @return �����̳� ���丮 �̸��� ������ ��θ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\" �Դϴ�.
	 * - ���丮 ��ΰ� "D:\\AAA\\BBB\\CCC"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\" �Դϴ�.
	 */
	std::wstring GetBasePath(const std::wstring& path);


	/**
	 * @brief ��ü �����̳� ���丮 ��ο��� ���̽� ��θ� �����մϴ�.
	 *
	 * @param path ���̽� ��θ� ������ ��ü �����̳� ���丮 ����Դϴ�.
	 *
	 * @return ���̽� ��ΰ� ������ ���� ��θ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "CCC.a" �Դϴ�.
	 * - ���丮 ��ΰ� "D:\\AAA\\BBB\\CCC"���, ��ȯ�ϴ� ���� "CCC" �Դϴ�.
	 */
	std::string RemoveBasePath(const std::string& path);


	/**
	 * @brief ��ü �����̳� ���丮 ��ο��� ���̽� ��θ� �����մϴ�.
	 *
	 * @param path ���̽� ��θ� ������ ��ü �����̳� ���丮 ����Դϴ�.
	 *
	 * @return ���̽� ��ΰ� ������ ���� ��θ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "CCC.a" �Դϴ�.
	 * - ���丮 ��ΰ� "D:\\AAA\\BBB\\CCC"���, ��ȯ�ϴ� ���� "CCC" �Դϴ�.
	 */
	std::wstring RemoveBasePath(const std::wstring& path);


	/**
	 * @brief ��ü ���� ��ο��� ���� Ȯ���ڸ� ����ϴ�.
	 *
	 * @param path ���� Ȯ���ڸ� ���� ��ü ���� ����Դϴ�.
	 *
	 * @return ��ü ���� ����� ���� Ȯ���ڸ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "a" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "a" �Դϴ�.
	 */
	std::string GetFileExtension(const std::string& path);


	/**
	 * @brief ��ü ���� ��ο��� ���� Ȯ���ڸ� ����ϴ�.
	 *
	 * @param path ���� Ȯ���ڸ� ���� ��ü ���� ����Դϴ�.
	 *
	 * @return ��ü ���� ����� ���� Ȯ���ڸ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "a" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "a" �Դϴ�.
	 */
	std::wstring GetFileExtension(const std::wstring& path);
}