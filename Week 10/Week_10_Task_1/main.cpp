#include "Linked_stack.h"

int main(){

    Linked_stack stack;
    stack.push(13);
    stack.print();
    stack.push(12);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();


    return EXIT_SUCCESS;
}
