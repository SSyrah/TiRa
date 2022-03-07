#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H

#include "queue.h"
#include "Utility.h"
#include "Extended_queue.h"
#include "Stack.h"

void help();
bool do_command(char c, Extended_queue &test_queue);
char get_command();
void introduction();
Error_code stack_to_queue(Stack&, Extended_queue&);
Error_code queue_to_stack(Extended_queue&, Stack&);
void print_queue(Extended_queue&);
void print_stack(Stack&);
Error_code stack_change(Stack&, Stack&);
Error_code stack_change_same_order(Stack&, Stack&);
Error_code stack_change_with_local_stack(Stack&);
Error_code stack_change_with_queue(Stack&);
void comparison_instructions();

#endif //UNTITLED_HEADER_H
