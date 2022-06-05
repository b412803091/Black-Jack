#include <iostream>
#include "Deck.h"
#include <ctime>
using namespace std;

Deck::Deck() {
	setCard();
}

void Deck::shuffle()
{
	for (int i = 0; i < 52; i++)
	{
		int r = rand() % 52;
		Poker temp = poker[i];
		poker[i] = poker[r];
		poker[r] = temp;
	}
}

void Deck::setCard()
{
	for (int i = 0; i < 52; i++) {
		poker[i].setAll(i / 13, i % 13+1);
	}
}

Poker Deck::deal()
{
	Poker deal = poker[0];
	for (int i = 0; i < 51; i++)
	{
		poker[i] = poker[i + 1];
	}
	return deal;
}
