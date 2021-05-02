//
// Created by Jacopo Gasparetto on 01/05/21.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <array>
#include "cards.h"

class Deck {


public:
    using deck_t = std::array<Card, 52>;
    using deck_index_t = deck_t::size_type;

    Deck();

    void shuffle();

    const Card &dealCard();

    void print() const;


private:
    deck_t m_deck;
    int m_cardIndex{ 0 };

    void createDeck();

};


#endif //BLACKJACK_DECK_H
