#pragma once

#include <array>
#include <cstdint>
#include <memory>

#include "IManager.h"
#include "IResource.h"


/**
 * @brief ���ҽ� ������ �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class ResourceManager : public IManager
{
public:
	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ResourceManager);


	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return ���ҽ� ������ �����ϴ� �Ŵ����� �����ڸ� ��ȯ�մϴ�.
	 */
	static ResourceManager& Get();


	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note �� �޼���� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Startup() override;


	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - ���ø����̼� ���� ���� �� �޼��带 �ݵ�� ȣ���Ͽ� ���� ���ҽ��� �����ؾ� �մϴ�.
	 * - �� �޼���� �ݵ�� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Shutdown() override;


	/**
	 * @brief ���ҽ��� �����մϴ�.
	 * 
	 * @param args ���ҽ��� �����ڿ� ������ ���ڵ��Դϴ�.
	 *
	 * @return ������ ���ҽ��� ID�� ��ȯ�մϴ�.
	 */
	template <typename TResource, typename... Args>
	RUID CreateID(Args&&... args)
	{
		CHECK(0 <= cacheSize_ && cacheSize_ < MAX_RESOURCE_SIZE);

		RUID resourceID = -1;
		for (int32_t index = 0; index < cacheSize_; ++index)
		{
			if (!cache_[index])
			{
				resourceID = static_cast<RUID>(index);
				break;
			}
		}

		if (resourceID == -1)
		{
			resourceID = cacheSize_++;
		}
		
		cache_[resourceID] = std::make_unique<TResource>(args...);
		cache_[resourceID]->SetID(resourceID);

		return resourceID;
	}


	/**
	 * @brief ���ҽ��� �����մϴ�.
	 *
	 * @param args ���ҽ��� �����ڿ� ������ ���ڵ��Դϴ�.
	 *
	 * @return ������ ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	template <typename TResource, typename... Args>
	TResource* CreateResource(Args&&... args)
	{
		CHECK(0 <= cacheSize_ && cacheSize_ < MAX_RESOURCE_SIZE);

		RUID resourceID = -1;
		for (int32_t index = 0; index < cacheSize_; ++index)
		{
			if (!cache_[index])
			{
				resourceID = static_cast<RUID>(index);
				break;
			}
		}

		if (resourceID == -1)
		{
			resourceID = cacheSize_++;
		}

		cache_[resourceID] = std::make_unique<TResource>(args...);
		cache_[resourceID]->SetID(resourceID);

		return reinterpret_cast<TResource*>(cache_[resourceID].get());
	}


	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� ����ϴ�.
	 *
	 * @param resourceID ���ҽ� ID�Դϴ�.
	 *
	 * @return ���ҽ��� �����͸� ����ϴ�.
	 */
	template <typename TResource>
	TResource* GetResource(const RUID& resourceID)
	{
		CHECK(0 <= resourceID && resourceID < cacheSize_);

		TResource* resource = reinterpret_cast<TResource*>(cache_[resourceID].get());
		CHECK(resource != nullptr);

		return resource;
	}


	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� �����մϴ�.
	 *
	 * @param resourceID ������ ���ҽ� ID�Դϴ�.
	 */
	void Destroy(const RUID& resourceID);


private:
	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ����Ʈ �����ڿ� �� ���� �Ҹ��ڸ� �����մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ResourceManager);

	
private:
	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� �ִ� ���ҽ� ���Դϴ�.
	 */
	static const uint32_t MAX_RESOURCE_SIZE = 1000;


	/**
	 * @brief ���ҽ� ĳ���� ũ���Դϴ�.
	 */
	uint32_t cacheSize_ = 0;


	/**
	 * @brief ���ҽ� �Ŵ��� ���� ���ҽ� ĳ���Դϴ�.
	 */
	std::array<std::unique_ptr<IResource>, MAX_RESOURCE_SIZE> cache_;
};