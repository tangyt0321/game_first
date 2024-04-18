#pragma once

#include "easyx.h"
#include "../camera.h"

// 图片垂直翻转函数
inline void FlipImageVertically(IMAGE *src, IMAGE *dst)
{
    int w = src->getwidth();
    int h = src->getheight();
    Resize(dst, w, h);
    DWORD *src_buffer = GetImageBuffer(src);
    DWORD *dst_buffer = GetImageBuffer(dst);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int src_index = y * w + x;
            int dst_index = y * w + (w - x - 1);
            dst_buffer[dst_index] = src_buffer[src_index];
        }
    }
}

// 修改图片为背景透明图片
#pragma comment(lib, "msimg32.lib")
inline void putimage_alpha(int dst_x, int dst_y, IMAGE *img)
{
    int width = img->getwidth();
    int height = img->getheight();
    AlphaBlend(GetImageHDC(GetWorkingImage()), dst_x, dst_y, width, height,
               GetImageHDC(img), 0, 0, width, height, {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA});
}
inline void putimage_alpha(const Camera &camera, int dst_x, int dst_y, IMAGE *img)
{
    int width = img->getwidth();
    int height = img->getheight();
    const Vector2 &pos_camera = camera.get_position();
    AlphaBlend(GetImageHDC(GetWorkingImage()), (int)(dst_x - pos_camera.x), (int)(dst_y - pos_camera.y),
               width, height, GetImageHDC(img), 0, 0, width, height, {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA});
}
inline void rectangle(const Camera &camera, int x1, int y1, int x2, int y2, COLORREF color) 
{
    setlinecolor(color);
    const Vector2 &pos_camera = camera.get_position();
    rectangle((int)(x1 - pos_camera.x), (int)(y1 - pos_camera.y), (int)(x2 - pos_camera.x), (int)(y2 - pos_camera.y));
}

void outtextxy_shaded(int x, int y, LPCTSTR str, int r = 0, int g = 0, int b = 0, int size_x = 12, int size_y = 12, LPCTSTR font = _T("Arial"))
{
    settextstyle(size_x, size_y, font);
    settextcolor(RGB(45, 45, 45));
    outtextxy(x + 3, y + 3, str);
    settextcolor(RGB(255, 255, 255));
    outtextxy(x, y, str);
}