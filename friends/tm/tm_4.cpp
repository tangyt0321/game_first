#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#define LEN sizeof(struct LNode)
struct LNode
{
    int num;
    struct LNode *next;
};

struct LNode *creat(void)
{
    struct LNode *head, *p1, *p2;
    int i;
    p1 = p2 = (struct LNode *)malloc(LEN);
    cin >> p1->num;
    head = p1;
    while (p1->num != -1)
    {
        p2 = (struct LNode *)malloc(LEN);
        cin >> p2->num;
        p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return head;
}

void print(struct LNode *head, int m)
{
    struct LNode *p = head;
    cout << "输出链表结果:";
    while (p != NULL)
    {
        if (p->num == m)
            break;
        p = p->next;
    }
    if (p == NULL)
        cout << "The " << m << " isn't in the link list.";
    while (p != NULL && p->num != -1)
    {
        cout << "    " << p->num;
        p = p->next;
    }
}

int main()
{
    struct LNode *head;
    char ch;
    int n;
    cout << "输入一组正数,以-1结束:";
    head = creat();
    do
    {
        ch = 'n';
        cout << "输入n值:";
        cin >> n;
        print(head, n);
        cout << endl
             << "是否继续?(y/n)";
        cin >> ch;
    } while (ch == 'y');
}