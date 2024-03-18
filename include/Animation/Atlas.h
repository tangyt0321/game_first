#pragma once

#include <vector>
#include <easyx.h>

// 批量处理图片
// IMAGE img_player[PLAYER_ANIM_NUM];
// 修改图片为背景透明图片
#pragma comment(lib, "msimg32.lib")
inline void putimage_alpha(int x, int y, IMAGE *img)
{
    size_t w = img->getwidth();
    size_t h = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h,
               GetImageHDC(img), 0, 0, w, h, {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA});
}

class Atlas
{
public:
    std::vector<IMAGE *> frame_list;

public:
    Atlas(LPCTSTR path, int num, int width = 0, int height = 0)
    {
        TCHAR path_file[256];
        for (size_t i = 0; i < num; i++)
        {
            sprintf(path_file, path, i);

            IMAGE *frame = new IMAGE();
            loadimage(frame, path_file, width, height);
            frame_list.push_back(frame);
        }
    }

    ~Atlas()
    {
        for (size_t i = 0; i < frame_list.size(); i++)
        {
            delete frame_list[i];
        }
    }
};

Atlas *atlas_player_left = nullptr;
Atlas *atlas_player_right = nullptr;
Atlas *atlas_enemy_left = nullptr;
Atlas *atlas_enemy_right = nullptr;