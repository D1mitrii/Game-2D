//
// Created by Dmitriy on 10/12/2022.
//

#include "MediatorObject.h"

MediatorObject::MediatorObject(IMediator *med) : mediator(med) {
}

void MediatorObject::set_mediator(IMediator *med) {
    this->mediator = med;
}
