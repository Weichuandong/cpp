//
// Created by weichuandong on 2023/12/5.
//
#include "iostream"
#include "memory"

class Base {
    int id;
public:
    Base() : id(123) {}
};

//自定义释放规则
void deleteInt(int *p) {
    delete[]p;
}

class father;
class son;

class father {
public:
    ~father() {
        std::cout << "~father()" << std::endl;
    }

    //std::shared_ptr<son> mySon;
    std::weak_ptr<son> mySon;
};

class son {
public:
    ~son() {
        std::cout << "~son()" << std::endl;
    }
    //std::shared_ptr<father> myFather;
    std::weak_ptr<father> myFather;
};

int main() {
//    std::shared_ptr<int> p1;
//    std::cout << p1.use_count() << std::endl;
//    std::shared_ptr<int> p2(nullptr);
//    std::cout << p2.use_count() << std::endl;
//    std::shared_ptr<int> p3(new int(10));
//    std::cout << p3.use_count() << std::endl;
//    std::shared_ptr<int> p4(p3);
//    std::cout << p3.use_count() << std::endl;
//    std::cout << p4.use_count() << std::endl;
//    std::shared_ptr<int> p5(std::move(p4));
//    std::cout << p4.use_count() << std::endl;
//    std::cout << p5.use_count() << std::endl;

//初始化智能指针，并自定义释放规则
    //std::shared_ptr<int> p7(new int[10], deleteInt);
    //std::shared_ptr<int> p8(new int[10], [](int *p) { delete[]p; });
//    std::unique_ptr<int> u1;
//    std::cout << u1.get() << std::endl;
//    std::unique_ptr<int> u2(nullptr);
//    std::cout << u2.get() << std::endl;
//
//    std::unique_ptr<int> u3(new int(1));
//    std::cout << u3.get() << std::endl;
//    std::unique_ptr<int> u4 = std::make_unique<int>(3);
//    std::unique_ptr<int> u5(u4);
//    std::unique_ptr<int> u6(std::move(u4));

//    struct myDel {
//        void operator()(int *p) {
//            delete p;
//        }
//    };
//
//    std::unique_ptr<int, myDel> p6(new int);
//    std::shared_ptr<int> sp1(new int(10));
//    std::shared_ptr<int> sp2(sp1);
//    std::weak_ptr<int> wp(sp2);
//    //输出和 wp 同指向的 shared_ptr 类型指针的数量
//    std::cout << wp.use_count() << std::endl;
//    //释放 sp2
//    sp2.reset();
//    std::cout << wp.use_count() << std::endl;
//    //借助 lock() 函数，返回一个和 wp 同指向的 shared_ptr 类型指针，获取其存储的数据
//    std::cout << *(wp.lock()) << std::endl;

    std::shared_ptr<father> f = std::make_shared<father>();
    std::shared_ptr<son> s = std::make_shared<son>();

    f->mySon = s;
    s->myFather = f;

    std::cout << f.use_count() << std::endl;
    std::cout << s.use_count() << std::endl;

}
