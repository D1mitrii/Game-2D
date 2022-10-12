#include "Mediator.h"

Mediator::Mediator(Game *pGame, IOCommander *pCommander)  : game(pGame), commander(pCommander) {
    game->set_mediator(this);
    commander->set_mediator(this);
}

void Mediator::notify(MediatorObject* who, IMediator::MEVENTS event) {
    if(auto temp = dynamic_cast<Game*>(who)){
        game_handler(event);
    }
    if(auto temp = dynamic_cast<IOCommander*>(who)){
        commander_handler(event);
    }
}

void Mediator::game_handler(IMediator::MEVENTS cmd) {
    switch (cmd) {
        case IMediator::GAME_STATUS:{
            if(game->get_status() == Game::START){
                commander->map_standard();
                return;
            }
            if(game->get_status() == Game::INPROGRESS)
                return;
            if(game->get_status() == Game::DEFEAT){
                commander->Defeat();
            }
            else if(game->get_status() == Game::WIN){
                commander->Victory();
            }
            game->set_status(Game::END);
            break;
        }
        case IMediator::STEP:{
            commander->input_step();
            break;
        }
        default:
            break;
    }
}

void Mediator::commander_handler(IMediator::MEVENTS cmd) {
    switch (cmd) {
        case IMediator::CONFIRM:{
            game->initialize_field(commander->read_size());
            break;
        }
        case IMediator::CANCEL:{
            game->initialize_field();
            break;
        }
        case IMediator::STEP:{
            game->set_step(commander->get_step());
            break;
        }
        default:
            break;
    }
}

Mediator::~Mediator() {
    delete game;
    delete commander;
}
