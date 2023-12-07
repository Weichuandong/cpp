//
// Created by weichuandong on 2023/12/3.
//
#include "iostream"
#include "bitset"

using std::cout;
using std::endl;
using std::bitset;
union U1 {
    int x;
    float y;
    double z;
};
union U2 {
    int arr[10];
    double z;
};

union U {
    unsigned char bits[4];
    int num;
};

int main() {
//    cout << sizeof(U1) << endl;
//    cout << sizeof(U2) << endl;

    U x;
    x.num = 64;
    for (int i = 0; i < 4; i++) {
        cout << bitset<8>(x.bits[i]) << " ";
    }
    cout << endl;
    x.num = 114514;
    for (int i = 0; i < 4; i++) {
        cout << bitset<8>(x.bits[i]) << " ";
    }
}
