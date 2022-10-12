//
// Created by Dmitriy on 10/9/2022.
//

#include <cstdio>
#include "ISubject.h"

void ISubject::attach(IObserver *observer) {
    observers.push_back(observer);
};

void ISubject::detach(IObserver *obs) {
    std::remove(observers.begin(), observers.end(), obs);
}

void ISubject::notify() {
    std::printf("[%p]", this);
    for(auto obs : observers){
        std::printf("|%p|", obs);
        obs->update();
    }
}