#include "Header.h"

void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/

{
    std::cout << std::endl
         << "This program allows the user to enter one command" << std::endl
         << "(but only one) on each input line." << std::endl
         << "For example, if the command S is entered, then" << std::endl
         << "the program will serve the front of the queue." << std::endl
         << std::endl

         << " The valid commands are:" << std::endl
         << "A - Append the next input character to the extended queue" << std::endl
         << "S - Serve the front of the extended queue" << std::endl
         << "R - Retrieve and print the front entry." << std::endl
         << "# - The current size of the extended queue" << std::endl
         << "C - Clear the extended queue (same as delete)" << std::endl
         << "P - Print the extended queue" << std::endl
         << "H - This help screen" << std::endl
         << "Q - Quit" << std::endl

         << "Press <Enter> to continue.\n" << std::flush;

    char c;
    do {
        std::cin.get(c);
    } while (c != '\n');
}

bool do_command(char c, Extended_queue &test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
      Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
*/

{
    bool continue_input = true;
    Queue_entry x;

    switch (c) {
        case 'r':
            if (test_queue.retrieve(x) == underflow)
                std::cout << "Queue is empty." << std::endl;
            else
                std::cout << std::endl
                     << "The first entry is: " << x
                     << std::endl;
            break;

        case 'q':
            std::cout << "Extended queue demonstration finished." << std::endl;
            continue_input = false;
            break;

        case 'a':
            std::cout << "Give the character to add queue: ";
            std::cin >> x;
            test_queue.append(x);
            break;

        case '#':
            std::cout << "Present size of the queue is: " << test_queue.size() << "\n";
            break;

        case 'h':
            help();
            break;

        case 'c':
            test_queue.clear();
            std::cout << "Queue is now empty.\n";
            std::cout << "Size is now: " << test_queue.size() << "\n";
            //  Additional cases will cover other commands.

        case 'p':
            test_queue.print(test_queue);
            break;
    }
    return continue_input;
}

char get_command() {
    std::cout << "Give command: ";
    char command;
    bool waiting = true;
    std::cin >> command;
    command = tolower(command);
    while (waiting) {
        if (command == 'a' || command == 's' || command == 'r' || command == '#' ||
            command == 'c' || command == 'h' || command == 'q' || command == 'p')
            waiting = false;
        else{
            std::cout << "Invalid Command, please enter new command. \n"
                 << "/H (help & list commands), /Q (quit)\n";
        }
    }
    return command;
}

void introduction(){
    std::cout << "Welcome to use queue-program!\n\n";
}

Error_code stack_to_queue(Stack& stack, Extended_queue& queue) {
    char temp;
    if (stack.size() == 0) return underflow;
    else {
        while(!stack.empty()){
        stack.top(temp);
        std::cout << temp << " ";
        queue.append(temp);
        stack.pop();
        }
    }
    return success;
}



void print_queue(Extended_queue & queue)  {
    char temp;
    while (!queue.empty()) {
        queue.serve_and_retrieve(temp);
        std::cout << temp << " ";
    }
}

Error_code queue_to_stack(Extended_queue & queue, Stack & stack) {
    if (queue.empty()){
        std::cout << "Queue is empty. \n";
        return underflow;
    }
    else {
        char temp;
        while (!queue.empty()){
        queue.serve_and_retrieve(temp);
        stack.push(temp);
        std::cout << temp << " ";
    }}
    return success;
}

void print_stack(Stack & stack) {
    if (stack.empty()){
        std::cout << "Stack is empty.\n";
    }
    else {
        char temp;
        while (!stack.empty()){
            stack.top(temp);
            std::cout << temp << " ";
            stack.pop();
        }
    }
}

Error_code stack_change(Stack & original, Stack & source)  {
        Stack temp;
        char x;
        if (original.empty()) {
            std::cout << "Original stack is empty\n";
            return underflow;}
        else {
            while (!original.empty()) {
                original.top(x);
                std::cout << x << " ";
                original.pop();
                temp.push(x);
            }
            while(!temp.empty()){
                temp.top(x);
                temp.pop();
                source.push(x);
            }
        }return success;
}

Error_code stack_change_same_order(Stack & original, Stack & dest) {
    char x;
    if (original.empty()) {
        std::cout << "Original stack is empty\n";
        return underflow;}
    else {
        while (!original.empty()) {
            original.top(x);
            std::cout << x << " ";
            original.pop();
            dest.push(x);
        }
    }
    return success;
}

Error_code stack_change_with_local_stack(Stack & source) {
    Stack temp;
    char x;
    if(source.empty()){
        std::cout << "Stack is empty.\n";
        return underflow;
    }
    else{
        while (!source.empty()){
            source.top(x);
            source.pop();
            temp.push(x);
        }
        while(!temp.empty()){
            temp.top(x);
            temp.pop();
            source.push(x);
        }
    return success;
}
}
Error_code stack_change_with_queue(Stack & source) {
    Extended_queue queue;
    char temp;
    if (source.empty()){
        std::cout << "Stack is empty.\n";
        return underflow;
    }
    else {
        while(!source.empty()){
            source.top(temp);
            source.pop();
            std::cout << temp << " ";
            queue.append(temp);
        }
        while (!queue.empty()){
            queue.serve_and_retrieve(temp);
            source.push(temp);
        }
    }
    return success;
}

void comparison_instructions(){
    std::cout << "Enter input, use ':' mark for separating lines to compare(f.eg sample:sample)\n"
                 "Program shows one of following symbols after comparison;\n"
              << "N        No colon on the line.\n"
                 "L        The left part (before the colon) is longer than the right.\n"
                 "R        The right part (after the colon) is longer than the left.\n"
                 "D        The left and right parts have the same length but are different.\n"
                 "S        The left and right parts are exactly the same.\n"
                  "\n\n";
}



