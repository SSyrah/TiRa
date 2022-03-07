#include "stack_exercise.h"

int main(){
    // EXCERCISE 1
    // Task 1, first method was easiest and fastest to write.
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

    // EXCERCISE 2
    //Task A
    Extended_stack test, temp;
    test.push(2);
    test.push(3);
    std::cout << "\nStack is full? -> " << std::boolalpha << test.full(test) << "\n";
    test.push(15);
    Stack_entry t;
    test.pop_top(test, t);
    std::cout << "Stack top was : " << t << std::endl;

    //Task B
    test.clear(test);
    std::cout << "\nStack is empty? -> " << std::boolalpha << test.empty() << "\n";

    //Task C
    test.push(3);
    test.push(2);
    test.push(4);
    test.push(3);
    t = test.size(test);
    std::cout << "Stack size is now: -->  " << t << std::endl;

    //Task D
    std::cout << "Let's remove this number from stack: " << t << "\n";
    test.delete_all(test, t);
    std::cout << "\nThe result is: \n";
    while(!test.empty()){
        test.top(x);
        std::cout << x << "  ";
        test.pop();
    }

    //EXCERCISE 3 PRIME
    std::cout << std::endl;
    test.push(3600);
    test.prime(test);

  return EXIT_SUCCESS;
}

