#include "Card.h"

Card::Card(int card_id):card_id_ (card_id) {}

void Card::add_access() {
    has_access_ = true;
}

void Card::remove_access() {
    has_access_ = false;
}