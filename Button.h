#pragma once

class Button
{
public:
    Button();
    ~Button() = default;
}

class StartGameButton : public Button
{
public:
    StartGameButton();
    ~StartGameButton() = default;
}