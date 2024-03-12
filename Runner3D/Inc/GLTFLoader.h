#pragma once

#include <string>

#include <cgltf.h>


/**
 * @brief GLTF 파일과 파일 내의 데이터 로딩을 수행합니다.
 * 
 * @note 이 클래스의 멤버 변수와 메서드는 모두 static 입니다.
 */
class GLTFLoader
{
public:
	/**
	 * @brief GLTF 파일을 로딩합니다.
	 * 
	 * @param path GLTF파일의 경로입니다.
	 * 
	 * @return GLTF 데이터의 포인터를 반환합니다.
	 * 
	 * @note 이 메서드를 이용해서 얻은 포인터는 반드시 Free 메서드를 이용해서 해제해야 합니다.
	 */
	cgltf_data* LoadFromFile(const std::string& path);


	/**
	 * @brief GLTF 데이터 할당을 해제합니다.
	 * 
	 * @param data 할당을 해제할 GLTF 데이터입니다.
	 */
	void Free(cgltf_data* data);
};