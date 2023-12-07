//
// Created by weichuandong on 2023/12/5.
//
#include "iostream"

using std::cout;
using std::endl;

class Base {
    int id;
public:
    Base() : id(0) {
        cout << "construct " << &id << endl;
    }

    Base(const Base &b) : id(b.id) {
        cout << "copy construct " << &id << endl;
    }

    Base(Base &&b) : id(b.id) {
        cout << "move construct " << &id << endl;
    }
};

int main() {
    Base a;
    Base b = a;
    Base c(std::move(a));
}