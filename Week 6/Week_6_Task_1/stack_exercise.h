#pragma once

#include<iostream>
#include<stack>
#include<stdlib.h>
typedef int Stack_entry;


enum Error_code {
    success, fail, utility_range_error, underflow, overflow, fatal,
    not_present, duplicate_error, entry_inserted, entry_found,
    internal_error
};

Error_code copy_stack_A(std::stack<int> &dest, std::stack<int>& source);
Error_code copy_stack_B(std::stack<int> &dest, std::stack<int>& source);
void print_stack(std::stack<int>&);
void fill_stack(std::stack<int>&);
Error_code copy_stack_C(std::stack<int>&, std::stack<int>&);

const int maxstack = 9;   //  small value for testing

class Extended_stack {
public:
    Extended_stack();
    Error_code pop();
    Error_code push(Stack_entry item);
    Error_code top(Stack_entry &item) const;
    bool empty() const;
    void clear(); //  Reset the stack to be empty.
    bool full() const ; //  If the stack is full, return true; else return false.
    int size() const;   //  Return the number of entries in the stack.
    // Error_code copy_stack_C(std::stack<int>&, std::stack<int>&);
    friend Error_code copy_stack_C(std::stack<int>&, std::stack<int>);

private:
    int count;
    Stack_entry entry[maxstack];
};
