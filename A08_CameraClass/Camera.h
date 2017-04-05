#pragma once
//#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>
class Camera {
	//static Camera* s_camera; // singleton
public:
	vector3 camPos, camTarget, camUp;
	matrix4 projOrth, projPerp;
	matrix4 view, proj;
	quaternion q1;

	float rPercent;

	float roll, pitch, yaw;

	/*static Camera* GetInstance();
	static void ReleaseInstance();*/

	matrix4 GetView(void); //get view matrix
	matrix4 GetProjection(bool bOrthographic); // get proj matrix, choose between perspective or orthographic

	void SetPosition(vector3 v3Position); // set position of camera
	void SetTarget(vector3 v3Target); // set target of camera
	void SetUp(vector3 v3Up); // set up vector of camera

	void MoveForward(float fIncrement); // move camera forward/backward depending on view vector
	void MoveSideways(float fIncrement); // move camera based on right vector depending on view vector
	void MoveVertical(float fIncrement); // move camera up or down depending on up vector
	void ChangePitch(float fIncremenet); // orient your camera (meaning the forward and up vectors) changing its angle in x
	void ChangeRoll(float fIncrement); // orient your camera changing its angle in z
	void ChangeYaw(float fIncrement); // orient your camera changing its angle in y

	Camera();
	~Camera();
};