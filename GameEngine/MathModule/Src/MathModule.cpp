#include <chrono>
#include <random>

#include "MathModule.h"

float MathModule::ToDegree(float radian)
{
	return (radian * 180.0f) / Pi;
}

float MathModule::ToRadian(float degree)
{
	return (degree * Pi) / 180.0f;
}

bool MathModule::NearZero(float value, float epsilon)
{
	return (std::fabsf(value) <= epsilon);
}

template <typename T>
T MathModule::Max(const T& lhs, const T& rhs)
{
	return (lhs < rhs ? rhs : lhs);
}

template<typename T>
T MathModule::Min(const T& lhs, const T& rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

float MathModule::Sin(float radian)
{
	float quotient = OneDivTwoPi * radian;
	if (radian >= 0.0f)
	{
		quotient = static_cast<float>(static_cast<int>(quotient + 0.5f));
	}
	else
	{
		quotient = static_cast<float>(static_cast<int>(quotient - 0.5f));
	}

	float y = radian - TwoPi * quotient;

	if (y > PiDiv2)
	{
		y = Pi - y;
	}
	else if (y < -PiDiv2)
	{
		y = -Pi - y;
	}

	float y2 = y * y;
	return (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;
}

float MathModule::Cos(float radian)
{
	float quotient = OneDivTwoPi * radian;
	if (radian >= 0.0f)
	{
		quotient = static_cast<float>(static_cast<int>(quotient + 0.5f));
	}
	else
	{
		quotient = static_cast<float>(static_cast<int>(quotient - 0.5f));
	}

	float y = radian - TwoPi * quotient;
	float sign = 1.0f;

	if (y > PiDiv2)
	{
		y = Pi - y;
		sign = -1.0f;
	}
	else if (y < -PiDiv2)
	{
		y = -Pi - y;
		sign = -1.0f;
	}

	float y2 = y * y;
	float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;

	return sign * p;
}

float MathModule::ASin(float value)
{
	float x = fabsf(value);
	float omx = 1.0f - x;
	if (omx < 0.0f)
	{
		omx = 0.0f;
	}

	float root = sqrtf(omx);
	float result = ((((((-0.0012624911f * x + 0.0066700901f) * x - 0.0170881256f) * x + 0.0308918810f) * x - 0.0501743046f) * x + 0.0889789874f) * x - 0.2145988016f) * x + 1.5707963050f;
	result *= root;

	if (value >= 0.0f)
	{
		return (PiDiv2 - result);
	}
	else
	{
		return (result - PiDiv2);
	}
}

float MathModule::ACos(float value)
{
	float x = fabsf(value);
	float omx = 1.0f - x;
	if (omx < 0.0f)
	{
		omx = 0.0f;
	}

	float root = sqrtf(omx);
	float result = ((((((-0.0012624911f * x + 0.0066700901f) * x - 0.0170881256f) * x + 0.0308918810f) * x - 0.0501743046f) * x + 0.0889789874f) * x - 0.2145988016f) * x + 1.5707963050f;
	result *= root;

	if (value >= 0.0f)
	{
		return result;
	}
	else
	{
		return Pi - result;
	}
}

float MathModule::Sqrt(float x)
{
	return std::sqrtf(x);
}

float MathModule::Abs(float x)
{
	return std::fabsf(x);
}

float MathModule::Fmod(float x, float y)
{
	return std::fmodf(x, y);
}

int32_t MathModule::GenerateRandomInt(int32_t minValue, int32_t maxValue)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<int32_t> distribution(Min<int32_t>(minValue, maxValue), Max<int32_t>(minValue, maxValue));

	return distribution(generator);
}

float MathModule::GenerateRandomFloat(float minValue, float maxValue)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_real_distribution<float> distribution(Min<float>(minValue, maxValue), Max<float>(minValue, maxValue));

	return distribution(generator);
}