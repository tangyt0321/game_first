#include <graphics.h>
#include <conio.h>
#include <time.h>

#define ENEMY_SIZE 20
#define BULLET_SIZE 5
#define BULLET_SPEED 5
#define ENEMY_SPEED 3
#define PLAYER_SIZE 40

int main()
{
    initgraph(1024, 1000);

    IMAGE bgImage;
    loadimage(&bgImage, _T("background.png"));
    putimage(0, 0, &bgImage);

    IMAGE player;
    loadimage(&player, _T("plane.png")); // 加载PNG图片

  
    POINT p_pos = {0, 0};
    
    while (!_kbhit())
    {
        MOUSEMSG m = GetMouseMsg();
        if (m.uMsg == WM_MOUSEMOVE)
        {
            p_pos.x = m.x - player.getwidth() / 2; // 调整位置以匹配图像中心
            p_pos.y = m.y - player.getheight() / 2;
        }

        // 清空屏幕
        cleardevice();

        // 绘制球（使用图像）
        putimage(p_pos.x, p_pos.y, &player);

        // Sleep(10);
    }

    // 释放图像资源
    // destroyimage(&player);

    // 关闭图形界面
    closegraph();

    return 0;
}