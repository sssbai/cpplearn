//
// Student Information Management System
// Created by 柏帅 on 2025/11/13.
//

#include "mims.h"

void Master::printInfo() const {
    std::cout << "id = " << id
        << ", name = " << name
        << ", grade = " << grade << std::endl;
}

void addMaster(std::vector<Master> & masters, int id, const std::string & name, float grade) {
    Master newMaster = {id, name, grade};
    masters.push_back(newMaster);
    std::cout << "add master successfully." << std::endl;
}

void displayMasters(const std::vector<Master> & masters) {
    if (masters.empty()) {
        std::cout << "masters are empty." << std::endl;
        return ;
    }
    std::cout << "the information of all masters:" << std::endl;
    for (const auto& master: masters) {
        master.printInfo();
    }
}

void findMasterById(const std::vector<Master> & masters, int id) {
    for (const auto& master: masters) {
        if (master.id == id) {
            std::cout << "find master successfully." << std::endl;
            master.printInfo();
            return ;
        }
    }
    std::cout << "cannot find master with id " << id << "." << std::endl;
}
