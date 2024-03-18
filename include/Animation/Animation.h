#ifndef _ANIMATION_H_
#define _ANIMATION_H_


#include "Atlas.h"

class Animation
{
private:
    int timer = 0;     // 动画计时器
    int idx_frame = 0; // 动画帧索引
    int interval_ms = 0;

private:
    Atlas *anim_atlas;

public:
    Animation(Atlas *atlas, int interval)
    {
        anim_atlas = atlas;
        interval_ms = interval;
    }

    ~Animation();

    void Play(int x, int y, int dalta)
    {
        timer += dalta;
        if (timer >= interval_ms)
        {
            idx_frame = (idx_frame + 1) % anim_atlas->frame_list.size();
            timer = 0;
        }

        putimage_alpha(x, y, anim_atlas->frame_list[idx_frame]);
    }
};

#endif