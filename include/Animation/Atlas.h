#pragma once

#include <vector>
#include <easyx.h>

class Atlas
{
public:
    std::vector<IMAGE> img_List;

public:
    Atlas() = default;
    ~Atlas() = default;

    // Atlas(LPCTSTR path, int num, int width = 0, int height = 0)
    // {
    //     TCHAR path_file[256];
    //     for (size_t i = 0; i < num; i++)
    //     {
    //         sprintf(path_file, path, i);
    //         IMAGE *frame = new IMAGE();
    //         loadimage(frame, path_file, width, height);
    //         img_List.push_back(frame);
    //     }
    // }
    // ~Atlas()
    // {
    //     for (size_t i = 0; i < img_List.size(); i++)
    //     {
    //         delete img_List[i];
    //     }
    // }

    void Load_from_file(LPCTSTR path_template, int num, int width = 0, int height = 0)
    {
        img_List.clear();
        img_List.resize(num);
        TCHAR path_file[256];
        for (int i = 0; i < num; i++)
        {
            sprintf(path_file, path_template, i);
            loadimage(&img_List[i], path_file, width, height);
        }
    }

    void clear()
    {
        img_List.clear();
    }

    int get_size()
    {
        return (int)img_List.size();
    }

    IMAGE *get_img(int index)
    {
        if (index < 0 || index >= img_List.size())
            return nullptr;
        return &img_List[index];
    }

    void add_img(const IMAGE &img)
    {
        img_List.push_back(img);
    }
};
