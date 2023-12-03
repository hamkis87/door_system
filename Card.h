#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int card_id_;
    bool access_;

public:
    Card(int card_id);

    bool has_access() const;
    void set_access(bool accessFlag);

};

#endif