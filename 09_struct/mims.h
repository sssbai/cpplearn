//
// Master Information Management System
// Created by 柏帅 on 2025/11/13.
//

#ifndef INC_09_STRUCT_MD_MIMS_H
#define INC_09_STRUCT_MD_MIMS_H
#include <iostream>
#include <vector>
struct Master {
    int id;
    std::string name;
    float grade;

    // 成员函数打印学生信息
    void printInfo() const ;
};
extern void addMaster(std::vector<Master>& masters, int id, const std::string& name, float grade);
extern void displayMasters(const std::vector<Master>& masters);

extern void findMasterById(const std::vector<Master>& masters, int id);
#endif //INC_09_STRUCT_MD_MIMS_H