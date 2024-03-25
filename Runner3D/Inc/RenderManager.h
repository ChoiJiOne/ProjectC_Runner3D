#pragma once

#include <string>
#include <vector>
#include <map>

#include "Mat4x4.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

#include "IManager.h"
#include "IResource.h"

class Shader;


/**
 * @brief �������� ���õ� ó���� �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(RenderManager);


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return ������ ó���� �����ϴ� �Ŵ����� �����ڸ� ��ȯ�մϴ�.
	 */
	static RenderManager& Get();


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - �� �޼��� ȣ�� ���� ������ ����� �Ǵ� ������ �����͸� �����ؾ� �մϴ�.
	 * - �� �޼���� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Startup() override;


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - ���ø����̼� ���� ���� �� �޼��带 �ݵ�� ȣ���Ͽ� ���� ���ҽ��� �����ؾ� �մϴ�.
	 * - �� �޼���� �ݵ�� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Shutdown() override;

	
	/**
	 * @brief ������ �������� �����մϴ�.
	 *
	 * @param red ���� ������ R ���Դϴ�.
	 * @param green ���� ������ G ���Դϴ�.
	 * @param blue ���� ������ B ���Դϴ�.
	 * @param alpha ���� ������ A ���Դϴ�.
	 * @param depth ���� ������ �ʱ�ȭ ���Դϴ�.
	 * @param stencil ���ٽ� ������ �ʱ�ȭ ���Դϴ�.
	 */
	void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief ����ۿ� ����Ʈ ���۸� �����մϴ�.
	 */
	void EndFrame();


	/**
	 * @brief �� ��Ʈ�� �����մϴ�.
	 *
	 * @param x ����Ʈ �簢���� ���� �Ʒ� �𼭸�(�ȼ�)�Դϴ�. �⺻���� (0,0)�Դϴ�.
	 * @param y ����Ʈ �簢���� ���� �Ʒ� �𼭸�(�ȼ�)�Դϴ�. �⺻���� (0,0)�Դϴ�.
	 * @param width ����Ʈ�� �ʺ��Դϴ�. OpenGL ���ؽ�Ʈ�� â�� ó�� ����Ǹ� �ʺ� �� ���� �� �ش� â�� ũ��� �����˴ϴ�.
	 * @param height ����Ʈ�� �����Դϴ�. OpenGL ���ؽ�Ʈ�� â�� ó�� ����Ǹ� �ʺ� �� ���� �� �ش� â�� ũ��� �����˴ϴ�.
	 */
	void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height);


	/**
	 * @brief ������ ����Ʈ�� �����մϴ�.
	 *
	 * @note ������ ���� Ÿ�� ������ �����Դϴ�.
	 */
	void SetWindowViewport();


	/**
	 * @brief ���� ����ȭ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���� ����ȭ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	void SetVsyncMode(bool bIsEnable);


	/**
	 * @brief ���� �׽�Ʈ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���� �׽�Ʈ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	void SetDepthMode(bool bIsEnable);


	/**
	 * @brief ���ٽ� �׽�Ʈ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���ٽ� �׽�Ʈ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	void SetStencilMode(bool bIsEnable);


	/**
	 * @brief ���� ���� �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���� ���� �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	void SetAlphaBlendMode(bool bIsEnable);


	/**
	 * @brief ��Ƽ ���ø� �ɼ��� �����մϴ�.
	 * 
	 * @param bIsEnable ��Ƽ ���ø� �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	void SetMultisampleMode(bool bIsEnable);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ������ �׸��ϴ�.
	 * 
	 * @param positions 2D �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 * @param pointSize ���� ũ���Դϴ�. �⺻ ���� 1.0f�Դϴ�.
	 *
	 * @note 2D ������ ������ MAX_VERTEX_SIZE(10000)�� ũ�⸦ ���� �� �����ϴ�.
	 */
	void RenderPoints2D(const std::vector<Vec2f>& positions, const Vec4f& color, float pointSize = 1.0f);


	/**
	 * @brief ���ε��� ������ ���ۿ� ������ ������ 2D ���� �׸��ϴ�.
	 * 
	 * @param positions 2D �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 *
	 * @note 2D ������ ������ MAX_VERTEX_SIZE(10000)�� ũ�⸦ ���� �� �����ϴ�.
	 */
	void RenderConnectPoints2D(const std::vector<Vec2f>& positions, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���� �׸��ϴ�.
	 * 
	 * @param fromPosition ���� �������Դϴ�.
	 * @param toPosition ���� �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 */
	void RenderLine2D(const Vec2f& fromPosition, const Vec2f& toPosition, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���� �׸��ϴ�.
	 * 
	 * @param fromPosition ���� �������Դϴ�.
	 * @param fromColor ���� ������ �����Դϴ�.
	 * @param toPosition ���� �����Դϴ�.
	 * @param toColor ���� ���� �����Դϴ�.
	 */
	void RenderLine2D(const Vec2f& fromPosition, const Vec4f& fromColor, const Vec2f& toPosition, const Vec4f& toColor);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D �ﰢ���� �׸��ϴ�.
	 * 
	 * @param fromPosition �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition �ﰢ�� �� ���Դϴ�.
	 * @param color �ﰢ���� �����Դϴ�.
	 */
	void RenderTriangle2D(const Vec2f& fromPosition, const Vec2f& byPosition, const Vec2f& toPosition, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D �ﰢ���� �׸��ϴ�.
	 * 
	 * @param fromPosition �ﰢ�� ���� ���Դϴ�.
	 * @param fromColor �ﰢ�� ���� ���� �����Դϴ�.
	 * @param byPosition �ﰢ�� �߰� ���Դϴ�.
	 * @param byColor �ﰢ�� �߰� ���� �����Դϴ�.
	 * @param toPosition �ﰢ�� �� ���Դϴ�.
	 * @param toColor �ﰢ�� �� ���� �����Դϴ�.
	 */
	void RenderTriangle2D(
		const Vec2f& fromPosition, const Vec4f& fromColor,
		const Vec2f& byPosition, const Vec4f& byColor,
		const Vec2f& toPosition, const Vec4f& toColor
	);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���̾� ������ �ﰢ���� �׸��ϴ�.
	 * 
	 * @param fromPosition �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition �ﰢ�� �� ���Դϴ�.
	 * @param color �ﰢ���� �����Դϴ�.
	 */
	void RenderWireframeTriangle2D(const Vec2f& fromPosition, const Vec2f& byPosition, const Vec2f& toPosition, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���̾� ������ �ﰢ���� �׸��ϴ�.
	 * 
	 * @param fromPosition �ﰢ�� ���� ���Դϴ�.
	 * @param fromColor �ﰢ�� ���� ���� �����Դϴ�.
	 * @param byPosition �ﰢ�� �߰� ���Դϴ�.
	 * @param byColor �ﰢ�� �߰� ���� �����Դϴ�.
	 * @param toPosition �ﰢ�� �� ���Դϴ�.
	 * @param toColor �ﰢ�� �� ���� �����Դϴ�.
	 */
	void RenderWireframeTriangle2D(
		const Vec2f& fromPosition, const Vec4f& fromColor,
		const Vec2f& byPosition, const Vec4f& byColor,
		const Vec2f& toPosition, const Vec4f& toColor
	);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���簢���� �׸��ϴ�.
	 * 
	 * @param center ���簢���� �߽� ��ǥ�Դϴ�.
	 * @param width ���簢���� ���� ũ���Դϴ�.
	 * @param heigt ���簢���� ���� ũ���Դϴ�.
	 * @param rotate ���簢���� ���� ȸ�� �����Դϴ�.
	 * @param color ���簢���� �����Դϴ�.
	 */
	void RenderRectangle2D(const Vec2f& center, float width, float height, float rotate, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���̾� ������ ���簢���� �׸��ϴ�.
	 * 
	 * @param center ���簢���� �߽� ��ǥ�Դϴ�.
	 * @param width ���簢���� ���� ũ���Դϴ�.
	 * @param heigt ���簢���� ���� ũ���Դϴ�.
	 * @param rotate ���簢���� ���� ȸ�� �����Դϴ�.
	 * @param color ���簢���� �����Դϴ�.
	 */
	void RenderWireframeRectangle2D(const Vec2f& center, float width, float height, float rotate, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� �𼭸��� �ձ� 2D �簢���� �׸��ϴ�.
	 * 
	 * @param center ���簢���� �߽� ��ǥ�Դϴ�.
	 * @param width ���簢���� ���� ũ���Դϴ�.
	 * @param heigt ���簢���� ���� ũ���Դϴ�.
	 * @param side �簢���� �ձ� �κ��� ũ���Դϴ�.
	 * @param rotate ���簢���� ���� ȸ�� �����Դϴ�.
	 * @param color ���簢���� �����Դϴ�.
	 */
	void RenderRoundRectangle2D(const Vec2f& center, float width, float height, float side, float rotate, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� �𼭸��� �ձ� 2D ���̾� ������ �簢���� �׸��ϴ�.
	 * 
	 * @param center ���簢���� �߽� ��ǥ�Դϴ�.
	 * @param width ���簢���� ���� ũ���Դϴ�.
	 * @param heigt ���簢���� ���� ũ���Դϴ�.
	 * @param side �簢���� �ձ� �κ��� ũ���Դϴ�.
	 * @param rotate ���簢���� ���� ȸ�� �����Դϴ�.
	 * @param color ���簢���� �����Դϴ�.
	 */
	void RenderWireframeRoundRectangle2D(const Vec2f& center, float width, float height, float side, float rotate, const Vec4f& color);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���� �׸��ϴ�.
	 * 
	 * @param center ���� �߽� ��ǥ�Դϴ�.
	 * @param radius ���� ������ �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 * @param sliceCount ���� �ѷ� ���� Ƚ���Դϴ�. �⺻ ���� 300�Դϴ�.
	 */
	void RenderCircle2D(const Vec2f& center, float radius, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���̾� ������ ���� �׸��ϴ�.
	 * 
	 * @param center ���� �߽� ��ǥ�Դϴ�.
	 * @param radius ���� ������ �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 * @param sliceCount �� �ѷ��� ���� Ƚ���Դϴ�. �⺻ ���� 300�Դϴ�.
	 */
	void RenderWireframeCircle2D(const Vec2f& center, float radius, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D Ÿ���� �׸��ϴ�.
	 * 
	 * @param center Ÿ���� �߽� ��ǥ�Դϴ�.
	 * @param xAxis Ÿ���� x�� �����Դϴ�. ����, �� ���̰� y�� ���̺��� ũ�ٸ� ������ �ǰ�, �׷��� ������ ������ �˴ϴ�.
	 * @param yAxis Ÿ���� y�� �����Դϴ�. ����, �� ���̰� x�� ���̺��� ũ�ٸ� ������ �ǰ�, �׷��� ������ ������ �˴ϴ�.
	 * @param color Ÿ���� �����Դϴ�.
	 * @param sliceCount Ÿ�� �ѷ��� ���� Ƚ���Դϴ�. �⺻ ���� 300�Դϴ�.
	 */
	void RenderEllipse2D(const Vec2f& center, float xAxis, float yAxis, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief ���ε��� ������ ���ۿ� 2D ���̾� ������ Ÿ���� �׸��ϴ�.
	 * 
	 * @param center Ÿ���� �߽� ��ǥ�Դϴ�.
	 * @param xAxis Ÿ���� x�� �����Դϴ�. ����, �� ���̰� y�� ���̺��� ũ�ٸ� ������ �ǰ�, �׷��� ������ ������ �˴ϴ�.
	 * @param yAxis Ÿ���� y�� �����Դϴ�. ����, �� ���̰� x�� ���̺��� ũ�ٸ� ������ �ǰ�, �׷��� ������ ������ �˴ϴ�.
	 * @param color Ÿ���� �����Դϴ�.
	 * @param sliceCount Ÿ�� �ѷ��� ���� Ƚ���Դϴ�. �⺻ ���� 300�Դϴ�.
	 */
	void RenderWireframeEllipse2D(const Vec2f& center, float xAxis, float yAxis, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief 2D ��������Ʈ�� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param textureID �ؽ�ó ���ҽ� ���̵��Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ���� ȸ�� �����Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void RenderSprite2D(const RUID& textureID, const Vec2f& center, float width, float height, float rotate, float transparent = 1.0f);


	/**
	 * @brief 2D ��������Ʈ�� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @note 2D ��������Ʈ�� ������ ��ü�� ä�������� �׸��ϴ�.
	 *
	 * @param textureID �ؽ�ó ���ҽ� ���̵��Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void RenderSprite2D(const RUID& textureID, float transparent = 1.0f);


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
	 * @param textureID �ؽ�ó ���ҽ� ���̵� �Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void RenderHorizonScrollSprite2D(const RUID& textureID, float rate, float transparent = 1.0f);


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
	 * @param textureID �ؽ�ó ���ҽ� ���̵� �Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ȸ�� �����Դϴ�. ������ �����Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void RenderHorizonScrollSprite2D(const RUID& textureID, const Vec2f& center, float width, float height, float rotate, float rate, float transparent = 1.0f);


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
	 * @param textureID �ؽ�ó ���ҽ� ���̵� �Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void RenderVerticalScrollSprite2D(const RUID& textureID, float rate, float transparent = 1.0f);


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
	 * @param textureID �ؽ�ó ���ҽ� ���̵� �Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ȸ�� �����Դϴ�. ������ �����Դϴ�.
	 * @param rate ���� �����Դϴ�. ���� ������ 0.0f ~ 1.0f �Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f(������)�Դϴ�.
	 */
	void RenderVerticalScrollSprite2D(const RUID& textureID, const Vec2f& center, float width, float height, float rotate, float rate, float transparent = 1.0f);


	/**
	 * @brief 2D ��������Ʈ�� �ܰ����� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *

	 * @param textureID �ؽ�ó ���ҽ� ���̵� �Դϴ�.
	 * @param center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param rotate �ؽ�ó�� ���� ȸ�� �����Դϴ�.
	 * @param outline �ؽ�ó �ܰ��� �����Դϴ�.
	 * @param transparent �ؽ�ó�� �����Դϴ�. �⺻ ���� 1.0f �Դϴ�.
	 */
	void RenderOutlineSprite2D(const RUID& textureID, const Vec2f& center, float width, float height, float rotate, const Vec4f& outline, float transparent = 1.0f);


	/**
	 * @brief 2D �ؽ�Ʈ�� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 * 
	 * @param fontID ��Ʈ ���ҽ� ���̵��Դϴ�.
	 * @param text �������� �ؽ�Ʈ�Դϴ�.
	 * @param center �ؽ�Ʈ�� ��ǥ�Դϴ�.
	 * @param color �ؽ�Ʈ�� RGBA �����Դϴ�.
	 * @param bIsCenter �ؽ�Ʈ ��ǥ�� �ؽ�Ʈ�� �߽����� Ȯ���ϴ� �ɼ��Դϴ�.
	 * 
	 * @note �߽����� �������� ������ ���� ����� �������� �մϴ�.
	 */
	void RenderText2D(const RUID& fontID, const std::wstring& text, const Vec2f& position, const Vec4f& color, bool bIsCenter = true);


	/**
	 * @brief ���ڸ��� ���� �ٸ� 2D �ؽ�Ʈ�� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 * 
	 * @param fontID ��Ʈ ���ҽ� ���̵��Դϴ�.
	 * @param text �������� �ؽ�Ʈ�Դϴ�.
	 * @param position �ؽ�Ʈ�� ��ǥ�Դϴ�.
	 * @param colors �� ������ ���� ����Դϴ�.
	 * @param bIsCenter �ؽ�Ʈ ��ǥ�� �ؽ�Ʈ�� �߽����� Ȯ���ϴ� �ɼ��Դϴ�.
	 */
	void RenderText2D(const RUID& fontID, const std::wstring& text, const Vec2f& position, const std::vector<Vec4f>& colors, bool bIsCenter = true);


	/**
	 * @brief 3D ������ ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param positions ȭ�� ���� 3D �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 *
	 * @note 3D ������ ������ MAX_VERTEX_SIZE(10000)�� ũ�⸦ ���� �� �����ϴ�.
	 */
	void RenderPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color);


	/**
	 * @brief ������ ������ 3D ���� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param positions ȭ�� ���� 3D �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 *
	 * @note 3D ������ ������ MAX_VERTEX_SIZE(10000)�� ũ�⸦ ���� �� �����ϴ�.
	 */
	void RenderConnectPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color);


	/**
	 * @brief 3D ���� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param fromPosition ���� �������Դϴ�.
	 * @param toPosition ���� �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 */
	void RenderLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec3f& toPosition, const Vec4f& color);


	/**
	 * @brief 3D ���� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param fromPosition ���� �������Դϴ�.
	 * @param fromColor ���� ������ �����Դϴ�.
	 * @param toPosition ���� �����Դϴ�.
	 * @param toColor ���� ���� �����Դϴ�.
	 */
	void RenderLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec4f& fromColor, const Vec3f& toPosition, const Vec4f& toColor);


	/**
	 * @brief 3D ť�긦 ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param world ���� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param extents ť���� X/Y/Z �� ���������� ũ���Դϴ�.
	 * @param color ť���� �����Դϴ�.
	 */
	void RenderCube3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const Vec3f& extents, const Vec4f& color);


	/**
	 * @brief 3D ���̾� ������ ��(Sphere)�� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param center ���� �߽� ��ǥ�Դϴ�.
	 * @param radius ���� ������ �����Դϴ�.
	 * @param color ���� �����Դϴ�.
	 * @param sliceCount �� ��鿡 �����ϴ� ���� �ѷ� ���� Ƚ���Դϴ�. �⺻ ���� 300�Դϴ�.
	 */
	void RenderSphere3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, float radius, const Vec4f& color, int32_t sliceCount = 300);


	/**
	 * @brief XZ ����� ���ڸ� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 *
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param minX X��ǥ�� �ּҰ��Դϴ�.
	 * @param maxX X��ǥ�� �ִ��Դϴ�.
	 * @param strideX X�� ���������� �����Դϴ�.
	 * @param minZ Z��ǥ�� �ּҰ��Դϴ�.
	 * @param maxZ Z��ǥ�� �ִ��Դϴ�.
	 * @param strideZ Z�� ���������� �����Դϴ�.
	 * @param color ������ �����Դϴ�.
	 */
	void RenderGrid3D(const Mat4x4& view, const Mat4x4& projection, float minX, float maxX, float strideX, float minZ, float maxZ, float strideZ, const Vec4f& color);


	/**
	 * @brief ���� �޽ø� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 * 
	 * @note ���̴��� ���ε� �Ǿ� �־�� �մϴ�.
	 * 
	 * @param meshID ���� �޽� ���ҽ� ���̵��Դϴ�.
	 */
	void RenderStaticMesh(const RUID& meshID);


	/**
	 * @brief ��Ű�� �޽ø� ���ε��� ������ ���ۿ� �׸��ϴ�.
	 * 
	 * @note ���̴��� ���ε� �Ǿ� �־�� �մϴ�.
	 * 
	 * @param meshID ��Ű�� �޽� ���ҽ� ���̵��Դϴ�.
	 */
	void RenderSkinnedMesh(const RUID& meshID);


	/**
	 * @brief ���� Ÿ�� �������� ���� ���� ũ�⸦ ����ϴ�.
	 *
	 * @param outWidth ���� Ÿ�� �������� ���� ũ���Դϴ�.
	 * @param outHeight ���� Ÿ�� �������� ���� ũ���Դϴ�.
	 */
	void GetRenderTargetWindowSize(int32_t& outWidth, int32_t& outHeight);


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� �� ���� �Ҹ��ڸ� �����մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


private:
	/**
	 * @brief ������ ����� �Ǵ� ������ �������Դϴ�.
	 */
	void* renderTargetWindow_ = nullptr;


	/**
	 * @brief OpenGL ���ؽ�Ʈ�Դϴ�.
	 */
	void* context_ = nullptr;


	/**
	 * @brief ��ũ�� ���� ����Դϴ�.
	 */
	Mat4x4 screenOrtho_;


	/**
	 * @brief ���� �Ŵ����� ������ �� ����� ���̴��Դϴ�.
	 */
	std::map<std::string, Shader*> shaderCache_;
};