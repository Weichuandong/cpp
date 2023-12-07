//
// Created by weichuandong on 2023/12/6.
//
#include "iostream"
#include "string"
#include "memory"
class A {
public:
    explicit operator int() { return 1; }

    explicit operator char *() { return nullptr; }
};

class Base {  //有虚函数，因此是多态基类
public:
    virtual ~Base() {}
};

class Derived : public Base {
};

int main() {
//    A a;
//    int n;
//    char *p = "New Dragon Inn";
//    std::cout << static_cast <int> (3.14) << std::endl;  // n 的值变为 3
//    std::cout << static_cast <int> (a) << std::endl;  //调用 a.operator int，n 的值变为 1
//    std::cout << static_cast <char *> (a) << std::endl;  //调用 a.operator char*，p 的值变为 NULL
    //n = static_cast <int> (p);  //编译错误，static_cast不能将指针转换成整型
    //p = static_cast <char*> (n);  //编译错误，static_cast 不能将整型转换成指针

//    const std::string s = "acd";
//    std::string &p = const_cast<std::string &>(s);
//    p = "dsaf ";
//    std::cout << s << "   " << p << std::endl;
//    std::string *ps = const_cast<std::string *>(&s);
//    *ps = "sadfsdaf";
//    std::cout << s << "   " << p << "   " << *ps << std::endl;
    Base b;
    Derived d;
    Derived *pd;
    pd = reinterpret_cast <Derived *> (&b);
    if (pd == NULL)
        //此处pd不会为 NULL。reinterpret_cast不检查安全性，总是进行转换
        std::cout << "unsafe reinterpret_cast" << std::endl; //不会执行
    pd = dynamic_cast <Derived *> (&b);
    if (pd == NULL)  //结果会是NULL，因为 &b 不指向派生类对象，此转换不安全
        std::cout << "unsafe dynamic_cast1" << std::endl;  //会执行
    pd = dynamic_cast <Derived *> (&d);  //安全的转换
    if (pd == NULL)  //此处 pd 不会为 NULL
        std::cout << "unsafe dynamic_cast2" << std::endl;  //不会执行
    return 0;
}

