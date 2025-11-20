//
// Created by 柏帅 on 2025/11/20.
//

#include "MyString.h"

MyString::MyString() {
    this->_data = nullptr;
}
MyString::MyString(const char * str) {
    if (str == nullptr) {
        this->_data = nullptr;
        return;
    }
    _data = new char[strlen(str) + 1];
    strcpy(_data, str);
}

MyString::MyString(const MyString & other) {
    if (other._data == nullptr) {
        this->_data = nullptr;
        return ;
    }
    _data = new char[strlen(other._data) + 1];
    strcpy(_data, other._data);

}

MyString & MyString::operator=(const MyString &other) {
    if (&other == this) {
        return *this;
    }
    // 异常安全：如果 new 抛异常，你原来的 _data 已经被 delete[]，对象处于无效状态。
    // 推荐先分配新内存，再删除旧内存：
    char * new_data = nullptr;
    if (other._data) {
       new_data = new char[strlen(other._data) + 1];
        strcpy(new_data, other._data);
    }
    delete[] _data;
    _data = new_data;
    return *this;
}

MyString::MyString(MyString &&other) noexcept {
    _data = other._data;
    other._data = nullptr;
}

MyString & MyString::operator=(MyString &&other) noexcept {
    if (this != &other) {
        delete[] _data;
        _data = other._data;
        other._data = nullptr;
    }
    return *this;
}

MyString MyString::operator+ (const char *str){
    const char* s1 = this->_data ? this->_data : "";
    const char* s2 = str ? str : "";
    MyString result;
    result._data = new char[strlen(s1) + strlen(s2) + 1];
    strcpy(result._data, s1);
    strcat(result._data, s2);
    return result;

}

MyString MyString::operator+(const MyString &str) {
    const char* s1 = this->_data ? this->_data : "";
    const char* s2 = str._data ? str._data : "";
    MyString result;
    result._data = new char[strlen(s1) + strlen(s2) + 1];
    strcpy(result._data, s1);
    strcat(result._data, s2);
    return result;
}

bool MyString::operator==(const MyString &str) const {
    if (str._data == nullptr) {
        return _data == nullptr;
    }
    return strcmp(this->_data, str._data) == 0;
}

MyString::~MyString() {
    delete[] _data;
}

std::ostream & operator<<(std::ostream &out, const MyString &str) {
    if (str._data!=nullptr)
        out << str._data;
    return out;
}
