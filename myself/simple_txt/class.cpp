#include <bits/stdc++.h>
using namespace std;

class circle
{
public:
    double r; // 成员属性

    double area() // 成员函数、成员方法
    {
        return 3.14 * r * r;
    }

    void setR(double r)
    {
        this->r = r;
    }
};

class person
{
public:
    string name;
    int age;

protected:
    int height;
    int weight;

private:
    int id;

public:
    void change(string name)
    {
        this->name = name;
    }
};

int main()
{
    circle c1, c2;
    person p1;
    // c1.r = 5;
    // c2.r = 10;
    c1.setR(20);
    c2.setR(30);
    cout << c1.area() << endl;
    cout << c2.area() << endl;

    p1.name = "zhangsan";
    p1.age = 20;
    cout << p1.name << endl;
    p1.change("lisi");
    cout << p1.name << endl;

    getchar();
    return 0;
}