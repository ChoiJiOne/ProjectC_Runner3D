#pragma once

#include <string>
#include <vector>

#include "Mat4x4.h"

#include "Pose.h"


/**
 * @brief ĳ���� ���̷���(����) �Դϴ�.
 */
class Skeleton
{
public:
	/**
	 * @brief ���̷����� �⺻ �������Դϴ�.
	 */
	Skeleton() {}


	/**
	 * @brief ���̷����� �������Դϴ�.
	 * 
	 * @param restPose ��� �����Դϴ�.
	 * @param bindPose ���ε� �����Դϴ�.
	 * @param jointNames ����Ʈ �̸� ����Դϴ�.
	 */
	Skeleton(const Pose& restPose, const Pose& bindPose, const std::vector<std::string>& jointNames)
		: restPose_(restPose)
		, bindPose_(bindPose)
		, jointNames_(jointNames)
	{
		UpdateInverseBindPose();
	}


	/**
	 * @brief ���̷����� ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������Ƽ ���縦 ������ ���̷��� �ν��Ͻ��Դϴ�.
	 */
	Skeleton(Skeleton&& instance) noexcept
		: restPose_(instance.restPose_)
		, bindPose_(instance.bindPose_)
		, invBindPose_(instance.invBindPose_)
		, jointNames_(instance.jointNames_) {}


	/**
	 * @brief ���̷����� ���� �������Դϴ�.
	 *
	 * @param instance ���� ������Ƽ ���縦 ������ ���̷��� �ν��Ͻ��Դϴ�.
	 */
	Skeleton(const Skeleton& instance) noexcept
		: restPose_(instance.restPose_)
		, bindPose_(instance.bindPose_)
		, invBindPose_(instance.invBindPose_)
		, jointNames_(instance.jointNames_) {}


	/**
	 * @brief ���̷����� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Skeleton() {}


	/**
	 * @brief ���̷����� ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������ ������ ���̷��� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ���� ������ ������ �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Skeleton& operator=(Skeleton&& instance) noexcept
	{
		if (this == &instance) return *this;

		restPose_ = instance.restPose_;
		bindPose_ = instance.bindPose_;
		invBindPose_ = instance.invBindPose_;
		jointNames_ = instance.jointNames_;

		return *this;
	}


	/**
	 * @brief ���̷����� ���� �������Դϴ�.
	 *
	 * @param instance ���� ������ ������ ���̷��� �ν��Ͻ��Դϴ�.
	 *
	 * @return ���� ������ ������ �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Skeleton& operator=(const Skeleton& instance) noexcept
	{
		if (this == &instance) return *this;

		restPose_ = instance.restPose_;
		bindPose_ = instance.bindPose_;
		invBindPose_ = instance.invBindPose_;
		jointNames_ = instance.jointNames_;

		return *this;
	}


	/**
	 * @brief ���̷��� ���� ���� ������Ƽ�� �����մϴ�.
	 * 
	 * @param restPose ��� �����Դϴ�.
	 * @param bindPose ���ε� �����Դϴ�.
	 * @param jointNames ����Ʈ �̸� ����Դϴ�.
	 */
	void SetProperties(const Pose& restPose, const Pose& bindPose, const std::vector<std::string>& jointNames);


	/**
	 * @brief ���̷����� ���ε� ��� ����ϴ�.
	 * 
	 * @return ���̷����� ���ε� ���� ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const Pose& GetBindPose() const { return bindPose_; }


	/**
	 * @brief ���̷����� ���ε� ��� ����ϴ�.
	 *
	 * @return ���̷����� ���ε� ���� �����ڸ� ��ȯ�մϴ�.
	 */
	Pose& GetBindPose() { return bindPose_; }


	/**
	 * @brief ���̷����� ��� ��� ����ϴ�.
	 *
	 * @return ���̷����� ��� ���� ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const Pose& GetRestPose() const { return restPose_; }


	/**
	 * @brief ���̷����� ��� ��� ����ϴ�.
	 *
	 * @return ���̷����� ��� ���� �����ڸ� ��ȯ�մϴ�.
	 */
	Pose& GetRestPose() { return restPose_; }


	/**
	 * @brief �� ���ε� ������ ��� ����� ����ϴ�.
	 *
	 * @return �� ���ε� ������ ��� ����� ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::vector<Mat4x4>& GetInvBindPose() const { return invBindPose_; }


	/**
	 * @brief �� ���ε� ������ ��� ����� ����ϴ�.
	 * 
	 * @return �� ���ε� ������ ��� ����� �����ڸ� ��ȯ�մϴ�.
	 */
	std::vector<Mat4x4>& GetInvBindPose() { return invBindPose_; }


	/**
	 * @brief ����Ʈ �̸� ����� ����ϴ�.
	 *
	 * @return ����Ʈ �̸� ����� ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::vector<std::string>& GetJointNames() const { return jointNames_; }


	/**
	 * @brief ����Ʈ �̸� ����� ����ϴ�.
	 * 
	 * @return ����Ʈ �̸� ����� �����ڸ� ��ȯ�մϴ�.
	 */
	std::vector<std::string>& GetJointNames() { return jointNames_; }


	/**
	 * @brief �ε����� �����ϴ� ����Ʈ �̸��� ����ϴ�.
	 *
	 * @param index ����Ʈ �̸��� ���� �ε����Դϴ�.
	 *
	 * @return �ε����� �����ϴ� ����Ʈ �̸��� ��ȯ�մϴ�.
	 */
	const std::string& GetJointName(uint32_t index) const;


	/**
	 * @brief �ε����� �����ϴ� ����Ʈ �̸��� ����ϴ�.
	 * 
	 * @param index ����Ʈ �̸��� ���� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� ����Ʈ �̸��� ��ȯ�մϴ�.
	 */
	std::string& GetJointName(uint32_t index);


private:
	/**
	 * @brief �� ���ε� ���带 ������Ʈ�մϴ�.
	 */
	void UpdateInverseBindPose();


private:
	/**
	 * @brief ������ ��� �����Դϴ�.
	 */
	Pose restPose_;


	/**
	 * @brief ������ ���ε� �����Դϴ�.
	 */
	Pose bindPose_;


	/**
	 * @brief �� ���ε� ������ ��� ����Դϴ�.
	 */
	std::vector<Mat4x4> invBindPose_;


	/**
	 * @brief ����Ʈ �̸� ����Դϴ�.
	 */
	std::vector<std::string> jointNames_;
};