#include "Header.h"

int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
    return count;
}

bool Extended_queue::full() const {
    if (count == maxqueue)
        return true;
    else
    return false;
}

void Extended_queue::clear() {
    count = 0;
    front = 0;
    rear = maxqueue-1;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
    if (count <= 0) return underflow;
    count--;
    item = entry[front];
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
    return success;
}

void Extended_queue::print(Extended_queue& queue) const {
    char item;
    cout << "Whole queue so far: \n";
    if (queue.empty()) cout << "Queue is empty.\n";
    else{
        for (int i = 0; i<count; i++){
            cout << entry[i] << " ";
        }
    }
    cout << "\n";
}
