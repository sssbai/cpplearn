#include <iostream>
// 函数声明
int add(int x, int y);
// 函数，计算除法
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero."); // 抛出异常
    }
    return numerator / denominator;
}
// 函数，检查数组索引
int getElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range."); // 抛出异常
    }
    return arr[index];
}

// 函数，抛出异常
void func1() {
    throw std::runtime_error("Error in func1.");
}

// 函数，调用 func1 并重新抛出异常
void func2() {
    try {
        func1();
    } catch (...) { // 捕获所有异常
        std::cout << "func2() caught an exception and is rethrowing it." << std::endl;
        throw; // 重新抛出当前异常
    }
}

int main() {
    {
        // 表达式语句
        int a = 5;          // 赋值表达式语句
        a = a + 10;         // 赋值表达式语句
        std::cout << a;     // 函数调用表达式语句
    }
    {
        // 声明语句
        int result = add(3, 4); // 调用函数
        std::cout << "Result: " << result;
    }
    {
        // {}代码块作用域
        // 新的代码块
        int x = 20; // 局部变量 x，隐藏外部的 x
        std::cout << "x inside block: " << x << std::endl;
    }
    {
        // goto语句
        // `goto` 允许无条件跳转到程序中指定的标签。虽然 `goto` 有时能简化代码，但不推荐频繁使用，因为它会使程序流程难以理解和维护。
        int number;
        std::cout << "Enter a positive number (negative to quit): ";
        std::cin >> number;

        if (number < 0) {
            goto end; // 跳转到 end 标签，结束程序
        }

        std::cout << "You entered: " << number << std::endl;

        end:
            std::cout << "Program ended." << std::endl;
    }
    {
        // try, catch, throw语句
        // try 块用于包含可能引发异常的代码。
        // throw 用于抛出异常。
        // catch 块用于捕获并处理异常。
        double num, denom;

        std::cout << "Enter numerator: ";
        std::cin >> num;
        std::cout << "Enter denominator: ";
        std::cin >> denom;

        try {
            double result = divide(num, denom);
            std::cout << "Result: " << result << std::endl;
        } catch (std::invalid_argument &e) { // 捕获 std::invalid_argument 异常
            std::cerr << "Error: " << e.what() << std::endl;
        }
        // 程序在异常处理后继续执行，而不会异常终止
        std::cout << "Program continues after try-catch." << std::endl;
    }
    {
        // 多重 catch
        try {
            // 模拟不同类型的异常
            int choice;
            std::cout << "Choose exception to throw (1: bad_alloc, 2: invalid_argument): ";
            std::cin >> choice;

            if (choice == 1) {
                throw std::bad_alloc();
            } else if (choice == 2) {
                throw std::invalid_argument("Invalid argument provided.");
            } else {
                std::cout << "No exception thrown." << std::endl;
            }
        } catch (std::bad_alloc &e) { // 处理 bad_alloc 异常
            std::cerr << "Caught std::bad_alloc: " << e.what() << std::endl;
        } catch (std::invalid_argument &e) { // 处理 invalid_argument 异常
            std::cerr << "Caught std::invalid_argument: " << e.what() << std::endl;
        }

        // std::cout —— 标准输出（正常信息）
        // std::cerr —— 标准错误输出（错误信息）
        // std::clog —— 标准日志输出（一般用于程序日志）

        std::cout << "Program continues after try-catch." << std::endl;
    }
    {
        // throw 的位置
        // throw 语句可以在任何需要引发异常的位置使用，包括函数内部、嵌套调用中等。
        int myArray[5] = {10, 20, 30, 40, 50};
        int index;

        std::cout << "Enter array index (0-4): ";
        std::cin >> index;

        try {
            int value = getElement(myArray, 5, index);
            std::cout << "Element at index " << index << " is " << value << "." << std::endl;
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        // getElement 函数检查索引是否有效，如果无效则抛出 std::out_of_range 的异常
        // main 函数中的 try 块调用 getElement，并在 catch 块中处理异常
    }
    {
        // rethrow 异常
        // 可以在 catch 块中使用 throw 语句重新抛出捕获的异常，以便其他部分处理
        try {
            func2();
        } catch (std::exception &e) { // 在 main 中捕获异常
            std::cerr << "Main caught: " << e.what() << std::endl;
        }
        // 预期结果为：
        // func2() caught an exception and is rethrowing it.
        // Main caught: Error in func1.

        // 分析流程为：
        // func1 抛出异常
        // func2 调用 func1，捕获异常后重新抛出
        // main 最终捕获并处理异常
    }
    return 0;           // return 表达式语句
}

// 函数定义
int add(int x, int y) {
    return x + y;
}