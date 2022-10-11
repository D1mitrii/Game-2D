#ifndef OOP_EVENT_H
#define OOP_EVENT_H


class Event {
public:
    Event() = default;
    virtual ~Event() = default;
    virtual void execute() = 0;
};


#endif //OOP_EVENT_H
