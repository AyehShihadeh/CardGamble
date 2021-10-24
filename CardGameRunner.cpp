//create a program that hits a player with a card and compares it to their previous card.
//if new card is larger, player gets 2 points. If new card is smaller, player loses a point.
//when do you know when to stop gambeling your points?

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<ctime>
#include<Windows.h>
using namespace std;

int counter = 0, points = 0;

class Card {
public:
	string face, suit, color;
};

class Deck {
private:
	Card *pDeck = new Card[52];
	Card *hand = new Card[52];

	string face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	string suit[4] = { "Heart", "Diamond", "Club", "Spade" };
	string color[2] = { "Red", "Black" };

public:

	void fillDeck() {
		cout << "\nFilling the deck...\n";
		Sleep(1000);
		for (int i = 0; i < 52; i++) {
			pDeck[i].face = face[i % 13];
			pDeck[i].suit = suit[i / 13];
			pDeck[i].color = color[i / 26];
		}
	}

	void showDeck() {
		cout << "\nCurrnet state of the deck...\n";
		Sleep(1000);
		for (int i = 0; i < 52; i++) {
			if (i % 4 == 0) cout << endl;
			cout << left << setw(6) << pDeck[i].face << " of " << setw(12) << pDeck[i].suit;

		}
	}



	void shuffleDeck() {
		cout << "\nShuffling the deck...\n";
		Sleep(1000);
		Card temp;
		srand(time(0));
		for (int i = 0; i < 52; i++) {
			int j = rand() % 52; //get a random number from 0-51
			temp = pDeck[i];
			pDeck[i] = pDeck[j]; //one card is missing(which is temp) and two cards are the same
			pDeck[j] = temp; //putting temp back into the deck

		}

	}

	void showCard() {

		cout << "\n\nThis is your current card: " << left << setw(6) << pDeck[counter].face <<
			"of " << setw(12) << pDeck[counter].suit;
		Sleep(1000);

	}

	string getCard(int counter) {


		Card temp = pDeck[counter];
		return temp.face;
	}



	char compareCard(string c, string p) {

		if (c == "Ace" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven" || p == "Eight" || p == "Nine" || p == "Ten" || p == "Jack" || p == "Queen" || p == "King"))
			return 'b';
		else if (c == "King" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven" || p == "Eight" || p == "Nine" || p == "Ten" || p == "Jack" || p == "Queen"))
			return 'b';
		else if (c == "Queen" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven" || p == "Eight" || p == "Nine" || p == "Ten" || p == "Jack"))
			return 'b';
		else if (c == "Jack" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven" || p == "Eight" || p == "Nine" || p == "Ten"))
			return 'b';
		else if (c == "Ten" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven" || p == "Eight" || p == "Nine"))
			return 'b';
		else if (c == "Nine" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven" || p == "Eight"))
			return 'b';
		else if (c == "Eight" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six" || p == "Seven"))
			return 'b';
		else if (c == "Seven" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five" || p == "Six"))
			return 'b';
		else if (c == "Six" && (p == "Deuce" || p == "Three" || p == "Four" || p == "Five"))
			return 'b';
		else if (c == "Five" && (p == "Deuce" || p == "Three" || p == "Four"))
			return 'b';
		else if (c == "Four" && (p == "Deuce" || p == "Three"))
			return 'b';
		else if (c == "Three" && (p == "Deuce"))
			return 'b';

		else if (p == c)
			cout << "**EQUAL CARDS, NO POINTS GIVEN OR TAKEN**";

		else return 's';

	}
};

int main() {

	Deck deck1; //asign each a value then pass to compare function after they have a value
	//we wont be including these function calls when the code is finished. 
	//it's just here to show that shuffling the deck works
	deck1.fillDeck();
	//deck1.showDeck(); 
	deck1.shuffleDeck();
	//deck1.showDeck(); 


	cout << "\n\n";

	char hit;

	cout << "Every higher card that you are hit with gives you a point. Every lower card deducts a point.-"
		<< " \nHow many points can you rack up and do you know when to stop?";
	Sleep(1000);
	cout << "\n\n. . .GAME STARTING. . .";
	Sleep(1000);
	deck1.showCard();
	cout << "\nHit? (y/n): ";
	Sleep(1000);
	cin >> hit;



	while (hit == 'y' || hit == 'Y') {

		counter++;
		string prev = deck1.getCard(counter - 1);
		string current = deck1.getCard(counter);

		deck1.showCard();


		//then switch statement to determine whether player gains points or gets a point deducted:
		switch (deck1.compareCard(current, prev)) {

		case'b': //b stands for bigger
			points+=2;
			break;
		case's': //s stands for smaller
			points--;
			break;
		}

		cout << "\nPOINTS: " << points << endl;
		cout << "\nHit? (y/n): ";
		cin >> hit;
		if (hit == 'n' || hit == 'N')
			cout << "Thanks for playing! Here is your final score: " << points;
	}


	cout << "\n\n";
	system("PAUSE");
	return 0;
}

