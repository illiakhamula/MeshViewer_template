#include "ViewerWindow.h"
#include "OpenglRenderSystem.h"
#include "GeometryPrimitives.h"

#include <glm/gtc/matrix_transform.hpp>

void renderScene(OpenglRenderSystem& rs)
{
    static const auto& data = GeometryPrimitives::createCubeVertices();
    rs.renderTriangleSoup(data);
}

void moveCube(OpenglRenderSystem& rs, glm::vec3 offset)
{
	rs.setViewMatrix(glm::translate(rs.getViewMatrix(), offset));
}

int main()
{
	constexpr int width = 640;
	constexpr int height = 480;

	OpenglRenderSystem rs;
	ViewerWindow window("myWindow", width, height);

	window.setKeyCallback([&rs](KeyCode key, Action action, Modifier mods)
	{
		if (key == KeyCode::UP)
			moveCube(rs, { 0, 0.1, 0 });

		if (key == KeyCode::DOWN)
			moveCube(rs, { 0, -0.1, 0 });

		if (key == KeyCode::LEFT)
			moveCube(rs, { 0.1, 0, 0 });

		if (key == KeyCode::RIGHT)
			moveCube(rs, { -0.1, 0, 0 });
	});

	rs.init();
	rs.setupLight(0, glm::vec3( 0,5,0 ), glm::vec3( 1,0,0 ), glm::vec3( 0,1,0 ), glm::vec3( 0,0,1 ));
	rs.turnLight(0, true);

	//glm::vec3 cameraPosition(2.0f, 2.0f, -3.0f);
	glm::vec3 cameraPosition(0.0f, 0.0f, -3.0f);
	glm::vec3 lookAtCenter(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUpVector(0.0f, 1.0f, 0.0f);

	glm::mat4 viewMatrix = glm::lookAt(cameraPosition, lookAtCenter, cameraUpVector);
	rs.setViewMatrix(viewMatrix);

	glm::mat4 projMatrix = glm::perspective(glm::radians(60.0f), float(width) / float(height), 0.1f, 500.f);
	rs.setProjectionMatrix(projMatrix);

	while (!glfwWindowShouldClose(window.getGLFWHandle()))
	{
		rs.setViewport(0, 0, window.getWidth(), window.getHeight());
		rs.clearDisplay(0.5f, 0.5f, 0.5f);
		renderScene(rs);
		glfwSwapBuffers(window.getGLFWHandle());
		glfwWaitEvents();
	}

    return 0;
}
