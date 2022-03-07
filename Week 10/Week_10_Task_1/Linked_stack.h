#ifndef LINKED_STACK_LINKED_STACK_H
#define LINKED_STACK_LINKED_STACK_H
#include <iostream>
#include "Utility.h"
typedef int Node_entry, Stack_entry;

struct Node {
//  data members
    Node_entry entry;
    Node *next;
//  constructors
    Node();
    Node(Node_entry item, Node *add_on = NULL);
};

class Linked_stack {
public:
    int Stack();
    bool empty() const;
    Error_code push(const Stack_entry &item);
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    void print() const;
protected:
    Node *top_node;
    int count;
};


#endif //LINKED_STACK_LINKED_STACK_H
