#include <iostream>
#include <iomanip>
#include "DoorSystem.h"


DoorSystem::DoorSystem(): lamplight_ (LampLight::ORANGE) {}

std::ostream& operator<< (std::ostream& os, const LampLight& lampLight)
{
    std::string lampLightStr;
    switch (lampLight)
    {
        case LampLight::ORANGE:
            lampLightStr = "ORANGE";
            break;
        case LampLight::GREEN:
            lampLightStr = "GREEN";
            break;
        case LampLight::RED:
            lampLightStr = "RED";
        default:
            break;
    }
    os << lampLightStr;
    return os;
}

bool DoorSystem::executeUserChoice(int userChoice) {
    switch (userChoice) {
                case 1:
                    std::cout << "Execute 1 option" << std::endl;
                    break;
                case 2:
                    std::cout << "Execute 2 option" << std::endl;
                    break;
                case 3:
                    std::cout << "Execute 3 option" << std::endl;
                    break;
                case 4:
                    std::cout << "Execute 4 option" << std::endl;
                    return false;
                case 5:
                    std::cout << "Execute 5 option" << std::endl;
                    break;
                default:
                    std::cout << "Unavailable option" << std::endl;
    }
    return true;
}

void DoorSystem::startSystem() {
    std::cout << "Door system started" << std::endl;
    bool keepSystemRun = true;
    while (keepSystemRun) {
        print_admin_menu();
        int userChoice;
        if (getValidUserInput(userChoice)) {
            std::cout << "user chose " << userChoice << std::endl;
            keepSystemRun = executeUserChoice(userChoice);
        }
        else {
            std::cout << "Sorry! Data enetered is not valid!" << std::endl;
            std::cout << "Please try again with valid data!" << std::endl;
        }
    }
    std::cout << lamplight_ << std::endl;
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