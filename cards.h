//cards.h
//Authors: Brian Ozawa Burns, 05/09/2021
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <string>
using namespace std;

#endif

class Hand{
    private:

        string playerName;

        struct Card{
            char suit = '\0';
            int rank = 0;
            Card *nextCard = nullptr;

            // Realized after doing hours of work that input is of type string
            // and that 10 is actually the single character '0'
            // meaning I would have approached this pa completely differently if I knew
            // One example: I would have simply made rank a char, then I wouldn't have needed
            // to write the conversion functions convertFaceCardValue and convertValueCardFace
            bool operator==(const Card& c);
            bool operator!=(const Card& c);
        };

        Card *firstCard; // head
        Card *lastCard; // tail

        void printMatch(Hand& source, Card *match); // source is opponent's Hand, function called from within findMatch(Hand& source)
        
    public:
        // Constructors
        Hand(); // Default contructor
        Hand(string n); // Constructor with playerName argument
        Hand(Hand& source); // Copy Constructor
        Hand& operator=(const Hand& source); // Copy Assignment Operator
        void setPlayerName(string n); // change player's name
        void appendCard(char s, char r); // Append a Card to hand by passing its values as arguments (more compatible with how input files are structured)

        void printCards(); // Prints Hand in form "suit rank\nsuit rank\n...etc"

        // Function to convert jacks and queens and kings and aces to numerical rank
        // Can sort of ignore these, just know they ensure values being output are correct (ex. 'k' instead of 13)
        int convertFaceCardValue(char f); // returns 11 if rank was 'j', 12 if 'q', 13 if 'k',  1 if 'a', and -1 if anything else
        char convertValueCardFace(int v); // Opposite of convertFaceCardValue

        // getCard functions can be utilized as contains functions (to check if a player's Hand contains a card or not)
        Card* getCard(Card *c) const; // Returns pointer to the Card if found, nullptr otherwise
        Card* getCard(char s, int r) const; // Returns pointer to the Card if found, nullptr otherwise
        Card* getPrevCard(Card *c) const; // Returns pointer to Card's precessor if found, nullptr, otherwise
        Card* getPrevCard(char s, int r) const; // Returns pointer to Card's precessor if found, nullptr, otherwise
        
        bool removeCard(Card *c); // Removes a card from Player's Hand, returns true if card is removed, false otherwise
        bool removeCard(char s, int r); // Removes a card from Player's Hand, returns true if card is removed, false otherwise

        bool displayMatch(Hand& source); // source is opponent's Hand, return true if match found, print the match found, call removeCard for each player, false if no match found
        bool isMatch(Hand& source); // return true if a match exists, false otherwise
        bool isEmpty(); // return true if Hand is empty, false if contains one or more Cards

        ~Hand(); // Destructor




        // Practice implementation functions
        void appendCard(Card *newCard); // Append an existing Card to Hand
        void appendCard(char s, int r); // Append a Card to hand by passing its values as arguments

        // Insert functions are not necessary to use (created them just because I felt like it)
        void insertCard(Card *newCard); // Insert an existing Card to Hand
        void insertCard(char s, int r); // Insert a Card to hand by passing its values as arguments

        // get functions for troubleshooting and unit testing
        string getPlayerName() const; // returns playerName
        int getRank() const; // returns rank of first Card
        char getSuit() const; // returns suit of first Card
        Card* getNextCard() const; // returns nextCard

};

/*
class Player{
    private:
        string nameOfPlayer;
        Hand *playerCards;
    
    public:
        // Constructors
        Player(); // Default constructor
        Player(string n); // Initialize by name, default values for Hand
        Player(Hand *newHand); // Initialize by Hand, empty string for name
        Player(string n, Hand *newHand); // Initialize with specified name and Hand

        // Relevant Hand functions
        
        void printCards() const;
        
        void appendCard(int val);
        void appendCard(Card newCard);
        void removeCard(int val);
        void removeCard(Card cardToRemove);
        bool findMatch(Player otherPlayer) const;
        
    
};
*/

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
