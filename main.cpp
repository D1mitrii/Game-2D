#include "src/Game.h"
#include "src/Utils/IOCommander.h"
#include "src/Utils/Med/Mediator.h"
#include "src/Logs/LogPool/LogPool.h"
#include "src/Logs/Messages/Message.h"
#include "src/Logs/Logger/FileLog.h"

int main(){

    Game game;
    IOCommander commander;
    Mediator mediator(&game, &commander);
    game.start();
}