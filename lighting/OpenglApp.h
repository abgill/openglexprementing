#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<map>
#include<string>
#include"Shader.h"
#include"Camera.h"

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
	std::map<std::string,unsigned int> VBOMap;
	std::map<std::string,unsigned int> VAOMap;
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	Camera camera;

	float deltaTime = 0.0f;	// time between current frame and last frame
	float lastFrame = 0.0f;
};

