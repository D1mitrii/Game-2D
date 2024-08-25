//
// Created by Dmitriy on 12/11/2022.
//

#include "Saver.h"

Saver::Saver(const std::string & filename) {
    error_code = 0;
    file.open(filename, std::ios_base::out);
    if(!file.is_open())
        error_code = 1;
}

void Saver::save(Memento *snapshot) {
    file << snapshot->get_hashcode() << "\n";
    for (int i = 0; i < snapshot->get_stats().size(); ++i) {
        file << std::to_string(snapshot->get_stats().at(i)) << "\n";
    }
    FieldView view;
    file << view.save_view(snapshot->get_map(),snapshot->get_position(), snapshot->get_width(), snapshot->get_height());
}

int Saver::invalid() const {
    return error_code;
}

Saver::~Saver() {
    if(file.is_open())
        file.close();
}
