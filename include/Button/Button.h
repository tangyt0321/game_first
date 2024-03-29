#pragma once

#include <easyx.h>

class Button
{
public:
    Button()
    {
    }
    ~Button()
    {
    }

private:
    enum class Status
    {
        hover,
        click,
        normal
    };

private:
    RECT regin;
    IMAGE img

}

class StartGameButton : public Button
{
public:
    StartGameButton();
    ~StartGameButton() = default;
}