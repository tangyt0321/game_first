#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
struct student
{
    int age;
    char name[20];
    double math_score;
    double chinese_score;
    double english_score;
};

struct student studentmakewith(int age, string a, double math_score, double chinese_score, double english_score)
{
    char *name = &a[0];
    struct student result;
    result.age = age;
    strcpy(result.name, name);
    result.math_score = math_score;
    result.chinese_score = chinese_score;
    result.english_score = english_score;
    return result;
}

void showmessageofstudent(struct student stu)
{
    cout << "age=" << stu.age << endl;
    cout << "name=" << stu.name << endl;
    cout << "math_score=" << stu.math_score << endl;
    cout << "chinese_score=" << stu.chinese_score << endl;
    cout << "english_score=" << stu.english_score << endl;
}

int main()
{
    struct student newstudent = studentmakewith(20, "xiaoming", 100, 100, 95.5);
    showmessageofstudent(newstudent);
    system("pause");
    return 0;
}