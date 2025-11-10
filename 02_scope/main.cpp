#include<iostream>

void calculate(){

    //整形变量支持计算，所谓计算就是我们熟悉的  `+` ,`-`,`*`,`/`,`%`等
    int a = 10;
    int b = 20;
    std::cout << "a + b = " << a+b << std::endl;
    std::cout << "a - b = " << a-b << std::endl;
    std::cout << "a * b = " << a*b << std::endl;
    std::cout << "a / b = " << a/b << std::endl;
    std::cout << "a % b = " << a%b << std::endl;

    //浮点型变量支持计算，所谓计算就是我们熟悉的  `+` ,`-`,`*`,`/`等
    float c = 10.5;
    float d = 20.3;
    std::cout << "c + d = " << c+d << std::endl;
    std::cout << "c - d = " << c-d << std::endl;
    std::cout << "c * d = " << c*d << std::endl;
    std::cout << "c / d = " << c/d << std::endl;

    //浮点型变量支持计算，所谓计算就是我们熟悉的  `+` ,`-`,`*`,`/`等
    double e = 10.5;
    double f = 20.3;
    std::cout << "e + f = " << e+f << std::endl;
    std::cout << "e - f = " << e-f << std::endl;
    std::cout << "e * f = " << e*f << std::endl;
    std::cout << "e / f = " << e/f << std::endl;
}

void print_ascii() {
    //字符变量支持计算，所谓计算就是我们熟悉的  `+` ,`-`,`*`,`/`等
    char g = 'a';
    char h = 'b';
    std::cout << "g + h = " << (int)(g+h) << std::endl;
    std::cout << "g - h = " << (int)(g-h) << std::endl;
    std::cout << "g * h = " << (int)(g*h) << std::endl;
    std::cout << "g / h = " << (int)(g/h) << std::endl;
}

void sizeofnum(){
    std::cout << "Size of char: " << sizeof(char) << " bytes\n";
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    std::cout << "Size of float: " << sizeof(float) << " bytes\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes\n";
    std::cout << "Size of long long: " << sizeof(long long) << " bytes\n";
}

void typetransfer() {
    char a = 100; // 100 是int类型，然后赋值给 char， int是四字节，char 是1字节，如果数字过大会损失精度。
    int b = a;    // char 转换为 int类型，不会损失数据
    double c = b; // int 转换为 double（算数转换）

    std::cout << "a = " << static_cast<int>(a) << ", b = " << b << ", c = " << c << std::endl;

    // 注意：下面的转换可能会导致数据丢失
    unsigned int d = -1; // int 转换为 unsigned int，导致数据丢失
    std::cout << "d = " << d << std::endl; // 输出一个很大的数
}

// 全局变量，具有全局作用域
int globalVar = 42;

void func1() {
    std::cout << "Inside func: globalVar = " << globalVar << std::endl;
}

void func2() {
    // 局部变量，具有局部作用域
    int localVar = 10;
    std::cout << "Inside func: localVar = " << localVar << std::endl;
    // localVar 在这里之后就不再可见

    int globalVar = 5;
    std::cout << "define localVar (same name with globalVar, not suggested.)" << globalVar << std::endl;
}

// 定义一个命名空间
namespace MyNamespace {
    // 命名空间内的变量，具有命名空间作用域
    int namespaceVar = 20;

    void printVar() {
        std::cout << "Inside MyNamespace: namespaceVar = " << namespaceVar << std::endl;
    }

    int globalVar = 0;
}

namespace MyNamespace2 {
    int globalVar = 0;
}

int main() {
    calculate();
    print_ascii();
    sizeofnum();
    typetransfer();

    std::cout << "Inside main: globalVar = " << globalVar << std::endl;
    func1(); // 访问全局变量

    // 尝试访问 localVar 会导致编译错误
    // std::cout << "localVar = " << localVar << std::endl; // 错误
    func2(); // 局部变量仅在func函数内部可见

    // 使用命名空间前缀访问变量
    std::cout << "Outside MyNamespace: namespaceVar = " << MyNamespace::namespaceVar << std::endl;
    MyNamespace::printVar(); // 访问命名空间内的函数
    return 0;
}