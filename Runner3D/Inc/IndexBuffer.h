#pragma once

#include <vector>

#include "Macro.h"


/**
 * @brief ������ �ε��� �����Դϴ�.
 */
class IndexBuffer
{
public:
	/**
	 * @brief ���� �ε��� ������ �⺻ �������Դϴ�.
	 */
	explicit IndexBuffer();


	/**
	 * @brief ���� �ε��� ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~IndexBuffer();


	/**
	 * @brief ���� �ε��� ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IndexBuffer);


	/**
	 * @brief �ε��� ������ ID ���� ����ϴ�.
	 *
	 * @return �ε��� ������ ID ���� ��ȯ�մϴ�.
	 */
	uint32_t GetBufferID() { return bufferID_; }


	/**
	 * @brief �ε��� ������ ���� ���� ����ϴ�.
	 *
	 * @return �ε��� ������ ���� ���� ��ȯ�մϴ�.
	 */
	uint32_t GetBufferCount() { return bufferCount_; }


	/**
	 * @brief ���� �ε��� ������ �����մϴ�.
	 *
	 * @param bufferPtr ���� ������ �������Դϴ�.
	 * @param bufferCount ���� ������ ũ���Դϴ�.
	 */
	void Set(const uint32_t* bufferPtr, uint32_t bufferCount);


	/**
	 * @brief ���� �ε��� ������ �����մϴ�.
	 *
	 * @param buffer ���� �����Դϴ�.
	 */
	void Set(const std::vector<uint32_t>& buffer);


	/**
	 * @brief ���� �ε��� ������ ���ε��մϴ�.
	 */
	void Bind() const;


	/**
	 * @brief ���� �ε��� ���� ���ε��� �����մϴ�.
	 */
	void Unbind() const;


private:
	/**
	 * @brief �ε��� ������ ID���Դϴ�.
	 */
	uint32_t bufferID_ = 0;


	/**
	 * @brief �ε����� ���Դϴ�.
	 */
	uint32_t bufferCount_ = 0;
};