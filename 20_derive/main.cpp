#include <iostream>
#include <string>
#include "Derived.h"

int main() {
    // Derived d(1,2);
    // d.derivedFunc();
    // d.baseFunc();
    // d.commonDisplay();
    // d.commonDisplay(1,4);
    //
    // Derived * dp = new Derived();
    // Base * bp = new Derived();
    //
    // dp->commonDisplay();
    // bp->commonDisplay();
    // // std::cout << typeid(dp);
    //
    // dp->virtualDisplay();
    // bp->virtualDisplay();
    //
    // Vehicle * pcar = new Car();
    // pcar->startEngine();
    //
    // Vehicle * pmotor = new Motorcycle();
    // pmotor->startEngine();

    Base* b = new Derived();
    delete b;// 输出为 ~Base()，没有执行 ~Derived()，因此需要对 Base 类构建 虚析构函数

    return 0;
}