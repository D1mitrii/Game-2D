//
// Created by Dmitriy on 12/11/2022.
//

#include "Loader.h"

Loader::Loader(const std::string &filename) {
    error_code = 0;
    file.open(filename, std::ios_base::in);
    if(!file.is_open())
        error_code = 1;
}

int Loader::invalid() const {
    return error_code;
}

Memento *Loader::load() {
    std::string hash;
    std::getline(file, hash);
    std::vector<int> stats;
    int counter = 0;
    std::string str;
    while (counter!= 4 || std::getline(file,str)){
        try {
            int num = std::stoi(str);
            stats.push_back(num);
        }
        catch (std::invalid_argument& e){

        }
        ++counter;
    }
    std::vector<std::string> char_map;
    std::pair<int, int> size = std::make_pair(0, 0);
    while (std::getline(file,str)){

        size.first += 1;
    }
    return nullptr;
}

Loader::~Loader() {
    if(file.is_open())
        file.close();
}