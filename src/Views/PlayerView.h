//
// Created by Dmitriy on 10/9/2022.
//

#ifndef OOP_PLAYERVIEW_H
#define OOP_PLAYERVIEW_H

#include "src/Utils/Obs/IObserver.h"
#include "src/Entities/Player.h"
#include <iostream>

class PlayerView : public IObserver {
private:
    void write_player_stats();
    Player* player;
public:
    PlayerView() = default;
    explicit PlayerView(Player* pl);
    void update() override;
    ~PlayerView() = default;
};


#endif //OOP_PLAYERVIEW_H
