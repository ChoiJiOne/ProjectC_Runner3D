#include "MathModule.h"

#include "Assertion.h"
#include "Track.h"

template Track<float, 1>;
template Track<Vec3f, 3>;
template Track<Quat, 4>;

template<typename T, uint32_t N>
inline Track<T, N>::Track()
{}

template<typename T, uint32_t N>
Track<T, N>::~Track()
{}

template<typename T, uint32_t N>
void Track<T, N>::ResizeFrame(uint32_t size)
{
	frames_.resize(size);
}

template<typename T, uint32_t N>
float Track<T, N>::GetStartTime() const
{
	return frames_.front().time;
	return 0.0f;
}

template<typename T, uint32_t N>
float Track<T, N>::GetEndTime() const
{
	return frames_.back().time;
}

template<typename T, uint32_t N>
T Track<T, N>::Sample(float time, bool bIsLooping)
{
	T sample;

	switch (interpolation_)
	{
	case EInterpolation::Constant:
		sample = SampleConstant(time, bIsLooping);
		break;

	case EInterpolation::Linear:
		sample = SampleLinear(time, bIsLooping);
		break;

	case EInterpolation::Cubic:
		sample = SampleCubic(time, bIsLooping);
		break;

	default:
		ASSERT(false, "undefined interpolation type");
		break;
	}

	return sample;
}

template<typename T, uint32_t N>
Frame<N>& Track<T, N>::operator[](uint32_t index)
{
	ASSERT(0 <= index && index < frames_.size());
	return frames_[index];
}

template<typename T, uint32_t N>
T Track<T, N>::SampleConstant(float time, bool bIsLooping)
{
	return T();
}

template<typename T, uint32_t N>
T Track<T, N>::SampleLinear(float time, bool bIsLooping)
{
	return T();
}

template<typename T, uint32_t N>
T Track<T, N>::SampleCubic(float time, bool bIsLooping)
{
	return T();
}

template<typename T, uint32_t N>
T Track<T, N>::Hermite(float time, const T& point1, const T& slope1, const T& point2, const T& slope2)
{
	return T();
}

template<typename T, uint32_t N>
int Track<T, N>::GetFrameIndex(float time, bool bIsLooping)
{
}
