#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int card_id_;
    bool has_access_;

public:
    Card(int card_id);

    void add_access();
    void remove_access();

};

#endif