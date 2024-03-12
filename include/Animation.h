#ifndef ANIMATION_H
#define ANIMATION_H

#include <easyx.h>
#include <vector>
#include <iostream>

#define PLAYER_ANIM_NUM 6

// 批量处理图片
IMAGE img_player[PLAYER_ANIM_NUM];
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
    int timer = 0;     // 动画计时器
    int idx_frame = 0; // 动画帧索引
    int interval_ms = 0;
    std::vector<IMAGE *> frame_list;

public:
    Animation(LPCTSTR path, int num, int interval, int width = 0, int height = 0)
    {
        interval_ms = interval;
        TCHAR path_file[256];
        for (size_t i = 0; i < num; i++)
        {
            sprintf(path_file, path, i);
            std::cout << path_file << std::endl;

            IMAGE *frame = new IMAGE();
            loadimage(frame, path_file, width, height);
            frame_list.push_back(frame);
        }
    }

    ~Animation()
    {
        for (size_t i = 0; i < frame_list.size(); i++)
            delete frame_list[i];
    }

    void Play(int x, int y, int dalta)
    {
        timer += dalta;
        if (timer >= interval_ms)
        {
            timer = 0;
            idx_frame = (idx_frame + 1) % frame_list.size();
        }

        putimage_alpha(x, y, frame_list[idx_frame]);
    }
};

#endif