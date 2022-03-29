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


template <class List_entry>
class List {
public:
//  Add specifications for the methods of the list ADT.
//  Add methods to replace the compiler-generated defaults.
Error_code remove(int position, List_entry &x);

protected:
//  Data members for the linked-list implementation with
//  current position follow:
   int count;
   mutable int current_position;
   Node<List_entry> *head;
   mutable Node<List_entry> *current;

//  Auxiliary function to locate list positions follows:
   void set_position(int position) const;
};




template <class List_entry>
void List<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List: 0 <= position < count.
Post: The current Node pointer references the Node at position.
*/
{
   if (position < current_position) {  //  must start over at head of list
      current_position = 0;
      current = head;
   }
   for ( ; current_position != position; current_position++)
      current = current->next;
}


template<typename List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (pos < 0 || pos > count) return utility_range_error;
    if (count == 0) return underflow;
    set_position(position);
    x = current->entry;
    for (int i = position; i <count; i++){
        current = current->next;
    }
    count--;
    return success;
}

