#include <iostream>
#include <iomanip>
int main() {
    // 声明一个指向整型的指针 pointer
    int * ponter;

    // ip1 和 ip2 都是只想 int 类型对象的指针
    int * ip1, * ip2;

    // dp1 是 double 类型的变量，dp2 是 double 类型的指针
    double dp1, * dp2;

    int var = 10;
    int * ptr = &var;
    int * * ptr_address = &ptr; // 二级指针

    std::cout << std::setw(30) << "The value of var is " << var << std::endl;
    std::cout << std::setw(30) << "The value of ptr is " << ptr << std::endl;
    std::cout << std::setw(30) << "The value of ptr_address is " << ptr_address << std::endl << std::endl;

    std::cout << std::setw(30) << "The address of var is " << &var << std::endl;
    std::cout << std::setw(30) << "The address of ptr is " << &ptr << std::endl;
    std::cout << std::setw(30) << "The address of ptr_address is " << &ptr_address << std::endl << std::endl;

    int ival = 24;
    // p_int 存放的是 ival 的地址
    int* p_int = &ival;
    // 通过解引用来取出指针所指的数值
    std::cout << "*p_int = " << *p_int << std::endl;
    // 通过指针修改原数值
    *p_int = 30;
    std::cout << "*p_int = " << *p_int << std::endl;

    // 空指针
    int* empty_pointer = nullptr;
    // 空指针不能解引用
    // int m = *empty_pointer;

    // & *
    int ival2 = 42;
    // &紧跟着类型名（int）出现，并且在声明中，表示r是一个引用类型
    int &r = ival2;
    // *紧跟着类型名（int）出现，并且在声明中，表示p是一个指针类型
    int *p;
    // &出现在表达式中，表示取地址
    p = &ival2;
    // *出现在表达式中，表示解引用
    *p = 43;

    // &是声明的一部分，表示r2是一个引用
    // *是表达式的一部分，表示解引用，*p表示取出ival的数值
    // r2是ival2的引用
    int &r2 = *p;
    r2 = 1024;
    std::cout << "ival2 = " << ival2 << std::endl;

    // 空指针
    // c++11写法，nullptr == 0
    int *p1 = nullptr;;
    // C98写法
    int *p2 = 0;
    // C语言最传统写法，#define NULL 0 #include<cstdio.h>
    int *p3 = NULL;

    // 指针之间也可以赋值
    int ival3 = 23;
    // pval3被初始化，但是并没有指向任何对象
    int* pval3 = nullptr;
    int* pval4 = &ival3;
    // pval3指向pval4
    pval3 = pval4;

    // 空指针判断
    int *empty_ptr = nullptr;
    if (!empty_ptr) {
        std::cout << "empty_ptr is nullptr.";
    }

    // 指针大小
    std::cout << "The size of int pointer = " << sizeof(empty_ptr) << std::endl;
    std::cout << "The size of double pointer = " << sizeof(dp2) << std::endl;

    // 万能指针 void *
    // void* 是一种特殊的指针类型，可以用于存放任意对象的地址。
    // void* 指针的作用：
    // 与其他指针进行比较；作为函数的输入或输出；赋值给另外一个void*指针
    double obj = 3.14, *obj_pd = &obj;
    void * pv = &obj;
    std::cout << "pv size = " << sizeof(pv) << std::endl;
    pv = obj_pd;
    // 如果输出访问该指针的元素，需要先指明指针类型
    std::cout << *((double*)pv) << std::endl;

    // 指向指针的指针
    int ival4 = 1024;
    int *pival4 = &ival4;
    int **ppi = &pival4;

    std::cout << "The value of ival \n"
        << "direct value: " << ival4 << std::endl
        << "indirect value: " << *pival4 << std::endl
        << "double indirect value: " << **ppi
        << std::endl;

    // 指向指针的引用 (int*)& rp
    int init = 42;
    int *pinit = nullptr;
    int *&rpinit = pinit;
    rpinit = &init;
    std::cout << "pinit = " << pinit << std::endl;
    std::cout << "rpinit = " << rpinit << std::endl;
    std::cout << "&init = " << &init << std::endl;
    *rpinit = 24;
    std::cout << "init = " << init << std::endl;

    // 指针的运算
    int arr[5] = {1, 2, 3, 4, 5};
    int * ptr_arr = arr;
    std::cout << "The first element's address of arr = " << ptr_arr << std::endl;
    std::cout << "The first element of arr = " << *ptr_arr << std::endl;
    *ptr_arr = 1024;
    std::cout << "The first element of arr = " << *ptr_arr << std::endl;
    // ptr_arr = ptr_arr + 1;
    ptr_arr++;
    // 偏移4个字节，即该指针类型的字节数量
    // 因此指针加一，不是地址加一，而是一个类型单位长度的偏倚
    std::cout << "ptr_arr = " << ptr_arr << std::endl;
    std::cout << "The second element = " << *ptr_arr << std::endl;
}