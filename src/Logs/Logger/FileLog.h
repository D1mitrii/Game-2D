//
// Created by Dmitriy on 10/25/2022.
//

#ifndef OOP_FILELOG_H
#define OOP_FILELOG_H

#include "ILogger.h"
#include <fstream>
#include "src/Logs/Messages/Message.h"

class FileLog final : public ILogger{
private:
    std::ofstream file;
public:
    explicit FileLog(const std::string& name = "log.txt");
    void print(const Message& msg) override;
    ~FileLog() final;
};


#endif //OOP_FILELOG_H
