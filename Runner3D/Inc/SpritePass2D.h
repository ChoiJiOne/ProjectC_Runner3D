#pragma once

#include <array>

#include "Shader.h"
#include "Vertex2D.h"

class Texture2D;


/**
 * @brief 2D ��������Ʈ�� �������ϴ� ���̴��Դϴ�.
 *
 * @note
 * - 2D ��������Ʈ ������ �� ������ �Ǵ� ��ǥ��� ������ ��ǥ���Դϴ�.
 * - ��ġ�� ũ�� ���� ���ڸ� ���� �ʰ� �������ϴ� �޼���� ������ ȭ�� ��ü�� �������� �մϴ�.
 */
class SpritePass2D : public Shader
{
public:
	/**
	 * @brief 2D ��������Ʈ�� �������ϴ� ���̴��� �������Դϴ�.
	 */
	explicit SpritePass2D();


	/**
	 * @brief 2D ��������Ʈ�� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~SpritePass2D();


	/**
	 * @brief 2D ��������Ʈ�� �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpritePass2D);


	/**
	 * @brief ���̴��� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief 2D ��������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 *
	 * @param ortho ���� ���� ����Դϴ�.
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ���� ȸ�� �����Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void DrawSprite2D(const Mat4x4& ortho, const Texture2D* texture, const Vec2f& center, float width, float height, float rotate, float transparent = 1.0f);


	/**
	 * @brief 2D ��������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 *
	 * @note 2D ��������Ʈ�� ������ ��ü�� ä�������� �׸��ϴ�.
	 *
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void DrawSprite2D(const Texture2D* texture, float transparent = 1.0f);


	/**
	 * @brief ���η� ��ũ�ѵ� 2D ��������Ʈ�� �׸��ϴ�.
	 *
	 * @note
	 * - 2D ��������Ʈ�� ������ ��ü�� ä�������� �׸��ϴ�.
	 * - �ؽ�ó ���� ������ ������ �����ϴ�.
	 * ������������������������������������������������������������������
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * �� 1.0f - rate��       rate       ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ������������������������������������������������������������������
	 *
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void DrawHorizonScrollSprite2D(const Texture2D* texture, float rate, float transparent = 1.0f);


	/**
	 * @brief ���η� ��ũ�ѵ� 2D ��������Ʈ�� �׸��ϴ�.
	 *
	 * @note
	 * - �ؽ�ó ���� ������ ������ �����ϴ�.
	 * ������������������������������������������������������������������
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * �� 1.0f - rate��       rate       ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ��            ��                  ��
	 * ������������������������������������������������������������������
	 *
	 * @param ortho ���� ���� ����Դϴ�.
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ȸ�� �����Դϴ�. ������ �����Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void DrawHorizonScrollSprite2D(const Mat4x4& ortho, const Texture2D* texture, const Vec2f& center, float width, float height, float rotate, float rate, float transparent = 1.0f);


	/**
	 * @brief ���η� ��ũ�ѵ� 2D ��������Ʈ�� �׸��ϴ�.
	 *
	 * @note
	 * - 2D ��������Ʈ�� ������ ��ü�� ä�������� �׸��ϴ�.
	 * - �ؽ�ó ���� ������ ������ �����ϴ�.
	 * ��������������������������������������������������������������
	 * ��                             ��
	 * ��                             ��
	 * ��              rate           ��
	 * ��                             ��
	 * ��������������������������������������������������������������
	 * ��                             ��
	 * ��          1.0f - rate        ��
	 * ��                             ��
	 * ��������������������������������������������������������������
	 *
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void DrawVerticalScrollSprite2D(const Texture2D* texture, float rate, float transparent = 1.0f);


	/**
	 * @brief ���η� ��ũ�ѵ� 2D ��������Ʈ�� �׸��ϴ�.
	 *
	 * @note
	 * - �ؽ�ó ���� ������ ������ �����ϴ�.
	 * ��������������������������������������������������������������
	 * ��                             ��
	 * ��                             ��
	 * ��              rate           ��
	 * ��                             ��
	 * ��������������������������������������������������������������
	 * ��                             ��
	 * ��          1.0f - rate        ��
	 * ��                             ��
	 * ��������������������������������������������������������������
	 *
	 * @param ortho ���� ���� ����Դϴ�.
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ȸ�� �����Դϴ�. ������ �����Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void DrawVerticalScrollSprite2D(const Mat4x4& ortho, const Texture2D* texture, const Vec2f& center, float width, float height, float rotate, float rate, float transparent = 1.0f);


	/**
	 * @brief 2D ��������Ʈ�� �ܰ����� ȭ�鿡 �׸��ϴ�.
	 *
	 * @param ortho ���� ���� ����Դϴ�.
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ���� ȸ�� �����Դϴ�.
	 * @param outline �ؽ�ó �ܰ��� �����Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f �Դϴ�.
	 *
	 * @see https://github.com/gdquest-demos/godot-shaders/blob/master/godot/Shaders/outline2D_outer.shader
	 */
	void DrawOutlineSprite2D(const Mat4x4& ortho, const Texture2D* texture, const Vec2f& center, float width, float height, float rotate, const Vec4f& outline, float transparent = 1.0f);


private:
	/**
	 * @brief 2D �⺻ ������ �׸��� Ÿ���Դϴ�.
	 */
	enum class EDrawType : int32_t
	{
		Triangles   = 0x0004,
		TriangleFan = 0x0006,
		None        = 0xFFFF,
	};


	/**
	 * @brief ��������Ʈ �׸��⸦ �����մϴ�.
	 *
	 * @param transform ��ȯ ����Դϴ�.
	 * @param ortho ���� ����Դϴ�.
	 * @param texture �ؽ�ó ���ҽ��Դϴ�.
	 * @param vertexCount ���� ���Դϴ�.
	 * @param bIsActiveOutline �ؽ�ó�� �ܰ��� Ȱ��ȭ �����Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�.
	 * @param outline �ؽ�ó�� �ܰ��� �����Դϴ�. �⺻ ���� ����Դϴ�.
	 */
	void DrawSprite2D(const Mat4x4& transform, const Mat4x4& ortho, const EDrawType& drawType, uint32_t vertexCount, const Texture2D* texture, bool bIsActiveOutline, float transparent, const Vec4f& outline = Vec4f(1.0f, 1.0f, 1.0f, 1.0f));


private:
	/**
	 * @brief �ؽ�ó ���� ����� �ִ� ũ���Դϴ�.
	 */
	static const int32_t MAX_VERTEX_SIZE = 12;


	/**
	 * @brief �ؽ�ó�� ���� ����Դϴ�.
	 */
	std::array<VertexPositionUv2D, MAX_VERTEX_SIZE> vertices_;


	/**
	 * @brief ���� ������ ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ���� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;
};