//
// Created by Jacopo Gasparetto on 01/05/21.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Deck.h"

class Player {

public:
    void dealCard(Deck &deck, bool isCardHidden = false);

    [[nodiscard]] int score() const;

private:
    int m_score{ 0 };
};


#endif //BLACKJACK_PLAYER_H
