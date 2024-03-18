#ifndef _ENEMY_
#define _ENEMY_

#include <easyx.h>
#include "../Animation/Animation.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define BOAR_ANIM_NUM 6

class Enemy
{

private:
	const int SPEED = 2;
	const int BOAR_WIDTH = 80;
	const int BOAR_HEIGHT = 80;
	const int SHADOW_ENEMY_WIDTH = 48;

private:
	IMAGE img_enemy_shaow;
	Animation *anim_left;
	Animation *anim_right;
	POINT position = {0, 0};
	bool facing_left = false;

public:
	Enemy()
	{
		loadimage(&img_enemy_shadow, _T("resource/images/enemy/shadow_enemy.png"), 50, 30);
		anim_left = new Animation(_T("resource/images/enemy/boar_left_%d.png"), BOAR_ANIM_NUM, 45, BOAR_WIDTH, BOAR_HEIGHT);
		anim_right = new Animation(_T("resource/images/enemy/boar_right_%d.png"), BOAR_ANIM_NUM, 45, BOAR_WIDTH, BOAR_HEIGHT);
	}
	~Enemy()
	{
		delete anim_left;
		delete anim_right;
	}

	void draw()
	{
		if(facing_left)
			anim_left->draw(position.x, position.y);
		else
			anim_right->draw(position.x, position.y);

		putimage_alpha(position.x, position.y, &img_enemy_shaow);
	}

	void Draw(int delta)
	{
		int pos_shadow_x = position.x + (BOAR_WIDTH / 2 - SHADOW_ENEMY_WIDTH / 2);
		int pos_shadow_y = position.y + (BOAR_HEIGHT / 2 + 30);
		putimage_alpha(pos_shadow_x, pos_shadow_y, &img_enemy_shaow);

		static bool facing_left = false;
		int dir_x = is_move_right - is_move_left;
		if (dir_x < 0)
			facing_left = true;
		else if (dir_x > 0)
			facing_left = false;

		if (facing_left)
			anim_left->Play(position.x, position.y, delta);
		else
			anim_right->Play(position.x, position.y, delta);
	}
};

#endif