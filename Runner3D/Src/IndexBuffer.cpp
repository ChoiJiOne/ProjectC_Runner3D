#include <glad/glad.h>

#include "Assertion.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
	GL_FAILED(glGenBuffers(1, &bufferID_));
	bufferCount_ = 0;
}

IndexBuffer::~IndexBuffer()
{
	GL_FAILED(glDeleteBuffers(1, &bufferID_));
}

void IndexBuffer::Set(const uint32_t* bufferPtr, uint32_t bufferCount)
{
	bufferCount_ = bufferCount;
	uint32_t size = sizeof(uint32_t);

	GL_FAILED(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_));
	GL_FAILED(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * bufferCount_, bufferPtr, GL_STATIC_DRAW));
	GL_FAILED(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void IndexBuffer::Set(const std::vector<uint32_t>& buffer)
{
	Set(buffer.data(), static_cast<uint32_t>(buffer.size()));
}

void IndexBuffer::Bind()
{
	GL_FAILED(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_));
}

void IndexBuffer::Unbind()
{
	GL_FAILED(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}