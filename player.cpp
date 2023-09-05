#include "Player.h"
#include <stdlib.h>

using namespace std;

// default constructor 
Player::Player()
{
    numCards = 0;       //number of cards in player's hand = 0
    vector<Card> cards; //create an empty vector of cards
}

// alternative constructor 
Player::Player(vector<Card> ini_cards)
{
    numCards = ini_cards.size();    //set numCards to number of cards in vector
    cards = ini_cards;  //sets cards equal to inital set of cards
}

// return how many cards player holds currently 
int Player::getNumCards() const 
{
    return numCards;
}

// player plays one card at the front of cards at hand 
Card Player::play_a_card() 
{

    Card playCard;

    playCard = cards.front();    //sets playCard to the card on top of deck
    cards.erase(cards.begin());     //removes card from pile
    numCards = numCards - 1;        //subtracts 1 from number of cards

    return playCard;
}

// player wins and adds winning cards to the end of the pile at hand  
void Player::addCards(vector<Card> winningCards) {
    for (int i = 0; i < winningCards.size(); i++) {
        cards.push_back(winningCards[i]);   //adds winning cards to deck
        numCards++; //adds 1 to numCards
    }
}

// player drops TWO cards from the front of pile at hand faced-down
// when there is a tie 
vector<Card> Player::dropCards() {
    vector<Card> dropCards;
    Card droppedCards;

    //if there are less than 2 cards, play cards and return empty vector
    if (cards.size() < 2) {
        for (int a = 0; a < cards.size(); a++)
            play_a_card();
        return dropCards;
    }
    //otherwise, return vector of 2 cards dropped
    else {
        for (int j = 0; j < 2; j++) {
            droppedCards = play_a_card();
            dropCards.push_back(droppedCards);
        }
        return dropCards;
    }
}

// display cards at player's hand 
void Player::print() const 
{

    //prints 8 cards on 1 line
    for (int z = 1; z <= cards.size(); z++) 
    {
        if (z % 8 == 0) {
            cards[z - 1].print();
            cout << "   " << endl;
        }
        else 
        {
            cards[z - 1].print();
            cout << "   ";
        }
    }
    cout << endl;
}