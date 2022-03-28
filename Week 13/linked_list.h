#pragma once
#include "Utility.h"

template <typename Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node<Node_entry> *next;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link = nullptr);
};

template <class List_entry>
class List {
public:
//  Specifications for the methods of the list ADT go here.
//  The following methods replace compiler-generated defaults.
    List();
   ~List();
   List(const List<List_entry> &copy);
   void operator =(const List<List_entry> &copy);

   Error_code insert(int position, const List_entry &x);
   Error_code replace(int position, const List_entry &x);
   Error_code retrieve(int position, List_entry &x);
   bool empty() const;
   bool full() const;
   int size() const;

protected:
//  Data members for the linked list implementation now follow.
   int count;
   Node<List_entry> *head;

//  The following auxiliary function is used to locate list positions
   Node<List_entry> *set_position(int position) const;
};

//--------------------------------------------------
// Constructors, destructors:
//--------------------------------------------------

template<typename Node_entry>
Node<Node_entry>::Node()
{
    next = NULL;
}

template<typename Node_entry>
Node<Node_entry>::Node(Node_entry data, Node<Node_entry> *link = nullptr)
{
    entry = data;
    next = link;
}

template<typename List_entry>
List<List_entry>::List()
{
    count = 0;
    head = nullptr;
}

template<typename List_entry>
List<List_entry>::List(const List<List_entry> &copy)
{
    // ???
}

template<typename List_entry>
List<List_entry>::~List()
{
    delete List;
    entry = NULL;
}

//--------------------------------------------------
// Methods and functions:
//--------------------------------------------------


template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List; 0 <= position < count.
Post: Returns a pointer to the Node in position.
*/
{
   Node<List_entry> *q = head;
   for (int i = 0; i < position; i++) q = q->next;
   return q;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
      where n is the number of entries in the List, the function succeeds:
      Any entry formerly at position and all later entries have their position
      numbers increased by 1, and x is inserted at position of the List.
      Else: The function fails with a diagnostic error code.
*/
{
   if (position < 0 || position > count)
      return range_error;
   Node<List_entry> *new_node, *previous, *following;
   if (position > 0) {
      previous = set_position(position - 1);
      following = previous->next;
   }
   else following = head;
   new_node = new Node<List_entry>(x, following);
   if (new_node == NULL)
      return overflow;
   if (position == 0)
      head = new_node;
   else
      previous->next = new_node;
   count++;
   return success;
}

template<typename List_entry>
bool List<List_entry>::empty() const
{
    return (count == 0);
}

template<typename List_entry>
int List<List_entry>::size() const
{
    return count;
}

template<typename List_entry>
bool List<List_entry>::full() const
{
   Node<List_entry> *new_node = new Node<List_entry>();
   if (new_node == NULL)
   return true;
   else{
       delete new_node;
       return false;
   }
}

template<typename List_entry>
Error_code List<List_entry>::replace(int pos, const List_entry &x)
{
    if (pos < 0 || pos > count) return utility_range_error;
    Node<List_entry> *new_node = set_position(pos);
    new_node->entry = x;
    return success;
}

template<typename List_entry>
Error_code List<List_entry>::retrieve(int pos, List_entry &x)
{
    if (pos < 0 || pos > count) return utility_range_error;
    Node<List> *new_node = set_position(pos);
    x = new_node->entry;
    return success;
}



