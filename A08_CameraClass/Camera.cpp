#include "Camera.h"


Camera::Camera(){
	camPos = vector3(0.0f, 0.0f, -15.0f);
	camTarget = vector3(0.0f, 0.0f, 0.0f);
	camUp = vector3(0.0f, 1.0f, 0.0f);

	projOrth = glm::ortho(-10.80f, 10.80f, -7.68f, 7.68f, 0.01f, 1000.0f);
	projPerp = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);

	roll = 0.0f;
	pitch = 0.0f;
	yaw = 0.0f;
}

Camera::~Camera()
{
}

/*Camera * Camera::GetInstance()
{
	if (s_camera == nullptr) {
		s_camera = new Camera();
	}
	return s_camera;
}

void Camera::ReleaseInstance()
{
	if (s_camera != nullptr) {
		delete s_camera;
		s_camera = nullptr;
	}
}*/

matrix4 Camera::GetView(void)
{
	q1 = glm::quat(vector3(pitch, roll, yaw));
	view = glm::lookAt(camPos, camTarget, camUp);
	return glm::toMat4(q1) * glm::translate(camPos);
}

matrix4 Camera::GetProjection(bool bOrthographic)
{
	if (bOrthographic) {
		proj = projOrth;
	}
	else {
		proj = projPerp;
	}
	return proj;
}

void Camera::SetPosition(vector3 v3Position)
{
	camPos = v3Position;
}

void Camera::SetTarget(vector3 v3Target)
{
	camTarget = v3Target;
}

void Camera::SetUp(vector3 v3Up)
{
	camUp = v3Up;
}

void Camera::MoveForward(float fIncrement)
{
	camPos.z += fIncrement;
	camTarget.z += fIncrement;
}

void Camera::MoveSideways(float fIncrement)
{
	camPos.x += fIncrement;
	camTarget.x += fIncrement;
}

void Camera::MoveVertical(float fIncrement)
{
	camPos.y += fIncrement;
	camTarget.y += fIncrement;
}

void Camera::ChangePitch(float fIncrement)
{
	pitch += fIncrement;
}

void Camera::ChangeRoll(float fIncrement)
{
	roll += fIncrement;
}

void Camera::ChangeYaw(float fIncrement)
{
	yaw += fIncrement;
}
