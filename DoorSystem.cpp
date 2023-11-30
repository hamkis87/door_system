#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>
#include "DoorSystem.h"

using std::cout; using std::endl;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;


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
    os << "CURRENTLY LAMP IS: " << lampLightStr << endl;
    return os;
}

void DoorSystem::openDoor() {
    lamplight_ = LampLight::GREEN;
    cout << lamplight_;
    sleep_for(3s);
    lamplight_ = LampLight::ORANGE;
}

void DoorSystem::run() {
    cout << "Door system started" << endl;
    bool keepSystemRun = true;
    while (keepSystemRun) {
        print_admin_menu();
        int userChoice;
        if (getValidUserInput(userChoice)) {
            cout << "user chose " << userChoice << endl;
            switch (userChoice) {
                case 1:
                    openDoor();
                    break;
                case 2:
                    cout << "Execute 2 option" << endl;
                    break;
                case 3:
                    cout << "Execute 3 option" << endl;
                    break;
                case 4:
                    cout << "Execute 4 option" << endl;
                    keepSystemRun = false;
                    break;
                case 5:
                    cout << "Execute 5 option" << endl;
                    break;
                default:
                    cout << "Unavailable option" << endl;
            }
        }
        else {
            cout << "Sorry! Data enetered is not valid!" << endl;
            cout << "Please try again with valid data!" << endl;
        }
    }
}

void DoorSystem::print_admin_menu() {
    cout << "Admin Menu" << endl;
    cout << std::left;
    cout << std::setw(3) << "1.";
    cout << "Remote Open Door" << endl;
    cout << std::setw(3) << "2.";
    cout << "List All Cards In System" << endl;
    cout << std::setw(3) << "3.";
    cout << "Add/Remove Access" << endl;
    cout << std::setw(3) << "4.";
    cout << "Exit" << endl;
    cout << std::setw(3) << "5.";
    cout << "Fake Test Scan Card" << endl;
    cout << lamplight_;
}