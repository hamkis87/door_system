#include "Card.h"

Card::Card(int card_id):card_id_ (card_id) {}

bool Card::has_access() const {
    return access_;
}

void Card::set_access(bool accessFlag) {
    access_ = accessFlag;
}