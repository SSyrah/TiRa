#include "l_extended_queue.h"

int Extended_queue::size() const
/*
Post: Return the number of entries in the Extended_queue.
*/
{
   Node *window = front;
   int count = 0;
   while (window != NULL) {
      window = window->next;
      count++;
   }
   return count;
}

bool Extended_queue::full() const {
    int temp = size();
    if (temp < max_length)
        return false;
        return true;
}

void Extended_queue::clear(){
    
    while (front != NULL){
        serve();
    }
    // count = 0;
    std::cout << "Queue is cleared!\n";
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item){
    if (front == NULL) return underflow;
    else {
        serve();
        item = front->entry;
    }
    return success;
}