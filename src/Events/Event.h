#ifndef OOP_EVENT_H
#define OOP_EVENT_H


class Event {
public:
    Event() = default;
    virtual ~Event() = 0;
    virtual void Execute() = 0;
};


#endif //OOP_EVENT_H
