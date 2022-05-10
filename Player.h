#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"

class Player {
public:
	Player();
	~Player();
	void setCoin(int);
	int getCoin() const;
	int getPoint() const;
	int getPlayerCount() const;
	void printHandCards() const;
	void addCard(Deck&);
	void addCoin(int);
	void subtractCoin(int);
	void clearCard();
private:
	int coin;
	int handCardsSize;
	Card* handCards;
	static int playerCount;

	friend class BlackJack;
};

#endif
