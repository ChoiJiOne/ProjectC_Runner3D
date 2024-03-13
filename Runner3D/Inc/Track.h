#pragma once

#include <vector>

#include "Macro.h"

#include "Vec3.h"
#include "Quat.h"


/**
 * @brief ���� ������ ��Ÿ���� �������Դϴ�.
 * 
 * @see https://gabormakesgames.com/blog_animation_pose.html
 */
enum class EInterpolation
{
	Constant = 0x01,
	Linear   = 0x02,
	Cubic    = 0x03,
};


/**
 * @brief �������� �������Դϴ�.
 * 
 * @see https://gabormakesgames.com/blog_animation_frames.html
 */
template <uint32_t N>
struct Frame
{
	float value[N];
	float in[N];
	float out[N];
	float time[N];
};

using ScalarFrame = Frame<1>;
using VectorFrame = Frame<3>;
using QuaternionFrame = Frame<4>;


/**
 * @brief �������� ������ ������ ���� ���� ������ ������ Ʈ���Դϴ�.
 * 
 * @see https://gabormakesgames.com/blog_animation_tracks.html
 */
template<typename T, uint32_t N>
class Track
{
public:
	/**
	 * @brief Ʈ���� �������Դϴ�.
	 */
	explicit Track();


	/**
	 * @brief Ʈ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Track();


	/**
	 * @brief Ʈ���� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Track);


	/**
	 * @brief Ʈ���� ������ ũ�⸦ �����մϴ�.
	 * 
	 * @param size ������ Ʈ���� ������ ũ���Դϴ�.
	 */
	void ResizeFrame(uint32_t size);


	/**
	 * @brief Ʈ���� ������ ũ�⸦ ����ϴ�.
	 * 
	 * @return Ʈ���� ������ ũ�⸦ ��ȯ�մϴ�.
	 */
	uint32_t GetFrameSize() const { return static_cast<uint32_t>(frames_.size()); }


	/**
	 * @brief Ʈ���� ���� ����� ���� ������ ���� ����ϴ�.
	 * 
	 * @return Ʈ���� ���� ����� ���� ������ ���� ��ȯ�մϴ�.
	 */
	const EInterpolation& GetInterpolation() const { return interpolation_; }


	/**
	 * @brief Ʈ���� ���� ����� ���� ������ ���� �����մϴ�.
	 * 
	 * @param interpolation ������ Ʈ���� ���� ����� ���� �������Դϴ�.
	 */
	void SetInterpolation(const EInterpolation& interpolation) { interpolation_ = interpolation; }


	/**
	 * @brief �������� �ð� �ð� ���� ����ϴ�.
	 * 
	 * @return �������� ���� �ð� ���� ��ȯ�մϴ�.
	 */
	float GetStartTime() const;


	/**
	 * @brief �������� ������ �ð� ���� ����ϴ�.
	 * 
	 * @return �������� ������ �ð� ���� ��ȯ�մϴ�.
	 */
	float GetEndTime() const;


	/**
	 * @brief ������ ���ø��� �����մϴ�.
	 * 
	 * @param time ���ø��� �ð� ���Դϴ�.
	 * @param bIsLooping �ݺ� �����Դϴ�.
	 * 
	 * @return ���ø��� ���� ��ȯ�մϴ�.
	 */
	T Sample(float time, bool bIsLooping);


	/**
	 * @brief Ʈ���� ������ ���� ����ϴ�.
	 * 
	 * @param index ������ ����� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� �������� �����ڸ� ��ȯ�մϴ�.
	 */
	Frame<N>& operator[](uint32_t index);


private:
	/**
	 * @brief ��� ���ø��� �����մϴ�.
	 * 
	 * @param time ���ø��� �ð� ���Դϴ�.
	 * @param bIsLooping �ݺ� �����Դϴ�.
	 *
	 * @return ���ø��� ���� ��ȯ�մϴ�.
	 */
	T SampleConstant(float time, bool bIsLooping);


	/**
	 * @brief ����(Linear) ���ø��� �����մϴ�.
	 * 
	 * @param time ���ø��� �ð� ���Դϴ�.
	 * @param bIsLooping �ݺ� �����Դϴ�.
	 *
	 * @return ���ø��� ���� ��ȯ�մϴ�.
	 */
	T SampleLinear(float time, bool bIsLooping);


	/**
	 * @brief ť�긯(Cubic, 3��) ���ø��� �����մϴ�.
	 * 
	 * @param time ���ø��� �ð� ���Դϴ�.
	 * @param bIsLooping �ݺ� �����Դϴ�.
	 *
	 * @return ���ø��� ���� ��ȯ�մϴ�.
	 */
	T SampleCubic(float time, bool bIsLooping);


	/**
	 * @brief �ع��� ���ö��� � ���� ����մϴ�.
	 * 
	 * @param time
	 * @param point1
	 * @param slope1
	 * @param point2
	 * @param slope2
	 * 
	 * @return 
	 */
	T Hermite(float time, const T& point1, const T& slope1, const T& point2, const T& slope2);


	/**
	 * @brief �ð� ���� �����ϴ� ������ �ε��� ���� ����ϴ�.
	 * 
	 * @param time ������ �ε��� ���� ���� �ð� ���Դϴ�.
	 * @param bIsLooping �ݺ� �����Դϴ�.
	 * 
	 * @return �ð� ���� �����ϴ� ������ �ε��� ���� ��ȯ�մϴ�.
	 */
	int GetFrameIndex(float time, bool bIsLooping);



	//float AdjustTimeToFitTrack(float time, bool looping);
	//T Cast(float* value);

private:
	/**
	 * @brief Ʈ���� ������ �����Դϴ�.
	 */
	std::vector<Frame<N>> frames_;


	/**
	 * @brief Ʈ���� ���� ����Դϴ�.
	 */
	EInterpolation interpolation_ = EInterpolation::Linear;
};

using ScalarTrack = Track<float, 1>;
using VectorTrack = Track<Vec3f, 3>;
using QuaternionTrack = Track<Quat, 4>;