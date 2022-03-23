#include "List.h"

int main(){

    int number, number2;
    char albphabet;

    List<int> numberTest;
    List<char> alphabetTest;

    numberTest.insert(0, 12);
    std::cout << "Size is: " << numberTest.size() << std::endl;
    std::cout << "Is is full: " << std::boolalpha  << numberTest.full() << std::endl;
    numberTest.retrieve(0, number);
    std::cout << "After retrieve, number: " << number << std::endl;
    numberTest.remove(0, number2);
    std::cout << "After remove, number: " << number << std::endl;
    std::cout << "Size is now: " << numberTest.size()  << std::endl;
    numberTest.insert(0,2);
    numberTest.insert(1,4);
    std::cout << numberTest.size() << std::endl;
    numberTest.retrieve(0,number);
    std::cout << number << std::endl;
    remove_first(number, numberTest);
    numberTest.retrieve(0, number2);
    std::cout << "pos0: " << number << "pos0 after remove: " << number2 << std::endl;
    numberTest.clear();
    std::cout << numberTest.size() << std::endl;
    numberTest.insert(0,1);
    numberTest.insert(1,2);
    numberTest.insert(2,3);
    numberTest.insert(3,4);
    median_list(number, numberTest);
    std::cout << "Median: "  << number << std::endl;
    return 0;
}