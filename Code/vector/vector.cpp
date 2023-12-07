//
// Created by weichuandong on 2023/12/6.
//
#include "vector"
#include "iostream"

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> v;
    cout << v.data() << " " << v.capacity() << "  " << v.size() << endl;
    v.resize(10);
    cout << v.data() << " " << v.capacity() << "  " << v.size() << endl;
    v.resize(5);
    cout << v.data() << " " << v.capacity() << "  " << v.size() << endl;
    v.resize(11);
    cout << v.data() << " " << v.capacity() << "  " << v.size() << endl;
}