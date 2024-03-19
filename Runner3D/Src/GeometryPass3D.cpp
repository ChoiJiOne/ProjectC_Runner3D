#include <glad/glad.h>

#include "Assertion.h"
#include "GeometryPass3D.h"

GeometryPass3D::GeometryPass3D() : Shader("Shader/GeometryPass3D.vert", "Shader/GeometryPass3D.frag")
{
	GL_FAILED(glGenVertexArrays(1, &vertexArrayObject_));
	GL_FAILED(glGenBuffers(1, &vertexBufferObject_));

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_));
	GL_FAILED(glBufferData(GL_ARRAY_BUFFER, VertexPositionColor3D::GetStride() * vertices_.size(), reinterpret_cast<const void*>(vertices_.data()), GL_DYNAMIC_DRAW));

	GL_FAILED(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPositionColor3D::GetStride(), (void*)(offsetof(VertexPositionColor3D, position))));
	GL_FAILED(glEnableVertexAttribArray(0));

	GL_FAILED(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VertexPositionColor3D::GetStride(), (void*)(offsetof(VertexPositionColor3D, color))));
	GL_FAILED(glEnableVertexAttribArray(1));

	GL_FAILED(glBindVertexArray(0));
}

GeometryPass3D::~GeometryPass3D()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void GeometryPass3D::Release()
{
	CHECK(bIsInitialized_);

	Shader::Release();

	GL_FAILED(glDeleteBuffers(1, &vertexBufferObject_));
	GL_FAILED(glDeleteVertexArrays(1, &vertexArrayObject_));
}

void GeometryPass3D::DrawPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color)
{
	CHECK(positions.size() <= MAX_VERTEX_SIZE);

	for (std::size_t index = 0; index < positions.size(); ++index)
	{
		vertices_[index] = VertexPositionColor3D(positions[index], color);
	}

	DrawGeometry3D(Mat4x4::Identity(), view, projection, EDrawType::Points, static_cast<uint32_t>(positions.size()));
}

void GeometryPass3D::DrawConnectPoints3D(const Mat4x4& view, const Mat4x4& projection, const std::vector<Vec3f>& positions, const Vec4f& color)
{
	CHECK(positions.size() <= MAX_VERTEX_SIZE);

	for (std::size_t index = 0; index < positions.size(); ++index)
	{
		vertices_[index] = VertexPositionColor3D(positions[index], color);
	}

	DrawGeometry3D(Mat4x4::Identity(), view, projection, EDrawType::LineStrip, static_cast<uint32_t>(positions.size()));
}

void GeometryPass3D::DrawLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec3f& toPosition, const Vec4f& color)
{
	uint32_t vertexCount = 0;

	vertices_[vertexCount++] = VertexPositionColor3D(fromPosition, color);
	vertices_[vertexCount++] = VertexPositionColor3D(toPosition, color);

	DrawGeometry3D(Mat4x4::Identity(), view, projection, EDrawType::LineStrip, vertexCount);
}

void GeometryPass3D::DrawLine3D(const Mat4x4& view, const Mat4x4& projection, const Vec3f& fromPosition, const Vec4f& fromColor, const Vec3f& toPosition, const Vec4f& toColor)
{
	uint32_t vertexCount = 0;

	vertices_[vertexCount++] = VertexPositionColor3D(fromPosition, fromColor);
	vertices_[vertexCount++] = VertexPositionColor3D(toPosition, toColor);

	DrawGeometry3D(Mat4x4::Identity(), view, projection, EDrawType::LineStrip, vertexCount);
}

void GeometryPass3D::DrawCube3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const Vec3f& extents, const Vec4f& color)
{
	uint32_t vertexCount = 0;

	Vec3f minPosition = -extents * 0.5f;
	Vec3f maxPosition = extents * 0.5f;

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, maxPosition.y, maxPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, maxPosition.y, maxPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, maxPosition.y, maxPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, maxPosition.y, minPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, maxPosition.y, minPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, maxPosition.y, minPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, maxPosition.y, minPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, maxPosition.y, maxPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, minPosition.y, maxPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, minPosition.y, maxPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, minPosition.y, maxPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, minPosition.y, minPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, minPosition.y, minPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, minPosition.y, minPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, minPosition.y, minPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, minPosition.y, maxPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, maxPosition.y, maxPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, minPosition.y, maxPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, maxPosition.y, maxPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, minPosition.y, maxPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, maxPosition.y, minPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minPosition.x, minPosition.y, minPosition.z), color);

	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, maxPosition.y, minPosition.z), color);
	vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxPosition.x, minPosition.y, minPosition.z), color);

	DrawGeometry3D(world, view, projection, EDrawType::Lines, vertexCount);
}

void GeometryPass3D::DrawSphere3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, float radius, const Vec4f& color, int32_t sliceCount)
{
	CHECK(radius >= 0.0f);

	int32_t vertexCount = 0;
	for (int32_t index = 0; index < sliceCount; ++index)
	{
		float radian = (static_cast<float>(index) * MathModule::TwoPi) / static_cast<float>(sliceCount);
		float x = radius * MathModule::Cos(radian);
		float y = radius * MathModule::Sin(radian);

		CHECK(vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(x, y, 0.0f), color);
	}
	DrawGeometry3D(world, view, projection, EDrawType::LineStrip, vertexCount);

	vertexCount = 0;
	for (int32_t index = 0; index < sliceCount; ++index)
	{
		float radian = (static_cast<float>(index) * MathModule::TwoPi) / static_cast<float>(sliceCount);
		float y = radius * MathModule::Cos(radian);
		float z = radius * MathModule::Sin(radian);

		CHECK(vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(0.0f, y, z), color);
	}
	DrawGeometry3D(world, view, projection, EDrawType::LineStrip, vertexCount);

	vertexCount = 0;
	for (int32_t index = 0; index < sliceCount; ++index)
	{
		float radian = (static_cast<float>(index) * MathModule::TwoPi) / static_cast<float>(sliceCount);
		float z = radius * MathModule::Cos(radian);
		float x = radius * MathModule::Sin(radian);

		CHECK(vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(x, 0.0f, z), color);
	}
	DrawGeometry3D(world, view, projection, EDrawType::LineStrip, vertexCount);
}

void GeometryPass3D::DrawGrid3D(const Mat4x4& view, const Mat4x4& projection, float minX, float maxX, float strideX, float minZ, float maxZ, float strideZ, const Vec4f& color)
{
	CHECK((strideX >= 1.0f && strideZ >= 1.0f));

	float minXPosition = MathModule::Min<float>(minX, maxX);
	float maxXPosition = MathModule::Max<float>(minX, maxX);
	float minZPosition = MathModule::Min<float>(minZ, maxZ);
	float maxZPosition = MathModule::Max<float>(minZ, maxZ);

	int32_t vertexCount = 0;
	for (float x = minXPosition; x <= maxXPosition; x += strideX)
	{
		CHECK(0 <= vertexCount && vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(x, 0.0f, minZPosition), color);

		CHECK(0 <= vertexCount && vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(x, 0.0f, maxZPosition), color);
	}

	for (float z = minZPosition; z <= maxZPosition; z += strideZ)
	{
		CHECK(0 <= vertexCount && vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(minXPosition, 0.0f, z), color);

		CHECK(0 <= vertexCount && vertexCount < MAX_VERTEX_SIZE);
		vertices_[vertexCount++] = VertexPositionColor3D(Vec3f(maxXPosition, 0.0f, z), color);
	}

	DrawGeometry3D(Mat4x4::Identity(), view, projection, EDrawType::Lines, static_cast<uint32_t>(vertexCount));
}

void GeometryPass3D::DrawGeometry3D(const Mat4x4& world, const Mat4x4& view, const Mat4x4& projection, const EDrawType& drawType, uint32_t vertexCount)
{
	CHECK(drawType != EDrawType::None);

	const void* bufferPtr = reinterpret_cast<const void*>(vertices_.data());
	uint32_t bufferByteSize = static_cast<uint32_t>(VertexPositionColor3D::GetStride() * vertices_.size());
	WriteDynamicVertexBuffer(vertexBufferObject_, bufferPtr, bufferByteSize);

	Shader::Bind();

	Shader::SetUniform("world", world);
	Shader::SetUniform("view", view);
	Shader::SetUniform("projection", projection);

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glDrawArrays(static_cast<GLenum>(drawType), 0, vertexCount));
	GL_FAILED(glBindVertexArray(0));

	Shader::Unbind();
}