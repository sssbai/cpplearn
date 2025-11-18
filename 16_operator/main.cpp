#include <iostream>

int main() {
    {
        // 算术运算符
        int a = 10, b = 3;
        int sum = a + b;    // 13
        int diff = a - b;   // 7
        int prod = a * b;   // 30
        int div = a / b;    // 3
        int mod = a % b;    // 1
        a++;                // a = 11
        --b;                // b = 2
    }
    {
        // 关系运算符
        int a = 5, b = 10;
        bool result1 = (a == b); // false
        bool result2 = (a < b);  // true
        bool result3 = (a >= b); // false
    }
    {
        // 逻辑运算符
        bool a = true, b = false;
        bool result1 = a && b; // false
        bool result2 = a || b; // true
        bool result3 = !a;     // false
    }
    {
        // 位运算符
        int a = 5;  // 二进制：0101
        int b = 3;  // 二进制：0011
        int andResult = a & b; // 1 (0001)
        int orResult = a | b;  // 7 (0111)
        int xorResult = a ^ b; // 6 (0110)
        int notResult = ~a;    // -6 (补码)
        int leftShift = a << 1; // 10 (1010)
        int rightShift = a >> 1; // 2 (0010)
    }
    {
        // 赋值运算符
        int a = 5;
        int b = 3;
        a += b; // a = 8
        a *= 2; // a = 16
        a &= b; // a = 16 & 3 = 0
    }
    {
        // 复合赋值运算符
        int a = 10;
        a += 5; // 等同于 a = a + 5; 结果 a = 15
    }
    {
        // 条件运算符
        int a = 10, b = 20, c;
        c = (a > b) ? a : b; // c = 20
    }
    {
        // 递增和递减运算符
        int a = 5;
        int b = ++a; // a = 6, b = 6
        int c = a--; // a = 5, c = 6
    }
    {
        // 指针运算符
        int a = 10;
        int *ptr = &a;
        int value = *ptr; // value = 10
    }
    {
        // 成员访问运算符
        struct Point {
            int x;
            int y;
        };

        Point p = {10, 20};
        Point *ptr = &p;
        int a = p.x;      // 使用 . 运算符
        int b = ptr->y;  // 使用 -> 运算符
    }
    {
        // 其他运算符
        int a = 5;
        int size = sizeof(a); // size = 4 (通常)
        int b, c;
        b = (a++, a + 2); // a = 6, b = 8
    }
    {
        // 运算符重载
        /* 可重载运算符：几乎所有的运算符都可以被重载，但如 ::, ?:, sizeof 等运算符不能被重载。
         * 至少一个操作数必须是用户定义类型：即至少有一个操作数是类、结构体或联合体类型。
         * 运算符重载不改变运算符的优先级、结合性和操作数数量。
         */
    }
    {
        int x = 5;
        int y = 26;
        std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
        // 交换操作
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
        std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    }
    return 0;
}
// 成员函数重载示例
class Complex1 {
public:
    double real, imag;

    Complex1 operator+(const Complex1 &c) {
        Complex1 temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

// 友元函数重载示例
class Complex2 {
public:
    double real, imag;

    friend Complex2 operator+(const Complex2 &c1, const Complex2 &c2);
};

Complex2 operator+(const Complex2 &c1, const Complex2 &c2) {
    Complex2 temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

// 多种重载混合示例
class Complex3 {
public:
    double real, imag;

    Complex3(double r = 0, double i = 0) : real(r), imag(i) {}

    // 重载 + 运算符
    Complex3 operator+(const Complex3 &c) {
        return Complex3(real + c.real, imag + c.imag);
    }

    // 重载 << 运算符（作为友元函数）
    friend std::ostream& operator<<(std::ostream &out, const Complex3 &c);
};
std::ostream& operator<<(std::ostream &out, const Complex3 &c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}