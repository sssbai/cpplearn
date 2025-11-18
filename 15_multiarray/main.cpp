#include <iostream>

int main() {
    {
        // 多维数组
        // 大小为3的数组，每个元素是大小为4的数组
        int ia[3][4];
        // 这些数组的元素是含有30个整数的数组
        int arr[10][20][30] = {0};
        //三个元素，每个元素是大小为4的数组
        int ia2[3][4] ={
            //第一行的初始值
            {0,1,2,3},
            //第二行初始值
            {4,5,6,7},
            //第三行初始值
            {8,9,10,11}
        };
        // 更加简洁的形式
        int ia3[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
        //初始化每一行的首元素
        int ia4[3][4] = {{0},{4},{8}};
        //值初始化第一i行
        int ix[3][4] = {0,3,5,9};
    }
    {
        // 多维数组的下标
        int ia[3][4] = {{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}};
        int arr[1][1][1] = {{{1}}};
        // 用arr的首元素为ia的最后一个元素赋值
        ia[2][3] = arr[0][0][0];
        //row是一个4维数组的引用,将row绑定到ia的第二个元素(4维数组)上
        int (&row)[4] = ia[1];
    }
    {
        // 使用 for 循环构建数组
        constexpr size_t rowCnt = 3, colCnt=4;
        //12 个未初始化的元素
        int ia[rowCnt][colCnt];
        //对于每一行
        for(size_t i = 0; i != rowCnt; ++i){
            //对于行内的每一列
            for( size_t j = 0; j != colCnt; ++j){
                ia[i][j] = i*colCnt + j;
            }
        }
    }
    {
        // C++ 风格处理多维数组
        constexpr size_t rowCnt = 3, colCnt=4;
        //12 个未初始化的元素
        int ia[rowCnt][colCnt];
        size_t cnt = 0;
        for(auto &row: ia){
            for(auto & col : row){
                col = cnt;
                ++cnt;
            }
        }
        for(const auto & row: ia){
            for(auto col : row){
                std::cout << col << "\t";
            }
            std::cout << std::endl;
        }
    }
    {
        // 指针和多维数组
        //大小为3的数组，每个元素是含有4个整数的数组
        int ia[3][4];
        //p指向含有4个整数的数组
        int(*p)[4] = ia;
        //将p修改为指向ia数组的尾部
        p = &ia[2];
    }
    {
        // C++11 中使用 auto 或者 decltype 可以避免在数组前面加上指针类型
        // ia数组
        int ia[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};

        //输出ia中每个元素的值,每个内存数组各占一行
        //p指向含有4个整数的数组
        for(auto p = ia; p != ia + 3; ++p){
            //q指向4个整数的数组的首元素
            for(auto q = *p; q != *p + 4; ++q){
                std::cout << *q << ' ';
            }
            std::cout << std::endl;
        }
    }
    {
        // C++11 中提供的 std::begin 也可以实现以上功能
        // ia数组
        int ia[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};

        // p指向ia的第一个数组
        for(auto p = std::begin(ia); p != std::end(ia); ++p){
            // q指向内存数组的首元素
            for( auto q = std::begin(*p); q != std::end(*p); ++q){
                // 输出q所指的整数值
                std::cout << *q << ' ';
            }
            std::cout << std::endl;
        }
    }
    {
        // C++11 中可以使用 using 类型别名来简化多维数组指针
        // C++98 中可以使用 typedef 类型别名来简化多维数组指针
        // ia数组
        int ia[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};
        // 新标准下类型别名的声明
        using int_array = int[4];
        // 使用typedef 声明类型的别名
        typedef int  int_array_t[4];

        for(int_array * p = ia; p != ia + 3; ++p){
            for(int *q = *p ; q != *p+4; ++q){
                std::cout << *q << " ";
            }
            std::cout << std::endl;
        }
    }
    {
        const int ROW = 2;
        const int COL = 3;
        int matrix1[ROW][COL];
        int matrix2[ROW][COL];
        int sum_matrix[ROW][COL];

        // 输入第一个矩阵
        std::cout << "请输入第一个2x3矩阵的元素（共6个整数）:" << std::endl;
        for(int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                matrix1[i][j] = i*COL + j;
            }
        }

        // 输入第二个矩阵
        std::cout << "请输入第二个2x3矩阵的元素（共6个整数）:" << std::endl;
        for(int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                matrix2[i][j] = i*COL + j;
            }
        }

        // 计算两个矩阵的和
        std::cout << "请输入第二个2x3矩阵的元素（共6个整数）:" << std::endl;
        for(int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        // 输出结果矩阵
        std::cout << "两个矩阵的和为:" << std::endl;
        for(int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                std::cout << sum_matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    {
        const int SIZE = 3;
        int matrix[SIZE][SIZE];
        int transpose[SIZE][SIZE];

        // 输入原始矩阵
        std::cout << "请输入一个3x3矩阵的元素（共9个整数）:" << std::endl;
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                std::cin >> matrix[i][j];
            }
        }

        // 计算转置矩阵
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                transpose[j][i] = matrix[i][j];
            }
        }

        // 输出转置后的矩阵
        std::cout << "矩阵的转置为:" << std::endl;
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                std::cout << transpose[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}