#include <iostream>
using namespace std;
#include <cstring>
#define LEN sizeof(struct Link)

struct Link
{
    char num[4];
    char name[5];
    double score;
    Link *next;
};

int n;

struct Link *creat(void)
{
    struct Link *head, *p1, *p2;
    p1 = (struct Link *)malloc(LEN);
    n = 0;
    cin >> p1->num;
    cin >> p1->name;
    cin >> p1->score;
    head = NULL;
    while (n >= 0)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct Link *)malloc(LEN);
        cin >> p1->num;
        if (strcmp(p1->num, "#") == 0)
            break;
        cin >> p1->name;
        cin >> p1->score;
    }
    p2->next = NULL;
    return head;
}

void count(struct Link *head)
{
    struct Link *p = head, *min = head, *max = head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->score < min->score)
            min = p;
        if (p->score > max->score)
            max = p;
    }
    cout << endl;
    cout << max->num << " " << max->name << " " << max->score << endl; // 最高分
    cout << min->num << " " << min->name << " " << min->score << endl; // 最低分
}

void add(struct Link *head, char num[])
{
    struct Link *p = head, *q;
    while (p->next->num != NULL)
        p = p->next;
    q = (struct Link *)malloc(LEN);
    strcpy(q->num, num);
    cin >> q->name;
    cin >> q->score;
    p->next = q;
    q->next = NULL;
}

void seek(struct Link *head)
{
    struct Link *p = head;
    cout << "指定学号：";
    char num[4];
    cin >> num;
    cout << endl;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->num, num) == 0)
        {
            cout << p->name << " " << p->score << endl;
            return;
        }
    }
    cout << "查无此人;请输入" << num << "的姓名、成绩：" << endl;
    add(head, num);
}

void print(struct Link *head)
{
    struct Link *p = head;
    while (p != NULL)
    {
        cout << p->num << " " << p->name << " " << p->score;
        p = p->next;
        cout << endl;
    }
}

int main()
{
    struct Link *head;
    cout << "输入学生数据：" << endl;
    head = creat();
    cout << endl;
    cout << "输出链表结果：" << endl;
    print(head);
    cout << endl;
    cout << "成绩最高和最低的学生：";
    count(head);
    cout << endl;
    seek(head);
    cout << endl;
    cout << "输出链表结果：" << endl;
    print(head);
    system("pause");
    return 0;
}