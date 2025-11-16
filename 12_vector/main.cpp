#include <iostream>
#include <vector>
#include <vector>
struct Student {
    int id;
    std::string name;
    float grade;
};
void addStudent(std::vector<Student>& students, int id_, std::string name_, float grade_);
void deleteStudent(std::vector<Student>& students, std::string name);
void displayStudents(std::vector<Student>& students, std::string name);
void findStudent(std::vector<Student>& students, std::string name);
int main() {
    {
        // 向量（vector）是STL中的一种序列容器
        std::vector<int> numbers;
        std::vector<std::string> words;
        // 空向量
        std::vector<int> vec1;
        // 指定大小和默认值
        std::vector<int> vec2(5,10);
        // 使用初始化列表
        std::vector<int> vec3 = {1, 2, 3, 4};
        // 拷贝构造
        std::vector<int> vec4(vec3);
        // 移动构造
        std::vector<int> vec5(std::move(vec4));

        // 输出vec2
        std::cout << "vec2: ";
        for(auto num : vec2) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 输出vec3
        std::cout << "vec3: ";
        for(auto num : vec3) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 输出vec5
        std::cout << "vec5: ";
        for(auto num : vec5) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 输出vec4， 这里已经是空了，因为将vec4 move to vec5
        std::cout << "vec4: ";
        for(auto num : vec4) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    {
        // 向量的大小与容量
        std::vector<int> numbers = {1, 3, 4, 5};
        std::cout << "Size = " << numbers.size() << std::endl;
        // capacity() 并不一定精准匹配 size()，它表示在需要重新分配内存之前，向量可以容纳的元素数量。
        std::cout << "Capacity = " << numbers.capacity() << std::endl;
        // empty() 判断当前向量是否为空
        std::cout << "Is empty ? " << (numbers.empty() ? "Yes" : "No") << std::endl;
        // 预留容量
        numbers.reserve(10);
        std::cout << "After reserve(10), Capacity = " << numbers.capacity() << std::endl;
        // 收缩到合适大小
        numbers.shrink_to_fit();
        std::cout << "After shrink_to_fit(), Capacity = " << numbers.capacity() << std::endl;
    }
    {
        // vector 向量的基本操作
        std::vector<int> numbers = {1, 2, 3, 4};

        // 使用 push_back 添加元素
        numbers.push_back(5);
        std::cout << "After push_back():";
        for (auto v: numbers) {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        // 使用 pop_back 移除最后一个元素
        numbers.pop_back();

        std::cout << "After pop_back():";
        for (auto v: numbers) {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        // 在第二个位置插入 25
        numbers.insert(numbers.begin() + 1, 25);
        std::cout << "After insert():";
        for (auto v: numbers) {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        // 删除第二个元素 25
        numbers.erase(numbers.begin() + 1);
        std::cout << "After erase():";
        for (auto v: numbers) {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        // 清空向量
        numbers.clear();
        std::cout << "After clear(), Size = " << numbers.size() << " Capacity = " << numbers.capacity() << std::endl;
    }
    {
        // 访问元素
        std::vector<std::string> fruits = {"Apple", "Banana", "Watermelon"};

        // 使用 operator[] 访问元素
        std::cout << "First fruit: " << fruits[0] << std::endl;

        // 使用 at() 访问元素
        try {
            std::cout << "Second fruit: " << fruits.at(1) << std::endl;
            // 抛出异常
            std::cout << "Third fruit: " << fruits.at(4) << std::endl;
        }catch (std::out_of_range& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        // 使用 front() 和 back()
        std::cout << "Front : " << fruits.front() << std::endl;
        std::cout << "Back : " << fruits.back() << std::endl;
    }
    {
        // 遍历向量
        std::vector<int> numbers = {1, 2, 3, 4};

        // 使用 范围 for 循环
        std::cout << "Using range-based for loop: ";
        for (auto num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 使用 传统 for 循环
        std::cout << "Using traditional for loop: ";
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        // 使用迭代器 iterator
        std::cout << "Using iterators: ";
        for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }
    {
        // 修改元素
        // modify the element of vector.
        std::vector<int> numbers = {1, 2, 3, 4};

        // 通过索引修改
        // modify value by index
        numbers[2] = 10;

        // 通过 at() 修改
        // modify value by using at()
        numbers.at(3) = 25;

        // 通过迭代器修改
        // modify value by using iterator
        for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
            if (*iter == 10) {
                *iter = 100;
            }
        }

        // print the result of vector.
        std::cout << "Modified vector: ";
        for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }
    {
        // 嵌套向量（二维向量）
        // 定义一个 3 x 4 的二维向量，初始化为 0
        std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));

        // 填充矩阵
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                matrix[i][j] = i * 4 + j + 1;
            }
        }
        std::cout << "Matrix: " << std::endl;
        for (auto row: matrix) {
            for (auto elem: row) {
                std::cout << elem << "\t";
            }
            std::cout << std::endl;
        }
    }
    {
        // 向量和其他数据结构结合
        std::vector<Student> students;

        // 添加元素
        students.push_back({101, "Alice", 83.2});
        students.push_back({102, "bob", 93.2});
        students.push_back({103, "Charlie", 81.2});

        // 遍历输出
        for (auto student: students) {
            std::cout << "ID: " << student.id << " Name: " << student.name << " Grade: " << student.grade << std::endl;
        }
    }
    {
        // 使用迭代器操作向量
        std::vector<int> vec = {1, 23, 5, 5, 10};

        // 使用迭代器遍历并修改元素
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            *it += 4;
        }
        std::cout << "Aftering modifying:";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        // 排序
        std::vector<int> vec = {1, 23, 5, 5, 10};

        std::cout << "Before sorting: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::sort(vec.begin(), vec.end());

        std::cout << "After sorting: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        // 自定义排序规则：降序
        std::vector<int> vec = {1, 23, 5, 5, 10};

        // 使用 sort() 并传入 lambda 表达式进行降序排序
        std::sort(vec.begin(), vec.end(), [](int a, int b){return a>b;});

        // 输出排序后的向量
        std::cout << "After sorting: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        // 反转
        std::vector<int> vec = {1, 23, 5, 5, 10};
        std::cout << "Before reversing: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        // 反转向量
        std::reverse(vec.begin(), vec.end());

        std::cout << "After reversing: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    {
        // 查找元素
        std::vector<std::string> fruits = {"Apple", "Banana", "Cherry", "Date"};
        std::string target = "Cherry";

        // 使用 find() 查找元素
        auto it = std::find(fruits.begin(), fruits.end(), target);
        if (it != fruits.end()) {
            std::cout << target <<" found at position " << std::distance(fruits.begin(), it) << std::endl;
        }
        else {
            std::cout << target << " not found." << std::endl;
        }
    }
    {
        // 向量的性能与优化
        // 内存管理：vector 会自动管理内存，自动调整其容量一适应新增或者删除的元素。频繁的内存分配可能会影响性能。
        // 预留空间：使用 reserve() 可以提前为向量分配足够的内存，减少内存重新分配的次数，提高性能。
        std::vector<int> vec;

        // 预留空间
        vec.reserve(100);
        std::cout << "Capacity after reserve(100): " << vec.capacity() << std::endl;

        // 添加元素
        for (int i = 0; i < 105; i++) {
            vec.push_back(i);
        }

        std::cout << "Size after adding elements: "<< vec.size() << std::endl;
        // 成倍扩容
        std::cout << "Capacity after adding elements: " << vec.capacity() << std::endl;
    }
    {
        // 收缩容量
        // shrink_to_fit()
        std::vector<int> vec;

        // 预留空间
        vec.reserve(100);
        std::cout << "Capacity before adding: " << vec.capacity() << std::endl;

        // 添加少量元素
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        std::cout << "Size after adding elements: " << vec.size() << std::endl;
        std::cout << "Capacity after adding elements: " << vec.capacity() << std::endl;

        // 收缩容量
        vec.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit: " << vec.capacity() << std::endl;
    }
    {

    }
    return 0;
}
void addStudent(std::vector<Student> &students) {
    Student s;
    std::cout << "Enter Student ID: ";
    std::cin >> s.id;
    std::cout << "Enter Student Name: ";
    std::cin.ignore(); // 忽略之前输入的换行符
    std::getline(std::cin, s.name);
    std::cout << "Enter Student Grade: ";
    std::cin >> s.grade;
    students.push_back(s);
    std::cout << "Student added successfully.\n";
}

void deleteStudent(std::vector<Student> &students) {
    int id;
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    auto it = std::find_if(students.begin(), students.end(),[id](const Student &s){return s.id == id;});
    if (it != students.end()) {
        students.erase(it);
        std::cout << "Student deleted successfully.\n";
    }
    else {
        std::cout << "Student not found.\n";
    }
}
void displayStudents(std::vector<Student> &students) {
    for (auto it = students.begin(); it != students.end();) {
        std::cout << "ID: " << it->id << " Name: " << it->name << " Grade: " << it->grade << std::endl;
    }
}
void findStudent(std::vector<Student> &students) {
    int id;
    std::cout << "Enter Student ID: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(),[id](const Student &s){return s.id == id;});
    if (it != students.end()) {
        std::cout << "Student found.\n";
    }
    else {
        std::cout << "Student not found.\n";
    }
}