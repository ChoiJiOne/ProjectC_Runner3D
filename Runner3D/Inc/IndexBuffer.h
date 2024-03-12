#pragma once

#include <vector>

#include "Macro.h"


/**
 * @brief 정점의 인덱스 버퍼입니다.
 */
class IndexBuffer
{
public:
	/**
	 * @brief 정점 인덱스 버퍼의 기본 생성자입니다.
	 */
	explicit IndexBuffer();


	/**
	 * @brief 정점 인덱스 버퍼의 가상 소멸자입니다.
	 */
	virtual ~IndexBuffer();


	/**
	 * @brief 정점 인덱스 버퍼의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IndexBuffer);


	/**
	 * @brief 인덱스 버퍼의 ID 값을 얻습니다.
	 *
	 * @return 인덱스 버퍼의 ID 값을 반환합니다.
	 */
	uint32_t GetBufferID() { return bufferID_; }


	/**
	 * @brief 인덱스 버퍼의 원소 수를 얻습니다.
	 *
	 * @return 인덱스 버퍼의 원소 수를 반환합니다.
	 */
	uint32_t GetBufferCount() { return bufferCount_; }


	/**
	 * @brief 정점 인덱스 버퍼을 설정합니다.
	 *
	 * @param bufferPtr 정점 버퍼의 포인터입니다.
	 * @param bufferCount 정점 버퍼의 크기입니다.
	 */
	void Set(const uint32_t* bufferPtr, uint32_t bufferCount);


	/**
	 * @brief 정점 인덱스 버퍼을 설정합니다.
	 *
	 * @param buffer 정점 버퍼입니다.
	 */
	void Set(const std::vector<uint32_t>& buffer);


	/**
	 * @brief 정점 인덱스 버퍼을 바인딩합니다.
	 */
	void Bind() const;


	/**
	 * @brief 정점 인덱스 버퍼 바인딩을 해제합니다.
	 */
	void Unbind() const;


private:
	/**
	 * @brief 인덱스 버퍼의 ID값입니다.
	 */
	uint32_t bufferID_ = 0;


	/**
	 * @brief 인덱스의 수입니다.
	 */
	uint32_t bufferCount_ = 0;
};