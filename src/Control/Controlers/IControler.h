//
// Created by Dmitriy on 11/1/2022.
//

#ifndef OOP_ICONTROLER_H
#define OOP_ICONTROLER_H


class IControler {
public:
    virtual char get_command() = 0;
    virtual ~IControler() = default;
};


#endif //OOP_ICONTROLER_H
