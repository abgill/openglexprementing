#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Camera::Camera()
{
	this->cameraPosition = glm::vec3(0.0f, 0.0f, -3.0f);

	this->upVector = glm::vec3(0.0f, 1.0f, 0.0f);

	this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	
	this->pitch = 10.0f;
	this->yaw = -90.0f;
	this->roll = 0;

	//directionVector = glm::vec3(0.0f, 0.0f, 1.0f);

	eulerToVectors(); //Update internal vectors using euler 
}


Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(cameraPosition, cameraPosition - directionVector, upVector);
}

void Camera::eulerToVectors()
{
	this->directionVector.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->directionVector.y = sin(glm::radians(this->pitch));
	this->directionVector.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

	this->directionVector = glm::normalize(directionVector);

	this->rightVector = glm::normalize(glm::cross(directionVector, worldUp));

	this->upVector = glm::normalize(glm::cross(rightVector, directionVector));
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
	float velocity = this->speed * deltaTime;
	if (direction == FORWARD)
		cameraPosition += directionVector * velocity;
	if (direction == BACKWARD)
		cameraPosition -= directionVector * velocity;
	if (direction == LEFT)
		cameraPosition -= rightVector * velocity;
	if (direction == RIGHT)
		cameraPosition += rightVector * velocity;

	eulerToVectors();
}

void Camera::processMouseMovement(float xPos, float yPos)
{
	this->yaw += (xPos - this->lastX) * sensivity; 
	yaw = glm::mod(yaw, 360.0f);
	this->pitch += (yPos - this->lastY) * sensivity;
	
	if (this->pitch > 85.5f) {
		this->pitch = 85.5f;
	}
	if (this->pitch < -85.5f) {
		this->pitch = -85.5f;
	}

	this->lastX = xPos;
	this->lastY = yPos;

	eulerToVectors();
}
