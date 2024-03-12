#pragma once

#include <vector>

#include "Macro.h"


/**
 * @brief ���� �Ӽ��Դϴ�.
 */
template <typename T>
class VertexAttribute
{
public:
	/**
	 * @brief ���� �Ӽ��� �⺻ �������Դϴ�.
	 */
	explicit VertexAttribute();

	
	/**
	 * @brief ���� �Ӽ��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~VertexAttribute();


	/**
	 * @brief ���� �Ӽ��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(VertexAttribute);


	/**
	 * @brief ���� ������ ID ���� ����ϴ�.
	 * 
	 * @return ���� ������ ID ���� ��ȯ�մϴ�.
	 */
	uint32_t GetBufferID() const { return bufferID_; }


	/**
	 * @brief ���� ������ ���� ���� ����ϴ�.
	 * 
	 * @return ���� ������ ���� ���� ��ȯ�մϴ�.
	 */
	uint32_t GetBufferCount() const { return bufferCount_; }


	/**
	 * @brief ���� �Ӽ��� �����մϴ�.
	 * 
	 * @param bufferPtr ���� ������ �������Դϴ�.
	 * @param bufferCount ���� ������ ũ���Դϴ�.
	 */
	void Set(const T* bufferPtr, uint32_t bufferCount);


	/**
	 * @brief ���� �Ӽ��� �����մϴ�.
	 * 
	 * @param buffer ���� �����Դϴ�.
	 */
	void Set(const std::vector<T>& buffer);


	/**
	 * @brief ���� �Ӽ��� ���ε��մϴ�.
	 * 
	 * @param slot ���ε��� �����Դϴ�.
	 */
	void Bind(uint32_t slot);


	/**
	 * @brief ���� �Ӽ� ���ε��� �����մϴ�.
	 * 
	 * @param slot ���ε��� ������ �����Դϴ�.
	 */
	void Unbind(uint32_t slot);
	

private:
	/**
	 * @brief ���� �Ӽ��� ������ �����մϴ�.
	 * 
	 * @param slot ������ ���� ���Դϴ�.
	 */
	void SetAttribPointer(uint32_t slot);


private:
	/**
	 * @brief ���� ������ ID ���Դϴ�.
	 */
	uint32_t bufferID_ = 0;


	/**
	 * @brief ���� ������ ���� ���Դϴ�.
	 */
	uint32_t bufferCount_ = 0;
};