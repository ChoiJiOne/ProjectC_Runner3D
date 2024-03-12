#pragma once

#include <string>

#include <cgltf.h>


/**
 * @brief GLTF ���ϰ� ���� ���� ������ �ε��� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ������ �޼���� ��� static �Դϴ�.
 */
class GLTFLoader
{
public:
	/**
	 * @brief GLTF ������ �ε��մϴ�.
	 * 
	 * @param path GLTF������ ����Դϴ�.
	 * 
	 * @return GLTF �������� �����͸� ��ȯ�մϴ�.
	 * 
	 * @note �� �޼��带 �̿��ؼ� ���� �����ʹ� �ݵ�� Free �޼��带 �̿��ؼ� �����ؾ� �մϴ�.
	 */
	cgltf_data* LoadFromFile(const std::string& path);


	/**
	 * @brief GLTF ������ �Ҵ��� �����մϴ�.
	 * 
	 * @param data �Ҵ��� ������ GLTF �������Դϴ�.
	 */
	void Free(cgltf_data* data);
};