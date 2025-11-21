//
// Created by 柏帅 on 2025/11/21.
//

#include "Derived.h"

void Base::baseFunc() const {
    std::cout << "Base Func" << std::endl;
    std::cout << "Private Num: " << privateNum << std::endl;
    std::cout << "Protected Num: " << protectedNum << std::endl;
}

void Base::commonDisplay() const {
    std::cout << "Base Common Func" << std::endl;
    std::cout << "Private Num: " << privateNum << std::endl;
    std::cout << "Protected Num: " << protectedNum << std::endl;
}

void Base::virtualDisplay() const {
    std::cout << "Base Virtual Func" << std::endl;
    std::cout << "Private Num: " << privateNum << std::endl;
    std::cout << "Protected Num: " << protectedNum << std::endl;
}


void Derived::derivedFunc() const {
    std::cout << "Derived Func" << std::endl;
    // 不可以访问父类的 private
    // std::cout << "Private Num: " << privateNum << std::endl;
    // 可以访问父类的 protected
    std::cout << "Protected Num: " << protectedNum << std::endl;

}

void Derived::commonDisplay() const {
    std::cout << "Derived Common Func" << std::endl;
    std::cout << "Protected Num: " << protectedNum << std::endl;
}

int Derived::commonDisplay(int num1, int num2) const {
    std::cout << "Derived Common Func" << std::endl;
    std::cout << "Num: " << num1 + num2 << std::endl;
}

void Derived::virtualDisplay() const {
    std::cout << "Derived Virtual Func" << std::endl;
    std::cout << "Protected Num: " << protectedNum << std::endl;
}

void Derived::callBaseCommonDisplay() const {
    // 使用作用域解析符来调用基类的 commonDisplay 函数
    Base::commonDisplay();
}

void Car::startEngine() {
    std::cout << "Car Start Engine." << std::endl;
}

void Motorcycle::startEngine() {
    std::cout << "Motorcycle Start Engine." << std::endl;
}
