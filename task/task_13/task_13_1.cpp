#include <iostream>
using namespace std;
#define LEN sizeof(struct LNode)

struct LNode
{
    int id;
    LNode *next;
};

int n;

struct LNode *creat(void)
{
    struct LNode *head, *p1, *p2;
    p1 = p2 = (struct LNode *)malloc(LEN);

    cin >> p1->id;
    head = p1;
    for (n = 1; n < 10; n++)
    {
        p1 = (struct LNode *)malloc(LEN);
        cin >> p1->id;
        p2->next = p1;
        p2 = p1;
    }
    p1->next = NULL;
    return head;
}

struct LNode *move(struct LNode *head, int m)
{
    struct LNode *p = head, *s, *t;
    s = t = NULL;
    // t = (struct LNode *)malloc(LEN);
    for (int count = 1; count < 10; count++)
    {
        if (count == m - 1)
        {
            t = p->next;
        }
        p = p->next;
    }
    p->next = head;
    head = t;
    p = head;
    for (int count = 1; count < 10; count++)
        p = p->next;
    p->next = NULL;
    return head;
}

void print(struct LNode *head)
{
    struct LNode *p = head;
    while (p != NULL)
    {
        cout << p->id << "  ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    struct LNode *head;
    int m;
    cout << "输入：";
    head = creat();
    cout << "n值：";
    cin >> m;
    head = move(head, m);
    cout << "输出：" << endl;
    print(head);
    return 0;
}