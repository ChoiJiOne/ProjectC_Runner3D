#pragma once

#include <vector>

#include "Macro.h"

#include "Vec3.h"
#include "Quat.h"


/**
 * @brief 보간 종류를 나타내는 열거형입니다.
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
 * @brief 데이터의 프레임입니다.
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
 * @brief 프레임의 모음과 보간할 지에 대한 정보를 포함한 트랙입니다.
 * 
 * @see https://gabormakesgames.com/blog_animation_tracks.html
 */
template<typename T, uint32_t N>
class Track
{
public:
	/**
	 * @brief 트랙의 생성자입니다.
	 */
	explicit Track();


	/**
	 * @brief 트랙의 가상 소멸자입니다.
	 */
	virtual ~Track();


	/**
	 * @brief 트랙의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Track);


	/**
	 * @brief 트랙의 프레임 크기를 변경합니다.
	 * 
	 * @param size 변경할 트랙의 프레임 크기입니다.
	 */
	void ResizeFrame(uint32_t size);


	/**
	 * @brief 트랙의 프레임 크기를 얻습니다.
	 * 
	 * @return 트랙의 프레임 크기를 반환합니다.
	 */
	uint32_t GetFrameSize() const { return static_cast<uint32_t>(frames_.size()); }


	/**
	 * @brief 트랙의 보간 방법에 대한 열거형 값을 얻습니다.
	 * 
	 * @return 트랙의 보간 방법에 대한 열거형 값을 반환합니다.
	 */
	const EInterpolation& GetInterpolation() const { return interpolation_; }


	/**
	 * @brief 트랙의 보간 방법에 대한 열거형 값을 설정합니다.
	 * 
	 * @param interpolation 설정할 트랙의 보간 방법에 대한 열거형입니다.
	 */
	void SetInterpolation(const EInterpolation& interpolation) { interpolation_ = interpolation; }


	/**
	 * @brief 프레임의 시간 시간 값을 얻습니다.
	 * 
	 * @return 프레임의 시작 시간 값을 반환합니다.
	 */
	float GetStartTime() const;


	/**
	 * @brief 프레임의 마지막 시간 값을 얻습니다.
	 * 
	 * @return 프레임의 마지막 시간 값을 반환합니다.
	 */
	float GetEndTime() const;


	/**
	 * @brief 프레임 샘플링을 수행합니다.
	 * 
	 * @param time 샘플링할 시간 값입니다.
	 * @param bIsLooping 반복 여부입니다.
	 * 
	 * @return 샘플링된 값을 반환합니다.
	 */
	T Sample(float time, bool bIsLooping);


	/**
	 * @brief 트랙의 프레임 값을 얻습니다.
	 * 
	 * @param index 프레임 목록의 인덱스입니다.
	 * 
	 * @return 인덱스에 대응하는 프레임의 참조자를 반환합니다.
	 */
	Frame<N>& operator[](uint32_t index);


private:
	/**
	 * @brief 상수 샘플링을 수행합니다.
	 * 
	 * @param time 샘플링할 시간 값입니다.
	 * @param bIsLooping 반복 여부입니다.
	 *
	 * @return 샘플링된 값을 반환합니다.
	 */
	T SampleConstant(float time, bool bIsLooping);


	/**
	 * @brief 선형(Linear) 샘플링을 수행합니다.
	 * 
	 * @param time 샘플링할 시간 값입니다.
	 * @param bIsLooping 반복 여부입니다.
	 *
	 * @return 샘플링된 값을 반환합니다.
	 */
	T SampleLinear(float time, bool bIsLooping);


	/**
	 * @brief 큐브릭(Cubic, 3차) 샘플링을 수행합니다.
	 * 
	 * @param time 샘플링할 시간 값입니다.
	 * @param bIsLooping 반복 여부입니다.
	 *
	 * @return 샘플링된 값을 반환합니다.
	 */
	T SampleCubic(float time, bool bIsLooping);


	/**
	 * @brief 해밀턴 스플라인 곡선 값을 계산합니다.
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
	 * @brief 시간 값에 대응하는 프레임 인덱스 값을 얻습니다.
	 * 
	 * @param time 프레임 인덱스 값을 얻을 시간 값입니다.
	 * @param bIsLooping 반복 여부입니다.
	 * 
	 * @return 시간 값에 대응하는 프레임 인덱스 값을 반환합니다.
	 */
	int GetFrameIndex(float time, bool bIsLooping);



	//float AdjustTimeToFitTrack(float time, bool looping);
	//T Cast(float* value);

private:
	/**
	 * @brief 트랙의 프레임 모음입니다.
	 */
	std::vector<Frame<N>> frames_;


	/**
	 * @brief 트랙의 보간 방법입니다.
	 */
	EInterpolation interpolation_ = EInterpolation::Linear;
};

using ScalarTrack = Track<float, 1>;
using VectorTrack = Track<Vec3f, 3>;
using QuaternionTrack = Track<Quat, 4>;