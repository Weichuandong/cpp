//
// Created by weichuandong on 2023/12/2.
//

#include <iostream>

using namespace std;

//int g_constructCount = 0;
//int g_copyConstructCount = 0;
//int g_destructCount = 0;
//
//struct A {
//    A() {
//        cout << "construct: " << ++g_constructCount << endl;
//    }
//
//    A(const A &a) {
//        cout << "copy construct: " << ++g_copyConstructCount << endl;
//    }
//
//    ~A() {
//        cout << "destruct: " << ++g_destructCount << endl;
//    }
//};
//

//
//int main() {
//    // 如果编译时设置编译选项-fno-elide-constructors用来关闭返回值优化效果，会输出：
//    // construct: 1
//    // copy construct: 1
//    // destruct: 1
//    // copy construct: 2
//    // destruct: 2
//    // destruct: 3
//    A a = GetA();
//
//    return 0;
//}

class A {
public:
    A() : m_ptr(new int(0)) {
        cout << "construct " << this << endl;
    }

    A(const A &a) : m_ptr(new int(*a.m_ptr)) //深拷贝的拷贝构造函数
    {
        cout << "copy construct " << this << endl;
    }

    A(A &&a) : m_ptr(a.m_ptr) {
        a.m_ptr = nullptr;
        cout << "move construct" << endl;
    }

    ~A() {
        delete m_ptr;
        cout << "destruct" << endl;
    }

private:
    int *m_ptr;
};

A Get() {
    return A();
}

int main() {
    A a = Get();
}
