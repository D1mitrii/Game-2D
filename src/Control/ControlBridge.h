#ifndef OOP_CONTROLBRIDGE_H
#define OOP_CONTROLBRIDGE_H

class Player;
class MediatorObject;
class IMediator;
#include "src/Entities/Player.h"
#include "src/Control/Controlers/IControler.h"
#include "src/Utils/Med/MediatorObject.h"

class ControlBridge : public MediatorObject {
private:
    std::map<char, Player::Moves> command_interpretator;
    IControler* controler;
    Player::Moves step;
public:
    ControlBridge(std::map<char, Player::Moves> maps, IControler* contrl);
    void next_step();
    Player::Moves get_step();
    ~ControlBridge();
};


#endif //OOP_CONTROLBRIDGE_H
