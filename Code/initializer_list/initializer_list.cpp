//
// Created by weichuandong on 2023/12/3.
//
#include "initializer_list"
#include "iostream"
#include "vector"

using std::cout;
using std::endl;

class FooVec {
public:
    std::vector<int> m_vec;

    FooVec(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); it++)
            m_vec.push_back(*it);
        for (const auto &m: m_vec)
            std::cout << m << " ";
        std::cout << std::endl;

    }
};

int main() {
    FooVec foo1{1, 2, 3, 4, 5, 6};
    FooVec foo2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    return 0;
}
