#include "Linked_stack.h"

Node::Node()
{
    next = NULL;
}


Node::Node(Node_entry item, Node *add_on)
{
    entry = item;
    next = add_on;
}

int Linked_stack::Stack() {
    count = 0;
}

bool Linked_stack::empty() const
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

Error_code Linked_stack::push(const Stack_entry &item)
/*
Post: Stack_entry item is added to the top of
      the Stack; returns success or returns a code
      of overflow if dynamic memory is exhausted.
*/
{
    Node *new_top = new Node(item, top_node);
    if (new_top == NULL)
        return overflow;
    top_node = new_top;
    count++;
    return success;
}

Error_code Linked_stack::pop()
/*
Post: The top of the Stack is removed.  If the Stack
      is empty the method returns underflow; otherwise it returns success.
*/
{
    Node *old_top = top_node;
    if (top_node == NULL) return underflow;
    top_node = old_top->next;
    delete old_top;
    if (count <= 0)
        return fail;
    count--;
    return success;
}

Error_code Linked_stack::top(Stack_entry &item) const {
    item = top_node->entry;
}

void Linked_stack::print() const{
    std::cout << "Top node value is: " << top_node->entry << std::endl;
}