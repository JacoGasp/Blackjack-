//
// Created by Jacopo Gasparetto on 01/05/21.
//

#include "Deck.h"
#include <random>
#include <iostream>
#include <algorithm>

Deck::Deck() { createDeck(); }

void Deck::createDeck() {
    deck_index_t i{ 0 };

    for (int suit = 0; suit < static_cast<int>(Card::Suit::max_suits); ++suit) {
        for (int rank = 0; rank < static_cast<int>(Card::Rank::max_rank); ++rank) {
            m_deck.at(i) = Card{ static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank) };
            ++i;
        }
    }
}

void Deck::shuffle() {
    std::random_device device;
    std::mt19937 mt(device());
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
}

void Deck::print() const {
    for (auto &card : m_deck) {
        card.print();
        std::cout << ' ';
    }
    std::cout << '\n';
}

const Card &Deck::dealCard() {
    return m_deck[m_cardIndex++];
}

