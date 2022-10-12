#include "HealEvent.h"

void HealEvent::execute(Player &player) {
    if(player.get_hearts() < player.get_max_stat()){
        player.set_hearts(player.get_max_stat());
    }
    if(player.get_power() < player.get_max_stat()){
        player.set_power(player.get_max_stat());
    }
}
