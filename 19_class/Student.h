//
// Created by 柏帅 on 2025/11/19.
//

#ifndef INC_19_CLASS_STUDENT_H
#define INC_19_CLASS_STUDENT_H
#include <iostream>
#include <string>
#include <vector>

class Student {
// 公有成员，可以被所有代码访问
public:
    // 默认构造函数
    // Student();
    // 禁止无参构造函数
    Student() = delete;
    // 参数化构造函数
    Student(const std::string & name, int age);
    // 拷贝构造函数
    Student(const Student & student);
    // 移动构造函数, noexcept 确保
    Student(Student && student ) noexcept;

    // 拷贝赋值运算符
    Student & operator=(const Student & student);

    // 移动赋值运算符
    Student & operator=(Student && student) noexcept;

    // 析构函数
    // ~Student();
    // 显式的使用编译器默认的析构函数
    ~Student() = default;
    // 公有成员函数
    Student setName(const std::string & name);
    // 常成员函数，不可以修改成员变量
    std::string getName() const;

    void setAge(int age);
    int getAge() const;

    // 友元函数
    // 友元函数可以访问类的私有和保护成员的

// 私有成员，仅能被类的成员函数和友元函数访问
private:
    // 私有成员变量
    // 常用下划线结尾表示成员变量，避免和局部变量混淆
    std::string name_;
    int age_;

// 受保护成员，仅能被类的成员函数，友元和派生类访问。
protected:
};


#endif //INC_19_CLASS_STUDENT_H