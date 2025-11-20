//
// Created by 柏帅 on 2025/11/19.
//

#include "Student.h"
// // 默认构造函数
// Student::Student() {
//     // 对成员变量做一些初始化的操作
//     name_ = "default name";
//     age_ = 0;
// }
// 参数化构造函数
Student::Student(const std::string & name, int age)
    :name_(name), age_(age) {
}
// 拷贝构造函数
Student::Student(const Student & student)
    :name_(student.name_), age_(student.age_) {
}
// 移动构造函数
Student::Student(Student && student) noexcept
    :name_(std::move(student.name_)), age_(std::move(student.age_)) {
    student.name_ = "";
    student.age_ = 0;
}

// 拷贝赋值运算符
Student& Student::operator=(const Student & student) {
    // 避免自拷贝
    if (this == &student)
        return *this;
    name_ = student.name_;
    age_ = student.age_;
    return *this;
}

// 移动赋值运算符
Student& Student::operator=(Student && student) noexcept {
    if (this == &student)
        return *this;
    this->name_ = std::move(student.name_);
    age_ = std::move(student.age_);
    return *this;
}

Student Student::setName(const std::string & name){
    // 如果参数名和成员变量同名，可以看了使用 this 指针来指向调用的对象/成员函数
    this->name_ = name;
    // 可以使用 this 来返回当前对象的引用，以支持链式调用
    // Student sobj;
    // sobj.setValue(10).setValue(20);
    return *this;
}
void Student::setAge(int age) {
    age_ = age;
}
std::string Student::getName() const {
    return name_;
}
int Student::getAge() const {
    return age_;
}

// 静态成员函数
void Student::testStatic() {

}

Student & Student::operator+(const Student &student) {
    this->age_ += student.age_;
    return *this;
}

std::ostream & operator<<(std::ostream &os, const Student &student) {
    os << "student name: " << student.name_ << " age: " << student.age_;
    return os;
}

// 友元函数
void ChangeAge(Student &student, int age) {
    student.age_ = age;
}

void StudentFriend::ChangeAge(Student &student, int age) {
    student.age_ = age;
}
