#ifndef CARD_H
#define CARD_H

#include <chrono>

class Card
{
private:
    int card_id_;
    bool access_;
    std::chrono::year_month_day creation_date_;

public:
    Card(int card_id);

    bool has_access() const;
    void set_access(bool accessFlag);

};

#endif