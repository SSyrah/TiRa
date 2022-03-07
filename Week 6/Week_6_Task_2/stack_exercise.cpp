#include "stack_exercise.h"

Error_code Extended_stack::push(const Stack_entry item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}


Error_code Extended_stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}


Error_code Extended_stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else
      item = entry[count - 1];
   return outcome;
}


bool Extended_stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}


Extended_stack::Extended_stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
   count = 0;
}

void Extended_stack::clear(){
   for (int i = count; i>0; i--){
      entry[i] = NULL;
      count--;
   }
}

bool Extended_stack::full(Extended_stack& source) const {
   return source.size() == maxstack;
}

int Extended_stack::size() const {
   return count;
}

Error_code Extended_stack::pop_top(Extended_stack& temp, Stack_entry& test) {

    Error_code outcome = success;
    if (!temp.empty()){
        temp.top(test);
        temp.pop();
    }
    else {
        outcome = underflow;
    }
    return outcome;
}

Error_code Extended_stack::clear(Extended_stack &temp) {

    Error_code outcome = success;
    if (temp.empty()){
        outcome = underflow;
    }
    else {
        while (!temp.empty()) {
            temp.pop();
        }
    }
    return outcome;
}

int Extended_stack::size(Extended_stack & source) const {
    Stack_entry x;
    x = source.size();
    return x;
}

void Extended_stack::delete_all(Extended_stack & source, Stack_entry& test) {
    Extended_stack temp;
    Stack_entry keep;
    std::cout << "The original stack is: \n";
    while (!source.empty()) {
        source.top(keep);
        std::cout << keep << " ";
        if (keep == test) {
            source.pop();
        }
        else{
            temp.push(keep);
            source.pop();
        }
    }
    while (!temp.empty()){
        temp.top(keep);
        source.push(keep);
        temp.pop();
    }

}

void Extended_stack::prime(Extended_stack & prime) {

    Extended_stack temp;
    int x,y;
    prime.top(x);
    for (int i = 2; i < 10; i++){
        while ( x % i == 0){
            temp.push(i);
            x = x / i;
        }
    }
    std::cout << "Let's print primes:  \n";
    while (!temp.empty()){
        temp.top(y);
        std::cout << y << " ";
        temp.pop();
    }

}

