#include "func.h"

bool is_palindrome (std::string str){
        std::string s;
        for (char c : str){
            if (std::isalnum(c))
                s += std::tolower(c);
        }
       return !s.empty() && std::equal(s.begin(), s.begin()+s.size()/2, s.rbegin());
    }


