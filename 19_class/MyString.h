//
// Created by 柏帅 on 2025/11/20.
//

#ifndef INC_19_CLASS_MYSTRING_H
#define INC_19_CLASS_MYSTRING_H
#include <iostream>
#include <cstring>

class MyString {
public:
    MyString();
    MyString(const char * str);
    MyString(const MyString & other);
    MyString & operator = (const MyString & other);
    MyString(MyString && other) noexcept;
    MyString & operator = (MyString && other) noexcept;
    MyString operator + (const char * str);
    MyString operator + (const MyString& str);
    bool operator == (const MyString& str) const;
    friend std::ostream & operator << (std::ostream & os, const MyString & str);
    ~MyString();
private:
    char * _data;
};


#endif //INC_19_CLASS_MYSTRING_H