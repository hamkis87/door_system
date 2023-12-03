#ifndef DOORSYSTEM_H
#define DOORSYSTEM_H

#include <map>
#include "Card.h"
#include "Utilities.h"


enum class LampLight {ORANGE, GREEN, RED};

class DoorSystem
{
private:
    void openDoor();
    // void listCards();
    void addOrRemoveAccess();
    void print_admin_menu();
    
    std::map<int, Card> cards_;
    LampLight lamplight_;

public:
    DoorSystem();

    void run();

};

#endif