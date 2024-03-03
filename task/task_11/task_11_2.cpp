#include <iostream>
using namespace std;
#include <cstring>

struct a
{
    char name[4];
    char number[9];
};

void seek(struct a *p);
int seek_name(struct a *p, char *seekname);

void seek(struct a *a)
{
    int k;
    char seekname[3];
    cout << "输入查找电话人的姓名";
    cin >> seekname;
    k = seek_name(a, seekname);
    if (k == -1)
    {
        cout << "未找到该记录";
    }
    else
    {
        cout << "电话号码：" << a[k].number;
    }
}

int seek_name(struct a *p, char *seek_name)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (*(p[i].name + j) != *(seek_name + j))
                break;
            if (j == 2)
                return i;
        }
    }
    return -1;
}

int main()
{
    struct a a[10];
    cout << "输入姓名和电话号码：" << endl;
    for (int i = 0;; i++)
    {
        cin >> a[i].name;
        if (a[i].name[0] == '#')
            break;
        cin >> a[i].number;
    }
    seek(a);
    system("pause");
    return 0;
}