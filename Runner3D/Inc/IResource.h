#pragma once

#include "Macro.h"


/**
 * @brief ���ҽ��� ���� ���̵�(Resource Unique Identity)�Դϴ�.
 */
using RUID = int32_t;


/**
 * @brief ���ҽ� �Ŵ��� Ŭ������ ���� �����Դϴ�.
 */
class ResourceManager;


/**
 * @brief ���� ���� ���ҽ� �������̽��Դϴ�.
 *
 * @note
 * - ���� ���� ���ҽ�(���̴�, �ؽ�ó, ��Ʈ, ���� ��)�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 * - �� �������̽����� ������ ������, �ʱ�ȭ�� �����ϴ�.
 * - �� �������̽��� ��ӹ޴� Ŭ������ ������ Ȥ�� �� ���� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
 */
class IResource
{
public:
	/**
	 * @brief ���ҽ� �������̽��� ����Ʈ �������Դϴ�.
	 */
	IResource() = default;


	/**
	 * @brief ���ҽ� �������̽��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���ҽ� �������̽��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~IResource() {}


	/**
	 * @brief ���ҽ� �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IResource);


	/**
	 * @brief ���ҽ� �������̽� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 *
	 * @note ���ҽ� �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Release() = 0;


	/**
	 * @brief ���ҽ��� �ʱ�ȭ�� ���� �ִ��� Ȯ���մϴ�.
	 *
	 * @return ���ҽ��� �ʱ�ȭ�� ���� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsInitialized() const { return bIsInitialized_; }


	/**
	 * @brief ���ҽ��� ID ���� ����ϴ�.
	 * 
	 * @return ���ҽ��� ID ���� ��ȯ�մϴ�.
	 */
	const RUID& GetID() const { return id_; }


private:
	/**
	 * @brief ���ҽ� �Ŵ������� ���ҽ� �������̽��� ������ �� �ֵ��� �����մϴ�.
	 */
	friend ResourceManager;


	/**
	 * @brief ���ҽ��� ID ���� �����մϴ�.
	 * 
	 * @param id ������ ���ҽ��� ID ���Դϴ�.
	 * 
	 * @note �� ����� ResourceManager������ ����ϴ� ����Դϴ�.
	 */
	void SetID(const RUID& id) { id_ = id; }

	
	/**
	 * @brief ���ҽ��� ID ���Դϴ�.
	 */
	RUID id_ = -1;


protected:
	/**
	 * @brief ���ҽ��� �ʱ�ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;
};