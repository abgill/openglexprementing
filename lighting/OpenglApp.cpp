#include "OpenglApp.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>


OpenglApp::OpenglApp()
{
	this->window = NULL;
	initialize_window();
}


OpenglApp::~OpenglApp()
{
}

unsigned int OpenglApp::startRenderLoop()
{
	while (!glfwWindowShouldClose(this->window)) {
		this->render();
	}

	return 0;
}

void OpenglApp::initialize_window()
{
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, this->framebuffer_size_callback );

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

void OpenglApp::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void OpenglApp::processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void OpenglApp::render()
{
	
	// input
	// -----
	processInput(window);
		
	// render
	// ------
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
		
	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------
	glfwSwapBuffers(window);
	glfwPollEvents();
}

