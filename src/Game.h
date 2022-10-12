#ifndef OOP_GAME_H
#define OOP_GAME_H

class MediatorObject;

#include "src/Entities/Player.h"
#include "src/Views/FieldView.h"
#include "src/Entities/Player.h"
#include "src/Views/PlayerView.h"
#include "src/Utils/Med/MediatorObject.h"
#include "src/Utils/Med/IMediator.h"

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
    void initialize_field();
    void initialize_field(std::pair<int, int> size);
    void start();
    STATUS get_status() const;
    void set_status(STATUS stat);
    void set_step(Player::Directions cur);
    ~Game() override;
private:
    Field* field;
    Player* player;
    FieldView* field_view;
    PlayerView* player_view;
    Player::Directions cur_step;
    void loop();
    void reaction();
    void event_handler(Event* ptr_event);
    void is_end();
    STATUS status;
};


#endif //OOP_GAME_H
