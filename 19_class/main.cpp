#include <iostream>
#include "Student.h"
#include "MyString.h"
int main() {
    {
        // 类与对象
        /*
         * 类（Class）是 C++ 中创建用户自定义类型的一种方式，它将数据（成员变量）和操作数据的函数（成员函数）封装在一起。
         * 对象（Object）是类的实例化，拥有类定义的所有属性和行为。
         */

    }
    {
        Student s1("Bob", 21);
        Student s2("Alice", 22);
        std::cout << s1.getName() << " " << s1.getAge() << std::endl;
        std::cout << s2.getName() << " " << s2.getAge() << std::endl;
        s2 = std::move(s1);
        std::cout << s1.getName() << " " << s1.getAge() << std::endl;
        std::cout << s2.getName() << " " << s2.getAge() << std::endl;
        StudentFriend sf1;
        sf1.ChangeAge(s2, 18);
        std::cout << s1.getName() << " " << s1.getAge() << std::endl;
        std::cout << s2.getName() << " " << s2.getAge() << std::endl;
        s2 = s2+s1;
        std::cout << s1.getName() << " " << s1.getAge() << std::endl;
        std::cout << s2.getName() << " " << s2.getAge() << std::endl;
        std::cout << "student operaotr << "<< s2 << std::endl;
    }
    {
        MyString s1;
        std::cout << "s1 = " << s1 << std::endl;
        MyString s2("hello world");
        std::cout << "s2 = " << s2 << std::endl;
        MyString s3(s2);
        std::cout << "s3 = " << s3 << std::endl;
        MyString s4(std::move(s3));
        std::cout << "s4 = " << s4 << std::endl;
        MyString s5 = s2;
        std::cout << "s5 = " << s5 << std::endl;
        MyString s6 = std::move(s5);
        std::cout << "s6 = " << s6 << std::endl;
        MyString s7 = s6 + " " +s2;
        std::cout << "s7 = " << s7 << std::endl;
        MyString s8 = s7 + " C++";
        std::cout << "s8 = " << s8 << std::endl;
    }
    return 0;
}