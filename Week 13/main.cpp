#include "linked_list.h"


int main()
{
    List<int> test;
    int print;
    
    test.insert(0, 24);
    test.retrieve(0, print);
    std::cout << "retrieve: " << print << std::endl;

    test.clear();
    std::cout << "after clear, size: " << test.size() << std::endl;
    print = 0;
    test.retrieve(0, print);
    std::cout << "retrieve: " << print << std::endl;
    
    return 0;
}