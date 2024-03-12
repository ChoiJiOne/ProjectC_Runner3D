#pragma once

#include <vector>

#include "Macro.h"


/**
 * @brief 정점 속성입니다.
 */
template <typename T>
class VertexAttribute
{
public:
	/**
	 * @brief 정점 속성의 기본 생성자입니다.
	 */
	explicit VertexAttribute();

	
	/**
	 * @brief 정점 속성의 가상 소멸자입니다.
	 */
	virtual ~VertexAttribute();


	/**
	 * @brief 정점 속성의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(VertexAttribute);


	/**
	 * @brief 정점 버퍼의 ID 값을 얻습니다.
	 * 
	 * @return 정점 버퍼의 ID 값을 반환합니다.
	 */
	uint32_t GetBufferID() const { return bufferID_; }


	/**
	 * @brief 정점 버퍼의 원소 수를 얻습니다.
	 * 
	 * @return 정점 버퍼의 원소 수를 반환합니다.
	 */
	uint32_t GetBufferCount() const { return bufferCount_; }


	/**
	 * @brief 정점 속성을 설정합니다.
	 * 
	 * @param bufferPtr 정점 버퍼의 포인터입니다.
	 * @param bufferCount 정점 버퍼의 크기입니다.
	 */
	void Set(const T* bufferPtr, uint32_t bufferCount);


	/**
	 * @brief 정점 속성을 설정합니다.
	 * 
	 * @param buffer 정점 버퍼입니다.
	 */
	void Set(const std::vector<T>& buffer);


	/**
	 * @brief 정점 속성을 바인딩합니다.
	 * 
	 * @param slot 바인딩할 슬롯입니다.
	 */
	void Bind(uint32_t slot);


	/**
	 * @brief 정점 속성 바인딩을 해제합니다.
	 * 
	 * @param slot 바인딩을 해제할 슬롯입니다.
	 */
	void Unbind(uint32_t slot);
	

private:
	/**
	 * @brief 정점 속성의 슬롯을 설정합니다.
	 * 
	 * @param slot 설정할 슬롯 값입니다.
	 */
	void SetAttribPointer(uint32_t slot);


private:
	/**
	 * @brief 정점 버퍼의 ID 값입니다.
	 */
	uint32_t bufferID_ = 0;


	/**
	 * @brief 정점 버퍼의 원소 수입니다.
	 */
	uint32_t bufferCount_ = 0;
};