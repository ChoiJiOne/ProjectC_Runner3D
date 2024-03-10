#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"


/**
 * @brief 2D ��ġ�� ���� ������ ���� �����Դϴ�.
 */
struct VertexPositionColor2D
{
	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionColor2D() noexcept 
		: position(0.0f, 0.0f)
		, color(0.0f, 0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param p ������ ��ġ�Դϴ�.
	 * @param c ������ �����Դϴ�.
	 */
	VertexPositionColor2D(Vec2f&& p, Vec4f&& c) noexcept
		: position(p)
		, color(c) {}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param p ������ ��ġ�Դϴ�.
	 * @param c ������ �����Դϴ�.
	 */
	VertexPositionColor2D(const Vec2f& p, const Vec4f& c) noexcept
		: position(p)
		, color(c) {}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param x ��ġ�� X��ǥ�Դϴ�.
	 * @param y ��ġ�� Y��ǥ�Դϴ�.
	 * @param r ���� ������ R�Դϴ�.
	 * @param g ���� ������ G�Դϴ�.
	 * @param b ���� ������ B�Դϴ�.
	 * @param a ���� ������ A�Դϴ�.
	 */
	VertexPositionColor2D(
		float x, float y,
		float r, float g, float b, float a
	) noexcept
		: position(x, y)
		, color(r, g, b, a) {}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColor2D(VertexPositionColor2D&& instance) noexcept
		: position(instance.position)
		, color(instance.color) {}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColor2D(const VertexPositionColor2D& instance) noexcept
		: position(instance.position)
		, color(instance.color) {}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColor2D& operator=(VertexPositionColor2D&& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		color = instance.color;

		return *this;
	}


	/**
	 * @brief 2D ��ġ�� ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColor2D& operator=(const VertexPositionColor2D& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		color = instance.color;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(Stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionColor2D);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vec2f position;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	Vec4f color;
};


/**
 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� �����Դϴ�.
 */
struct VertexPositionUv2D
{
	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionUv2D() noexcept
		: position(0.0f, 0.0f)
		, uv(0.0f, 0.0f) {}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ�Դϴ�.
	 * @param tex ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	VertexPositionUv2D(Vec2f&& p, Vec2f&& tex) noexcept
		: position(p)
		, uv(tex) {}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ�Դϴ�.
	 * @param tex ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	VertexPositionUv2D(const Vec2f& p, const Vec2f& tex) noexcept
		: position(p)
		, uv(tex) {}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ �������Դϴ�.
	 *
	 * @param x ��ġ�� X��ǥ�Դϴ�.
	 * @param y ��ġ�� Y��ǥ�Դϴ�.
	 * @param u �ؽ�ó ��ġ�� U��ǥ�Դϴ�.
	 * @param v �ؽ�ó ��ġ�� V��ǥ�Դϴ�.
	 */
	VertexPositionUv2D(
		float x, float y,
		float u, float v
	) noexcept
		: position(x, y)
		, uv(u, v) {}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 */
	VertexPositionUv2D(VertexPositionUv2D&& instance) noexcept
		: position(instance.position)
		, uv(instance.uv) {}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 */
	VertexPositionUv2D(const VertexPositionUv2D& instance) noexcept
		: position(instance.position)
		, uv(instance.uv) {}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionUv2D& operator=(VertexPositionUv2D&& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		uv = instance.uv;

		return *this;
	}


	/**
	 * @brief 2D ��ġ�� �ؽ�ó ��ǥ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionUv2D& operator=(const VertexPositionUv2D& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		uv = instance.uv;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(Stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionUv2D);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vec2f position;


	/**
	 * @brief ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	Vec2f uv;
};


/**
 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� �����Դϴ�.
 */
struct VertexPositionUvColor2D
{
	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionUvColor2D() noexcept
		: position(0.0f, 0.0f)
		, uv(0.0f, 0.0f) 
		, color(0.0f, 0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param p ������ ��ġ�Դϴ�.
	 * @param tex ������ �ؽ�ó ��ǥ�Դϴ�.
	 * @param c ������ �����Դϴ�
	 */
	VertexPositionUvColor2D(Vec2f&& p, Vec2f&& tex, Vec4f&& c) noexcept
		: position(p)
		, uv(tex)
		, color(c) {}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param p ������ ��ġ�Դϴ�.
	 * @param tex ������ �ؽ�ó ��ǥ�Դϴ�.
	 * @param c ������ �����Դϴ�
	 */
	VertexPositionUvColor2D(const Vec2f& p, const Vec2f& tex, const Vec4f& c) noexcept
		: position(p)
		, uv(tex)
		, color(c) {}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param x ��ġ�� X��ǥ�Դϴ�.
	 * @param y ��ġ�� Y��ǥ�Դϴ�.
	 * @param u �ؽ�ó ��ġ�� U��ǥ�Դϴ�.
	 * @param v �ؽ�ó ��ġ�� V��ǥ�Դϴ�.
	 * @param r ���� ������ R�Դϴ�.
	 * @param g ���� ������ G�Դϴ�.
	 * @param b ���� ������ B�Դϴ�.
	 * @param a ���� ������ A�Դϴ�.
	 */
	VertexPositionUvColor2D(
		float x, float y,
		float u, float v,
		float r, float g, float b, float a
	) noexcept
		: position(x, y)
		, uv(u, v)
		, color(r, g, b, a) {}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 */
	VertexPositionUvColor2D(VertexPositionUvColor2D&& instance) noexcept
		: position(instance.position)
		, uv(instance.uv)
		, color(instance.color) {}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 */
	VertexPositionUvColor2D(const VertexPositionUvColor2D& instance) noexcept
		: position(instance.position)
		, uv(instance.uv)
		, color(instance.color) {}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionUvColor2D& operator=(VertexPositionUvColor2D&& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		uv = instance.uv;
		color = instance.color;

		return *this;
	}


	/**
	 * @brief 2D ��ġ, �ؽ�ó ��ǥ, ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionUvColor2D& operator=(const VertexPositionUvColor2D& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		uv = instance.uv;
		color = instance.color;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(Stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionUvColor2D);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vec2f position;


	/**
	 * @brief ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	Vec2f uv;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	Vec4f color;
};