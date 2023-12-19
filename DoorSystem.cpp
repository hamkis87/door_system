#include <thread>
#include <iostream>
#include <iomanip>
#include <string>
#include "DoorSystem.h"

using std::cout; using std::endl;
using std::string;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;


// DoorSystem::DoorSystem(): lamplight_ (LampLight::OFF) {}
DoorSystem::DoorSystem(std::string cards_file_name) {
    cards_file_name_ = cards_file_name;
    lamplight_ = LampLight::OFF;
    readCardData();
}
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

void DoorSystem::readCardData() {
    std::ifstream data_file(cards_file_name_);
    std::string line;
    while (std::getline(data_file, line)) {
        int card_id;
        std::string temp_str;
        std::stringstream lineStream(line);
        if (lineStream >> card_id && lineStream >> temp_str) {
            int n = 0;
            bool hasAccess = false; 
            if (temp_str == "Access") {
                hasAccess = true;
                n = 3; // there are 3 strings before reading the date
            }
            else if (temp_str == "No")
                n = 4; // there are 4 strings before reading the date
            else // line corrupted
                continue;
            for(int i = 0; i < n; ++i) {
                lineStream >> temp_str;
            }
            unsigned int a,b,c;
            char ch;
            if (lineStream >> a && lineStream >> ch && lineStream >> b &&
                lineStream >> ch && lineStream >> c) {
                const unsigned int y = a; const unsigned int m = b;
                const unsigned int d = c;
                std::chrono::month m1{m};
                std::chrono::year y1{y};
                std::chrono::day d1{d};
                auto ymd = std::chrono::year_month_day(y1, m1, d1);
                Card card(card_id, hasAccess, ymd);
                cards_.emplace(card_id, card);   
            }
        }
    }
    data_file.close();
}

void DoorSystem::saveCardData() {
    std::ofstream data_file(cards_file_name_);
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