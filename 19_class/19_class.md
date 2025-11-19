---
title: 零基础C++(19) 类基础用法
date: 2024-11-09 20:58:32
tags: C++ cppbase
categories: C++ cppbase


---

## 1. 类与对象简介



### 1.1 什么是类和对象



- **类（Class）**是C++中创建用户自定义类型的一种方式，它将数据（成员变量）和操作数据的函数（成员函数）封装在一起。
- **对象（Object）**是类的实例化，拥有类定义的所有属性和行为。
- **类**更像是汽车图纸，**对象**更像是造出来的汽车。



### 1.2 类的作用



- **封装（Encapsulation）**：将数据和操作数据的代码绑定在一起，保护数据不被外界直接访问。
- **抽象（Abstraction）**：通过类定义抽象出具有共同特性的对象，提高代码的可重用性和可维护性。
- **继承（Inheritance）和多态（Polymorphism）**：实现代码的复用与动态绑定。



------



## 2. 类的定义



### 2.1 基本语法



```cpp
class ClassName {
public:
    // 公有成员
private:
    // 私有成员
protected:
    // 受保护成员
};
```



### 2.2 示例



创建一个表示学生的类：



```cpp
#include <string>

class Student {
public:
    // 公有构造函数
    Student(const std::string& name, int age);

    // 公有成员函数
    void setName(const std::string& name);
    std::string getName() const;

    void setAge(int age);
    int getAge() const;

private:
    // 私有成员变量
    std::string name_;
    int age_;
};
```



------



## 3. 成员变量与成员函数



### 3.1 成员变量



- **成员变量（Member Variables）**：用于存储对象的状态信息。
- **命名约定**：常用下划线结尾（例如 `name_`）表示成员变量，避免与局部变量混淆。



### 3.2 成员函数



- **成员函数（Member Functions）**：定义对象的行为，可以访问和修改成员变量。
- **常成员函数（Const Member Functions）**：保证函数不会修改对象的状态。

**成员函数初始化列表**

成员初始化列表使用场景与示例（总表）

| 序号  | 必要性 / 原因                                              | 描述                                              | 示例代码（精简版）                                           |
| ----- | ---------------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------------------ |
| **1** | **必须：const 成员必须初始化**                             | `const` 只能初始化一次，不能在构造函数体赋值      | `class A{const int x; A(int v):x(v){};};`                    |
| **2** | **必须：引用成员（reference）必须初始化**                  | 引用必须在创建时绑定，不能重新赋值                | `class A{int& r; A(int& x):r(x){};};`                        |
| **3** | **必须：成员对象没有默认构造函数**                         | 构造函数体会先尝试默认构造 → 报错                 | `class B{B(int v){}}; class A{B b; A():b(10){}};`            |
| **4** | **性能：避免“构造 → 赋值”多余开销**                        | 初始化列表只构造一次；构造体赋值是构造 + 赋值两步 | `A():b(10){} // 只构造一次` `A(){ b=B(10);} // 默认构造+赋值` |
| **5** | **正确性：初始化顺序由成员声明顺序决定（与列表顺序无关）** | 列表写成 `: y(2), x(y)` 也不会先初始化 y          | `class A{int x,y; A():y(2),x(y){} };`                        |
| **6** | **父类构造必须通过初始化列表调用**                         | 子类构造必须显式调用父类构造函数                  | `class A:public Base{A():Base(10){}};`                       |
| **7** | **复杂对象必须初始化（vector/string/unique_ptr 等）**      | 容器、智能指针等不能先默认构造再赋值              | `class A{vector<int> v; A():v{1,2,3}{} };`                   |
| **8** | **语义表达更清晰，代码更安全、可维护**                     | 让成员的初始化意图一目了然                        | `A(int a,int b):x(a),y(b){};`                                |

### 3.3 示例实现



```cpp
// Student.cpp
#include "Student.h"

Student::Student(const std::string& name, int age)
    : name_(name), age_(age) {}

void Student::setName(const std::string& name) {
    name_ = name;
}

std::string Student::getName() const {
    return name_;
}

void Student::setAge(int age) {
    if (age > 0)
        age_ = age;
}

int Student::getAge() const {
    return age_;
}
```



------



## 4. 访问控制



### 4.1 访问修饰符



- **public**：公有成员，可以被所有代码访问。
- **private**：私有成员，仅能被类的成员函数和友元访问。
- **protected**：受保护成员，仅能被类的成员函数、友元和派生类访问。



### 4.2 例子



```cpp
class Sample {
public:
    void publicFunction();

private:
    int privateVar_;
    void privateFunction();

protected:
    int protectedVar_;
};
```



------



## 5. 构造函数与析构函数



### 5.1 构造函数



- **默认构造函数**：没有参数的构造函数。
- **参数化构造函数**：接受参数以初始化对象。
- **拷贝构造函数**：用一个对象初始化另一个对象。
- **移动构造函数（C++11）**：从临时对象“移动”资源。

**移动构造函数和拷贝构造函数的关系**

1. 首先vector由三个部分组成：begin，end，capacity（存在栈里），vector的元素（存在堆里）
2. vector<int> a; vector<int> b(a);
   这里如果采用的是移动构造，那就是a的begin,end,capacity设置为nullptr
3. 之后将b的begin，end，capacity改为a的元素在堆中的地址
4. 就无需拷贝一份一模一样的，注意这里如果移动构造不采用noexcept，会导致编译器采用更加安全的拷贝构造
5. 对于vector<Image>这种较大数据类型的数组扩容时
6. Image* img = new Image(); vector<Image> images; images.push_back(img);
   这里采用的是移动构造扩容，可以加速。原因在于直接使用原本img在堆中的数据，而不是创建一份新的img
7. 本身扩容操作就有O(n)的时间复杂度
8. 即：旧堆中分配了n个连续空间，每个元素是一个指针，为4n字节，现在push_back之后，需要重新分配堆空间，重新分配空间为2*4n字节，那么就需要将原本n个指针拷贝到前n个位置，之后将img指针放在n+1的位置上，将img指针修改为nullptr



### 5.2 析构函数



- **析构函数（Destructor）**：在对象生命周期结束时调用，用于释放资源。



### 5.3 示例



```cpp
#include <iostream>

class Example {
public:
    // 默认构造函数
    Example() : data_(0) {
        std::cout << "Default constructor called.\n";
    }

    // 参数化构造函数
    Example(int data) : data_(data) {
        std::cout << "Parameterized constructor called with data = " << data_ << ".\n";
    }

    // 拷贝构造函数
    Example(const Example& other) : data_(other.data_) {
        std::cout << "Copy constructor called.\n";
    }

    // 移动构造函数
    Example(Example&& other) noexcept : data_(other.data_) {
        other.data_ = 0;
        std::cout << "Move constructor called.\n";
    }

    // 析构函数
    ~Example() {
        std::cout << "Destructor called for data = " << data_ << ".\n";
    }

private:
    int data_;
};
```



### 5.4 使用示例



```cpp
int main() {
    Example ex1;               // 调用默认构造函数
    Example ex2(42);           // 调用参数化构造函数
    Example ex3 = ex2;         // 调用拷贝构造函数
    Example ex4 = std::move(ex2); // 调用移动构造函数
    return 0;
}
```



**输出示例：**



```kotlin
Default constructor called.
Parameterized constructor called with data = 42.
Copy constructor called.
Move constructor called.
Destructor called for data = 0.
Destructor called for data = 42.
Destructor called for data = 42.
```



### 5.5 拷贝构造是否必须实现

当一个类A中有成员变量是另一个类类型B的时候，有时候拷贝构造会失效。比如一个类A中有成员变量`std::thread`，`std::thread`没有构造函数，所以A类的拷贝构造无法合成，需要显示编写。

同样析构也要显示编写，等待线程完成。

除此之外我们可以自己实现拷贝构造，进而实现浅拷贝和深拷贝的不同效果

![https://cdn.llfc.club/1731294878994.jpg](https://cdn.llfc.club/1731294878994.jpg)

![https://cdn.llfc.club/1731295328032.jpg-llfc](https://cdn.llfc.club/1731295328032.jpg-llfc)

### 5.6 构造顺序和析构顺序

类A中包含成员变量是类B的类型，如果是先调用A的构造还是B的构造呢？

如果析构的时候是A先析构还是B先析构呢？

> **记忆技巧**：构造“内到外”，析构“外到内”。构造成员先，析构成员后。

因此，先执行B的构造，再执行A的构造；先执行A的析构，再执行B的析构

### 5.7 类默认构造是否必须实现

如果类中有继承关系或者其他类型的成员，默认构造函数是很有必要实现的。

系统提供的合成的默认构造函数不会对成员做初始化操作。



### 5.8 `this` 指针的特性和用途



1. **指向当前对象**：

    - `this` 指针是一个隐式参数，指向调用成员函数的对象。通过 `this`，你可以访问当前对象的属性和方法。

2. **区分成员变量和参数**：

    - 在构造函数或成员函数中，参数名和成员变量可能同名。使用



     ```
     this
     ```


​      

     可以明确指代成员变量。例如：
    
     ```cpp
     class MyClass {
     private:
         int value;
     public:
         MyClass(int value) {
             this->value = value; // 使用 this 指针区分成员变量和参数
         }
     };
     ```

3. **返回当前对象**：

    - ```
     this
     ```



     可以用于返回当前对象的引用，以支持链式调用。例如：
    
     ```cpp
     class MyClass {
     private:
         int value;
     public:
         MyClass& setValue(int value) {
             this->value = value;
             return *this; // 返回当前对象的引用
         }
     };
     
     MyClass obj;
     obj.setValue(10).setValue(20); // 链式调用
     ```

4. **在 const 成员函数中的使用**：

    - 在 `const` 成员函数中，`this` 的类型为 `const MyClass*`，这意味着你不能通过 `this` 修改成员变量。这有助于确保对象的状态不被改变。

5. **在静态成员函数中的不可用性**：

    - 静态成员函数没有 `this` 指针，因为它们不属于任何特定对象，而是属于类本身。因此，静态成员函数不能访问非静态成员变量和成员函数。



**示例代码**



以下是一个简单的示例，展示了 `this` 指针的用法：



```cpp
#include <iostream>

class MyClass {
private:
    int value;

public:
    // 构造函数
    MyClass(int value) {
        this->value = value; // 使用 this 指针区分成员变量和参数
    }

    // 成员函数
    MyClass& setValue(int value) {
        this->value = value; // 使用 this 指针
        return *this; // 返回当前对象的引用
    }

    // 输出值
    void printValue() const {
        std::cout << "Value: " << this->value << std::endl; // 使用 this 指针
    }
};

int main() {
    MyClass obj(10);
    obj.printValue(); // 输出: Value: 10

    obj.setValue(20).printValue(); // 链式调用，输出: Value: 20

    return 0;
}
```

### 5.9 delete和default

`C++11`用法：

delete可以删除指定的构造函数。

default可以指定某个构造函数为系统默认合成。

```c++
// 禁止无参构造函数
Student() = delete;
// 显式的使用编译器默认的析构函数
~Student() = default;
```

## 6. 拷贝控制

**拷贝构造函数与拷贝赋值运算符**

### 6.1 拷贝构造函数



- **定义**：用于创建一个新对象，并复制现有对象的成员。
- **语法**：`ClassName(const ClassName& other);`



### 6.2 拷贝赋值运算符



- **定义**：用于将一个已有对象的值赋给另一个已有对象。
- **语法**：`ClassName& operator=(const ClassName& other);`



### 6.3 示例



```cpp
#include <iostream>
#include <cstring>

class MyString {
public:
    // 构造函数
    MyString(const char* str = nullptr) {
        if (str) {
            size_ = std::strlen(str);
            data_ = new char[size_ + 1];
            std::strcpy(data_, str);
        } else {
            size_ = 0;
            data_ = new char[1];
            data_[0] = '\0';
        }
        std::cout << "Constructor called.\n";
    }

    // 拷贝构造函数
    MyString(const MyString& other) : size_(other.size_) {
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
        std::cout << "Copy constructor called.\n";
    }

    // 拷贝赋值运算符
    MyString& operator=(const MyString& other) {
        std::cout << "Copy assignment operator called.\n";
        if (this == &other)
            return *this; // 自赋值检查

        delete[] data_; // 释放现有资源

        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
        return *this;
    }

    // 析构函数
    ~MyString() {
        delete[] data_;
        std::cout << "Destructor called.\n";
    }

    void print() const {
        std::cout << data_ << "\n";
    }

private:
    char* data_;
    std::size_t size_;
};
```

这里注意，如果释放单一元素，直接使用 `delete` 即可

使用数组元素，那么需要使用 `delete []`

### 6.4 使用示例



```cpp
int main() {
    MyString s1("Hello");
    MyString s2 = s1;        // 调用拷贝构造函数
    MyString s3;
    s3 = s1;                  // 调用拷贝赋值运算符

    s1.print();
    s2.print();
    s3.print();
    return 0;
}
```



**输出示例：**



```kotlin
Constructor called.
Copy constructor called.
Constructor called.
Copy assignment operator called.
Hello
Hello
Hello
Destructor called.
Destructor called.
Destructor called.
```



## 7. 移动语义



### 7.1 什么是移动语义



- **移动语义（Move Semantics）**：允许资源的所有权从一个对象转移到另一个对象，避免不必要的拷贝，提高性能。



### 7.2 移动构造函数与移动赋值运算符



- **移动构造函数**：`ClassName(ClassName&& other) noexcept;`
- **移动赋值运算符**：`ClassName& operator=(ClassName&& other) noexcept;`



### 7.3 示例



```cpp
#include <iostream>
#include <utility>

class MoveExample {
public:
    // 构造函数
    MoveExample(int size) : size_(size), data_(new int[size]) {
        std::cout << "Constructor called.\n";
    }

    // 拷贝构造函数
    MoveExample(const MoveExample& other) : size_(other.size_), data_(new int[other.size_]) {
        std::copy(other.data_, other.data_ + size_, data_);
        std::cout << "Copy constructor called.\n";
    }

    // 移动构造函数
    MoveExample(MoveExample&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
        std::cout << "Move constructor called.\n";
    }

    // 拷贝赋值运算符
    MoveExample& operator=(const MoveExample& other) {
        std::cout << "Copy assignment operator called.\n";
        if (this == &other)
            return *this;

        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        std::copy(other.data_, other.data_ + size_, data_);
        return *this;
    }

    // 移动赋值运算符
    MoveExample& operator=(MoveExample&& other) noexcept {
        std::cout << "Move assignment operator called.\n";
        if (this == &other)
            return *this;

        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;

        other.size_ = 0;
        other.data_ = nullptr;
        return *this;
    }

    // 析构函数
    ~MoveExample() {
        delete[] data_;
        std::cout << "Destructor called.\n";
    }

private:
    int size_;
    int* data_;
};
```



### 7.4 使用示例



```cpp
int main() {
    MoveExample ex1(100);                 // Constructor
    MoveExample ex2 = ex1;                // Copy Constructor
    MoveExample ex3 = MoveExample(200);   // Move Constructor

    MoveExample ex4(300);
    ex4 = ex1;                             // Copy Assignment
    ex4 = MoveExample(400);                // Move Assignment

    return 0;
}
```



**输出示例：**



```kotlin
Constructor called.
Copy constructor called.
Constructor called.
Move constructor called.
Destructor called.
Constructor called.
Copy assignment operator called.
Move constructor called.
Move assignment operator called.
Destructor called.
Destructor called.
Destructor called.
Destructor called.
```



------



## 8. 类的友元



### 8.1 什么是友元



- **友元（Friend）**：可以访问类的私有和保护成员的非成员函数或另一个类。



### 8.2 类型



- **友元函数**：单个函数可以被声明为友元。
- **友元类**：整个类可以被声明为友元。



### 8.3 使用示例



```cpp
#include <iostream>

class Box {
public:
    Box(double length, double width, double height)
        : length_(length), width_(width), height_(height) {}

    // 声明友元函数
    friend double calculateVolume(const Box& b);

private:
    double length_;
    double width_;
    double height_;
};

// 友元函数定义
double calculateVolume(const Box& b) {
    return b.length_ * b.width_ * b.height_;
}
```



### 8.4 使用友元类



```cpp
class Rectangle {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

private:
    double width_;
    double height_;

    // 声明友元类
    friend class AreaCalculator;
};

class AreaCalculator {
public:
    double calculateArea(const Rectangle& rect) {
        return rect.width_ * rect.height_;
    }
};
```



------



## 9. 运算符重载



### 9.1 什么是运算符重载



- **运算符重载（Operator Overloading）**：允许对自定义类型使用C++运算符，如 `+`, `-`, `<<` 等。



### 9.2 重载运算符的规则



- 只能对已有运算符进行重载，不能创建新运算符。
- 至少有一个操作数必须是用户定义的类型。
- 不能改变运算符的优先级或结合性。



### 9.3 示例：重载 `+` 运算符



```cpp
#include <iostream>
#include <string>

class Point {
public:
    Point(double x, double y) : x_(x), y_(y) {}

    // 成员函数重载 +
    Point operator+(const Point& other) const {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    void print() const {
        std::cout << "(" << x_ << ", " << y_ << ")\n";
    }

private:
    double x_;
    double y_;
};

// 也可以使用友元函数重载 +

Point operator-(const Point& a, const Point& b) {
    return Point(a.x_ - b.x_, a.y_ - b.y_);
}

int main() {
    Point p1(1.5, 2.5);
    Point p2(3.0, 4.0);

    Point p3 = p1 + p2;
    p3.print(); // 输出： (4.5, 6.5)

    Point p4 = p2 - p1;
    p4.print(); // 输出： (1.5, 1.5)

    return 0;
}
```



### 9.4 示例：重载 `<<` 运算符（输出流）



```cpp
#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string& name, double salary)
        : name_(name), salary_(salary) {}

    // 声明友元函数以重载 <<
    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);

private:
    std::string name_;
    double salary_;
};

// 定义重载的 <<
std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << "Employee Name: " << emp.name_ << ", Salary: $" << emp.salary_;
    return os;
}

int main() {
    Employee emp("John Doe", 75000);
    std::cout << emp << std::endl;
    return 0;
}
```



**输出示例：**



```yaml
Employee Name: John Doe, Salary: $75000
```



## 10. 练习示例



### 项目：实现自定义`MyString`类



**目标**：创建一个简单的`MyString`类，支持拷贝构造，默认构造，有参构造，支持输出和比较等。

``` cpp
#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;  // 动态分配的字符数组
public:
    // 默认构造函数
    MyString() : data(nullptr) {}

    // 有参构造函数
    MyString(const char* str) {
        if (str) {
            data = new char[strlen(str) + 1]; // +1 for the null terminator
            strcpy(data, str);
        } else {
            data = nullptr;
        }
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    // 赋值运算符重载
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data; // 释放原有内存
            if (other.data) {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // 比较运算符重载
    bool operator==(const MyString& other) const {
        if (data == nullptr && other.data == nullptr) return true;
        if (data == nullptr || other.data == nullptr) return false;
        return strcmp(data, other.data) == 0;
    }

    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
        if (myStr.data) {
            os << myStr.data;
        }
        return os;
    }

    // 析构函数
    ~MyString() {
        delete[] data; // 释放动态分配的内存
    }
};

int main() {
    MyString str1("Hello, World!");
    MyString str2 = str1; // 拷贝构造
    MyString str3;

    str3 = str1; // 赋值运算符重载

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    if (str1 == str2) {
        std::cout << "str1 and str2 are equal." << std::endl;
    } else {
        std::cout << "str1 and str2 are not equal." << std::endl;
    }

    return 0;
}
```



### 代码说明



1. **私有成员**：
    - `char* data`：指向动态分配的字符数组，用于存储字符串。
2. **构造函数**：
    - **默认构造函数**：初始化 `data` 为 `nullptr`。
    - **有参构造函数**：接收一个 `const char*` 类型的字符串，动态分配内存并复制字符串内容。
    - **拷贝构造函数**：复制另一个 `MyString` 对象的内容，确保深拷贝。
3. **赋值运算符重载**：支持将一个 `MyString` 对象赋值给另一个，确保释放原有内存并进行深拷贝。
4. **比较运算符重载**：支持比较两个 `MyString` 对象是否相等。
5. **输出运算符重载**：支持直接使用 `std::cout` 输出 `MyString` 对象。
6. **析构函数**：释放动态分配的内存，防止内存泄漏。



### 使用示例



在 `main` 函数中，创建了几个 `MyString` 对象，演示了拷贝构造、赋值和比较的用法。

## 视频教程

关于C++的视频教程可参考我的主页

[C++教程视频](https://space.bilibili.com/271469206)