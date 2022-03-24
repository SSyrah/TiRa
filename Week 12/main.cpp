#include "List.h"

int main(){

    int number, number2;
    char albphabet;

    List<int> numberTest;
    List<int> number2Test;
    List<int> oddlist, evenlist;

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
    std::cout << "After two inserts, size: " << numberTest.size() << std::endl;
    numberTest.retrieve(0,number);
    remove_first(number, numberTest);
    numberTest.retrieve(0, number2);
    std::cout << "pos0: " << number << " ,pos0 after remove: " << number2 << std::endl;
    numberTest.clear();
    std::cout << "After clear, size: " << numberTest.size() << std::endl;
    numberTest.insert(0,1);
    numberTest.insert(1,2);
    numberTest.insert(2,3);
    numberTest.insert(3,4);
    numberTest.insert(4,5);
    median_list(number, numberTest);
    std::cout << "Median: "  << number << std::endl;
    insert_first(1, numberTest);
    numberTest.retrieve(0, number);
    std::cout << "Insert 1 to first place, let's see is it: " << number << std::endl;
    insert_last(12, numberTest);
    numberTest.retrieve(6, number);
    std::cout << "Insert 12 to last place, let's see is it: " << number << std::endl;
    interchange<int>(0,1, numberTest);
    copy<int>(number2Test, numberTest);
    join<int>(numberTest, number2Test);
    reverse<int>(number2Test);
    split<int>(numberTest, oddlist, evenlist);

    return 0;
}