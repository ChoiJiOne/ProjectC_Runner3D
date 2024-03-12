#include <glad/glad.h>

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Quat.h"

#include "Assertion.h"
#include "VertexAttribute.h"

template VertexAttribute<int32_t>;
template VertexAttribute<float>;
template VertexAttribute<Vec2i>;
template VertexAttribute<Vec2f>;
template VertexAttribute<Vec3i>;
template VertexAttribute<Vec3f>;
template VertexAttribute<Vec4i>;
template VertexAttribute<Vec4f>;
template VertexAttribute<Quat>;

template<typename T>
VertexAttribute<T>::VertexAttribute()
{
	GL_FAILED(glGenBuffers(1, &bufferID_));
	bufferCount_ = 0;
}

template<typename T>
VertexAttribute<T>::~VertexAttribute()
{
	GL_FAILED(glDeleteBuffers(1, &bufferID_));
}

template<typename T> 
void VertexAttribute<T>::Set(const T* bufferPtr, uint32_t bufferCount)
{
	bufferCount_ = bufferCount;
	uint32_t size = sizeof(T);

	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, bufferID_));
	GL_FAILED(glBufferData(GL_ARRAY_BUFFER, size * bufferCount_, bufferPtr, GL_STREAM_DRAW));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

template<typename T>
void VertexAttribute<T>::Set(const std::vector<T>& buffer)
{
	Set(buffer.data(), static_cast<uint32_t>(buffer.size()));
}

template<typename T>
void VertexAttribute<T>::Bind(uint32_t slot)
{
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, bufferID_));
	GL_FAILED(glEnableVertexAttribArray(slot));
	SetAttribPointer(slot);
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

template<typename T>
void VertexAttribute<T>::Unbind(uint32_t slot)
{
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, bufferID_));
	GL_FAILED(glDisableVertexAttribArray(slot));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

template<>
void VertexAttribute<int32_t>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribIPointer(slot, 1, GL_INT, 0, (void*)0);
}

template<>
void VertexAttribute<Vec2i>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribIPointer(slot, 2, GL_INT, 0, (void*)0);
}

template<>
void VertexAttribute<Vec3i>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribIPointer(slot, 3, GL_INT, 0, (void*)0);
}

template<>
void VertexAttribute<Vec4i>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribIPointer(slot, 4, GL_INT, 0, (void*)0);
}

template<>
void VertexAttribute<float>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribPointer(slot, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void VertexAttribute<Vec2f>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribPointer(slot, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void VertexAttribute<Vec3f>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribPointer(slot, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void VertexAttribute<Vec4f>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribPointer(slot, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void VertexAttribute<Quat>::SetAttribPointer(uint32_t slot)
{
	glVertexAttribPointer(slot, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
}