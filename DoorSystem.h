#ifndef DOORSYSTEM_H
#define DOORSYSTEM_H

#include <fstream>
#include <map>
#include "Card.h"
#include "Utilities.h"


enum class LampLight {OFF, GREEN, RED};

class DoorSystem
{
private:
    std::string cards_file_name_;
    void openDoor();
    void listCards();
    void listCards(std::ostream& out);
    void addOrRemoveAccess();
    void scanCard();
    void print_admin_menu();
    void readCardData();
    void saveCardData();
    
    std::map<int, Card> cards_;
    LampLight lamplight_;

public:
    // DoorSystem();
    DoorSystem(std::string cards_file_name = "cardInfo.txt");

    void run();

};

#endif