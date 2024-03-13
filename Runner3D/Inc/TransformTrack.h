#pragma once

#include "Transform.h"

#include "Macro.h"
#include "Track.h"


/**
 * @brief Ʈ������ Ʈ���Դϴ�.
 * 
 * @see https://gabormakesgames.com/blog_animation_transformtracks.html
 */
class TransformTrack
{
public:
	/**
	 * @brief Ʈ������ Ʈ���� �������Դϴ�.
	 */
	explicit TransformTrack() {}


	/**
	 * @brief Ʈ������ Ʈ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~TransformTrack() {}


	/**
	 * @brief Ʈ������ Ʈ���� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(TransformTrack);


	/**
	 * @brief ���� ID ���� ����ϴ�.
	 *
	 * @return ���� ID���� ��ȯ�մϴ�.
	 */
	const uint32_t& GetBoneID() const { return boneID_; }


	/**
	 * @brief ���� ID ���� ����ϴ�.
	 * 
	 * @return ���� ID���� ��ȯ�մϴ�.
	 */
	uint32_t& GetBoneID() { return boneID_; }


	/**
	 * @brief ���� ID�� �����մϴ�.
	 * 
	 * @param boneID ������ ���� ID���Դϴ�.
	 */
	void SetBoneID(const uint32_t& boneID) { boneID_ = boneID; }


	/**
	 * @brief ��ġ Ʈ������ ����ϴ�.
	 *
	 * @return ��ġ Ʈ������ ��ȯ�մϴ�.
	 */
	const VectorTrack& GetPositionTrack() const { return position_; }


	/**
	 * @brief ��ġ Ʈ������ ����ϴ�.
	 * 
	 * @return ��ġ Ʈ������ ��ȯ�մϴ�.
	 */
	VectorTrack& GetPositionTrack() { return position_; }


	/**
	 * @brief ȸ�� Ʈ������ ����ϴ�.
	 *
	 * @return ȸ�� Ʈ������ ��ȯ�մϴ�.
	 */
	const QuaternionTrack& GetRotateTrack() const { return rotate_; }


	/**
	 * @brief ȸ�� Ʈ������ ����ϴ�.
	 * 
	 * @return ȸ�� Ʈ������ ��ȯ�մϴ�.
	 */
	QuaternionTrack& GetRotateTrack() { return rotate_; }


	/**
	 * @brief ������ Ʈ������ ����ϴ�.
	 *
	 * @return ������ Ʈ������ ��ȯ�մϴ�.
	 */
	const VectorTrack& GetScaleTrack() const { return scale_; }


	/**
	 * @brief ������ Ʈ������ ����ϴ�.
	 * 
	 * @return ������ Ʈ������ ��ȯ�մϴ�.
	 */
	VectorTrack& GetScaleTrack() { return scale_; }


	/**
	 * @brief Ʈ���� ���� �ð� ���� ����ϴ�.
	 * 
	 * @return Ʈ���� ���� �ð� ���� ��ȯ�մϴ�.
	 */
	float GetStartTime();


	/**
	 * @brief Ʈ���� ���� �ð� ���� ����ϴ�.
	 * 
	 * @return Ʈ���� ���� �ð� ���� ��ȯ�մϴ�.
	 */
	float GetEndTime();


	/**
	 * @brief Ʈ���� ��ȿ���� �˻��մϴ�.
	 * 
	 * @return Ʈ���� ���� ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsValid();


	/**
	 * @brief Ʈ���� ���ø��� �����մϴ�.
	 * 
	 * @param transform ���ø��� Ʈ�������Դϴ�.
	 * @param time ���ø��� �ð� ���Դϴ�.
	 * @param bIsLooping �ݺ� �����Դϴ�.
	 * 
	 * @return ���ø��� Ʈ�������� ��ȯ�մϴ�.
	 */
	Transform Sample(const Transform& transform, float time, bool bIsLooping);
	

private:
	/**
	 * @brief ��ȯ�� ���� ����(��) ���̵��Դϴ�.
	 */
	uint32_t boneID_ = 0;


	/**
	 * @brief ��ġ Ʈ���Դϴ�.
	 */
	VectorTrack position_;


	/**
	 * @brief ȸ�� Ʈ���Դϴ�.
	 */
	QuaternionTrack rotate_;


	/**
	 * @brief ������ Ʈ���Դϴ�.
	 */
	VectorTrack scale_;
};