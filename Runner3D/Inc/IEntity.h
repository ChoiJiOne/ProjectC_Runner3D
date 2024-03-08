#pragma once

#include <cstdint>

#include "Macro.h"


/**
 * @brief ��ƼƼ�� ���� ���̵�(Entity Unique Identity)�Դϴ�.
 */
using EUID = int32_t;


/**
 * @brief ��ƼƼ �Ŵ��� Ŭ������ ���� �����Դϴ�.
 */
class EntityManager;


/**
 * @brief ��ƼƼ �������̽��Դϴ�.
 */
class IEntity
{
public:
	/**
	 * @brief ��ƼƼ �������̽��� ����Ʈ �������Դϴ�.
	 */
	IEntity() = default;


	/**
	 * @brief ��ƼƼ �������̽��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~IEntity() {}


	/**
	 * @brief ��ƼƼ �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IEntity);


	/**
	 * @brief ��ƼƼ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 * 
	 * @note 
	 * - ��ƼƼ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 * - ��Ÿ �ð� ���� �ʴ����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) = 0;


	/**
	 * @brief ��ƼƼ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() = 0;


	/**
	 * @brief ��ƼƼ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 *
	 * @note ��ƼƼ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Release() = 0;


	/**
	 * @brief ��ƼƼ�� �ʱ�ȭ�� ���� �ִ��� Ȯ���մϴ�.
	 *
	 * @return ��ƼƼ�� �ʱ�ȭ�� ���� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsInitialized() const { return bIsInitialized_; }


	/**
	 * @brief ��ƼƼ�� ID ���� ����ϴ�.
	 * 
	 * @return ��ƼƼ�� ID ���� ��ȯ�մϴ�.
	 */
	const EUID& GetID() const { return id_; }


private:
	/**
	 * @brief ��ƼƼ �Ŵ����� ��ƼƼ �������̽��� ������ �� �ֵ��� �����մϴ�.
	 */
	friend EntityManager;


	/**
	 * @brief ��ƼƼ�� ID ���� �����մϴ�.
	 * 
	 * @param id ������ ��ƼƼ�� ID ���Դϴ�.
	 * 
	 * @note �� ����� EntityManager������ ����ϴ� ����Դϴ�.
	 */
	void SetID(const EUID& id) { id_ = id; }


	/**
	 * @brief ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID id_ = -1;


protected:
	/**
	 * @brief ��ƼƼ�� �ʱ�ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;
};