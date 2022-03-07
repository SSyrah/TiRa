#ifndef UNTITLED_EXTENDED_QUEUE_H
#define UNTITLED_EXTENDED_QUEUE_H
#include "Header.h"

class Extended_queue: public Queue {
public:
    void print(Extended_queue&) const;
    bool full() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};


#endif //UNTITLED_EXTENDED_QUEUE_H
