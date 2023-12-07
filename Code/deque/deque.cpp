//
// Created by weichuandong on 2023/12/6.
//
#include "deque"
#include "iostream"

using std::cout;
using std::endl;
using std::deque;

int main() {
    deque<int> dq{1, 2, 3, 4};
    cout << dq[1] << endl;
    dq.emplace_back(5);
    cout << dq[1] << endl;
    dq.emplace_front(0);
    cout << dq[1] << endl;
    return 0;
}