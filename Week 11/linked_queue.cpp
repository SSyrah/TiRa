#include "linked_queue.h"

Node::Node()
{
   next = NULL;
}


Node::Node(Node_entry item, Node *add_on)
{
   entry = item;
   next = add_on;
}

Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
   front = rear = NULL;
}

Error_code Queue::append(const Queue_entry &item)
/*
Post: Add item to the rear of the Queue and return a code of success
      or return a code of overflow if dynamic memory is exhausted.
*/
{
   Node *new_rear = new Node(item);
   if (new_rear == NULL) return overflow;
   if (rear == NULL) front = rear = new_rear;
   else {
      rear->next = new_rear;
      rear = new_rear;
   }
   return success;
}

Error_code Queue::serve()
/*
Post: The front of the Queue is removed.  If the Queue
      is empty, return an Error_code of underflow.
*/
{
   if (front == NULL) return underflow;
   Node *old_front = front;
   front = old_front->next;
   if (front == NULL) rear = NULL;
   delete old_front;
   return success;
}

bool Queue::empty() const 
{
   if (rear == NULL && front == NULL)
   return true;
   return false;
}

Error_code Queue::retrieve(Queue_entry &item) const {

   if (front == NULL) return underflow;
   else {
      item = front->entry;
   }
   return success;
}

Queue::~Queue(){
   Node* current = front;
   Node* next;
   while (current != NULL){
      next = current->next;
      delete current;
      current = next;
   }
}

Queue::Queue(const Queue& original){
   Node* new_copy, *original_copy = original.front;
   if (original_copy == NULL) front = NULL;
   else{
      front = new_copy = new Node(original_copy->entry);
      while (original_copy->next != NULL){
         original_copy = original_copy->next;
         new_copy->next = new Node(original_copy->entry);
         new_copy = new_copy->next;
      }
   }
}

void Queue::operator =(const Queue &original){
   Node* new_front, *new_copy, *original_copy = original.front;
   if (original_copy == NULL) new_front == NULL;
   else {
      new_copy = new_front = new Node(original_copy->entry);
      while (original_copy->next != NULL){
         original_copy = original_copy->next;
         new_copy->next = new Node(original_copy->entry);
         new_copy = new_copy->next;
      }
   }
   while (!empty()){
      serve();
   }
   front = new_front;
}