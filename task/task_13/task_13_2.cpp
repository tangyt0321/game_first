#include <iostream>
using namespace std;
#define LEN sizeof(struct NUM)

struct NUM
{
    int num;
    NUM *next;
};

int n;

struct NUM *creat(void)
{
    struct NUM *head, *p1, *p2;
    p1 = (struct NUM *)malloc(LEN);
    n = 0;
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
        p1 = (struct NUM *)malloc(LEN);
        cin >> p1->num;
    }
    p2->next = NULL;
    return head;
}

struct NUM *dele(struct NUM *head)
{
    struct NUM *p, *q;
    q = (struct NUM *)malloc(LEN);
    p = head;
    q->next = p;
    head = q;
    while (p != NULL)
    {
        if (p->num % 2 == 0)
            q->next = p->next;
        else
            q = q->next;
        p = p->next;
    }
    head = head->next;
    return head;
}

void print(struct NUM *head)
{
    struct NUM *p = head;
    if (p == NULL)
        cout << "空链表";
    else
        while (p != NULL)
        {
            cout << p->num << " ";
            p = p->next;
        }
    cout << endl;
}

int main()
{
    struct NUM *head;
    cout << "输入：";
    head = creat();
    cout << "原链表：";
    print(head);
    head = dele(head);
    cout << "删除后链表：";
    print(head);
    return 0;
}