#ifndef OOP_CELLCOIN_H
#define OOP_CELLCOIN_H


#include "src/Events/PlayerEvents/CoinEvent.h"
#include "ICell.h"

class CellCoin : public ICell {
private:
    Event* event;
public:
    CellCoin();
    Event* get_event() override;
    ~CellCoin() override;
};


#endif //OOP_CELLCOIN_H
