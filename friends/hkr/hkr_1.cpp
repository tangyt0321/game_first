#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct LNode
{
    int num;
    struct LNode *next;
};

int n; //

struct LNode *creat(void)
{
    struct LNode *p1, *p2, *head;
    p1 = (struct LNode *)malloc(sizeof(struct LNode));
    cout << "输入：" << endl;
    cin >> p1->num;
    head = NULL;
    // head = p1;
    n = 0; //
    while (p2->num != -1)
    {
        n++; //
        if (n == 1)
            head = p1;
        else
            p1 = p2;
        p2 = (struct LNode *)malloc(sizeof(struct LNode));
        p1->next = p2;
        cin >> p2->num;
    }
    p1->next = NULL;
    return (head);
}

void print(struct LNode *head)
{
    struct LNode *p = head;
    if (head == NULL)
        cout << "空链表";
    else
        while (p != NULL)
        {
            cout << p->num << " ";
            p = p->next;
        }
    cout << endl;
}

struct LNode *dele(struct LNode *head)
{
    struct LNode *p1 = head, *p2;
    while (p1 != NULL)
    {
        if (head->num % 2 == 0)
            head = head->next;
        else
            break;
        p1 = p1->next;
    }
    if (head != NULL)
        p2 = head->next;
    while (p2 != NULL && head != NULL)
    {
        if (p2->num % 2 == 0)
            p1->next = p2->next;
        else
        {
            p1->next = p1;
        }
        p2 = p2->next;
    }
    return (head);
}
int main()
{
    struct LNode *head;
    head = creat();
    cout << "原链表：";
    print(head);
    head = dele(head);
    cout << "删除后链表：";
    print(head);
    return 0;
}