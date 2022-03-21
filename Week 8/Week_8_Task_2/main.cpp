#include "Header.h"

int main() {

    int temp=5;
    /*
    Queue test;
    for (int i=0; i<maxqueue;i++) {
        test.append(temp + rand() % 254+3);
        temp++;
    }
    std::cout << "Is queue empty: " << std::boolalpha << test.empty() << "\n";
    /////////////////////////////////////

    test.retrieve(temp);
    std::cout << "First number in queue was: " << temp << "\n";
    //////////////////////////////////////
    */
    Extended_queue ex_queue;
    ex_queue.append(12);
    ex_queue.append(14);
    ex_queue.append(13);
    ex_queue.append(15);

    std::cout << "Queue is empty: " << std::boolalpha << ex_queue.empty() << "\n";
    std::cout << "Clearing queue...\n";
    ex_queue.clear();
    std::cout << "Queue is empty: " << std::boolalpha << ex_queue.empty() << "\n";

    ex_queue.append(12);
    ex_queue.append(14);
    ex_queue.append(13);
    ex_queue.append(15);
    ex_queue.serve_and_retrieve(temp);
    std::cout << "First item in queue is: " << temp << ". The next item in line is: ";
    ex_queue.retrieve(temp);
    std::cout << temp << "\n";
    
    


    return 0;
}
