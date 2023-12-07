//
// Created by weichuandong on 2023/12/4.
//
#include "iostream"

class Base {
    int val;
public:
    explicit Base(int v) : val(v) {
        std::cout << val << std::endl;
    }

    ~Base() {
        std::cout << "~" << val << std::endl;
    }
};

void createSta() {
    static Base base(-999);
}

void createSta1() {
    static Base base(-888);
}

int main() {
    Base b1(-1);

    for (int i = 1; i <= 2; ++i) {
        Base b2(i);
        Base b3(i * 10);
        createSta();
    }
    createSta1();

    const Base b4(4);

}
