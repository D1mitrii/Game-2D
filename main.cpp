#include "src/Game.h"
#include "src/Utils/IOCommander.h"
#include "src/Utils/Med/Mediator.h"
int main(){
    Game game;
    IOCommander commander;
    Mediator mediator(&game, &commander);
    game.start();
}