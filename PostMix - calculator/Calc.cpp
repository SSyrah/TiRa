#include "Stack.h"

char Stack::get_command()
{
    char command;
    bool waiting = true;
    std::cout << "Select command and press <Enter>: ";

    while (waiting) {
        std::cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == 'h' || command == 'a' || command == '%' ||
            command == '^' || command == 'v') waiting = false;


        else {
            std::cout << "Please enter a valid command:"   << std::endl
                    << "[?] push to stack   [=] print top value" << std::endl
                    << "[+] [-] [p = product] [/]  are arithmetic operations" << std::endl
                    << "[s] gives sum from all values  [h] instructions" << std::endl
                    << "[x] exchanges the place for last two values" << std::endl
                    << "[a] gives average [%] modulo [^] pow [v] sqrt " << std::endl
                    << "[Q]uit." << std::endl;
        }
    }
    return command;
}

bool Stack::do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    double p, q, r, s;
    switch (command) {
        case '?':
            std::cout << "Enter a real number: " << std::flush;
            std::cin >> p;
            if (numbers.push(p) == overflow)
                std::cout << "Warning: Stack full, lost number" << std::endl;
            break;

        case '=':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else
                std::cout << p << std::endl;
            break;

        case '+':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                    std::cout << "The results is for " << q << " + " << p << " = " << q + p << std::endl;
                        numbers.pop();
                        numbers.push(p+q);
                    }
                }
            }
            break;

        case '-':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        std::cout << "The results is for " << q << " - " << p << " = " << q - p << std::endl;
                        numbers.pop();
                        numbers.push(p-q);
                    }
                }
            }
            break;

            //   Add options for further user commands.
        case 'x':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    // numbers.pop();
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        double temp = 0;
                        numbers.top(r);
                        numbers.pop();
                        numbers.top(s);
                        numbers.pop();
                        std::cout << "Numbers first: " << r << " + " << s << std::endl;
                        temp = r;
                        r = s;
                        s = temp;
                        numbers.push(s);
                        numbers.push(r);
                        std::cout << "Numbers last: " << r << " + " << s << std::endl;
                    }
                }
            }
            break;

        case 's':
            numbers.sum(numbers);
            numbers.top(p);
            std::cout << "Sum =  " << p << "\n";
            break;

        case 'a':
            numbers.average(numbers);
            numbers.top(p);
            std::cout << "Average =  " << p << "\n";

        case '/':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        std::cout << "The results is for " << q << " / " << p << " = " << q / p << std::endl;
                        numbers.pop();
                        numbers.push(p/q);
                    }
                }
            }
            break;

        case 'p':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        std::cout << "The results is for " << p << " * " << q << " = " << p * q << std::endl;
                        numbers.pop();
                        numbers.push(p*q);
                    }
                }
            }
            break;

        case '%':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        std::cout << "The results is for " << q << " % " << p << " = " << fmod(q,p) << std::endl;
                        numbers.pop();
                        numbers.push(fmod(q,p));
                    }
                }
            }
            break;
        
        case '^':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        std::cout << "The results is for " << q << " ^ " << p << " = " << pow(q,p) << std::endl;
                        numbers.pop();
                        numbers.push(pow(p,q));
                    }
                }
            }
            break;

              
        case 'v':
            if (numbers.top(p) == underflow)
                std::cout << "Stack empty" << std::endl;
            else {
                /* numbers.pop();
                if (numbers.size() == 1) {
                    std::cout << "Stack has just one entry" << std::endl;
                    // numbers.push(p);
                }*/

                // else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        std::cout << "Warning: Stack full, lost result" << std::endl;
                    else{
                        numbers.pop();
                        std::cout << "The results is for sqrt " << p << " = " << sqrt(q) << std::endl;
                        numbers.pop();
                        numbers.push(sqrt(p));
                    }
               //}
            }
            break;

        case 'h':
            instructions();
            break;

        case 'q':
            std::cout << "Calculation finished.\n";
            return false;
    }
    return true;
}

void introduction() {
    std::cout << "\t --------------------------------------\n";
    std::cout << "\t | Welcome to use PostFix-Calculator! | \n";
    std::cout << "\t --------------------------------------\n\n";
}

void instructions(){
    std::cout << "How to use this calculator:"   << std::endl
         << "[?] push to stack   [=] print top value" << std::endl
        << "[+] [-] [p = product] [/]  are arithmetic operations" << std::endl
        << "[s] gives sum from all values  [h] instructions" << std::endl
        << "[x] exchanges the place for last two values" << std::endl
        << "[a] gives average [%] modulo [^] pow [v] sqrt " << std::endl
        << "[Q]uit." << std::endl;
}
