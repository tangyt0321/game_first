#ifndef _SCENE_H_
#define _SCENE_H_

#include <graphics.h>
#include <string>
#include "../Animation/util.h"
#include "../camera.h"

class Scene
{
private:
public:
    Scene() = default;
    ~Scene() = default;
    virtual void on_enter() {}
    virtual void on_update(int delta) {}
    virtual void on_draw() {}
    virtual void on_input(const ExMessage &msg) {}
    virtual void on_exit() {}
};

#endif // !_SCENE_H_