//
// Created by Jacopo Gasparetto on 23/04/21.
//

#include "cards.h"
#include <iostream>
#include <algorithm>
#include <random>


Card::Card(Card::Suit suit, Card::Rank rank) : m_suit{ suit }, m_rank{ rank } {}

int Card::value() const {
    switch (m_rank) {
        case Rank::rank_jack:
        case Rank::rank_queen:
        case Rank::rank_king:
            return 10;
        case Rank::rank_ace:
            return 11;
        default:
            return static_cast<int>(m_rank) + 2;
    }
}

void Card::print() const {

    switch (m_rank) {
        case Rank::rank_2:
            std::cout << '2';
            break;
        case Rank::rank_3:
            std::cout << '3';
            break;
        case Rank::rank_4:
            std::cout << '4';
            break;
        case Rank::rank_5:
            std::cout << '5';
            break;
        case Rank::rank_6:
            std::cout << '6';
            break;
        case Rank::rank_7:
            std::cout << '7';
            break;
        case Rank::rank_8:
            std::cout << '8';
            break;
        case Rank::rank_9:
            std::cout << '9';
            break;
        case Rank::rank_10:
            std::cout << 'T';
            break;
        case Rank::rank_jack:
            std::cout << 'J';
            break;
        case Rank::rank_queen:
            std::cout << 'Q';
            break;
        case Rank::rank_king:
            std::cout << 'K';
            break;
        case Rank::rank_ace:
            std::cout << 'A';
            break;

        default:
            std::cout << '?';
            break;
    }

    switch (m_suit) {
        case Suit::suit_clubs:
            std::cout << "♣️";
            break;
        case Suit::suit_diamonds:
            std::cout << "♦️";
            break;
        case Suit::suit_hearts:
            std::cout << "♥️";
            break;
        case Suit::suit_spades:
            std::cout << "♠️";
            break;
        default:
            std::cout << '?';
            break;
    }
}
