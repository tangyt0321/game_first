#include "iostream"
#include "cstring"
#define N 3

using namespace std;

void input(struct good stu[]);
void seek(struct good *p);
int seek_name(struct good *p, char *number);
void count(struct good *p, int num);

struct good
{
    char num[8];
    char name[5];
    float value;
    int count;
};

void input(struct good *a)
{
    cout << "请输入商品数据：" << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i].num;
        cin >> a[i].name;
        cin >> a[i].value;
        cin >> a[i].count;
    }
    cout << endl;
}

void seek(struct good *p, char *code)
{
    int k;
    k = seek_name(p, code);
    if (k == -1)
        cout << "查无此商品！";
    else
    {
        cout << "名称\t单价\t库存量" << endl;
        cout << p[k].name << "\t" << p[k].value << "\t" << p[k].count << endl;
    }
}

int seek_name(struct good *p, char *number)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (strcmp(p[i].num, number) == 0)
            return i;
    }
    return -1;
}

void count(struct good *p, int num)
{
    cout << "需要补货的信息：" << endl;
    int i;
    for (i = 0; i < N; i++)
    {
        if (p[i].count < num)
        {
            cout << p[i].num << "\t" << p[i].name << "\t" << p[i].value << endl;
        }
    }
}

int main()
{
    struct good stu[N];
    input(stu);
    cout << "请输入要搜索商品的编码：";

    char code[8];
    cin >> code;
    seek(stu, code);
    cout << endl;

    cout << "请输入要清点的最低库存量：";
    int min;
    cin >> min;
    cout << endl;

    count(stu, min);
    cout << endl;

    cout << "需要补货的总金额：";
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (stu[i].count < min)
            sum = sum + stu[i].value * (min - stu[i].count);
    }
    cout << sum;
    cout << endl;

    system("pause");
    return 0;
}
