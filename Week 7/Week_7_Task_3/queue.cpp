#include "Header.h"

Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
    count = 0;
    rear = maxqueue - 1;
    front = 0;
}

bool Queue::empty() const
/*
Post: Return true if the Queue is empty, otherwise return false.
*/
{
    return count == 0;
}


Error_code Queue::append(const Queue_entry &item)
/*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
*/

{
    if (count >= maxqueue) return overflow;
    count++;
    rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
    entry[rear] = item;
    return success;
}


Error_code Queue::serve()
/*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
*/

{
    if (count <= 0) return underflow;
    count--;
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
    return success;
}


Error_code Queue::retrieve(Queue_entry &item) const
/*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/

{
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/

{
    cout << endl
         << "This program allows the user to enter one command" << endl
         << "(but only one) on each input line." << endl
         << "For example, if the command S is entered, then" << endl
         << "the program will serve the front of the queue." << endl
         << endl

         << " The valid commands are:" << endl
         << "A - Append the next input character to the extended queue" << endl
         << "S - Serve the front of the extended queue" << endl
         << "R - Retrieve and print the front entry." << endl
         << "# - The current size of the extended queue" << endl
         << "C - Clear the extended queue (same as delete)" << endl
         << "P - Print the extended queue" << endl
         << "H - This help screen" << endl
         << "Q - Quit" << endl

         << "Press <Enter> to continue.\n" << flush;

    char c;
    do {
        cin.get(c);
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
                cout << "Queue is empty." << endl;
            else
                cout << endl
                     << "The first entry is: " << x
                     << endl;
            break;

        case 'q':
            cout << "Extended queue demonstration finished." << endl;
            continue_input = false;
            break;

        case 'a':
            cout << "Give the character to add queue: ";
            cin >> x;
            test_queue.append(x);
            break;

        case '#':
            cout << "Present size of the queue is: " << test_queue.size() << "\n";
            break;

        case 'h':
            help();
            break;

        case 'c':
            test_queue.clear();
            cout << "Queue is now empty.\n";
            cout << "Size is now: " << test_queue.size() << "\n";
            //  Additional cases will cover other commands.

        case 'p':
            test_queue.print(test_queue);
            break;
    }
    return continue_input;
}

char get_command() {
    cout << "Give command: ";
    char command;
    bool waiting = true;
    cin >> command;
    command = tolower(command);
    while (waiting) {
        if (command == 'a' || command == 's' || command == 'r' || command == '#' ||
            command == 'c' || command == 'h' || command == 'q' || command == 'p')
            waiting = false;
        else{
            cout << "Invalid Command, please enter new command. \n"
            << "/H (help & list commands), /Q (quit)\n";
        }
    }
    return command;
}

void introduction(){
    cout << "Welcome to use queue-program!\n\n";
}

