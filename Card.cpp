#include "Card.h"


std::ostream& operator<<(std::ostream& out, const Card& card) {
    std::string access_str = card.access_ ? " Access" : " No Access";
    out << card.card_id_ << access_str << " Added to system: ";
    out << card.creation_date_ << std::endl;
    return out;
}
Card::Card(int card_id, bool access, 
           std::chrono::year_month_day creation_date) {
    card_id_ = card_id;
    access_ = access;
    creation_date_ = creation_date;
}
bool Card::has_access() const {
    return access_;
}

void Card::set_access(bool accessFlag) {
    access_ = accessFlag;
}