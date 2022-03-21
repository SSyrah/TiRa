#include "stack_exercise.h"

int main(){

    Extended_stack test;

    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);

    std::cout << "Size is: " << test.size() << std::endl;

    std::cout << "Is it full --> " << test.full() << std::endl;

    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    test.push(rand() % 100 + 1);
    
    std::cout << "Is it full --> " << test.full() << std::endl;

    test.clear();

    std::cout << "Size is: " << test.size() << std::endl;
    
    

return 0;
}




