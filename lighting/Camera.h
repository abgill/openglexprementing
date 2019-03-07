#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera();
	~Camera();
	static enum Camera_Movement {
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};
	glm::mat4 getViewMatrix();
	void ProcessKeyboard(Camera_Movement direction, float deltaTime);
	void processMouseMovement(float xPos, float yPos);
	
private:
	float pitch;
	float roll;
	float yaw;

	glm::vec3 cameraPosition;

	glm::vec3 upVector;
	glm::vec3 rightVector;
	glm::vec3 directionVector;
	glm::vec3 worldUp;

	float speed = -1.0f; //Set to negative value for fps like controls

	void eulerToVectors(); //Updates internal vectors
	float lastX = 0.0f;
	float lastY = 0.0f;
	float sensivity = .01f;
	
	
};

