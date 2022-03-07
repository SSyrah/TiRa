#include "stack_exercise.h"

Error_code copy_stack_A(std::stack<int> &dest, std::stack<int>& source){
    Error_code outcome = success;
    dest = source;
    if (source == dest)
        return outcome;
    else{
        outcome = fail;
        return outcome;
    }
}
Error_code copy_stack_B(std::stack<int> &dest, std::stack<int> &source){

    Error_code outcome = success;
    std::stack<int> temp;
    temp = source;
    int count = 0;
    for (int i=temp.size(); i>0;i--){
        dest.push(temp.top());
        temp.pop();

    }
    if (dest.size() !=  source.size()){
        outcome = fail;
        return outcome;
    }
return outcome;
}
void fill_stack(std::stack<int>& dest){
    std::cout << "Filling Stack....\n";
    for (int i=0; i<9;i++){
        dest.push(rand() % 100 +1);
        std::cout << dest.top() << "  ";
    }
}

void print_stack(std::stack<int>& dest){
    std::cout << "Printing and Emptying Stack...\n";
    std::cout << dest.size() << "\n";
    for (int i=dest.size(); i>0; i--){
        std::cout << dest.top() << "  ";
        dest.pop();
    }
}

Error_code copy_stack_C(std::stack<int>& dest, std::stack<int>& source){

    Error_code outcome = success;
    Stack_entry entry[maxstack];
    for (int i=0; i<maxstack; i++){
            entry[i] = source.top();
            source.pop();
        }
    for (int i=0;i<maxstack;i++){
        dest.push(entry[i]);
        source.push(entry[i]);
    }
    if (dest.size() == source.size())
        return outcome;
    else{
        outcome = fail;
        return outcome;
    }
}