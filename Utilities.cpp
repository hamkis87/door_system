#include <iostream>
#include <string>
#include <sstream>

bool getValidUserInput(int &x) {
    // std::cout << "Testing utilites file" << std::endl;
    std::string userInput;
    std::getline(std::cin, userInput);
    std::stringstream userInputStringS(userInput);
    int n;
    char c;
    if (userInputStringS >> n && !(userInputStringS >> c) && (n > 0)) {
        x = n;
        return true;
    }
    return false;    
}