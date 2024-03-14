#pragma once

#include <string>
#include <vector>

#include "Macro.h"
#include "TransformTrack.h"
#include "Pose.h"


/**
 * @brief �ִϸ��̼� Ʈ���� ������ ��Ÿ���� Ŭ���Դϴ�.
 */
class Clip
{
public:
	/**
	 * @brief Ŭ���� �⺻ �������Դϴ�.
	 */
	explicit Clip()
		: startTime_(0.0f)
		, endTime_(0.0f)
		, bIsLooping_(true) {}


	/**
	 * @brief Ŭ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Clip() {}


	/**
	 * @brief Ŭ���� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Clip);


	/**
	 * @brief �ε����� �����ϴ� Ʈ���� ID���� ����ϴ�.
	 * 
	 * @param index Ʈ���� ID���� ���� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� Ʈ���� ID���� ��ȯ�մϴ�.
	 */
	uint32_t GetTrackID(uint32_t index);


	/**
	 * @brief �ε����� �����ϴ� Ʈ���� ID���� �����մϴ�.
	 * 
	 * @param index ������ Ʈ���� �ε����Դϴ�.
	 * @param id ������ Ʈ���� ID���Դϴ�.
	 */
	void SetTrackID(uint32_t index, uint32_t id);


	/**
	 * @brief �ִϸ��̼� Ʈ�� ������ ũ�⸦ ����ϴ�.
	 * 
	 * @return Ʈ�� ������ ũ�⸦ ��ȯ�մϴ�.
	 */
	uint32_t GetTrackSize() const { return static_cast<uint32_t>(tracks_.size()); }


	/**
	 * @brief �ð��� ���� ��� ���ø��մϴ�.
	 * 
	 * @param outPose ���ø��� ��� ������ ���Դϴ�.
	 * @param time ���ø��� �ð� ���Դϴ�.
	 * 
	 * @return ���ø��� �ð� ���� ��ȯ�մϴ�.
	 */
	float Sample(Pose& outPose, float time);


	/**
	 * @brief �ε����� �����ϴ� Ʈ������ ����ϴ�.
	 * 
	 * @param index Ʈ������ ���� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� Ʈ������ �����ڸ� ��ȯ�մϴ�.
	 */
	TransformTrack& operator[](uint32_t index);


	/**
	 * @brief ���� �ð��� �ٽ� ����մϴ�.
	 */
	void RecomputeDuration();


	/**
	 * @brief Ŭ���� �̸��� ����ϴ�.
	 * 
	 * @return Ŭ���� �̸����� ��ȯ�մϴ�.
	 */
	const std::string& GetName() const { return name_; }


	/**
	 * @brief Ŭ�� �̸��� �����մϴ�.
	 * 
	 * @param name ������ Ŭ�� �̸��Դϴ�.
	 */
	void SetName(const std::string& name) { name_ = name; }


	/**
	 * @brief ���� �ð� ���� ����ϴ�.
	 * 
	 * @return ���� �ð� ���� ��ȯ�մϴ�.
	 */
	float GetDuration() const { return endTime_ - startTime_; }


	/**
	 * @brief ���� �ð� ���� ����ϴ�.
	 * 
	 * @return ���� �ð� ���� ��ȯ�մϴ�.
	 */
	float GetStartTime() const { return startTime_; }


	/**
	 * @brief ���� �ð� ���� ����ϴ�.
	 * 
	 * @return ���� �ð� ���� ��ȯ�մϴ�.
	 */
	float GetEndTime() const { return endTime_; }


	/**
	 * @brief �ݺ� ���θ� ����ϴ�.
	 * 
	 * @return �ݺ��Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsLooping() const { return bIsLooping_; }


	/**
	 * @brief �ݺ� ���θ� �����մϴ�.
	 * 
	 * @param bIsLooping ������ �ݺ� �����Դϴ�.
	 */
	void SetLooping(bool bIsLooping) { bIsLooping_ = bIsLooping; }

	
private:
	/**
	 * @brief �ð� ���� ���� ���� �����մϴ�.
	 * 
	 * @param time ������ ������ �ð� ���Դϴ�.
	 * 
	 * @return ������ ������ �ð� ���� ��ȯ�մϴ�.
	 */
	float AdjustTimeToFitRange(float time);


private:
	/**
	 * @brief �ִϸ��̼� Ʈ�� �����Դϴ�.
	 */
	std::vector<TransformTrack> tracks_;


	/**
	 * @brief Ŭ�� �̸��Դϴ�.
	 */
	std::string name_;


	/**
	 * @brief ���� �ð��Դϴ�.
	 */
	float startTime_ = 0.0f;


	/**
	 * @brief ���� �ð��Դϴ�.
	 */
	float endTime_ = 0.0f;


	/**
	 * @brief �ݺ� �����Դϴ�.
	 */
	bool bIsLooping_ = true;
};