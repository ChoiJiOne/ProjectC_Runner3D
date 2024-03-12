#pragma once

#include <map>
#include <string>

#include "Mat2x2.h"
#include "Mat3x3.h"
#include "Mat4x4.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

#include "IResource.h"


/**
 * @brief GLSL ���̴��� �������ϰ� ���̴� ���α׷��� �����մϴ�.
 */
class Shader : public IResource
{
public:
	/**
	 * @brief ���̴� ������ �о� ���̴� ���α׷��� �����մϴ�.
	 *
	 * @param vsPath ���ؽ� ���̴�(Vertex Shader)�� ����Դϴ�.
	 * @param fsPath �����׸�Ʈ ���̴�(Fragment Shader)�� ����Դϴ�.
	 */
	explicit Shader(const std::string& vsPath, const std::string& fsPath);


	/**
	 * @brief ���̴� ������ �о� ���̴� ���α׷��� �����մϴ�.
	 *
	 * @param vsPath ���ؽ� ���̴�(Vertex Shader)�� ����Դϴ�.
	 * @param gsFile ������Ʈ�� ���̴��� Ȯ����(.geom)�� ������ ����Դϴ�.
	 * @param fsPath �����׸�Ʈ ���̴�(Fragment Shader)�� ����Դϴ�.
	 */
	explicit Shader(const std::string& vsPath, const std::string& gsPath, const std::string& fsPath);
	

	/**
	 * @brief ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Shader();


	/**
	 * @brief ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


	/**
	 * @brief ���̴� ���ο��� �Ҵ�� ���ҽ��� �Ҵ��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���̴��� ���������ο� ���ε��մϴ�.
	 */
	void Bind();


	/**
	 * @brief ���̴��� ���ε� �����մϴ�.
	 */
	void Unbind();


	/**
	 * @brief ���̴� ���� boolean Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, bool value);


	/**
	 * @brief ���̴� ���� int Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, int32_t value);


	/**
	 * @brief ���̴� ���� float Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, float value);


	/**
	 * @brief ���̴� ���� 2���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Vec2f& value);


	/**
	 * @brief ���̴� ���� 2���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 */
	void SetUniform(const std::string& name, float x, float y);


	/**
	 * @brief ���̴� ���� 2���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Vec2i& value);


	/**
	 * @brief ���̴� ���� 2���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 */
	void SetUniform(const std::string& name, int32_t x, int32_t y);


	/**
	 * @brief ���̴� ���� 3���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Vec3f& value);


	/**
	 * @brief ���̴� ���� 3���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 * @param z ������ ������ z ���Դϴ�.
	 */
	void SetUniform(const std::string& name, float x, float y, float z);


	/**
	 * @brief ���̴� ���� 3���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Vec3i& value);


	/**
	 * @brief ���̴� ���� 3���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 * @param z ������ ������ z ���Դϴ�.
	 */
	void SetUniform(const std::string& name, int32_t x, int32_t y, int32_t z);


	/**
	 * @brief ���̴� ���� 4���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Vec4f& value);


	/**
	 * @brief ���̴� ���� 4���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 * @param z ������ ������ z ���Դϴ�.
	 * @param w ������ ������ w ���Դϴ�.
	 */
	void SetUniform(const std::string& name, float x, float y, float z, float w);


	/**
	 * @brief ���̴� ���� 4���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Vec4i& value);


	/**
	 * @brief ���̴� ���� 4���� ���� Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 * @param z ������ ������ z ���Դϴ�.
	 * @param w ������ ������ w ���Դϴ�.
	 */
	void SetUniform(const std::string& name, int32_t x, int32_t y, int32_t z, int32_t w);


	/**
	 * @brief ���̴� ���� 2x2 Ÿ���� ��� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Mat2x2f& value);


	/**
	 * @brief ���̴� ���� 3x3 Ÿ���� ��� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Mat3x3f& value);


	/**
	 * @brief ���̴� ���� 4x4 Ÿ���� ��� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetUniform(const std::string& name, const Mat4x4f& value);


	/**
	 * @brief ���ؽ� �Ӽ� ��ġ�� ����ϴ�.
	 * 
	 * @param name ��ġ�� ã�� ���ؽ� ���̾ƿ��� �̸��Դϴ�.
	 * 
	 * @return ���ؽ� �Ӽ� ��ġ�� ��ȯ�մϴ�. ã�� ���ϸ� -1�� ��ȯ�մϴ�.
	 * 
	 * @see
	 * - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetAttribLocation.xhtml
	 * - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetActiveAttrib.xhtml
	 */
	int32_t GetVertexAttribute(const std::string& name);


	/**
	 * @brief ���̴� �� ������ ��ü�� ��ġ�� ����ϴ�.
	 *
	 * @param name ��ġ�� ã�� ���̴� �� ������ �̸��Դϴ�.
	 *
	 * @return ���̴� �� ������ ��ü�� ��ġ�� ��ȯ�մϴ�. ã�� ���ϸ� -1�� ��ȯ�մϴ�.
	 *
	 * @see https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml
	 */
	int32_t GetUniformLocation(const std::string& name);
	

protected:
	/**
	 * @brief ���̴��� �����Դϴ�.
	 */
	enum class EType : int32_t
	{
		Vertex   = 0x00,
		Geometry = 0x01,
		Fragment = 0x02,
	};


	/**
	 * @brief ���̴� ������ �а� ������ ������ �ҽ��� ����ϴ�.
	 *
	 * @param path ���̴� ������ ����Դϴ�.
	 *
	 * @return ���̴� �ҽ� �ڵ��� ���ڿ��� ��ȯ�մϴ�. �����ϸ� �� ���ڿ��� ��ȯ�մϴ�.
	 */
	std::string ReadShaderFile(const std::string& path);


	/**
	 * @brief ���̴� ��ü�� �����ϰ� ���̴� �ҽ��� �������մϴ�.
	 *
	 * @note ���̴� ��ü ������ �����ϸ� 0�� �ƴ� ���� ��ȯ�մϴ�.
	 *
	 * @param type ���̴� Ÿ���Դϴ�.
	 * @param source ���̴� �ҽ��Դϴ�.
	 *
	 * @return �����ϵ� ���̴� ��ü�� ���̵� ��ȯ�մϴ�.
	 */
	uint32_t CreateAndCompileShader(const EType& type, const std::string& source);


	/**
	 * @brief ���̴��� ���� �Ӽ��� �����մϴ�.
	 */
	void CreateVertexAttributes();


	/**
	 * @brief ���ؽ��� ���� ���̳��� ���ؽ� ���۸� ���ϴ�.
	 *
	 * @param vertexBufferID ���⸦ ������ ���ؽ� ������ ID�Դϴ�.
	 * @param vertexPtr ���⸦ ������ ���ؽ� ������ �������Դϴ�.
	 * @param bufferByteSize ���ؽ� ������ ����Ʈ ũ���Դϴ�.
	 */
	void WriteDynamicVertexBuffer(uint32_t vertexBufferID, const void* vertexPtr, uint32_t bufferByteSize);
	

protected:
	/**
	 * @brief ���̴� ���α׷��� ���̵��Դϴ�.
	 */
	uint32_t programID_ = 0;


	/**
	 * @brief ���̴��� �Ӽ� ��ġ���Դϴ�.
	 */
	std::map<std::string, uint32_t> attributeCache_;


	/**
	 * @brief ������ ������ ��ġ���Դϴ�.
	 */
	std::map<std::string, uint32_t> uniformLocationCache_;
};