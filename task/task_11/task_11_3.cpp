#include "iostream"
#include "cstring"
#define N 3
#define M 3

using namespace std;

void input(struct student stu[]);
void danke(struct student *p);
void everyone(struct student *p);
void seek(struct student *p);
int seek_name(struct student *p, char *number);

struct student
{
    char num[8];
    char name[10];
    int score[M];
};

void input(struct student stu[])
{
    cout << "请输入学生状况：" << endl;
    cout << "学号\t姓名\t课1\t课2\t课3" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> stu[i].num;
        cin >> stu[i].name;
        for (int j = 0; j < M; j++)
            cin >> stu[i].score[j];
    }
    cout << endl;
}

void danke(struct student *p)
{
    int score;
    for (int i = 0; i < M; i++)
    {
        score = 0;
        for (int j = 0; j < N; j++)
            score += p[j].score[i];
        cout << "课程" << i + 1 << "平均分：" << score / N << endl;
    }
    cout << endl;
}

void everyone(struct student *p)
{
    int score;
    for (int i = 0; i < N; i++)
    {
        score = 0;
        for (int j = 0; j < M; j++)
            score += p[i].score[j];
        cout << "学生" << p[i].name << "的平均分：" << score / N << endl;
    }
    cout << endl;
}

void seek(struct student *p)
{
    int k;
    char number[8];
    cout << "请输入要查询的学生学号：" << endl;
    cin >> number;
    k = seek_name(p, number);
    if (k == -1)
    {
        cout << "查无此人";
        system("pause");
    }
    else
    {
        cout << "查询结果" << p[k].name << endl;
    }
    cout << "课1\t课2\t课3\t" << endl;
    cout << p[k].score[0] << "\t" << p[k].score[1] << "\t" << p[k].score[2] << endl;
}

int seek_name(struct student *p, char *number)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (*(p[i].num + j) != *(number + j))
                break;
            if (j == 7)
                return i;
        }
    }
    return -1;
}

int main()
{
    struct student stu[N];
    input(stu);
    danke(stu);
    everyone(stu);
    seek(stu);
    system("pause");
    return 0;
}
