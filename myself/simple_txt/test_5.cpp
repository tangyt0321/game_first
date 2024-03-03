#include <iostream>
using namespace std;
#define MAX sizeof(struct stu)

struct stu
{
    int num;
    stu *next;
};

struct stu *creat(void)
{
    struct stu *head, *p2, *p1;
    int n = 0;
    p1 = (struct stu *)malloc(MAX);
    cin >> p1->num;
    head = NULL;
    while (p1->num != -1)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct stu *)malloc(MAX);
        cin >> p->num;
    }
    p2->next = NULL;
    return head;
}

void print(struct stu *head)
{
    struct stu *p = head;
    while (p != NULL)
    {
        cout << p->num;
        p = p->next;
    }
}

int main()
{
    struct stu *head;
    head = creat();
    print(head);
    system("pause");
    return 0;
}