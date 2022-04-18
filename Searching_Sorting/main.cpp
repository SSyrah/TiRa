#include "header.h"

int main()
{
    bool operand = true;
    int target, key;
    SortableList<int> theList;

    while (operand) {
        initialize(target);
        if (target != 6) {
            std::cout << "Enter number for searching: ";
            std::cin >> key;
            checkInt(key);
        }
        switch (target) {
            case 1:
                sequentialSearch(theList,key);
                break;
            case 2:
                std::cout << "placeholder 2\n";
                break;
            case 3:
                std::cout << "placeholder 3\n";
                break;
            case 4:
                std::cout << "placeholder 4\n";
                break;
            case 5:
                std::cout << "placeholder 5\n";
                break;
            case 6:
                std::cout << "Ending program, thank you for using!\n";
                operand = false;
                break;
            default:
                std::cout << "Sorry, wrong input\n";
        }
    }




    return EXIT_SUCCESS;
}
