#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "Atlas.h"
#include "util.h"

#include <functional>

class Animation
{
private:
    int timer = 0;       // 计时器
    int idx_frame = 0;   // 动画帧索引
    int interval_ms = 0; // 动画间隔时间
    bool is_loop = true; // 是否循环播放
    std::function<void()> callback;

private:
    Atlas *anim_atlas;

public:
    Animation() = default;
    ~Animation() = default;

    void reset()
    {
        timer = 0;
        idx_frame = 0;
    }

    void set_atlas(Atlas *new_atlas)
    {
        reset();
        anim_atlas = new_atlas;
    }

    void set_loop(bool flag)
    {
        is_loop = flag;
    }

    void set_interval(int ms)
    {
        interval_ms = ms;
    }

    int get_idx_frame()
    {
        return idx_frame;
    }

    IMAGE *get_frame()
    {
        return anim_atlas->get_img(idx_frame);
    }

    bool check_end()
    {
        if (is_loop)
            return false;
        return (idx_frame == anim_atlas->get_size() - 1);
    }

    void on_update(int dalta)
    {
        timer += dalta;
        if (timer >= interval_ms)
        {
            timer = 0;
            idx_frame++;
            if (idx_frame >= anim_atlas->get_size())
            {
                idx_frame = is_loop ? 0 : anim_atlas->get_size() - 1;
                if (is_loop && callback)
                    callback();
            }
        }
    }

    void on_draw(const Camera &Camera, int x, int y) const
    {
        putimage_alpha(Camera, x, y, anim_atlas->get_img(idx_frame));
    }

    void set_callback(std::function<void()> callback)
    {
        this->callback = callback;
    }
};

#endif