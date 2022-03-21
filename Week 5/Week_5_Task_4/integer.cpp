#include<iostream>
#include<stack>
#include<cstdlib>
#include<unistd.h>


int main() {

    std::stack<int> lines;
    int number=0, rounds=0;


    std::cout << "Welcome to rounds-roulette! \n"
              << "You choose max amount of rounds, i will create random numbers between 1-100000 \n"
              << "When next number is lower than it's predecessor, i will stop and print numbers \n"
              << "in decreasing order.\n"
              << "How many rounds you want to take max? :  ";
              std::cin >> rounds;
              std::cout << "Give me the number: ";
              std::cin >> number;
              lines.push(number);

              for (int i=1; i <=rounds; i++){
                    std::cout << "Give me the number: ";
                    std::cin >> number;
                    if (number > lines.top()){
                        lines.push(number);
                        }

                    else{
                        std::cout << "Ups, the number isn't higher than the previous one!" << std::endl;
                        break;
                    }}

                    while(!lines.empty()){
                        std::cout << lines.top() << " ";
                        lines.pop();
                    }



    return 0;
}
