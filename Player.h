#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"

class Player {
public:
	Player();
	~Player();
	void setCoin(int);
	int getCoin();
	void setPoint(int);
	int getPoint();
	int getPlayerCount();
	void printHandCards();
	void addCard(Deck);
	void sumPoint();
	void addCoin();
	void subtract();
	void clearCard();
private:
	int coin;
	int point;
	int handCardsSize;
	Card* handCards;
	static int playerCount;
};

#endif
