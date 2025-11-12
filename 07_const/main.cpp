#include <iostream>
#include "global.h"

// 定义一个全局 int 变量 global_i
int global_i = 10;

int main() {
    {
        // const 在变量声明中的位置

        // const 用于指示变量的数值不可被修改
        const int a = 10;
        // 以下这种写法较为少见
        int const b = 20;

        // 可以用一个变量初始化常量
        int i1 = 10;
        const int i2 = 20;

        // 也可以将一个常量赋值给一个变量
        int i3 = i2;
    }
    {
        // 编译器如何处理 const 修饰的变量
        /*
         * 链接类型：无链接，内部链接，外部链接
         * 无链接（no linkage）：可见范围仅在当前作用域，如：局部变量，不可被其他文件访问
         * 内部链接（internal linkage）：可见范围当前 .cpp 文件，如 static int 或者 const int，不可被其他文件访问
         * 外部链接（external linkage）：可见范围整个程序，如 int 或者 extern int，可以被其他文件访问
         */
        // 从以下输出可以看出，
        // const int 在不同文件中有不同的地址
        std::cout << "main.cpp buf address = " << &bufSize1 << std::endl;
        // extern const int 在不同文件中地址一致
        std::cout << "main.cpp buf2 address = " << &bufSize2 << std::endl;
        PrintBufAddress();

        // main.cpp buf address = 0x1048e3ebc
        // main.cpp buf2 address = 0x1048e3ec0
        // global.cpp buf address = 0x1048e3ec4
        // global.cpp buf2 address = 0x1048e3ec0

        // 结论，如果想要在多个文件中共享 const 对象，必须要在变量的定义之前添加 extern 关键字

    }
    {
        // const的引用

        // 定义常量
        const int c1 = 1024;

        // 用常量引用绑定常量
        const int &r1 = c1;

        // 不能修改常量引用的值
        // r1 = 2048;

        // 不能用非常量引用指向一个常量对象
        // int &r2 = c1;

        // 允许将 const int & 绑定到一个普通的 int 对象上
        int i1 = 200;
        const int &r2 = i1;

        // 常量引用绑定字面量
        const int &r3 = 100;

        // 常量引用绑定表示式计算的值
        const int &r4 = r3 * 2;
        const int &r5 = r4 * 2 + 10;

        // 以下是错误用法，类型不匹配
        // double dval = 3.14;
        // int & rd = dval;

        // 编译可以通过
        double dval = 3.14;
        const int &r6 = dval;
        // 上面代码会做隐式的转换，相当于以下代码
        // const int temp = dval;
        // const int & r6 = temp;
        // 这里 r6 绑定了一个临时量对象
        // 临时量对象就是当编译器需要一个空间来暂存表达式的求值结果时临时创建的一个未命名的对象。

        int i2 = 1024;
        // 非 const 引用绑定 i2
        int &r7 = i2;
        // const 引用绑定一个变量, 这里仅仅限制了引用的操作，不能够进行修改操作
        const int &r8 = i2;
        // 可以通过非 const 引用修改 i2 的数值
        r7 = 102;
        std::cout << "r8 = " << r8 << std::endl;
    }
    {
        // 指针和 const

        // 指向常量的指针（pointer to const）
        // PI 是一个常量，它的数值不能改变
        const double PI = 3.14;

        // 错误， ptr是一个普通指针
        // double * ptr = &PI;

        // 正确，cptr可以指向一个双精度常量
        const double * cptr = &PI;

        // 错误，不能给 * cptr 赋值
        // *cptr = 3.14;

        // 可以用指向常量的指针指向一个非常量
        int i3 = 2048;
        // cptr2 指向 i3
        const int * cptr2 = &i3;
    }
    {
        // const 指针（常量指针）
        int errNumb = 0;
        // curErr 是一个常量指针，指向errNumb
        int * const curErr = &errNumb;
        const double pi2 = 3.14;
        // pip是一个指向常量对象的常量指针
        const double * const pip = &pi2;


        // 错误，pip是一个指向常量的指针
        // *pip = 3.21;

        // 可以修改常量指针指向的内容
        * curErr = 1024;

        // 不可以修改常量指针指向的地址
        // int i1 = 0;
        // curErr = &i1;
    }
    {
        /* 顶层 const VS 底层 const
         * md 中写的比较拗口，
         * 顶层 const 就可以理解为当前类型是不可变的
         * 底层 const 就可以理解为当前类型所指向的部分是不可变的
         */

        int i = 0;

        // 不能改变p1的值，顶层const
        int * const pi = &i;

        // 不能改变 ci 的值，顶层const
        const int ci = 42;

        // 允许改变 p2 的值，底层const
        const int * p2 = &ci;

        // 右侧 const 是顶层const，左侧 const 是底层const
        const int * const p3 = p2;

        // 用于声明引用的 const 都是底层const
        const int &r = ci;

        // 指针赋值需要关注底层const
        // p2 拥有底层 const，p4 无底层 const，所以无法赋值
        // int * p4 = p2;
    }
    {
        /*
         * constexpr 和常量表达式
         * 常量表达式（const expression）是指指不会发生改变切在编译过程中那种就能得到计算结果的表达式
         * 常量表达式：字面值，用常量表达式初始化的 const 对象
         */

        // max_files 是一个常量表达式
        const int max_files = 20;

        // limit 是一个常量表达式
        const int limit = max_files + 10;

        // staff_size 不是常量表达式，无 const 声明
        int staff_size = 10;

        // sz 不是常量表达式，运行时计算才得知
        const int sz = GetSize();

        // c++11新标准，允许将变量声明为 constexpr 类型一遍有编译器来验证变量的值是否是一个常量表达式。
        // 声明为 constexpr 的变量一定是一个常量，而且必须用常量表达式初始化

        // 20是一个常量表达式
        constexpr int mf = 20;

        // mf + 1 是一个常量表达式
        constexpr int limit2 = mf + 10;

        // 错误，GetSize() 不是一个常量表达式，需要运行才能返回
        // constexpr int sz2 = GetSize();

        constexpr int sz2 = GetSizeConst();

        // 指针和 constexpr
        // 一个 constexpr 指针的初始值必须是 nullptr 或者 0，或者是存储与某个固定地址中对象。
        // 注意函数题内部定义的变量一般来说 不是存放在固定地址中的，因此 constexpr 指针不能指向这样的变量
        // 定义与所有函数体之外的对象起地址固定不变，能用来初始化 constexpr 指针

        // p 是一个指向整型常量的指针
        const int * p = nullptr;

        // q 是一个指向整数的常量指针
        constexpr int * q = nullptr;

        // constexpr 指针只能绑定固定地址
        // constexpr int * p = &mvalue;

        // 可以绑定全局变量，全局变量地址固定
        constexpr int * cp = &global_i;
        // 修改 p 指向的内容数据
        *cp = 1024;

        // Summery
        // constexpr pointer to const
        constexpr const int * cp2 = & global_i;
        // constexpr pointer to const
        const constexpr int * cp3 = &global_i;
        // const pointer to const
        const int * const cp4 = &global_i;
        // constexpr to int
        constexpr int * const cp5 = &global_i;
        // const pointer to int
        int * const cp6 = &global_i;
        // pointer to const
        const int * cp7 = &global_i;
        // pointer to int
        int * cp8 = &global_i;

    }
    return 0;
}