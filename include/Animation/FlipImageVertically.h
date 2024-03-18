#pragma once

#include "easyx.h"

// 图片垂直翻转函数
void FlipImageVertically(IMAGE *src, IMAGE *dst)
{
    if (src == nullptr || dst == nullptr)
    {
        return;
    }

    int width = src->getwidth();
    int height = src->getheight();

    // 逐行读取原图片，然后从下往上写入目标图片
    for (int y = 0; y < height; y++)
    {
        getimage(dst, 0, height - y - 1, width, 1, src, 0, y, SRCCOPY);
    }
}