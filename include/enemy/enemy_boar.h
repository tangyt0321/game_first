#pragma once

#include "enemy.h"
#include <vector>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int random_id;

extern Atlas atlas_enemy_boar_left;
extern Atlas atlas_enemy_boar_right;
extern IMAGE img_enemy_boar_shadow;

extern Camera main_camera;

const int BOAR_ANIM_NUM = 6;
const int BOAR_WIDTH = 80;		   // 野猪宽度
const int BOAR_HEIGHT = 80;		   // 野猪高度
const int SHADOW_ENEMY_WIDTH = 48; // 阴影宽度

class EnemyBoar : public Enemy
{
private:
	Animation anim_left;
	Animation anim_right;
	bool facing_left = false;
	bool is_alive = true;
	const size_t HP_MAX = 3;
	size_t HP = HP_MAX;
	const int SPEED = 4;

public:
	EnemyBoar()
	{
		anim_left.set_atlas(&atlas_enemy_boar_left);
		anim_left.set_interval(45);
		anim_right.set_atlas(&atlas_enemy_boar_right);
		anim_right.set_interval(45);

		// 怪刷新位置
		srand(random_id);
		position.x = rand() % (WINDOW_WIDTH - BOAR_WIDTH);
		position.y = rand() % (WINDOW_HEIGHT - BOAR_HEIGHT);
	}

	~EnemyBoar() = default;

	// 玩家碰撞
	bool CheckPlayerConllision(const Player &player)
	{
		POINT check_pos = {position.x + BOAR_WIDTH / 2, position.y + BOAR_HEIGHT / 2};
		bool is_overlap_x = player.position.x < check_pos.x && player.position.x + player.PLAYER_WIDTH / 2 > check_pos.x;
		bool is_overlap_y = player.position.y < check_pos.y && player.position.y + player.PLAYER_HEIGHT / 2 > check_pos.y;
		return is_overlap_x && is_overlap_y;
	}

	// 子弹碰撞
	bool CheckBulletConllision(const Bullet *bullet)
	{
		bool is_overlap_x = bullet->position.x > position.x && bullet->position.x < position.x + BOAR_WIDTH;
		bool is_overlap_y = bullet->position.y > position.y && bullet->position.y < position.y + BOAR_HEIGHT;
		return is_overlap_x && is_overlap_y;
	}

	void hurt()
	{
		HP--;
		if (HP <= 0)
			is_alive = false;
	}

	bool isAlive() const
	{
		return is_alive;
	}

	void Move(const Player &player)
	{
		const POINT &player_pos = player.GetPosition();
		int dir_x = player_pos.x - position.x;
		int dir_y = player_pos.y - position.y;
		double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (len_dir >= 1)
		{
			double normailized_x = dir_x / len_dir;
			double normailized_y = dir_y / len_dir;
			position.x += (int)(normailized_x * SPEED);
			position.y += (int)(normailized_y * SPEED);
		}
		if (dir_x < 0)
			facing_left = true;
		else if (dir_x > 0)
			facing_left = false;
	}

	void Draw(int delta)
	{
		int pos_shadow_x = position.x + (BOAR_WIDTH / 2 - SHADOW_ENEMY_WIDTH / 2);
		int pos_shadow_y = position.y + (BOAR_HEIGHT / 2 + 5);
		putimage_alpha(main_camera, pos_shadow_x, pos_shadow_y, &img_enemy_boar_shadow);

		// static bool facing_left = false;
		// int dir_x = is_move_right - is_move_left;

		if (facing_left)
		{
			anim_left.on_update(delta);
			anim_left.on_draw(main_camera, position.x, position.y);
		}
		else
		{
			anim_right.on_update(delta);
			anim_right.on_draw(main_camera, position.x, position.y);
		}

		if (is_debug_mode)
		{
			// 绘制血条
			int hp_left = position.x + (BOAR_WIDTH / 2 - HP_MAX * 20 / 2);
			int hp_top = position.y + 10;
			int hp_bottom = position.y;
			int hp_width = hp_left + HP_MAX * 20;
			int hp_right = hp_left + HP * 20;
			setfillcolor(BLACK);
			fillrectangle(hp_left - 1, hp_top + 1, hp_width + 1, hp_bottom - 1);
			setfillcolor(RED);
			fillrectangle(hp_left, hp_top, hp_right, hp_bottom);

			// 绘制碰撞箱
			int box_left = position.x + (BOAR_WIDTH / 2 - 20);
			int box_top = position.y + (BOAR_HEIGHT / 2 - 20);
			int box_right = position.x + (BOAR_WIDTH / 2 + 20);
			int box_bottom = position.y + (BOAR_HEIGHT / 2 + 20);
			setlinecolor(BLUE);
			rectangle(box_left, box_top, box_right, box_bottom);
		}
	}
};
