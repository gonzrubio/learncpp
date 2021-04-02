/* Summary */
// Classes allow us to create cutom data types that bundle data and functions together. 
// Members of the class are accessed using the . operator or ->  if accessing through a pointer.
// Encapsulation is the process of making all the member data private, so they can not be accessed directly.
// Member initializer lists allows us to initializa our member variables throught the constructor.
// Constructors are allowed to call other constructors (delegating constructors/constructor chaining).
// To avoid circular depedencies, put class definitions in a header file and member function definitions
// in a .cpp file of the same name as the class.
// Member functions should be made const if they do not modify the state of the object. Const class objects
// can only call const member funcitons.
// Static member variables are shared across all class objects and should be accessed through the scope resolution operator.
// Static member functions are member functions that have no *this pointer. Static member functions
// can only acess static member variables.
// We can create anonymous class objects for the purpose of evaluating in an expression, or passing a return value.

#include "Card.h"
#include "Deck.h"
#include "HelloWorld.h"
#include "Monster.h"
#include "MonsterGenerator.h"
#include "Player.h"
#include "Point2d.h"
#include <iostream>

void question1() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}

void question2() {
    HelloWorld hello{};
    hello.print();
}

void question3() {
    Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();
}

bool playerWantsHit() {
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";
        char ch{};
        std::cin >> ch;

        switch (ch) {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player) {
    while (true)     {
        std::cout << "You have: " << player.score() << '\n';

        if (player.isBust()) {
            return true;
        } else {
            if (playerWantsHit()) {
                player.drawCard(deck);
            } else {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer) {
    while (dealer.score() < minimumDealerScore) {
        dealer.drawCard(deck);
    }
    return dealer.isBust();
}

bool playBlackjack(Deck& deck) {
    Player dealer{};
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    if (playerTurn(deck, player)) {
        return false;
    }

    if (dealerTurn(deck, dealer)) {
        return true;
    }
    return (player.score() > dealer.score());
}

void question4() {
    Deck deck{};
    deck.shuffle();

    if (playBlackjack(deck)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
}

int main() {
    //question1();
    //question2();
    //question3();
    question4();
}
