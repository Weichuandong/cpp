//
// Created by weichuandong on 2023/12/6.
//
#include <iostream>
#include <list>

using namespace std;

int main() {
    std::list<int> values{1, 2, 3, 4, 5};
    //找到遍历的开头位置和结尾位置
    auto end = values.rend();
    auto begin = values.rbegin();
    //开始遍历
    while (begin != end) {
        cout << *begin << " ";
        ++begin;
    }
    return 0;
}