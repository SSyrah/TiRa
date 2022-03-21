#include "Header.h"

int main() {

    int temp=5;
    Queue test;
    for (int i=0; i<maxqueue;i++) {
        test.append(temp + rand() % 254+3);
        temp++;
    }
    std::cout << "Is queue empty: " << std::boolalpha << test.empty() << "\n";
    /////////////////////////////////////

    test.retrieve(temp);
    std::cout << "First number in queue was: " << temp << "\n";
    //////////////////////////////////////






    return 0;
}
