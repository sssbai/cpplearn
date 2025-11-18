#include "event_system.h"
//
// Created by 柏帅 on 2025/11/18.
//
// 注册回调函数
void EventSystem::register_callback(const Callback &callback) {
    this->callbacks.push_back(callback);
}
// 触发事件，传递参数给回调函数
void EventSystem::triggerEvent(int data) {
    std::cout << "Event triggered with data = " << data << ". Executing callbacks..." << std::endl;
    for (auto & callback: callbacks) {
        callback(data);
    }
}
void onEvent(int data) {
    std::cout << "Function callback received data: " << data << std::endl;
}


