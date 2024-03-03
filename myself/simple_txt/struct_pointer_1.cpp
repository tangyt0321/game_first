#include <iostream>
using namespace std;
#define LEN sizeof(struct student)

struct student
{
    int id;
    int age;
    int score;
    student *next;
};

int n;

struct student *creat(void)
{
    struct student *head, *p1, *p2;
    p1 = p2 = (struct student *)malloc(LEN);
    n = 0;
    head = NULL;
    cout << "please input the " << n + 1 << " student information:" << endl;
    cin >> p1->age >> p1->id >> p1->score;
    while (p1->age != -1)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct student *)malloc(LEN);
        cout << "please input the " << n + 1 << " student information:";
        cout << endl;
        cin >> p1->age >> p1->id >> p1->score;
    }
    p2->next = NULL;
    return head;
}

void print(struct student *head)
{
    struct student *p = head;
    int i = 1;
    while (p != NULL)
    {
        printf("the %d student information is\n%d\t%d\t%d\n", i, p->age, p->id, p->score);
        p = p->next;
        i++;
    }
}

int main()
{
    struct student *head;
    head = creat();
    print(head);
    system("pause");
    return 0;
}