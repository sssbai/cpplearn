#include <iostream>
#include <vector>

int main() {
    {
        // 定义和初始化内置数组
        // 定义数组的时候必须制定数组的类型，不允许使用 auto 关键字由初始值的列表推断类型。
        // 另外，和 vector 一样，数组的元素应为对象，因此不存在引用的数组。
        //不是常量表达式
        unsigned cnt = 42;
        //常量表达式, 用constexpr修饰
        constexpr unsigned sz = 42;
        //包含10个整数的数组
        int arr[10];
        //含有42个整数指针的数组
        int *parr[sz];
        //定义字符串数组，错误！cnt不是常量表达式,但是部分编译器可通过
        std::string bad[cnt];
    }
    {
        // 显式初始化数组元素
        // 可以对数组的元素进行列表初始化，此时允许忽略数组的维度。
        // 如果在声明时没有指明维度，编译器会根据初始值的数量计算并推测出来

        const unsigned sz = 42;
        // 含有 3 个元素的数组，元素值分别是 0，1，2
        int ial[sz] = {0, 1, 2};
        // 维度是 3 的数组
        int a2[] = {1, 2, 3};
        // 等价于 a3[] = {0, 1, 2, 0, 0};
        int a3[5] = {0, 1, 2};
        // 等价于 a4[] = {"hi", "bye", ""};
        std::string a4[3] = {"hi", "bye"};
        // 错误，初始值过多
        // int a5[2] = {1, 2, 3};
    }
    {
        // 不允许拷贝和赋值

        //含有三个整数的数组
        int a[] = {0,1,2};
        // 错误，不允许使用一个数组初始化另一个数组
        // int a2[] = a;
    }
    {
        // 理解复杂的数组声明
        // “引用的数组” 和 “引用数组”

        //ptrs是含有10个整数指针的数组
        int *ptrs[10];
        //错误, 不存在引用的数组。一个“引用的数组”，数组里有 10 个引用
        //int& refs[10] = /*?*/;
        //Parray指向一个含有10个整数的数组
        int arr[10] ={0,1,2,3,4,5,6,7,8,9};
        int (*Parray)[10] = &arr;
        //arrRef 引用一个含有10个整数的数组
        int (&arrRef)[10] = arr;
    }
    {
        // 访问数组元素
        int arr[10] = {0,1,2,3,4,5,6,7,8,9};
        for (size_t i = 0; i < sizeof(arr)/sizeof(int); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        // array 数组中并没有越界检查
    }
    {
        // 指针和数组
        int arr[10] = {0,1,2,3,4,5,6,7,8,9};
        // 第一个元素地址
        std::cout << "first element: address is " << &arr[0] << std::endl;
        // 数组首地址
        std::cout << "arr address is " << arr << std::endl;
        // 数组首地址
        std::cout << "arr address is " << &arr << std::endl;

        // 等价于 int * first_elem_addr = & arr[0];
        int * first_elem_addr = arr;
        std::cout << "first element address is " << first_elem_addr << std::endl;

        // 使用 auto 推断数组类型时，得到的是类型的指针
        auto ia2(arr);
        // ia3 是一个含有 10 个整数的数组
        // decltype 得到的是 int[10] 类型
        decltype(arr) ia3 = {1,3,4,5};
        // 错误，不能用整数指针给数组赋值
        // ia3 = ia2;
    }
    {
        // 指针也是迭代器
        int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
        // p 指向 arr 的第一个元素
        int * p = arr1;
        // p 指向 arr1[1]
        ++p;
        // 使用指针遍历数组中的元素
        int arr2[10] = {0,1,2,3,4,5,6,7,8,9};
        // e 指向 arr2[10]， 也就是最后一个元素的下一个地址
        int * e = arr2 + 10;
        for (int * b = arr2; b < e; ++b) {
            std::cout << *b << " ";
        }
        std::cout << std::endl;

        // C++11 中提供了获取最后一个元素的下一个位置的指针，以及指向首元素的指针
        int ia[] = {1,2,3,4};
        int * beg = std::begin(ia);
        int * end = std::end(ia);
        for (auto it = beg; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        // 指针运算
        constexpr size_t sz = 42;
        int arr[sz] = {1,3,3,4,5};
        // 等价于 int * ip = &arr[0];
        int * ip = arr;
        // ip2
        int * ip2 = ip + 4;

        // 计算数组中的元素的个数
        auto n = std::begin(arr) - std::end(arr);
        std::cout << "n is " << n << std::endl;
    }
    {
        // 解引用和指针运算的交互
        int arr[] = {12,23,4};
        int last = *(arr+2);
        std::cout << "last is " << last << std::endl;
        // 以下等价于 arr[0]+2
        int value  = *arr + 2;
    }
    {
        // 下标和指针的关系
        int arr[] = {1,23,4,5,6};
        // 等价于 arr[1]
        int value  = *(arr + 1);
    }
    {
        // C 风格字符串
        char * msg = "Hello World!";
        char ca[] = {'C','P','P'};
        //有风险，因为ca没有以\0结束，所以strlen可能访问越界
        int len = strlen(ca);
        std::cout << "len is " << len << std::endl;
    }
    {
        // 比较字符串
        std::string s1 = "A string example";
        std::string s2 = "A different string example";
        if(s1 < s2){
            std::cout << "s1 is less than s2" << std::endl;
        }else{
            std::cout << "s1 is not less than s2" << std::endl;
        }

        const char ca1[] = "A string example";
        const char ca2[] = "A different string example";
        //未定义的，视图比较两个无关地址
        // if(ca1 < ca2){
        //
        // }
        //和两个string比较大小功能一样
        if(strcmp(ca1, ca2) < 0){
            std::cout << "ca1 is less than ca2" << std::endl;
        }else{
            std::cout << "ca1 is not less than ca2" << std::endl;
        }
    }
    {
        // 字符串拼接
        char dest[20] = "Hello, "; // 确保有足够的空间
        const char *src = "World!";

        // 使用strcpy
        strcpy(dest + strlen(dest), src); // 从dest的末尾开始复制src
        std::cout << "After strcpy: " << dest << std::endl;

        // 另一个例子，直接使用strcat
        char anotherDest[40] = "Hello, ";
        strcat(anotherDest, src);
        std::cout << "After strcat: " << anotherDest << std::endl;
    }
    {
        // 混用 string 对象和 C 风格字符串
        std::string s("Hello World");
        //注意返回const char *
        const char *str = s.c_str();
    }
    {
        // 使用数组初始化 vector 对象
        int int_arr[] = {0,1,2,3,4,5};
        std::vector<int> ivec(std::begin(int_arr), std::end(int_arr));
        for(auto e : ivec){
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    {
        // 编写一个 my_strcpy 的程序，其功能与标准库函数 strcpy 类似，用于将源字符串复制到目标字符串中。
        char dest[20] = "Hello";
        const char *src = " New World!";
        char * cur_dest = dest;
        while (*src != '\0') {
            *cur_dest = *src;
            src++;
            cur_dest++;
        }
        *cur_dest = '\0';
        std::cout << "After strcpy: " << dest << std::endl;
    }
    {
        // 编写一个函数 my_strcat，其功能与标准库函数 strcat 类似，用于将源字符串追加到目标字符串的末尾。

        char dest[20] = "Hello";
        const char *src = " New World!";
        char * cur_dest = dest;
        while (* cur_dest != '\0') {
            cur_dest++;
        }
        while (*src != '\0') {
            *cur_dest = *src;
            src++;
            cur_dest++;
        }
        *cur_dest = '\0';
        std::cout << "After strcat: " << dest << std::endl;
    }

    return 0;
}