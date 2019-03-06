#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	glm::mat4 getViewMatrix();
private:
	float pitch;
	float roll;
	float yaw;

	glm::vec3 cameraPosition;

	glm::vec3 upVector;
	glm::vec3 rightVector;
	glm::vec3 directionVector;
	glm::vec3 worldUp;

	void eulerToVectors(); //Updates internal vectors
};

