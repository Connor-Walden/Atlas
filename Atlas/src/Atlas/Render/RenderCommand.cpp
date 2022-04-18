#include "atlaspch.h"
#include "RenderCommand.h"

#include "Platform\OpenGL\OpenGLRenderAPI.h"

namespace Atlas
{
	RenderAPI* RenderCommand::s_RenderAPI = new OpenGLRenderAPI();
}