#include <iostream>
#include <iomanip>
#include "DoorSystem.h"


DoorSystem::DoorSystem(): lamplight_ (LampLight::ORANGE) {}

void DoorSystem::startSystem() {
    std::cout << "Door system started" << std::endl;
    print_admin_menu();
}

void DoorSystem::print_admin_menu() {
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
    std::cout << std::setw(3) << "5.";
    std::cout << "Fake Test Scan Card" << std::endl;
}