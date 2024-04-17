#pragma once

#include <chrono>
#include <functional>

class Timer
{
private:
    int pass_time = 0;              // 已过时间
    int wait_time = 0;              // 等待时间
    bool paused = false;             // 是否暂停
    bool shotted = false;           // 是否触发
    bool one_shot = false;          // 是否单次触发
    std::function<void()> callback; // 触发回调

public:
    Timer() = default;
    ~Timer() = default;

    void restart()
    {
        pass_time = 0;
        shotted = false;
    }

    void set_wait_time(int val)
    {
        wait_time = val;
    }

    void set_one_shot(bool flag)
    {
        one_shot = flag;
    }

    void set_callback(std::function<void()> func)
    {
        this->callback = func;
    }

    void pause()
    {
        paused = true;
    }

    void resume()
    {
        paused = false;
    }

    void update(int delta_time)
    {
        if (paused)
            return;

        pass_time += delta_time;

        if (pass_time >= wait_time)
        {
            if ((!one_shot || (one_shot && !shotted)) && callback)
                callback();
            shotted = true;
            pass_time = 0;
        }
    }

protected:
    // virtual void callback()
    // {
    //     // do something here
    // }
};