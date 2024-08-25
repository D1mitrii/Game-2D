#ifndef OOP_GAME_H
#define OOP_GAME_H

class MediatorObject;
class Field;
class WinEvent;

#include "src/Views/FieldView.h"
#include "src/Entities/Player.h"
#include "src/Entities/Player.h"
#include "src/Views/PlayerView.h"
#include "src/Utils/Med/MediatorObject.h"
#include "src/Utils/Med/IMediator.h"
#include "src/Events/GameEvents/WinEvent.h"
#include "src/Generator/FieldGen.h"
#include "src/Generator/Rules/R_Column_Walls.h"
#include "src/Generator/Rules/R_Row_Walls.h"
#include "src/Generator/Rules/R_Rand_Walls.h"
#include "src/Generator/Rules/R_Player_Spawn.h"
#include "src/Generator/Rules/R_Rand_Events.h"
#include "src/Generator/Rules/R_Field_Size.h"
#include "src/Generator/Rules/R_Win_Cell.h"
#include "src/Events/EventGenerator/FieldEventGen.h"
#include "src/Events/EventGenerator/PlayerEventGen.h"
#include "src/Utils/Memento/Saver.h"

class Game : public MediatorObject{
public:
    enum STATUS{
        START,
        INPROGRESS,
        WIN,
        DEFEAT,
        END
    };
    Game();
    void initialize_field(int level_num);
    void start();
    STATUS get_status() const;
    void set_status(STATUS stat);
    void set_step(Player::Moves cur);
    void save_game() const;
    void load_game() const;
    ~Game() override;
private:
    Field* field;
    Player* player;
    FieldView* field_view;
    PlayerView* player_view;

    Player::Moves cur_step;
    std::map<int, std::function<Field* (Player*)>> levels_gens;
    void loop();
    void reaction();
    void is_end();
    STATUS status;
};


#endif //OOP_GAME_H
