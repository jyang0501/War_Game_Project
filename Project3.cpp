#include <iostream>
#include "deck.h"
#include "player.h"
#include "card.h"
#include <string>

using namespace std;

int main() 
{
    // create a standard 52-card deck and shuffle it
    Deck deck;
    deck.createDeck();
    deck.shuffleDeck();

    vector<Card> pile;      // represents the pile of cards on the table


    // initialize two players with half of the deck each
    vector<Card> p1_cards;
    vector<Card> p2_cards;
    for (int i = 0; i < 26; i++) {
        p1_cards.push_back(deck.deal_a_card());
        p2_cards.push_back(deck.deal_a_card());
    }
    Player player1(p1_cards);
    Player player2(p2_cards);

    // start the game
    int pile_size = 0;
    while (true) 
    {
        // display the top card of each player and store the cards in the pile vector
        cout << "Player 1 plays: ";
        Card faceup1 = player1.play_a_card();
        faceup1.print();
        cout << endl;
        pile_size += 1;
        pile.push_back(faceup1);
        cout << "Player 2 plays: ";
        Card faceup2 = player2.play_a_card();
        faceup2.print();
        cout << endl;
        pile.push_back(faceup2);
        pile_size += 1;
        cout << "---------------------------------------------------------" << endl;
        cout << "There are " << pile_size << " cards on the pile." << endl;
        cout << "---------------------------------------------------------" << endl;

        // determine the winner of the round or if it's a tie
        int cmp = faceup1.compareTo(faceup2);
        if (cmp == 1) 
        { // player 1 wins
            cout << "Player 1 wins...get all cards from the current round!" << endl;


            // take cards from the pile, the winning cards, and add them to player1 deck
            vector<Card> winningCards;
            for (int i = 0; i < pile_size; i++)
            {
                winningCards.push_back(pile.back());
                pile.pop_back();
            }
            player1.addCards(winningCards);

            //set pile size to 0
            pile_size = 0;

            // check if one player finishes all their cards
            if (player1.getNumCards() <= 0)
            {
                cout << "Player 1 has 0 cards in hand!" << endl;
                cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl << endl;

                cout << "Game is over!" << endl << "Player 2 wins the game!" << endl;
                break;
            }
            else if (player2.getNumCards() <= 0)
            {
                cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
                cout << "Player 2 has 0 cards in hand!" << endl<<endl<<endl;
                cout << "Game is over!" << endl << "Player 1 wins the game!" << endl;
                break;
            }
        }
        else if (cmp == -1) 
        { // player 2 wins
            cout << "Player 2 wins...get all cards from the current round!" << endl;

            //add the cards from the pile to player 2's deck of cards
            vector<Card> winningCards;
            for (int i = 0; i < pile_size; i++)
            {
                winningCards.push_back(pile.back());
                pile.pop_back();
            }
            
            player2.addCards(winningCards);


            //set pile to 0
            pile_size = 0 ;
            
            // check if one player finishes all their cards
            if (player1.getNumCards() <= 0)
            {
                cout << "Player 1 has 0 cards in hand!" << endl;
                cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl << endl;

                cout << "Game is over!" << endl << "Player 2 wins the game!" << endl;
                break;
            }
            else if (player2.getNumCards() <= 0)
            {
                cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
                cout << "Player 2 has 0 cards in hand!" << endl << endl << endl;
                cout << "Game is over!" << endl << "Player 1 wins the game!" << endl;
                break;
            }
        }
        else { // it's a tie
            cout << "It's a tie...for this round!"<<endl;
            cout << "Each player drops three cards(face down) on the pile, then play one more card(face up)" << endl;
            
            // check if one player finishes all their cards
            if (player1.getNumCards() <= 0)
            {
                // display how many cards are on the pile
                cout << "---------------------------------------------------------" << endl;
                cout << "There are " << pile_size << " cards on the pile." << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "Player 1 has 0 cards in hand!" << endl;
                cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl << endl;

                cout << "Game is over!" << endl << "Player 2 wins the game!" << endl;
                break;
            }
            else if (player2.getNumCards() <= 0)
            {
                // display how many cards are on the pile
                cout << "---------------------------------------------------------" << endl;
                cout << "There are " << pile_size << " cards on the pile." << endl;
                cout << "---------------------------------------------------------" << endl;

                //display how many cards the players have
                cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
                cout << "Player 2 has 0 cards in hand!" << endl << endl << endl;

                //display who wins
                cout << "Game is over!" << endl << "Player 1 wins the game!" << endl;
                break;
            }

            //if it was tied the whole game
            if (pile_size == 50 && player1.getNumCards() == 1 && player2.getNumCards() == 1)
            {
                cout << "Game is over!"<<endl << "It is a tie game!" << endl;
                cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
                cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl;

            }

            //store the dropped cards in pile
            vector<Card> p1_dropped = player1.dropCards();
            for (int i = 0; i < p1_dropped.size(); i++)
            {
                pile.push_back(p1_dropped[i]);
            }

            //store the dropped cards in pile
            vector<Card> p2_dropped = player2.dropCards();
            for (int i = 0; i < p2_dropped.size(); i++)
            {
                pile.push_back(p2_dropped[i]);
            }


            pile_size += 4;
            if (player1.getNumCards() == 0 || player2.getNumCards() == 0) {
                break;
            }
            //play a card and store it in pile vector
            Card faceup3 = player1.play_a_card();
            pile.push_back(faceup3);
            
            //play a card and store it in pile vector
            Card faceup4 = player2.play_a_card();
            pile.push_back(faceup4);

            //add number of cards
            pile_size += 2;

            // check if one player finishes all their cards
            if (player1.getNumCards() <= 0)
            {
                cout << "Player 1 has 0 cards in hand!" << endl;
                cout << "Player 2 has " << player2.getNumCards() << " cards in hand!"<<endl << endl << endl;

                cout << "Game is over!" << endl << "Player 2 wins the game!" << endl;
                break;
            }
            else if (player2.getNumCards() <= 0)
            {
                cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
                cout << "Player 2 has 0 cards in hand!" << endl << endl << endl;
                cout << "Game is over!" << endl << "Player 1 wins the game!" << endl;
                break;
            }


            // display how many cards are on the pile
            cout << "---------------------------------------------------------" << endl;
            cout << "There are " << pile_size << " cards on the pile." << endl;
            
        }
        
        // display how many cards the player have
        cout << "---------------------------------------------------------" << endl;
        cout << "Player 1 has " << player1.getNumCards() << " cards left." << endl;
        cout << "Player 2 has " << player2.getNumCards() << " cards left." << endl;
       
        

        // ask if the user wants to continue to the next round
        string input;
        cout << endl;
        cout << "Do you want to continue for the next round? (N or n to quit the game)" << endl;
        
        getline(cin, input);
            if (input == "N" || input == "n") 
            {
                cout << "You choose to quit the game!"<<endl<<"Player 1 has " << player1.getNumCards() << " cards left!"<<endl<<"Player 2 has " << player2.getNumCards() << " cards left!" << endl;
                break;
            }
    }

    return 0;
}


