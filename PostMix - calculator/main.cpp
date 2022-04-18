#include "Stack.h"

int main(int argc, char* argv[]) {
    /*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/
        std::cout << "argc value: " << argc << "\n";
        for (int i = 0; i < argc; i++)
        std::cout << i << ":"<< argv[i] << "  ";
        std::cout <<"\n";
       

        std::stringstream ss;
        Stack stored_numbers;
        std::string line = "-p", temp;
        int number, count = 0;
        char command;
        bool num1 = false, num2 = false, operand = false;
        
        
        if (argv[1] == line) { 
            introduction();
            instructions();
            while (stored_numbers.do_command(stored_numbers.get_command(), stored_numbers));
        }
        else if (argc >= 2){
            
            for (int i = 1; i <= argc; i++){
                if (i < argc){
                    ss << argv[i];
                }
                    if (num1 == false){
                        if (ss >> number){
                        std::cout << "number1: " << number << "\n";
                        stored_numbers.push(number);
                        num1 = true;
                        std::stringstream().swap(ss);
                    }}
                    else if (num1 == true && num2 == false){
                        if (ss >> number){
                        std::cout << "number2: " << number << "\n";
                        stored_numbers.push(number);
                        num2 = true;
                        std::stringstream().swap(ss);
                    }}
                    else if (num1 == true && num2 == true && operand == false){
                        command = *(argv[i]);
                        std::cout << "command: " << command <<"\n";
                        operand == true;     
                        stored_numbers.do_command(command, stored_numbers);
                        num1 = false; num2 = false, operand = false;
                        std::stringstream().swap(ss);
                        std::cout << "size of stack: " << stored_numbers.size() << "\n";
                        if (stored_numbers.size() == 1){
                            num1 = true;
                            }
                        }
                    }                
                }                         
            
    return 0;
}
