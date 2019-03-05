#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<map>
#include<string>
#include"Shader.h"

class OpenglApp
{
public:
	OpenglApp();
	~OpenglApp();
	unsigned int startRenderLoop();
private:
	void initialize_window();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow *window);
	void render();
	GLFWwindow* window;
	std::map<std::string, Shader> shaderMap;
};

