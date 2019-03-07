#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<map>
#include<string>
#include"Shader.h"
#include"Camera.h"
#include<iostream>

class OpenglApp
{
public:
	OpenglApp();
	~OpenglApp();
	unsigned int startRenderLoop();
	Camera camera;
	
private:
	void initialize_window();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow *window);
	void render();
	GLFWwindow* window;
	std::map<std::string, Shader> shaderMap;
	std::map<std::string,unsigned int> VBOMap;
	std::map<std::string,unsigned int> VAOMap;
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	

	float deltaTime = 0.0f;	// time between current frame and last frame
	float lastFrame = 0.0f;

	static void mouse_callback(GLFWwindow * window, double xpos, double ypos)
	{
		auto self = static_cast<OpenglApp*>(glfwGetWindowUserPointer(window)); // Get pointer to current application object
		self->camera.processMouseMovement(xpos, ypos);
	}

};

