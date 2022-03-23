#pragma once
#include "Utility.h"

template <class Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node<Node_entry> *next;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link = NULL);
};


template<class Node_entry>
Node<Node_entry>::Node()
{
    entry = NULL;
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry>* link)
{
    entry = item;
    next = link;
}