#pragma once

#include "scene/scene.h"

class UpgradeScene : public Scene
{
public:
    UpgradeScene();
    ~UpgradeScene();

    void update(float delta) override;
    void render() override;
};
