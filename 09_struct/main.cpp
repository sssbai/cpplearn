#include <iostream>
#include "mims.h"
// 定义结构体
// 学生结构体
struct Student {
    // 成员变量
    // 学号
    int id;
    // 姓名
    std::string name;
    // 学分权重
    float grade;

    // 构造函数，用来创建对象时调用的，并且传递参数给各个成员变量
    Student(int id_, std::string name_, float grade_)
    : id(id_), name(name_) { // 初始化列表
        grade = grade_; // 函数体内初始化
    }
    // 默认构造函数，如果构建了一个个性的构造函数，那么默认构造函数会被覆盖
    Student():id(0), name(""), grade(0.0f) {}

};
struct Point {
    int x;
    int y;
};

// 通过值传递
void printPoint(Point p) {
    std::cout << "Point(" << p.x << ", " << p.y << ")" << std::endl;
}

// 通过引用传递
void movePoint(Point & p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
}

// 矩形结构体
struct Rectangle {
    int width;
    int height;
};

// 计算面积的结构体
struct Area {
    int value;
};

// 函数返回结构体
Area calculateArea(Rectangle rect) {
    Area area;
    area.value = rect.width * rect.height;
    return area;
}

int main() {

    // 定义结构体变量
    Student student1;
    Student student2;

    // 修改结构体内的成员变量
    // 修改学号
    student1.id = 512;
    // 修改名字
    student1.name = std::string("bai");
    // 修改评分权重
    student1.grade = 89.5f;

    // 结构体成员的访问
    std::cout << "student id = " << student1.id << std::endl;
    std::cout << "student name = " << student1.name << std::endl;
    std::cout << "student grade = " << student1.grade << std::endl;

    // 快速初始化结构体变量
    Student student3 = {513 , "ly", 95.04f};

    std::cout << "student id = " << student3.id << std::endl;
    std::cout << "student name = " << student3.name << std::endl;
    std::cout << "student grade = " << student3.grade << std::endl;

    // 运算符重载后才能输出，需要重载 << 运算符
    // std::cout << student4 << std::endl;

    Student student5(100, "Daisy", 0.9);
    std::cout << "student id = " << student5.id << std::endl;
    std::cout << "student name = " << student5.name << std::endl;
    std::cout << "student grade = " << student5.grade << std::endl;
    {
        // 嵌套结构体
        struct Address {
            std::string city;
            std::string street;
            int houseNumber;
        };
        struct Person {
            std::string name;
            int age;
            Address address; // 嵌套结构体
        };
        Person person;
        person.name = "Eve";
        person.age = 30;
        person.address.city = "New York";
        person.address.street = "5th Avenue";
        person.address.houseNumber = 5;

        std::cout << person.name << " lives at "
            << person.address.houseNumber << " "
            << person.address.street << " "
            << person.address.city << std::endl;
    }
    {
        // 结构体数组
        Student array[3] = {
            {1, "Alice", 55.0f},
            {2, "Bob", 76.2f},
            {3, "Williams", 77.2f},
        };

        for (int i = 0; i < 3; i++) {
            std::cout << array[i].id << std::endl;
            std::cout << array[i].name << std::endl;
            std::cout << array[i].grade << std::endl;
        }
    }
    {
        // 结构体指针
        struct Car {
            std::string brand;
            std::string model;
            int year;
        };

        Car car1 = {"BMW", "M5", 2019};
        int a = 100;
        int *p = &a;
        Car * pcar = &car1;
        std::cout << pcar->brand << std::endl;
    }
    {
        // 使用 typedef 简化结构体定义
        // 使用 typedef (或 using 关键字) 可以为结构体类型创建别名，使代码更简洁
        typedef struct {
            int id;
            std::string name;
            float grade;
        } Student1;

        // 拆解开来的写法
        struct Student2 {
            int id;
            std::string name;
            float grade;
        };
        typedef Student2 Student3;

        // 或者使用 using （C++11 及以上）
        using Student4 = struct {
            int id;
            std::string name;
            float grade;
        };
    }
    {
        // 结构体中的函数
        struct Book{
            std::string title;
            std::string author;
            int pages;

            // 成员函数
            void printInfo() const {
                std::cout << "title = " << title
                    << ", author = " << author
                    << ", pages = " << pages << std::endl;
            }
        };
        Book mybook = {"C++ Primer", "Stanley B. Lippman", 976};
        mybook.printInfo();
    }
    {
        // 使用结构体作为函数参数和返回值
        Point p1 = {10, 20};
        printPoint(p1);

        movePoint(p1, 5, -5);
        printPoint(p1);
    }
    {
        // 从函数返回结构体
        Rectangle rect = {5, 10};
        Area rectArea = calculateArea(rect);
        std::cout << "The area of rectangle = " << rectArea.value << std::endl;

    }
    {
        std::vector<Master> masters;
        int choice;
        do {
            std::cout <<"\n==== Master Information Management System ====" << std::endl;
            std::cout << "1. Add Master" << std::endl;
            std::cout << "2. View All Master" << std::endl;
            std::cout << "3. Find Master according to ID" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "Enter Choice (1-4): ";
            std::cin >> choice;
            if (choice == 1) {
                int id;
                std::string name;
                float grade;
                std::cout << "Enter Master ID:";
                std::cin >> id;
                std::cout << "Enter Master Name:";
                std::cin >> name;
                std::cout << "Enter Master Grade:";
                std::cin >> grade;
                addMaster(masters, id, name, grade);
            }
            else if (choice == 2) {
                displayMasters(masters);
            }
            else if (choice == 3) {
                int searchId;
                std::cout << "Enter Master ID:";
                std::cin >> searchId;
                findMasterById(masters, searchId);
            }
            else if (choice == 4) {
                std::cout << "Exiting ..." << std::endl;
            }
            else {
                std::cout << "Invalid Choice" << std::endl;
            }
        }while (choice != 4);
    }
    return 0;
}