#pragma once

#include <vector>

#include "Clip.h"
#include "Pose.h"
#include "Skeleton.h"


/**
 * @brief �ִϸ��̼� ������ ���� ũ�ν� ���̵� ��Ʈ�ѷ��Դϴ�.
 */
class CrossFadeContoller
{
public:
	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� �������Դϴ�.
	 *
	 * @param skeleton ��Ʈ�ѷ��� ����� �Ǵ� �����Դϴ�.
	 */
	explicit CrossFadeContoller(Skeleton&& skeleton)
		: skeleton_(skeleton)
		, clip_(nullptr)
		, time_(0.0f) {}


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� �������Դϴ�.
	 * 
	 * @param skeleton ��Ʈ�ѷ��� ����� �Ǵ� �����Դϴ�.
	 */
	explicit CrossFadeContoller(const Skeleton& skeleton)
		: skeleton_(skeleton)
		, clip_(nullptr)
		, time_(0.0f) {}


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~CrossFadeContoller() {}


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(CrossFadeContoller);


	/**
	 * @brief �ִϸ��̼� �÷��̸� �����մϴ�.
	 * 
	 * @param target �ִϸ��̼��� �÷����� Ÿ�� Ŭ���Դϴ�.
	 * 
	 * @note �� �޼��带 �����ϸ� Ȱ�� ũ�ν����̵�� �����˴ϴ�.
	 */
	void Play(Clip* target);


	/**
	 * @brief ���̵� Ÿ���� ��ȿ���� Ȯ���ϰ� ��ȿ�ϸ� ���̵� Ÿ�� ��Ͽ� �߰��մϴ�.
	 * 
	 * @param target �ִϸ��̼��� �÷����� Ÿ�� Ŭ���Դϴ�.
	 * @param fadeSeconds �ʴ��� ���̵� �ð� ���Դϴ�.
	 */
	void FadeTo(Clip* target, float fadeSeconds);


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� ������Ʈ�մϴ�.
	 * 
	 * @param deltaSeconds ������Ʈ�� �� ���� ��Ÿ �ð� ���Դϴ�.
	 */
	void Update(float deltaSeconds);


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� ���� ���� �����ڸ� ����ϴ�.
	 * 
	 * @return ũ�ν� ���̵� ��Ʈ�ѷ��� ���� ���� �����ڸ� ��ȯ�մϴ�.
	 */
	Pose& GetCurrentPose() { return pose_; }


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� ���� Ŭ���� ����ϴ�.
	 * 
	 * @return ũ�ν� ���̵� ��Ʈ�ѷ��� ���� Ŭ���� ��ȯ�մϴ�.
	 */
	Clip* GetCurrentClip() { return clip_; }


	/**
	 * @brief ũ�ν� ���̵� ��Ʈ�ѷ��� ���븦 ����ϴ�.
	 * 
	 * @return ũ�ν� ���̵� ��Ʈ�ѷ��� ���븦 ��ȯ�մϴ�.
	 */
	Skeleton& GetSkeleton() { return skeleton_; }


private:
	/**
	 * @brief ũ�ν� ���̵� Ÿ���Դϴ�.
	 */
	struct CrossFadeTarget
	{
		Pose pose;
		Clip* clip;
		float time;
		float duration;
		float elapsed;
	};


private:
	/**
	 * @brief ��Ʈ�ѷ��� Ÿ�� ����Դϴ�.
	 */
	std::vector<CrossFadeTarget> targets_;


	/**
	 * @brief ��Ʈ�ѷ��� �ִϸ��̼� Ŭ���Դϴ�.
	 */
	Clip* clip_ = nullptr;


	/**
	 * @brief Ÿ���� �ִϸ��̼� �ð��Դϴ�.
	 */
	float time_ = 0.0f;


	/**
	 * @brief ��Ʈ�ѷ��� �ִϸ��̼� �����Դϴ�.
	 */
	Pose pose_;


	/**
	 * @brief ��Ʈ�ѷ��� ������� ��� �����Դϴ�.
	 */
	Skeleton skeleton_;
};