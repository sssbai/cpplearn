//
// Created by 柏帅 on 2025/11/29.
//

#ifndef INC_21_INTERVIEW_JOININGTHREAD_H
#define INC_21_INTERVIEW_JOININGTHREAD_H

#include <thread>
class JoiningThread {
public:
    JoiningThread(): _i(0) {};
    JoiningThread(int i): _i(i) {}
    int GetIndex() const {return _i;}
private:
    std::thread _t;
    int _i;
};


#endif //INC_21_INTERVIEW_JOININGTHREAD_H