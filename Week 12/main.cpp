#include "List.h"

int main(){

    int number;
    char albphabet;

    List<int> numberTest;
    List<char> alphabetTest;

    numberTest.insert(0, 12);
    numberTest.retrieve(0, number);
    std::cout << "After retrieve: " << number << std::endl;
    numberTest.replace(0,25);
    numberTest.retrieve(0, number);
    std::cout << "After replace and retrieve: " << number << std::endl;
    alphabetTest.insert(0,'s');
    alphabetTest.retrieve(0, albphabet);
    std::cout << "Testing character after retrieve: " << albphabet << std::endl;
    std::cout << "Size is: " << numberTest.size() << std::endl;
    numberTest.insert(4,number);
    numberTest.remove(1,number);
    numberTest.remove(0,number);
    std::cout << "After retrieve: " << number << std::endl;
    std::cout << "Size is: " << numberTest.size() << std::endl;



    return 0;
}