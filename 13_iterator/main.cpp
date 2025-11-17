#include <iostream>
#include <vector>

int main() {
    {
        // 迭代器（Iterator）是C++的STL模版库中的一个重要概念，提供了一种方法，按顺序访问容器中的元素，而无需暴露容器的内部表示。
        std::vector<int> v;
        auto a = v.begin(), b = v.end();
    }
    {
        // 比较运算
        std::string s("some string");
        //确保s非空
        if(s.begin() != s.end()){
            //第一个字母改为大写
            auto it = s.begin();
            *it = toupper(*it);
            std::cout << s << std::endl;
        }
    }
    {
        // 自增运算
        std::string s = "another string";
        for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
            *it = toupper(*it);
        }
        std::cout << s << std::endl;
    }
    {
        // 泛型编程：养成使用迭代器和!=的习惯，而不用太在意用的到底是哪种容器类型
        // 迭代器类型
        // 迭代器it, it能读写vector<int>的元素
        std::vector<int>::iterator it;
        // it2能读写string对象的字符
        std::string::iterator it2;
        // it3只能读元素，不能写元素
        std::vector<int>::const_iterator it3;
        // it4只能读字符,不能写字符
        std::string::const_iterator it4;

        std::vector<int> numbers = {1,2,3,4,5};

        // 使用 const_iterator 遍历
        std::vector<int>::const_iterator iter;
        for (iter = numbers.begin(); iter != numbers.end(); ++iter) {
            // 读取元素值
            std::cout << *iter << " ";
            // *iter = 10; 这里是不正确的，无法修改元素值
        }
        std::cout << std::endl;
    }
    {
        // begin 和 end 运算符
        // begin 和 end 所返回的具体类型是由对象是否是常量所决定的，如果对象是常量，那么返回的就是const_iterator
        std::vector<int> v = {1,2,3};
        const std::vector<int> cv;
        //it1是 vector<int>的迭代器，
        auto it1 = v.begin();
        //it2是const vector<int>的迭代器
        auto it2 = cv.begin();

        // C++11，如果一个容器是非常量，可以通过 cbegin 和 cend 来获取对应的常量迭代器
        //it3的类型是vector<int>::const_iterator
        auto it3 = v.cbegin();
        std::cout << *it3 << std::endl;
    }
    {
        // 结合解引用和成员访问操作
        // (*it).empty(); 解引用迭代器可获得迭代器所指的对象,这里得到的对象是类，进一步访问它的成员
        std::vector<std::string> vs = {"hello","", "world"};

        for(auto it = vs.begin(); it != vs.end(); ++it){
            //(*it)解引用获取string对象，再次调用empty()方法判断为空
            if((*it).empty()){
                std::cout << "empty string" << std::endl;
            }
        }

        // 如果整个循环从头到位只是读取 text 中的元素，而不需要写值，因此可以使用 cbegin 和 cend
        for (auto it = vs.cbegin(); it != vs.cend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    // {
    //     // 迭代器失效
    //     // vector 对象可以动态增长，但是存在副作用：
    //     // 一、不能在 range-for 循环中向 vector 对象添加元素
    //     // 二、任何可能改变 vector 对象容器的操作，比如 push_back，都会使该 vector 对象的迭代器失效
    //
    //     // 注意下面逻辑错误，在 for 循环中 push 元素导致死循环
    //     std::vector<int> numbers = {1,2,3};
    //     for (auto i = 0; i < numbers.size(); i++) {
    //         numbers.push_back(i);
    //     }
    //     // 注意下面逻辑错误，在 for 循环中 push 元素导致迭代器失效，也会导致死循环
    //     for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    //         numbers.push_back(1);
    //     }
    //     // 删除第一个元素
    //     numbers.erase(numbers.begin());
    // }
    {
        // vector<int>容器存储了一系列数字，在循环中遍历每一个元素，并且删除其中的奇数，要求循环结束，vector元素为偶数，要求时间复杂度o(n)
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        // 循环遍历，并删除其中奇数
        for (auto it = numbers.begin(); it != numbers.end();) {
            // 删除奇数
            if (*it % 2 != 0) {
                it = numbers.erase(it);
                continue;
            }
            ++it;
        }
        for (auto num:numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    {
        // 迭代器的算术运算
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        // 中间位置的迭代器
        auto mid = numbers.begin()+numbers.size()/2;
        // 判断迭代器是否有效
        if (mid!=numbers.end()) {
            std::cout << *mid << std::endl;
        }
        else {
            std::cout << "mid is end." << std::endl;
        }
    }
    {
        // 使用迭代器运算
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        // 二分查找 4 所在的迭代器为止
        auto beg = numbers.begin(), end = numbers.end();
        auto mid = beg + (end - beg) / 2;
        // 二分查找
        while (mid !=end && *mid != 4) {
            // 4 在 mid 的右边
            if (*mid < 4) {
                beg = mid + 1;
            }
            else {
                // 4 在 mid 的左边
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }
        if (mid != end) {
            std::cout << "4 is found." << std::endl;
        }
        else {
            std::cout << "4 is not found." << std::endl;
        }
    }
    {
        // 相邻元素的和
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        int num;

        // std::cout << "Please enter numbers:";
        // while (std::cin >> num && num != -1) {
        //     numbers.push_back(num);
        // }

        for (auto it = numbers.begin(); it != numbers.end(); ++it) {
            std::cout << (*it + *(it + 1)) << " ";
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        for (std::vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> vector1={1,2,3,4,5}, vector2={1,2,3,4,5}, mergedVector;
        mergedVector.insert(mergedVector.end(), vector1.begin(), vector1.end());
        mergedVector.insert(mergedVector.end(), vector2.begin(), vector2.end());
        for (std::vector<int>::iterator it = mergedVector.begin(); it != mergedVector.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}