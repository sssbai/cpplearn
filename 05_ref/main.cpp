#include <iostream>

// 定义一个函数，返回右值的函数
std::string foo() {
    return std::string("hello world.");
}

// 引用底层是使用指针来实现的。
int main() {
    // 定义整型 a ，数值为 10
    int a = 10;

    // 定义引用 b ，并且指向 a ， b 就是 a 的别名
    // b 是 a 的别名，并且不占用新的存储空间，在编译器层面 b 被视作 a 的直接替代
    // 必须初始化
    // 一旦绑定，不可改变
    // 没有空引用
    int &b = a;

    // 输出 a 和 b 的数值
    std::cout << "The value of a is " << a << std::endl;
    std::cout << "The value of b is " << b << std::endl;

    // 输出 a 的地址
    std::cout << "The address of a is " << &a << std::endl;
    // 输出 b 的地址
    std::cout << "The address of b is " << &b << std::endl;

    // 修改 a 的数值为200
    a = 200;
    // 修改后 a 和 b 的数值
    std::cout << "The value of a is " << a << std::endl;
    std::cout << "The value of b is " << b << std::endl;

    int c = 300;
    b = c; // 这种操作并不是修改引用，而是修改对应空间的数值，即修改 b 的数值为 c
    std::cout << "The value of b is " << b << std::endl;
    std::cout << "The value of c is " << c << std::endl;

    // 打印地址，可以看到 a 和 b 的地址相同，但是 c 的地址不同
    std::cout << "The address of a is " << &a << std::endl;
    std::cout << "The address of b is " << &b << std::endl;
    std::cout << "The address of c is " << &c << std::endl;

    // -----------------------------------------------------
    // 左值：可以被修改的值为左值
    // 右值：不可以被修改的值为右值，如函数返回值，字面量等

    // 绑定到左值的引用叫做：左值引用
    int m = 10;
    int & m_r = m; // m_r是一个左值引用

    // 绑定到右值的引用叫做：右值引用
    // 这是c++11 中新增的特性，允许我们为右值（即临时对象或即将被销毁的对象）创建一个引用。
    int && m_rr = 10; // m_rr是一个右值引用

    // 不能用 左值引用 绑定 右值
    // int & m_r = 10; error

    // ---------------------------------------------------------------------------
    // 使用 右值引用 延长了临时对象的寿命，即直到右值引用的作用域结束，该临时对象才会被销毁。
    std::string && foo_rr = foo();
    std::cout << "The return value of foo is " << foo_rr << std::endl;

    // 右值引用主要用于：移动语义，完美转发

    return 0;
}