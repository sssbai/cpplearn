#include <iostream>

int main() {
    {
        // 类型别名（type alias）

        // C++98 中使用 typedef 关键字来定义类型别名
        // wages 是 double 的同义词
        typedef double wages;
        // base 是 double 的同义词，p 是 double* 的同义词
        typedef wages base, * p;

        // C++11 规定了一种新的定义方法使用别名声明（alias declaration）来定义类型的别名
        // 64位整型
        using int64_t = long long;
        // 定义变量 a 为64位整型
        int64_t a = 10;
    }
    {
        // 指针，常量和类型别名

        // 以下声明是类型 char * 的别名
        typedef char * pstring;
        // 以下定义等价于 char * const
        const pstring cstr = nullptr;
        // 以下定义等价于 char * const *
        const pstring * ps = &cstr;
        // 这是正确的
        // ps = &cstr+1;
        // 这是错误的
        // *ps = cstr;
    }
    {
        // auto类型说明符
        // C++11 中引入了 auto 类型说明符，让编译器自动分析表达式所属的类型
        int age1 = 20;
        int age2 = 30;
        auto age_add = age1 + age2;

        // 正确，i 是 int， p 是 int *
        auto i = 0, * p = &i;
        // 错误，sz 是 int，pi是 double
        // auto sz = 0, pi = 2.1;
    }
    {
        // 复合类型，常量和auto
        // 编译器推断出来的auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则

        int i = 0, &r = i;
        // a 是一个int，类型是 r 所引用的类型
        auto a = r;

        // auto 一般会忽略掉顶层 const，同时底层 const 则会保留下来
        // cr 是一个常量引用，ci 是一个 int 类型的常量
        const int ci = i, &cr = ci;
        // b 是一个整数，ci 顶层的 const 被忽略了
        auto b = ci;
        // c 是一个整数，cr 是 ci 的别名，ci 本身是一个顶层 const
        auto c = cr;
        // d 是一个 int 指针，i 是 int
        auto d = &i;
        // e 是一个指向整数常量的指针，对常量对象取地址是一种底层 const
        auto e = &ci;

        // 如果希望推断出的 auto 类型是一个顶层 const ，可以明确指出
        // 顶层 const 可显示指定，f 是一个 const int 类型
        const auto f = ci;

        // 还可以将引用的类型设置为 auto， 此时原来的初始化规则仍然适用
        // g 是一个整型常量引用，绑定到 ci
        auto & g = ci;
        // 错误，非常量引用不能绑定到字面量
        // auto & h = 42;
        // int & h2 = 42;
        // 正确，常量引用可以绑定字面量
        const auto &j = 42;

        // i 为 int 类型，ci 为 const int 类型，但是 k 是 int 类型，l 是 int & 类型
        auto k = ci, &l = i;
        // m 是对常量的引用，p 是指向整数常量的指针
        // p 为 const int * 类型
        auto & m = ci, * p = & ci;
        // 错误，i 为 int 类型，& ci 的类型为 const int *
        // auto & n = i, * p2 = &ci;
    }
    {
        // decltype 类型指示符
        // C++11 中引入类型说明符 decltype，作用：选择并返回操作数的数据类型，在这个过程中，编译器分析表达式并得到它的类型，而不是计算表达式的数值
        // decltype(f()) sum = x; sum 的类型就是函数 f 的返回值的类型

        // decltype 处理顶层 const 和引用的方式不同于auto
        // 如果使用 decltype 使用的表达式是一个变量，则 decltype 返回该变量的类型（包括顶层 const 和引用在内）
        const int ci = 0, &cj = ci;
        // x 是 const int 类型
        decltype(ci) x = 0;
        // y 是一个const int & 类型，y 绑定到 x
        decltype(cj) y = x;
        // 错误，z 是一个引用，引用必须初始化
        // decltype(cj) = x;

        // 需要指出的是，引用从来都是作为其所指对象的同义词出现，只有用在 decltype 处是一个例外，是直接作为一种类型来返回的
    }
    {
        // decltype 和引用

        // decltype 的结果可以是 类型 或 引用类型

        /*
         * The results of decltype(e)
         * 如果 e 为变量名或者类成员对象，得到的就是该变量的声明类型（包括顶层 const，引用）
         * 如果 e 为一个左值表达式（但不是上面那种简单变量名情况），得到的就是 T&
         * 如果 e 为一个右值表达式，得到的就是 T
         */

        int i = 42, * p = &i, & r = i;
        // r + 0 是一个右值表达式，得到的返回值的类型为 int， 因此 decltype 得到的为 int
        decltype(r+0) b;
        // r 是 int & 类型，那么 decltype 得到的为 int &
        decltype(r) r2 = i;
        // * p 是左值表达式，那么 decltype 得到的为 int &
        decltype(*p) c = i;
        // 注意，如果给变量多加一个括号，那么编译器就认为该语句为左值表达式，那么 decltype 得到的为 int &
        decltype((i)) f = i;

        /*
         * 左值（lvalue） VS 右值（rvalue）
         * 左值：表示对象在内存中有确定地址的表达式，如变量名，解引用表达式*p，返回引用的函数调用
         * 右值：表示临时值、字面量或计算结果的表达式，如字面量42、i+1、返回非引用的函数调用结果
         * C++11将右值分为：纯右值（prvalue）（临时结果、字面量）、将亡值（xvalue）（即将被“夺取资源”的对象，右值引用，int && c = 20;）
         *
         * 右值引用见04_ref中的描述
         */

    }

    return 0;
}