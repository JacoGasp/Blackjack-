//
// Created by Jacopo Gasparetto on 01/05/21.
//

#include "Player.h"
#include "Deck.h"

void Player::dealCard(Deck &deck, bool isCardHidden) {
    auto outCard = deck.dealCard();
    if (!isCardHidden)
        outCard.print();
    m_score += outCard.value();
}

int Player::score() const {
    return m_score;
}
