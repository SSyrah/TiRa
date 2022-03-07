#include "stack_exercise.h"

int main(){
    int x;
    std::stack<int> source, dest;


    fill_stack(source);
    std::cout << std::endl;
    x = copy_stack_A(dest, source);
    print_stack(dest);
    std::cout << "\nError code: " << x << std::endl;
    x = copy_stack_B(dest, source);
    print_stack(dest);
    std::cout << "\nError code: " << x << std::endl;

    x = copy_stack_C(dest, source);
    print_stack(dest);
    return EXIT_SUCCESS;
}

