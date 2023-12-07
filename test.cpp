//
// Created by weichuandong on 2023/12/2.
//
#include "iostream"

void trans1(unsigned int a) {
    std::cout << typeid(a).name();
}

int main() {
    // const
    const int a = 1;
    int const b = 2;
    //a = 2;  error
    //b = 3;  error
    // const pointer
    int c = 3, d = 4;

    const int *p1 = &c;
    int *const p2 = &d;
    const int *const p3 = &c;
    //    *p1 = 3;
    //    p2 = &a;
    //    p3 = &b;
    //    *p3 = 4;
    int e = 5, f = 6;

    const int &ee = e;
    //ee = 6;
    //ee = f; error

    //std::cout << sizeof(int *) << std::endl;
    //std::cout << typeid(sizeof(int *)).name() << std::endl;
//    std::cout << 1 - sizeof(int *) << std::endl;
//    std::cout << (int)1 - sizeof(int *) << std::endl;
    //std::cout<<bool(-43);
    trans1(32);
}