#pragma once

#include <array>
#include <vector>
#include <cstdint>
#include <memory>

#include "IManager.h"
#include "IEntity.h"


/**
 * @brief ��ƼƼ ������ �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class EntityManager : public IManager
{
public:
	/**
	 * @brief ��ƼƼ ������ �����ϴ� �Ŵ����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(EntityManager);


	/**
	 * @brief ��ƼƼ ������ �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return ��ƼƼ ������ �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ��ȯ�մϴ�.
	 */
	static EntityManager& Get();


	/**
	 * @brief ��ƼƼ ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note �� �޼���� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Startup() override;


	/**
	 * @brief ��ƼƼ ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - ���ø����̼� ���� ���� �� �޼��带 �ݵ�� ȣ���Ͽ� ���θ� �����ؾ� �մϴ�.
	 * - �� �޼���� �ݵ�� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Shutdown() override;


	/**
	 * @brief ��ƼƼ�� �����մϴ�.
	 *
	 * @param args ��ƼƼ�� �����ڿ� ������ ���ڵ��Դϴ�.
	 *
	 * @return ������ ��ƼƼ�� ID�� ��ȯ�մϴ�.
	 */
	template <typename TEntity, typename... Args>
	EUID CreateID(Args&&... args)
	{
		CHECK(0 <= cacheSize_ && cacheSize_ < MAX_RESOURCE_SIZE);

		EUID entityID = -1;
		for (int32_t index = 0; index < cacheSize_; ++index)
		{
			if (!cache_[entityID])
			{
				entityID = static_cast<EUID>(index);
			}
		}

		if (entityID == -1)
		{
			entityID = cacheSize_++;
		}

		cache_[entityID] = std::make_unique<TEntity>(args...);
		cache_[entityID]->SetID(entityID);

		return entityID;
	}


	/**
	 * @brief ��ƼƼ�� �����մϴ�.
	 *
	 * @param args ��ƼƼ�� �����ڿ� ������ ���ڵ��Դϴ�.
	 *
	 * @return ������ ��ƼƼ�� ID�� ��ȯ�մϴ�.
	 */
	template <typename TEntity, typename... Args>
	TEntity* CreateEntity(Args&&... args)
	{
		CHECK(0 <= cacheSize_ && cacheSize_ < MAX_RESOURCE_SIZE);

		EUID entityID = -1;
		for (int32_t index = 0; index < cacheSize_; ++index)
		{
			if (!cache_[entityID])
			{
				entityID = static_cast<EUID>(index);
			}
		}

		if (entityID == -1)
		{
			entityID = cacheSize_++;
		}

		cache_[entityID] = std::make_unique<TEntity>(args...);
		cache_[entityID]->SetID(entityID);

		return reinterpret_cast<TEntity*>(cache_[entityID].get());
	}


	/**
	 * @brief ��ƼƼ �Ŵ����� �����ϴ� ��ƼƼ�� ����ϴ�.
	 *
	 * @param entityID ��ƼƼ ID�Դϴ�.
	 *
	 * @return ��ƼƼ�� �����͸� ����ϴ�.
	 */
	template <typename TEntity>
	TEntity* GetEntity(const EUID& entityID)
	{
		CHECK(0 <= entityID && entityID < cacheSize_);

		TEntity* entity = reinterpret_cast<TEntity*>(cache_[entityID].get());
		CHECK(entity != nullptr);

		return entity;
	}

	
	/**
	 * @brief ��ƼƼ�� �Ŵ����� �����ϴ� ��ƼƼ���� �����մϴ�.
	 *
	 * @param entityID ������ ��ƼƼ ID�Դϴ�.
	 */
	void Destroy(const EUID& entityID);


private:
	/**
	 * @brief ��ƼƼ ������ �����ϴ� �Ŵ����� ����Ʈ �����ڿ� �� ���� �Ҹ��ڸ� �����մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(EntityManager);


private:
	/**
	 * @brief ��ƼƼ �Ŵ����� �����ϴ� �ִ� ��ƼƼ�� ���Դϴ�.
	 */
	static const uint32_t MAX_RESOURCE_SIZE = 1000;


	/**
	 * @brief ��ƼƼ ĳ���� ũ���Դϴ�.
	 */
	uint32_t cacheSize_ = 0;


	/**
	 * @brief ��ƼƼ �Ŵ��� ���� ��ƼƼ ĳ���Դϴ�.
	 */
	std::array<std::unique_ptr<IEntity>, MAX_RESOURCE_SIZE> cache_;
};