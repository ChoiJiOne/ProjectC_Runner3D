#pragma once

#include <vector>

#include "Vec3.h"
#include "Quat.h"

/**
 * @brief 보간 종류를 나타내는 열거형입니다.
 * 
 * @see https://gabormakesgames.com/blog_animation_pose.html
 */
enum class EInterpolation
{
	Constant = 0x00,
	Linear   = 0x01,
	Cubic    = 0x02,
};

