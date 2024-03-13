#pragma once

#include <vector>

#include "Vec3.h"
#include "Quat.h"


/**
 * @brief ���� ������ ��Ÿ���� �������Դϴ�.
 * 
 * @see https://gabormakesgames.com/blog_animation_pose.html
 */
enum class EInterpolation
{
	Constant = 0x00,
	Linear   = 0x01,
	Cubic    = 0x02,
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