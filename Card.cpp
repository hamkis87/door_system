#include "Card.h"
#include <stdexcept>

Card::Card(int card_id) {
    if (card_id <= 0) {
        throw std::invalid_argument("Invalid Card Id!");
    }
    card_id_ = card_id;
}

void Card::add_access() {
    has_access_ = true;
}

void Card::remove_access() {
    has_access_ = false;
}