#pragma once

#include "easyx.h"

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