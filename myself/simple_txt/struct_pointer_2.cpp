#include <iostream>
using namespace std;
#define LEN sizeof(struct NUM)

struct NUM
{
    int id;

    NUM *next;
};

int n;

void print(struct NUM *head);

struct NUM *creat(void)
{
    struct NUM *head, *p1, *p2;
    p1 = p2 = (struct NUM *)malloc(LEN);
    n = 0;
    head = NULL;
    cin >> p1->id;
    while (p1->id != -1)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct NUM *)malloc(LEN);
        cin >> p1->id;
    }
    p2->next = NULL;
    return head;
}

struct NUM *index(struct NUM *head, int m)
{
    struct NUM *p = head, *q, *s;
    q = s = (struct NUM *)malloc(LEN);
    s->id = m;
    q->next = p;

    if (m <= p->id)
    {
        s->next = p;
        head = s;
        return head;
    }
    while (p != NULL)
    {
        if (p->id >= s->id && q->id <= s->id)
        {
            q->next = s;
            s->next = p;
            return head;
        }
        else if (p->next == NULL)
        {
            p->next = s;
            s->next = NULL;
            return head;
        }
        p = p->next;
        q = q->next;
    }
}

void print(struct NUM *head)
{
    struct NUM *p = head;
    while (p != NULL)
    {
        cout << p->id << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    struct NUM *head;
    int m;
    head = creat();
    for (int i = 0; i < 20; i++)
    {
        cout << "input the number:";
        cin >> m;
        head = index(head, m);
        print(head);
    }

    system("pause");
    return 0;
}