//
// Created by weichuandong on 2023/12/3.
//
#include "iostream"

class Base {
    int a, b;
public:
    Base(int a, int b) : a(a), b(b) {}

    int getA() { return a; }
};

class extend : public Base {
    int x;
public:
    explicit extend(int x) : x(x), Base(x, x) {}
};

class example {
    int &a;
    const float b;
    Base c;
public:
    example(int x, float y) : a(x), b(y), c(x, x) {
        std::cout << a << " " << b << std::endl;
        std::cout << c.getA();
    }
};

int main() {
    Base base(1, 2);
    example ex(2, 312.12);

    return 0;
}
