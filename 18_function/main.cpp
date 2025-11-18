#include <iostream>
#include <vector>
#include "multiply.h"
#include "event_system.h"

// 高阶函数，接受函数指针作为参数
void execute(void (*func)()) {
    // 调用传入的函数
    func();
}
// 执行函数
void greet() {
    std::cout << "Hello World!" << std::endl;
}

// 回调类型定义
typedef void (*Callback1)();
using Callback2 = void (*)();

// 函数接受回调
void registerCallback(Callback1 callback) {
    std::cout << "Before callback" << std::endl;
    callback();
    std::cout << "After callback" << std::endl;
}

// 回调函数
void myCallback() {
    std::cout << "Callback executed!" << std::endl;
}

// 函数
int main() {
    {
        // 函数的声明与定义
        /*
         * 函数的声明，放在头文件中 (如 multiply.h)
         * 函数的定义，放在源文件中 (如 multiply.cpp)
         */
        int a = 4, b = 10;
        int c = multiply(a, b);
        std::cout << "The result of a * b is " << c << std::endl;
    }

    // C++ 中有三种函数传递参数的机制
    /*
     * 传值调用（pass by value）：适用于不需要修改原始数据且数据量较小的情况
     * 传引用调用（pass by reference）：适用于需要修改原始数据或传递大型数据结构以提高效率
     * 传指针调用（pass by pointer）：类似于传引用调用，但是更加灵活，可用于传递 nullptr 或指向动态分配的内存
     */

    // C++ 中函数返回值可以是基本数据类型，引用，指针，对象等
    /*
     * 返回基本数据类型
     * 返回引用：返回引用需要确保引用的对象在返回后依然有效（避免悬垂引用）
     * 返回指针：注意若在函数内创建的对象，且返还的指针，调用者需要负责释放堆空间——内存
     * 返回对象：现代编译器通过返回值优化 (RVO) 减少对象拷贝，提高效率（不在函数内创建，直接在外部创建）
     */
    {
        // 函数重载
        /*
         * 函数重载允许在同一个作用域内定义多个名称相同，但是参数列表不同的函数。编译器通过参数列表的不通来区分调用哪个函数
         * 规则：
         * （1）函数名相同
         * （2）参数列表相同（类型、数量、顺序）不同
         * （3）返回类型不参与重载的区分
         */
        int a = 3, b = 10, c = 20;
        double d = 1.2, e = 10.3;
        std::cout << "The result of a * b is " << multiply(a, b) << std::endl;
        std::cout << "The result of a * b * c is " << multiply(a, b, c) << std::endl;
        std::cout << "The result of a * b * c is " << multiply(d, e) << std::endl;

        // 注意
        // 仅返回类型不同的重载是非法的
        // 默认参数可能会与重载产生冲突，使用时需要谨慎

        // 冲突重载，仅返回类型不同
        // 会导致编译错误
        // double multipy(int a, int b);
    }
    {
        // 默认参数
        /*
         * 函数参数可以指定默认值，调用函数时可以省略这些参数，默认值将被使用
         * 规则
         * 默认参数从右到左设置，不能部分设置，默认参数需要从右端开始，不能跳过中间参数
         * 函数声明和定义中默认参数只需要在声明中指定
         * 如果同时使用默认参数和重载，可能会产生歧义，需要谨慎设计 int func(int a, int b = 10) 和 int func(int a)
         */

    }
    {
        // 内联函数
        /*
         * 内联函数通过在函数前加 inline 关键字，建议编译器将函数代码嵌入到调用处，减少函数调用的开销
         * 使用场景
         * 适用于函数体积小、调用频繁的函数，如访问器（getter）和修改器（setter）等
         */

        // 优点：减少函数调用的开销（如栈操作）、可能提高程序的性能
        // 缺点：使得代码体积增大，可能影响缓存性能、编译器可能忽略内联请求，特别是对于复杂函数
        // 注意：编译器对于 inline 关键字的处理是建议性质，最终是否内联由编译器决定、过度使用内联函数可能导致代码膨胀
    }
    {
        // 递归函数
        /*
         * 递归函数是指在函数体内调用自身的函数。
         * 递归通常用于解决可以分解为相似子问题的问题，如阶乘、斐波那契数列、树的遍历等。
         */

        // 递归函数通常包含两个部分
        // 1. 基准情形（Base Case）：直接返回结果，避免无限递归
        // 2. 递归情形（Recursive Case）：将问题分解为更小的子问题并调用自身

        // 注意事项
        // 基准情形：必须正确设置，避免无限递归导致栈溢出（stack overflow）
        // 效率问题：一些递归实现可能效率低下（如斐波那契数列），可以通过“记忆化”或改用迭代法优化
        // 堆栈深度：递归深度过大可能导致栈溢出，需避免深度递归

        // 递归优化：尾递归
        // 尾递归是指递归调用在函数的最后一步，可以被编译器优化为循环，减少堆栈消耗。
    }
    {
        // lambda表达式
        // lambda表达式是 C++11 引入的匿名函数，便于在需要函数对象的地方快速定义和使用函数。
        // 它是允许定义内联的、小型的可调用对象，无需单独定义函数。

        // 语法：
        // [capture_list](parameter_list) -> return_type{
        //      // function body;
        // }

        std::vector<int> numbers = {1, 2, 3, 4, 5};

        // 使用 lambda 表达式打印每个元素
        std::for_each(numbers.begin(), numbers.end(), [](int x) {
            std::cout << x << " ";
        });
        std::cout << std::endl;

        // 使用 lambda 表达式计算总和
        int sum = 0;
        std::for_each(numbers.begin(), numbers.end(), [&sum](int x) {
            sum += x;
        });
        std::cout << sum << std::endl;

        // 组件说明
        // 1. 捕获列表（Capture List）：指定如何访问外部变量
        //      []：不捕获任何外部变量
        //      [&]：按引用捕获所有外部变量，不建议使用
        //      [=]：按值捕获所有外部变量，不建议使用
        //      [x,&y]：按值捕获x，按引用捕获y
        // 2.参数列表（Parameter List）：类似普通函数的参数列表，可以省略类型（C++14及以上支持自动类型推断）
        // 3.返回类型（Return Type）：可指定返回类型，也可以省略，编译器自动推断
        // 4.函数题（Function Body）：Lambda的具体实现

        // 按降序排序，使用Lambda表达式
        std::sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool {
            return a > b;
        });

        std::cout << "Sorted data: ";
        for(auto num : numbers)
            std::cout << num << " ";
        std::cout << std::endl;

        // 使用 lambda 表达式与标准库
        // C++ 标准库中的许多算法（如std::for_each, std::sort, std::transform 等）常用 Lambda 表达式作为参数，以实现自定义的操作。
    }
    {
        // 函数指针
        // 定义：指向函数的指针变量，保存函数的地址，可以通过指针调用函数

        // 定义函数指针
        void (*funcPtr)() = &greet;
        // 等同以下内容
        // void (*funcPtr)() = greet;
        // 通过函数指针调用函数
        funcPtr();

        // 函数指针作为参数
        execute(greet);
    }
    {
        // 回调函数
        // 定义：通过函数指针传递的函数，通常用于在特定时间发生时执行自定义操作

        // 示例：基于函数指针的回调
        registerCallback(myCallback);

        // 与 Lambda 表达式结合
        // 函数指针也可以指向 lambda 表达式，但是仅限于不捕获外部变量的 Lambda
        Callback1 callback = []() {
            std::cout << "Lambda callback!" << std::endl;
        };
        execute(callback);
    }
    {
        EventSystem eventSystem;

        // 注册基于函数指针的回调
        eventSystem.register_callback(onEvent);

        // 注册基于 Lambda 表达式的回调
        eventSystem.register_callback([](int x) {
            std::cout << "Lambda callback received: " << x*2 << std::endl;
        });

        // 注册带捕获的 Lambda 表达式的回调
        int multiplier = 5;
        eventSystem.register_callback([&multiplier](int x) {
            std::cout << "Lambda with capture received: " << x*multiplier << std::endl;
        });

        // 触发事件，传递参数
        eventSystem.triggerEvent(10);


        // - 定义了一个带参数的回调函数类型 `std::function<void(int)>`，允许回调函数接受一个整数参数。
        // - `EventSystem` 类的方法 `triggerEvent` 接受一个整数 `data`，并将其作为参数传递给每个回调函数。
        // - 在 `main` 函数中，注册了三个带不同处理逻辑的回调函数，并在触发事件时传递参数 `10`。
        // - 回调函数根据传入的 `data` 执行相应的操作，展示了回调函数的灵活性。

    }
    return 0;
}