#ifndef _STACK_H
#define _STACK_H
#include "Utility.h"
#include <iostream>
#include <ctype.h>
#include <cmath>
#include <sstream>
#include<string.h>
#include<stdio.h>
// using namespace std;

// Section 2.2:

typedef double Stack_entry;
const int maxstack = 10;   //  small value for testing


void introduction();
void instructions();

class Stack {
public:
   Stack();
   bool empty() const;
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   Error_code push(const Stack_entry &item);
   bool do_command(char command, Stack &numbers);
   char get_command();
   int size();
   void sum(Stack&);
   void average(Stack&);

private:
   int count;
   Stack_entry entry[maxstack];
};
#endif