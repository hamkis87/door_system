#include <iostream>
#include <iomanip>
#include <chrono>

void print_admin_menu();

int main() {
    print_admin_menu();
    
    return 0;
}

void print_admin_menu() {
    std::cout << "Admin Menu" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(3) << "1.";
    std::cout << "Remote Open Door" << std::endl;
    std::cout << std::setw(3) << "2.";
    std::cout << "List All Cards In System" << std::endl;
    std::cout << std::setw(3) << "3.";
    std::cout << "Add/Remove Access" << std::endl;
    std::cout << std::setw(3) << "4.";
    std::cout << "Exit" << std::endl;
    std::cout << std::setw(3) << "9.";
    std::cout << "Fake Test Scan Card" << std::endl;
}