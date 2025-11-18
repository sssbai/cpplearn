//
// Created by 柏帅 on 2025/11/18.
//

#ifndef INC_18_FUNCTION_EVENT_SYSTEM_H
#define INC_18_FUNCTION_EVENT_SYSTEM_H
#include <iostream>
#include <vector>
#include <functional>

// 定义带参数的回调函数类型
using Callback = std::function<void(int)>;
// typedef std::function<void(int)> Callback;

// 事件系统类
class EventSystem {
private:
    std::vector<Callback> callbacks;
public:
    // 注册回调函数
    void register_callback(const Callback &callback);

    // 触发事件，传递参数给回调函数
    void triggerEvent(int data);

};

void onEvent(int data);
#endif //INC_18_FUNCTION_EVENT_SYSTEM_H