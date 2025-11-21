//
// Created by 柏帅 on 2025/11/21.
//

#ifndef INC_19_CLASS_BASE_H
#define INC_19_CLASS_BASE_H
#include <iostream>

class Base {
public:
    // C++11 的语法
    Base(int num1, int num2):privateNum(num1), protectedNum(num2) {};
    void baseFunc() const;
    void commonDisplay() const;
    virtual void virtualDisplay() const;
    // 虚析构函数，在执行 delete base* 这种数据，无法回收其子函数的数据
    // 虚析构函数，可以在执行 ~Base 函数之前，先执行 ~Derived()
    virtual ~Base() {
        std::cout << "~Base()" << std::endl;
    }
private:
    int privateNum;
protected:
    int protectedNum;
};
class Derived: public Base {
public:
    // 构造函数实现顺序：基类构造函数->成员变量构造->派生类构造函数
    Derived():Base(0, 0) {};
    Derived(int num1, int num2):Base(num1, num2) {};

    void derivedFunc() const;
    // 覆盖父类的 commonDisplay() 函数
    // 重载：参数类型不同
    void commonDisplay() const;
    int commonDisplay(int num1, int num2) const;

    // virtual 函数是重写父类的 virtualDisplay 函数
    // 以下两种写法都正确，如果基类中声明了 virtual 函数，那么子类中同名的函数，也是 virtual 函数，
    // 为了保证语法检查的重要性，使用 override 可以进行有效的检查
    // virtual void virtualDisplay() const;
    void virtualDisplay() const override;

    void callBaseCommonDisplay() const;

    ~Derived() override{
        std::cout << "~Derived()" << std::endl;
    }
};

// 纯虚类
class Vehicle {
public:
    // 纯虚函数
    virtual void startEngine() = 0;
};

class Car : public Vehicle{
public:
    void startEngine() override;
};
// final 表示当前类是最底层的类，不能再被继承
class Motorcycle final: public Vehicle{
public:
    void startEngine() override;
};
#endif //INC_19_CLASS_BASE_H
