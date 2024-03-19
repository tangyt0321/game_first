#pragma once

#include <vector>
#include <easyx.h>


class Atlas
{
public:
    std::vector<IMAGE *> frame_list;

public:
    Atlas(LPCTSTR path, int num, int width = 0, int height = 0)
    {
        TCHAR path_file[256];
        for (size_t i = 0; i < num; i++)
        {
            sprintf(path_file, path, i);

            IMAGE *frame = new IMAGE();
            loadimage(frame, path_file, width, height);
            frame_list.push_back(frame);
        }
    }

    ~Atlas()
    {
        for (size_t i = 0; i < frame_list.size(); i++)
        {
            delete frame_list[i];
        }
    }
};

Atlas *atlas_player_left = nullptr;
Atlas *atlas_player_right = nullptr;
Atlas *atlas_enemy_left = nullptr;
Atlas *atlas_enemy_right = nullptr;