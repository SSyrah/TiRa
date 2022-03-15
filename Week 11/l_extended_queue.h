#ifndef L_EXTENDED_QUEUE_H
#define L_EXTENDED_QUEUE_H
#pragma once
#include "header.h"
#include "linked_queue.h"

class Extended_queue: public Queue {
public:
   bool full() const;
   int size() const;
   void clear();
   Error_code serve_and_retrieve(Queue_entry &item);
private:
    int max_length = 100;
};


#endif