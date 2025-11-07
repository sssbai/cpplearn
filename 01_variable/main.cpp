//
// Created by 柏帅 on 2025/11/7.
//
#include <iomanip>
#include <iostream>

void calculate_sum() {
    // 初始化变量 a 和 b
    int a = 5, b = 5;

    // a + b 的值赋值给 sum
    int sum = a + b;

    // 输出求和的结果
    std::cout << "sum = " << sum << std::endl;
}

void print_variable() {
    // print string variable
    std::cout << "Hello World!" << std::endl;

    // print integer variable
    int number = 42;
    std::cout << "The number is:" << number << std::endl;

    // print double variable
    double pi = 3.14159;
    std::cout << "pi = " << pi << std::endl;

    // print char variable
    char ch = 'A';
    std::cout << "ch = " << ch << std::endl;

    // print bool variable (C++17 and later)
    bool truth = true;
    std::cout << std::boolalpha;
    std::cout << "truth = " << truth << std::endl;
}

void control_print() {
    double number = 3.14159;

    // control the space of ouput.
    std::cout << std::setw(10) << number << std::endl;

    // control the precision of number.
    std::cout << std::setprecision(2) << number << std::endl;
}

int main() {
    // 声明一个整型变量age，未初始化
    int age;

    // 声明并初始化一个整型变量height
    int height = 175;

    // 声明并初始化一个双精度浮点型变量weight
    double weight = 65.5;

    // 声明并初始化一个字符型变量gender
    char gender = 'M';

    calculate_sum();

    print_variable();

    control_print();

    return 0;
}
