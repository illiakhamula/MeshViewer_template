#include "ViewerWindow.h"
#include "glad/glad.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ViewerWindow* wnd = reinterpret_cast<ViewerWindow*>(glfwGetWindowUserPointer(window));
	if (wnd && wnd->m_keyClBck)
		wnd->m_keyClBck(static_cast<KeyCode>(key), static_cast<Action>(action), static_cast<Modifier>(mods));
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	ViewerWindow* wnd = reinterpret_cast<ViewerWindow*>(glfwGetWindowUserPointer(window));
	if (wnd && wnd->m_mouseClBck)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		wnd->m_mouseClBck(static_cast<ButtonCode>(button),
						static_cast<Action>(action),
						static_cast<Modifier>(mods), xpos, ypos);
	}
}

void cursorCallback(GLFWwindow* window, double xpos, double ypos)
{
	// TODO: write this function
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	// TODO: write this function
}

ViewerWindow::ViewerWindow(const std::string& title, uint32_t width, uint32_t height)
	: m_width(width)
	, m_height(height)
{
	if (glfwInit() == GL_FALSE)
	{
		const char* errorDesc = new char[256];
		int code = glfwGetError(&errorDesc);
		if (code == GLFW_NOT_INITIALIZED)
		{
			// TODO: add error message to console output
		}
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_ptrHandle = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
	glfwMakeContextCurrent(m_ptrHandle);

	static bool initGLAD = false;
	if (!initGLAD)
	{
		initGLAD = true;
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	glfwSetWindowUserPointer(m_ptrHandle, this);

	glfwSetKeyCallback(m_ptrHandle, &keyCallback);
	glfwSetMouseButtonCallback(m_ptrHandle, &mouseButtonCallback);
	// TODO: provide callbacks for cursor and scroll as it provided for key and mouse;
}

ViewerWindow::~ViewerWindow()
{
	glfwDestroyWindow(m_ptrHandle);
}

uint32_t ViewerWindow::getWidth() const
{
    return m_width;
}

uint32_t ViewerWindow::getHeight() const
{
    return m_height;
}

void ViewerWindow::setKeyCallback(const KeyCallback& callback)
{
	m_keyClBck = callback;
}

void ViewerWindow::setCursorPosCallback(const CursorPosCallback& callback)
{
	m_cursorPosClBck = callback;
}

void ViewerWindow::setMouseCallback(const MouseCallback& callback)
{
	// TODO: write this function
}

void ViewerWindow::setScrollCallback(const ScrollCallback& callback)
{
	// TODO: write this function
}

GLFWwindow* ViewerWindow::getGLFWHandle() const
{
    return m_ptrHandle;
}
