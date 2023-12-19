#include <thread>
#include <iostream>
#include <iomanip>
#include <string>
#include "DoorSystem.h"

using std::cout; using std::endl;
using std::string;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;


DoorSystem::DoorSystem(): lamplight_ (LampLight::OFF) {}

std::ostream& operator<< (std::ostream& os, const LampLight& lampLight)
{
    std::string lampLightStr;
    switch (lampLight)
    {
        case LampLight::OFF :
            lampLightStr = "OFF";
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
    lamplight_ = LampLight::OFF;
}

void DoorSystem::listCards(std::ostream& out) {
    if (!cards_.empty()) {
        for (auto i = cards_.begin(); i != cards_.end(); i++) {
            Card card = i->second;
            out << card;
        }
    }
}

void DoorSystem::listCards() {
    // if (!cards_.empty()) {
    //     for (auto i = cards_.begin(); i != cards_.end(); i++) {
    //         Card card = i->second;
    //         cout << card;
    //     }
    // }
    // else {
    //     cout << "No cards exist in the system" << endl; 
    // }
    listCards(cout);
}

void DoorSystem::addOrRemoveAccess() {
    int cardNumber;
    cout << "Enter card number> ";
    if (getValidUserInput(cardNumber)) {
        bool hasAccess = false;
        bool isNewCard = true;
        if (cards_.find(cardNumber) != cards_.end()) {
            isNewCard = false;
            hasAccess = cards_.at(cardNumber).has_access();
        }
        string accessInfo = hasAccess ? "has access" : "has no access";
        cout << "This card " << accessInfo;
        cout << ". Enter 1 for access, 2 for no access: ";
        int accessInput;
        hasAccess = getValidUserInput(accessInput)? (accessInput == 1): false;
        if (isNewCard) {
            const std::chrono::time_point now{std::chrono::system_clock::now()};
            const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};
            //cout << "ymd: " << ymd << '\n';
            Card card(cardNumber, hasAccess, ymd);
            cards_.emplace(cardNumber, card);
            // constexpr auto ymd2 = std::chrono::year_month_day(
            //     2020y, std::chrono::January, 31d // overload (2)
            //     );
            // std::cout << "ymd2: " << ymd2 << '\n';
            
        }
        else {
            cards_.at(cardNumber).set_access(hasAccess);
        }
    }
    else {
        cout << "Sorry the card number is invalid" << endl;
    }
}

void DoorSystem::scanCard() {
    int cardNumber;
    cout << "Please scan card to enter ";
    cout << "or X to go back to admin mode" << endl;
    if (getValidUserInput(cardNumber)) {
        if (cards_.find(cardNumber) != cards_.end() && 
            cards_.at(cardNumber).has_access()) {
            lamplight_ = LampLight::GREEN;
        }
        else {
            lamplight_ = LampLight::RED;
        }
        cout << lamplight_;
        sleep_for(3s);
        lamplight_ = LampLight::OFF;    
    }
}

void DoorSystem::saveCardData() {
    std::ofstream data_file("cardInfo.txt");
    listCards(data_file);
    data_file.close();
}

void DoorSystem::run() {
    //cout << "Door system started" << endl;
    bool keepSystemRun = true;
    while (keepSystemRun) {
        print_admin_menu();
        int userChoice;
        if (getValidUserInput(userChoice)) {
            //cout << "user chose " << userChoice << endl;
            switch (userChoice) {
                case 1:
                    openDoor();
                    break;
                case 2:
                    listCards();
                    break;
                case 3:
                    addOrRemoveAccess();
                    break;
                case 4:
                    keepSystemRun = false;
                    saveCardData();
                    break;
                case 5:
                    scanCard();
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