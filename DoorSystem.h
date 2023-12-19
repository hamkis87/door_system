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
    void openDoor();
    void listCards();
    void listCards(std::ostream& out);
    void addOrRemoveAccess();
    void scanCard();
    void print_admin_menu();
    void saveCardData();
    
    std::map<int, Card> cards_;
    LampLight lamplight_;

public:
    DoorSystem();

    void run();

};

#endif