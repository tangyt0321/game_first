#include <iostream>
using namespace std;
#define LEN sizeof(struct LNode)

struct LNode
{
    int num;
    LNode *next;
};

int n;

struct LNode *creat(void)
{
    cout << "输入一组正整数（以-1结束）：";
    struct LNode *head, *p1, *p2;
    p1 = (struct LNode *)malloc(LEN);
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
        p1 = (struct LNode *)malloc(LEN);
        cin >> p1->num;
    }
    p2->next = NULL;
    return head;
}

void print(struct LNode *head, int m)
{
    cout << "输出链表结果：";
    struct LNode *p;
    p = head;

    for (int count = 0;; count++, p = p->next)
    {
        if (count >= n)
        {
            cout << "the number " << m << " is not in the link-list";
            break;
        }
        if (p->num == m)
            break;
    }
    while (p != NULL)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    struct LNode *head;
    int m;
    char ch;
    head = creat();
    while (ch != 'n')
    {
        cout << "输入m值：";
        cin >> m;
        print(head, m);
        cout << "是否继续？(y/n)：";
        getchar();
        ch = getchar();
        cout << endl;
    }
    return 0;
}