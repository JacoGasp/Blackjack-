#include <iostream>
#include "cards.h"
#include "Deck.h"
#include "Player.h"

bool isHit() {
    while (true) {
        std::cout << "Enter 'h' to hit or 's' to stay: ";
        char option{};
        std::cin >> option;
        std::cout << option << '\n';

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if (option == 'h' || option == 's')
            return (option == 'h');

        std::cout << "Invalid option.\n";
    }
}


bool playBlackjack(Deck &deck, Player &player, Player &dealer) {

    std::cout << "You start with a ";

    player.dealCard(deck);

    std::cout << " and a ";
    player.dealCard(deck);
    std::cout << ". Your score is: " << player.score() << '\n';

    // Dealer
    std::cout << "The Dealer starts with a ";
    dealer.dealCard(deck);
    std::cout << " and a hidden card.\n\n";
    dealer.dealCard(deck, true);

    while (isHit()) {

        std::cout << "You received a ";
        player.dealCard(deck, false);
        std::cout << " a and your score is " << player.score() << ".\n";

        if (player.score() == BlackJackConstants::winScore)
            return true;
        else if (player.score() > BlackJackConstants::winScore) {
            return false;
        }

        std::cout << "The Dealer received a ";
        dealer.dealCard(deck, false);
        std::cout << ".\n\n";

        if (dealer.score() > BlackJackConstants::dealerMaxScore)
            break;
    }

    return (player.score() > dealer.score());
}

int main() {
    Deck deck{};
    deck.shuffle();

    Player player;
    Player dealer;

    bool playerWon{ playBlackjack(deck, player, dealer) };

    std::cout << "Your score is " << player.score()
              << " and the dealer score is " << dealer.score() << ".\n\n";

    if (playerWon)
        std::cout << "Congratulations! You won! 🎉\n\n";
    else
        std::cout << "Aww, you loose! ☹️\n\n";

    std::cout << "The entire deck was:\n";
    deck.print();

    return 0;
}