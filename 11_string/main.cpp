#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <map>
bool isValidEmail(const std::string& email) {
    // 简单的正则表达式，匹配基本的邮件格式
    const std::regex pattern(R"((\w+)(\.?\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern);
}

int main() {
    {
        // C 风格字符串 VS std::string
        // C 风格字符串示例
        char cstr[] = "Hello, World!";
        // std::string 示例
        std::string str = "Hello, World!";
    }
    {
        // std::string基础

        // 默认构造函数
        std::string str1;

        // 使用字符串字面值初始化
        std::string str2 = "Hello, World!";

        // 使用拷贝构造函数
        std::string str3(str2);

        // 使用部分初始化
        std::string str4(str2, 0, 3); // Hel

        // 使用重复字符初始化
        std::string str5(5, 'a');

        std::cout << "str1 = " << str1 << std::endl;
        std::cout << "str2 = " << str2 << std::endl;
        std::cout << "str3 = " << str3 << std::endl;
        std::cout << "str4 = " << str4 << std::endl;
        std::cout << "str5 = " << str5 << std::endl;
    }
    {
        std::string greeting = "Hello, C++ Strings!";
        std::cout << greeting << std::endl;
    }
    // {
    //     // 从用户输入字符串
    //     std::string input;
    //     std::cout << "please enter a string: ";
    //     std::cin >> input;
    //     std::cout << "the string is " << input << std::endl;
    // }
    // {
    //     // 读取包含空格的整行字符串
    //     std::string line;
    //     std::cout << "please enter a string:"<< std::endl;
    //     std::getline(std::cin, line);
    //     std::cout << "the string is " << line << std::endl;
    // }
    {
        // 使用 + 运算符
        std::string first = "Hello,";
        std::string second = "World!";
        std::string combined = first + second;
        std::cout << combined << std::endl;
    }
    {
        // 使用 append() 函数
        std::string str = "Hello";
        str.append(", World!");
        std::cout << str << std::endl;
    }
    {
        // 使用 += 运算符
        std::string str = "Data";
        str += " Structures";
        std::cout << str << std::endl;
    }
    {
        std::string a = "apple";
        std::string b = "banana";

        if (a == b) {
            std::cout << "a 和 b 相等" << std::endl;
        } else {
            std::cout << "a 和 b 不相等" << std::endl;
        }

        if (a < b) {
            std::cout << "a 在字典序中小于 b" << std::endl;
        } else {
            std::cout << "a 在字典序中不小于 b" << std::endl;
        }
    }
    {
        std::string text = "The quick brown fox jumps over the lazy dog.";
        std::string word = "fox";
        size_t pos = text.find(word);
        if (pos != std::string::npos) {
            std::cout << "找到 '" << word << "' 在位置: " << pos << std::endl;
        } else {
            std::cout << "'" << word << "' 未找到。" << std::endl;
        }
    }
    {
        std::string text = "I like cats.";
        std::string from = "cats";
        std::string to = "dogs";

        size_t pos = text.find(from);
        if (pos != std::string::npos) {
            text.replace(pos, from.length(), to);
            std::cout << "替换后: " << text << std::endl; // 输出: I like dogs.
        } else {
            std::cout << "'" << from << "' 未找到。" << std::endl;
        }
    }
    {
        std::string str = "Hello, World!";
        std::string sub = str.substr(7, 5); // 从位置7开始，长度5
        std::cout << sub << std::endl; // 输出: World
    }
    {
        std::string str = "C++ Programming";
        std::cout << "字符串长度: " << str.length() << std::endl; // 输出: 14
        // 或者使用 size()
        std::cout << "字符串大小: " << str.size() << std::endl; // 输出: 14
    }
    {
        std::string str = "Hello";
        std::cout << "初始容量: " << str.capacity() << std::endl;

        str += ", World!";
        std::cout << "追加后的容量: " << str.capacity() << std::endl;
    }
    {
        std::string str = "ABCDE";

        // 正向索引
        for (size_t i = 0; i < str.length(); ++i) {
            std::cout << "字符 " << i << ": " << str[i] << std::endl;
        }

        //反向遍历
        for(int i = str.length() - 1; i >= 0 ; i --){
            std::cout << "下标为 " << i << "的字符为" << str[i] << std::endl;
        }
    }
    {
        std::string str = "ABCDE";
        try {
            char c = str.at(10); // 超出范围，会抛出异常
        } catch (const std::out_of_range& e) {
            std::cout << "异常捕获: " << e.what() << std::endl;
        }
    }
    {
        std::string str = "Hello, World!";
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::toupper(c); });
        std::cout << str << std::endl; // 输出: HELLO, WORLD!
    }
    {
        std::string str = "Hello, World!";
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        std::cout << str << std::endl; // 输出: hello, world!
    }
    {
        std::string str;
        if (str.empty()) {
            std::cout << "字符串为空。" << std::endl;
        }
    }
    {
        std::string str = "Clear me!";
        str.clear();
        std::cout << "str: " << str << std::endl; // 输出为空
    }
    {
        std::string str = "Hello, World!";
        str.erase(5, 7); // 从位置5开始，删除7个字符
        std::cout << str << std::endl; // 输出: Hello!
    }
    {
        std::string str = "Hello World";
        str.insert(5, ",");
        std::cout << str << std::endl; // 输出: Hello, World
    }
    {
        std::string str = "apple, banana, cherry";
        size_t pos = str.find_first_of(", ");
        std::cout << "第一个逗号或空格的位置: " << pos << std::endl; // 输出: 5
    }
    {
        // 字符串流 stringstream
        // std::stringstream 是 C++ 标准库中的 <sstream> 头文件提供的一个类，用于在内存中进行字符串的读写操作，类似于文件流
        std::stringstream ss;
        ss << "Value: "<< 42 << ", " << 3.14;
        std::string str = ss.str();
        std::cout << str << std::endl;
    }
    {
        // 从字符串流中读取数据
        std::string data = "123 45.67 Hello";
        std::stringstream ss(data);
        std::cout << ss.str() << std::endl;
        int a;
        double b;
        std::string c;

        ss >> a >> b >> c;
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    }
    {
        // to_string()
        int num = 100;
        double pi = 3.14;

        std::string str1 = std::to_string(num);
        std::string str2 = std::to_string(pi);

        std::cout << "str1: " << str1 << ", pi: " << pi << std::endl;

    }
    {
        // 使用字符流，将 string 转换为其他类型
        std::string numStr = "234";
        std::string piStr = "2.31";

        int num;
        double pi;

        std::stringstream ss1(numStr);
        std::stringstream ss2(numStr);

        ss1 >> num;
        ss2 >> pi;

        std::cout << "num: " << num << ", pi: " << pi << std::endl;
    }
    {
        // 使用 std::stoi(), std::stod() 等函数（C++11及以上）
        std::string numStr = "234";
        std::string piStr = "2.31";

        int num = std::stoi(numStr);
        double pi = std::stod(piStr);

        std::cout << "num: " << num << ", pi: " << pi << std::endl;
    }
    {
        // 正则表达式与字符串匹配
        std::string text = "The quick brown fox jumps over the lazy dog.";
        std::regex pattern(R"(\b\w{5}\b)"); // 匹配所有5个字母的单词
        std::sregex_iterator it(text.begin(), text.end(), pattern);
        std::sregex_iterator end;

        std::cout << "5个字母的单词有:" << std::endl;
        while (it != end) {
            std::cout << (*it).str() << std::endl;
            ++it;
        }
    }
    {
        // 从 C 风格字符串转换为 std::string
        const char* cstr = "Hello, C-strings!";
        std::string str(cstr);
        std::cout << str << std::endl; // 输出: Hello, C-strings!
    }
    {
        // 从 std::string 转换为 C 风格字符串
        std::string str = "Hello, std::string!";
        const char* cstr = str.c_str();
        std::cout << cstr << std::endl;
    }
    {
        std::string text;
        std::cout << "Please enter a string (Exit by exit)" << std::endl;

        // 读取整段文本
        std::ostringstream oss;
        std::string line;
        while (true) {
            std::getline(std::cin, line);
            if (!std::cin || line == "exit") break;
            oss << line << " ";
        }
        text = oss.str();

        // 使用字符串流分割单词
        std::stringstream ss(text);
        std::string word;
        std::map<std::string, int> wordCount;
        size_t totalWords = 0;
        std::string longestWord;

        while (ss >> word) {
            // 去除标点符号（简单处理）
            word.erase(std::remove_if(word.begin(), word.end(),
                [](char c){ return ispunct(c);}), word.end());

            // 转为小写
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!word.empty()) {
                wordCount[word]++;
                totalWords++;
                if (word.length() > longestWord.length()) {
                    longestWord = word;
                }
            }
        }
        std::cout << "The result of the statistics" << std::endl;
        std::cout << "The number of words = " << totalWords << std::endl;
        std::cout << "The longest word length = " << longestWord.length() << std::endl;
        std::cout << "The number of per word:" << std::endl;
        for (const auto& pair: wordCount) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }

        // Find the number of occurrences of the specified word
        std::string searchWord;
        std::cout << "Please enter the word you need to search for:" << std::endl;
        std::cin >> searchWord;

        // Convert to lowercase
        std::transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);
        auto it = wordCount.find(searchWord);
        if (it != wordCount.end()) {
            std::cout << "'" << searchWord << "' appeared " << it->second << " times." << std::endl;
        }
        else {
            std::cout << "'" << searchWord << "' not found." << std::endl;
        }
    }
    {
        std::string email;
        std::cout << "Please enter the email you need to check ( user@example.com ):" << std::endl;
        std::cin >> email;
        if (isValidEmail(email)) {
            std::cout << "The valid email entered: " << email << std::endl;
        }
        else {
            std::cout << "The email entered is not valid." << std::endl;
        }
    }
    return 0;
}