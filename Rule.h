#pragma once
#include "Deck.h"
#include "Player.h"
class Rule {
private:
	Player* player;
public:
	Rule();
	Rule(Player*);
	Player* getPlay() const;
	Player getPlay(int) const;
	void setPlay(Player*);
	void setPlay(Player, int);
	
	int compare(int);
	Player* ranking();
	void action(int, Deck);
};