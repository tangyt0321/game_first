#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "Atlas.h"
#include "FlipImageVertically.h"

#include <functional>


// 修改图片为背景透明图片
#pragma comment(lib, "msimg32.lib")
inline void putimage_alpha(int x, int y, IMAGE *img)
{
    size_t w = img->getwidth();
    size_t h = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h,
               GetImageHDC(img), 0, 0, w, h, {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA});
}

class Animation
{
private:
    int timer = 0;       // 计时器
    int idx_frame = 0;   // 动画帧索引
    int interval_ms = 0; // 动画间隔时间
    bool is_loop = true; // 是否循环播放
    Atlas *atlas = nullptr;
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

    void on_draw(int x, int y) const
    {
        putimage_alpha(x, y, anim_atlas->get_img(idx_frame));
    }

    void set_callback(std::function<void()> callback)
    {
        this->callback = callback;
    }

    // void Play(int x, int y, int dalta)
    // {
    //     timer += dalta;
    //     if (timer >= interval_ms)
    //     {
    //         idx_frame = (idx_frame + 1) % anim_atlas->img_List.size();
    //         timer = 0;
    //     }
    //     putimage_alpha(x, y, &(anim_atlas->img_List[idx_frame]));
    // }
};

#endif