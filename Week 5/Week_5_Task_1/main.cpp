#include "func.h"
int main()
{
   int n;
   std::string test_string;
   std::stack<char> line;  //  declares and initializes a stack of numbers

   std::cout << "Type a word or sentence: " << std::endl;
   std::getline(std::cin, test_string, '\n');

   for (int i = 0; i < test_string.size(); i++) {
      line.push(test_string[i]);

   }
   std::cout << std::endl << std::endl;
   std::cout << "So your word/sentence you gave was:\n";
   std::cout << test_string << std::endl;
   std::cout << "Now, let's print those letters in reverse order:\n ";
   while (!line.empty()) {
      std::cout << line.top() << " ";
      line.pop();
   }

   std::cout << std::endl;
   if (is_palindrome(test_string))
        std::cout << "Hey look, it's a PALINDROME!";
   else
        std::cout << "Unfortunately it's NOT a palindrome.";

   std::cout << std::endl;
   return 0;
}
