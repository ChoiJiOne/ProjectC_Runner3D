#pragma once

#include <vector>

#include "Transform.h"


/**
 * @brief �ִϸ��̼ǵ� ���� ������ �� ���� ��ȯ�� �����մϴ�.
 */
class Pose
{
public:
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 */
	explicit Pose() {}


	/**
	 * @brief ������ �������Դϴ�.
	 * 
	 * @param size ��ȯ ��� �� �ε����� ũ���Դϴ�.
	 */
	explicit Pose(uint32_t size);


	/**
	 * @brief ������ ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������Ƽ�� ������ �ν��Ͻ��Դϴ�.
	 */
	Pose(Pose&& instance) noexcept;


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���� ������Ƽ�� ������ �ν��Ͻ��Դϴ�.
	 */
	Pose(const Pose& instance) noexcept;


	/**
	 * @brief ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Pose() {}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������ ������ �ν��Ͻ��Դϴ�.
	 * 
	 * @return ���� ������ ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Pose& operator=(Pose&& instance) noexcept;


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���� ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ���� ������ ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Pose& operator=(const Pose& instance) noexcept;


	/**
	 * @brief �� ��� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return �� ��� ��ġ�Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Pose&& instance) noexcept;


	/**
	 * @brief �� ��� ��ġ�ϴ��� Ȯ���մϴ�.
	 * 
	 * @param instance ��ġ�ϴ��� Ȯ���� �ν��Ͻ��Դϴ�.
	 * 
	 * @return �� ��� ��ġ�Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Pose& instance) noexcept;


	/**
	 * @brief �� ��� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return �� ��� ��ġ���� �ʴ´ٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Pose&& instance) noexcept;


	/**
	 * @brief �� ��� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ν��Ͻ��Դϴ�.
	 *
	 * @return �� ��� ��ġ���� �ʴ´ٸ� true, �׷��ٸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Pose& instance) noexcept;


	/**
	 * @brief �ε����� �����ϴ� ��ȯ���� ����ϴ�.
	 * 
	 * @param index ��ȯ���� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� ��ȯ���Դϴ�.
	 */
	Transform operator[](uint32_t index);


	/**
	 * @brief ���� ���� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param size ������ ������ ũ���Դϴ�.
	 */
	void Resize(uint32_t size);


	/**
	 * @brief ��ȯ ����� ũ�⸦ ����ϴ�.
	 * 
	 * @return ��ȯ ����� ũ�⸦ ��ȯ�մϴ�.
	 */
	uint32_t GetJointSize() { return static_cast<uint32_t>(joints_.size()); }


	/**
	 * @brief �ε����� �����ϴ� ���� ��ȯ ���� ����ϴ�.
	 * 
	 * @param index ���� ��ȯ ���� ���� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� ���� ��ȯ ���� ��ȯ�մϴ�.
	 */
	Transform GetLocalTransform(uint32_t index);


	/**
	 * @brief �ε����� �����ϴ� ���� ��ȯ ���� �����մϴ�.
	 * 
	 * @param index ������ �ε����Դϴ�.
	 * @param transform ������ ��ȯ ���Դϴ�.
	 */
	void SetLocalTransform(uint32_t index, const Transform& transform);


	/**
	 * @brief �ε����� �����ϴ� �۷ι� ��ȯ ���� ����ϴ�.
	 * 
	 * @param index �۷ι� ��ȯ ���� ���� �ε����Դϴ�.
	 * 
	 * @return �ε����� �����ϴ� �۷ι� ��ȯ ���� ��ȯ�մϴ�.
	 */
	Transform GetGlobalTransform(uint32_t index);


	/**
	 * @brief ��ȯ���� �����ϴ� ��� ����Դϴ�.
	 * 
	 * @param outMatrices ��ȯ���� �����ϴ� ����� ������ �����Դϴ�.
	 */
	void GetMatrixPalette(std::vector<Mat4x4>& outMatrices);


	/**
	 * @brief �ε����� �����ϴ� �θ� �ε��� ���� ����ϴ�.
	 * 
	 * @param index �θ� �ε��� ���� �ε��� �Դϴ�.
	 * 
	 * @return �θ� �ε��� ���� ��ȯ�մϴ�.
	 */
	int32_t GetParent(uint32_t index);


	/**
	 * @brief �ε����� �����ϴ� �θ� �ε��� ���� �����մϴ�.
	 * 
	 * @param index ������ �ε����Դϴ�.
	 * @param parent ������ �θ� �ε��� ���Դϴ�.
	 */
	void SetParent(uint32_t index, int32_t parent);


	/**
	 * @brief ���� ���� �� ����Ʈ�� �ٸ� ����Ʈ�� �ڼ����� Ȯ���մϴ�.
	 * 
	 * @param pose ����� �Ǵ� �����Դϴ�.
	 * @param parent ��Ʈ ����Ʈ�Դϴ�.
	 * @param search �˻��� ����Ʈ�Դϴ�.
	 * 
	 * @return �˻� ����Ʈ�� ��Ʈ ����Ʈ�� �ڼ��̶�� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsInHierarchy(Pose& pose, uint32_t parent, uint32_t search);


	/**
	 * @brief �� ��� �����մϴ�.
	 * 
	 * @param output ������ ����� ������ �����Դϴ�.
	 * @param start ������ �� ������ ���� �����Դϴ�.
	 * @param end ������ �� ������ �� �����Դϴ�.
	 * @param t ������ 0.0���� 1.0 ������ ���Դϴ�.
	 * @param blendRoot ������ ��Ʈ �ε����Դϴ�.
	 */
	static void Blend(Pose& output, Pose& start, Pose& end, float t, int32_t blendRoot);


private:
	/**
	 * @brief Pose�� ��ȯ ����Դϴ�.
	 */
	std::vector<Transform> joints_;


	/**
	 * @brief Pose�� �θ� ��Ÿ���� ����(�ε���)�Դϴ�.
	 */
	std::vector<int32_t> parents_;
};