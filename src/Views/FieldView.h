//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H


#include "src/Background/Field.h"
#include "src/Views/CellView.h"
#include "src/Utils/Obs/IObserver.h"
#include <iostream>

class FieldView : public IObserver{
private:
    void write_horizontal_border() const;
    void write_field() const;
    Field* field;
public:
    FieldView() = default;
    explicit FieldView(Field* map);
    std::string save_view(std::vector<std::vector<Cell>> map_field, std::pair<int,int> player, int width, int height);
    ~FieldView() = default;
    void update() override;
};


#endif //OOP_FIELDVIEW_H
