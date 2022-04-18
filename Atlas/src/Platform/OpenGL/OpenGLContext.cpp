#include "atlaspch.h"
#include "OpenGLContext.h"

#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace Atlas
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CORE_ASSERT(m_WindowHandle, "Window handle is null D:");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CORE_ASSERT(status, "Failed to initialize GLAD D:");

		LOG_CORE_INFO("OpenGL Info");
		LOG_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
		LOG_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		LOG_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}