#include <glad/glad.h>

#include "Assertion.h"
#include "Pose.h"
#include "Skeleton.h"
#include "SkinnedMesh.h"

SkinnedMesh::SkinnedMesh(const std::vector<VertexPositionNormalUvSkin3D>& vertices, const std::vector<uint32_t>& indices)
	: vertices_(vertices)
	, indices_(indices)
{
	const void* vertexBufferPtr = reinterpret_cast<const void*>(vertices_.data());
	uint32_t vertexBufferSize = static_cast<uint32_t>(vertices_.size()) * VertexPositionNormalUvSkin3D::GetStride();

	const void* indexBufferPtr = reinterpret_cast<const void*>(indices_.data());
	uint32_t indexBufferSize = static_cast<uint32_t>(indices_.size()) * sizeof(uint32_t);

	GL_FAILED(glGenVertexArrays(1, &vertexArrayObject_));
	GL_FAILED(glGenBuffers(1, &vertexBufferObject_));
	GL_FAILED(glGenBuffers(1, &indexBufferObject_));

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_));
	GL_FAILED(glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, vertexBufferPtr, GL_DYNAMIC_DRAW));
	GL_FAILED(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject_));
	GL_FAILED(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferSize, indexBufferPtr, GL_STATIC_DRAW));

	GL_FAILED(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPositionNormalUvSkin3D::GetStride(), (void*)(offsetof(VertexPositionNormalUvSkin3D, position))));
	GL_FAILED(glEnableVertexAttribArray(0));

	GL_FAILED(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VertexPositionNormalUvSkin3D::GetStride(), (void*)(offsetof(VertexPositionNormalUvSkin3D, normal))));
	GL_FAILED(glEnableVertexAttribArray(1));

	GL_FAILED(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, VertexPositionNormalUvSkin3D::GetStride(), (void*)(offsetof(VertexPositionNormalUvSkin3D, uv))));
	GL_FAILED(glEnableVertexAttribArray(2));

	GL_FAILED(glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, VertexPositionNormalUvSkin3D::GetStride(), (void*)(offsetof(VertexPositionNormalUvSkin3D, weight))));
	GL_FAILED(glEnableVertexAttribArray(3));

	GL_FAILED(glVertexAttribIPointer(4, 4, GL_INT, VertexPositionNormalUvSkin3D::GetStride(), (void*)(offsetof(VertexPositionNormalUvSkin3D, joints))));
	GL_FAILED(glEnableVertexAttribArray(4));

	GL_FAILED(glBindVertexArray(0));

	bIsInitialized_ = true;
}

SkinnedMesh::~SkinnedMesh()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void SkinnedMesh::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteBuffers(1, &indexBufferObject_));
	GL_FAILED(glDeleteBuffers(1, &vertexBufferObject_));
	GL_FAILED(glDeleteVertexArrays(1, &vertexArrayObject_));

	bIsInitialized_ = false;
}

void SkinnedMesh::Bind()
{
	GL_FAILED(glBindVertexArray(vertexArrayObject_));
}

void SkinnedMesh::Unbind()
{
	GL_FAILED(glBindVertexArray(0));
}

void SkinnedMesh::Skin(Skeleton* skeleton, Pose* pose)
{
	pose->GetMatrixPalette(posePalette_);
	const std::vector<Mat4x4>& invPosePalette = skeleton->GetInvBindPose();

	for (int32_t index = 0; index < vertices_.size(); ++index)
	{
		Vec4f& weight = vertices_[index].weight;
		Vec4i& joints = vertices_[index].joints;
		
		Mat4x4 m0 = (posePalette_[joints.x] * invPosePalette[joints.x]) * weight.x;
		Mat4x4 m1 = (posePalette_[joints.y] * invPosePalette[joints.y]) * weight.y;
		Mat4x4 m2 = (posePalette_[joints.z] * invPosePalette[joints.z]) * weight.z;
		Mat4x4 m3 = (posePalette_[joints.w] * invPosePalette[joints.w]) * weight.w;

		Mat4x4 skin = m0 + m1 + m2 + m3;

		//mSkinnedPosition[i] = transformPoint(skin, mPosition[i]);
		//mSkinnedNormal[i] = transformVector(skin, mNormal[i]);
	}
}
