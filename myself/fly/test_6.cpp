#include <graphics.h>
#include <conio.h>


int main()
{
    // 初始化图形界面
    initgraph(640, 480); // 设置窗口大小

    // 加载背景图片
    IMAGE bgImage;
    loadimage(&bgImage, _T("background.png")); // 加载JPG图片

    // 检查图片是否成功加载
    if (bgImage.gethandle() == NULL)
    {
        // 如果图片加载失败，输出错误信息并退出
        printf("Failed to load background image.\n");
        getch();
        closegraph();
        return -1;
    }

    // 绘制背景图片
    putimage(0, 0, &bgImage); // 在(0, 0)位置绘制图片

    // 你可以在这里添加其他绘图代码，比如随鼠标移动的球

    // 等待用户按键，然后关闭图形界面
    _getch();
    closegraph();

    // 释放图像资源
    //destroyimage(&bgImage);

    return 0;
}