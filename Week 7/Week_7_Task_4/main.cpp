#include "Header.h"

int main() {

    int maxcount = 10;
    Extended_queue queue;
    Stack stack, stack_b;

    // a) move stack to queue
    for (int i = 0; i < maxcount; i++){stack.push(i);}
    std::cout << "a) Stack: ";
    stack_to_queue(stack, queue);
    std::cout << " --> Queue: ";
    print_queue(queue);

    // b) move queue to stack
    for (int i = 0; i< maxcount; i++) {queue.append(i);}
    std::cout << "\nb) Stack: ";
    queue_to_stack(queue,stack);
    std::cout << " --> Queue: ";
    print_stack(stack);

    // c) Empty stack to another stack with same order
    for (int i = 0; i < maxcount; i++){stack.push(i);}
    std::cout << "\nc) Stack: ";
    stack_change(stack, stack_b);
    std::cout << " --> Stack_B: ";
    print_stack(stack_b);

    //d) Empty stack to another with reverse order
    for (int i = 0; i < maxcount; i++){stack.push(i);}
    std::cout << "\nd) Stack: ";
    stack_change_same_order(stack, stack_b);
    std::cout << " --> Stack_B: ";
    print_stack(stack_b);

    //e) Use a local Stack to reverse the order of all the entries in a Queue.
    std::cout << "\ne) Stack: ";
    for (int i = 0; i < maxcount; i++){
        std::cout << i << " ";
        stack.push(i);}
    stack_change_with_local_stack(stack);
    std::cout << " --> Stack again: ";
    print_stack(stack);

    //f) Use a local Queue to reverse the order of all the entries in a Stack.
    std::cout << "\ne) Stack: ";
    for (int i = 0; i < maxcount; i++){
        stack.push(i);
    }
    stack_change_with_queue(stack);
    std::cout << " --> Stack again: ";
    print_stack(stack);

    return 0;
}
