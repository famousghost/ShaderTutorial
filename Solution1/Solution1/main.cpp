#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <Windows.h>
#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "ShaderOpenGL", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cerr << "Cannot create window" << std::endl;
		system("pause");
		return -1;
	}

	glewExperimental = GL_TRUE;

	glfwMakeContextCurrent(window);

	int width, height;
	glfwSetKeyCallback(window, key_callback);
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}