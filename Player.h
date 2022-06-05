#ifndef PLAYER_H
#define PLAYER_H

#include "Poker.h"

class Player {
public:
	Player();
	void setCoin(int);
	int getCoin() const;
	int getPoint() const;
	void setHandCards(Poker*);
	Poker getHandCard(int) const;
	Poker getLastHandCard() const;
	void setHandCardsSize(int);
	int getHandCardsSize() const;
	void addCard(Poker);
	void addCoin(int);
	void clearCard();
	void isBustCheck();
	bool getIsBust() const;
	bool getIsStand() const;
	int getPlayerID() const;
	void setIsBust(bool);
	void setIsStand(bool);   
	void setPlayerID(int);
private:
	int coin;
	int handCardsSize;
	Poker* handCards;
	bool isBust;
	bool isStand;
	int playerID;
};

#endif