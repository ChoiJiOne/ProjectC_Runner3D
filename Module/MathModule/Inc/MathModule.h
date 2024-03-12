#pragma once

#include <cstdint>


/**
 * ���� ���� ����� �����մϴ�.
 */
namespace MathModule
{
	/**
	 * @brief ����(��) ���Դϴ�.
	 */
	const float Pi = 3.141592654f;


	/**
	 * @brief 2����(2��) ���Դϴ�.
	 */
	const float TwoPi = 6.283185307f;


	/**
	 * @brief ����(��) �� ���� ���Դϴ�.
	 */
	const float OneDivPi = 0.318309886f;


	/**
	 * @brief 2����(2��) �� ���� ���Դϴ�.
	 */
	const float OneDivTwoPi = 0.159154943f;


	/**
	 * @brief ����(��) �� �ݰ�(��/2)�Դϴ�.
	 */
	const float PiDiv2 = 1.570796327f;


	/**
	 * @brief ����(��) �� ���� �� ��(��/4)�Դϴ�.
	 */
	const float PiDiv4 = 0.785398163f;


	/**
	 * @brief ���Ƿ�(��) ���Դϴ�.
	 */
	const float Epsilon = 1.192092896e-07F;


	/**
	 * @brief ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 *
	 * @param radian ��ȯ�� ���� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	float ToDegree(float radian);


	/**
	 * @brief ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
	 *
	 * @param degree ��ȯ�� ���ʺй� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���� ���Դϴ�.
	 */
	float ToRadian(float degree);


	/**
	 * @brief �ε� �Ҽ��� ���� 0�� ������� Ȯ���մϴ�.
	 *
	 * @param value 0�� ������� Ȯ���� ���Դϴ�.
	 * @param epsilon �� Ȯ���� ���� ���Ƿ� ���Դϴ�.
	 *
	 * @return �ε� �Ҽ��� ���� 0�� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool NearZero(float value, float epsilon = Epsilon);


	/**
	 * @brief �� ���� ū ���� ��ȯ�մϴ�.
	 *
	 * @param lhs ũ�⸦ ���� �� �� ���� ���Դϴ�.
	 * @param rhs ũ�⸦ ���� �� �� ������ ���Դϴ�.
	 *
	 * @return �� �� �� ū ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	T Max(const T& lhs, const T& rhs);


	/**
	 * @brief �� ���� ���� ���� ��ȯ�մϴ�.
	 *
	 * @param lhs ũ�⸦ ���� �� �� ���� ���Դϴ�.
	 * @param rhs ũ�⸦ ���� �� �� ������ ���Դϴ�.
	 *
	 * @return �� �� �� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	T Min(const T& lhs, const T& rhs);


	/**
	 * @brief ���� ������ �����ϴ� ���� ���� ����ϴ�.
	 * 
	 * @param radian ���� ���� ���� ���� �����Դϴ�.
	 * 
	 * @return ���� ������ �����ϴ� ���ΰ��� ��ȯ�մϴ�.
	 * 
	 * @note
	 * - DirectXMath�� XMScalarSin ����
	 * - �˰����� 11���� �̴ϸƽ�(Minimax) �ٻ�ġ(1th-degree Minimax approximation) ���
	 * - https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91
	 */
	float Sin(float radian);


	/**
	 * @brief ���� ������ �����ϴ� �ڻ��� ���� ��ȯ�մϴ�.
	 *
	 * @param radian �ڻ��� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ������ �����ϴ� �ڻ��ΰ��� ��ȯ�մϴ�.
	 *
	 * @note
	 * - DirectXMath�� XMScalarCos ����
	 * - �˰����� 10���� �̴ϸƽ�(Minimax) �ٻ�ġ(1th-degree Minimax approximation) ���
	 * - https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91
	 */
	float Cos(float radian);


	/**
	 * @brief �ε� �Ҽ��� ������ ��ũ ������ ����մϴ�.
	 * 
	 * @param value -1.0 ���� 1.0 ������ ���Դϴ�.
	 * 
	 * @return �Է��� ���� ��ũ ����(�� ����) ���� ��ȯ�մϴ�.
	 * 
	 * @note
	 * - DirectXMath�� XMScalarASin ����
	 * - �˰����� 7���� �̴ϸƽ�(Minimax) �ٻ�ġ(1th-degree Minimax approximation) ���
	 * - https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91
	 */
	float ASin(float value);


	/**
	 * @brief �ε� �Ҽ��� ������ ��ũ �ڻ����� ����մϴ�.
	 *
	 * @param value -1.0 ���� 1.0 ������ ���Դϴ�.
	 *
	 * @return �Է��� ���� �ھ�ũ ����(�� ����) ���� ��ȯ�մϴ�.
	 *
	 * @note
	 * - DirectXMath�� XMScalarACos ����
	 * - �˰����� 7���� �̴ϸƽ�(Minimax) �ٻ�ġ(1th-degree Minimax approximation) ���
	 * - https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91
	 */
	float ACos(float value);


	/**
	 * @brief �������� ����մϴ�.
	 *
	 * @param x �������� ����� �ε��Ҽ������Դϴ�.
	 *
	 * @return ������ ���� ��ȯ�մϴ�.
	 */
	float Sqrt(float x);


	/**
	 * @brief ������ ����մϴ�.
	 *
	 * @param x ������ ����� �ε��Ҽ������Դϴ�.
	 *
	 * @return ���밪�� ��ȯ�մϴ�.
	 */
	float Abs(float x);


	/**
	 * @brief ���� [lower, upper] ������ �ڸ��ϴ�.
	 *
	 * @param value ������ �ڸ� ���Դϴ�.
	 * @param lower ������ �ּҰ��Դϴ�.
	 * @param upper ������ �ִ밪�Դϴ�.
	 *
	 * @return ������ �߷� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T Clamp(const T& value, const T& lower, const T& upper)
	{
		return Min<T>(upper, Max<T>(lower, value));
	}
	

	/**
	 * @brief ������ ������ �����մϴ�.
	 *
	 * @param minValue ������ ���� ������ �ּڰ��Դϴ�.
	 * @param maxValue ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return ������ ������ ������ ��ȯ�մϴ�.
	 */
	int32_t GenerateRandomInt(int32_t minValue, int32_t maxValue);


	/**
	 * @brief ������ �Ǽ��� �����մϴ�.
	 *
	 * @param minValue ������ ���� ������ �ּڰ��Դϴ�.
	 * @param maxValue ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return ������ ������ �Ǽ��� ��ȯ�մϴ�.
	 */
	float GenerateRandomFloat(float minValue, float maxValue);
}