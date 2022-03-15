#include "header.h"
#include "linked_queue.h"
#include "l_extended_queue.h"

int main (){

    Extended_queue ex_queue;
    Queue test;
    int temp;
    
    // testing for queue class
    test.append(12);
    test.retrieve(temp);
    std::cout << "temp is: "<< temp << "\n";
    //testing for extended_queue class
    temp = ex_queue.size();
    std::cout << "ex_queue size now: " << temp << "\n";  
    ex_queue.append(12);
    std::cout << "is ex_queue full: " << std::boolalpha << ex_queue.full() << "\n";
    ex_queue.append(18);
    ex_queue.append(19);
    ex_queue.append(20);
    ex_queue.append(21);
    ex_queue.append(22);
    ex_queue.append(23);
    temp = ex_queue.size();
    std::cout << "ex_queue size now: " << temp << "\n";
    ex_queue.retrieve(temp);
    std::cout << "Top node is: " << temp << "\n";
    std::cout << "Next, testing serve and retrieve.\n";
    ex_queue.serve_and_retrieve(temp);
    std::cout << "Top node is: " << temp << "\n";
    ex_queue.retrieve(temp);
    std::cout << "Removed one, now top node is: " << temp << "\n";
    std::cout << "Next, testing clear.\n";
    temp = ex_queue.size();
    std::cout << "ex_queue size now: " << temp << "\n";
    ex_queue.clear();
    temp = ex_queue.size();
    std::cout << "ex_queue size now: " << temp << "\n";  
   
    return 0;
}