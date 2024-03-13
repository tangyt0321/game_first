#ifndef _ENEMY_
#define _ENEMY_

#include "animation.h"

class Enemy
{

private:
	const int SPEED = 2;
	const int FRAME_WIDTH = 80;
	const int FRAME_HEIGHT = 80;
	const int SHADOW_WIDTH = 48;

private:
	IMAGE img_shaow;
	Animation *anim_left;
	Animation *anim_right;
	POINT position = {0, 0};
	bool facing_left = false;

public:
	Enemy();
	~Enemy();

	void Update();
	void Render();

	void SetPosition(float x, float y);

	float GetPositionX();
	float GetPositionY();

	float GetWidth();
	float GetHeight();
};

#endif