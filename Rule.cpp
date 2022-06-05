#include "Rule.h"
#include <algorithm>
using namespace std;

Rule::Rule():player(new Player[4])
{
	
}

Rule::Rule(Player* play)
{
	setPlay(play);
}

Player* Rule::getPlay() const
{
	return player;
}

Player Rule::getPlay(int index) const
{
	return player[index];
}

void Rule::setPlay(Player* player)
{
	this->player = player;
}

void Rule::setPlay(Player player, int index)
{
	this->player[index] = player;
}

int Rule::compare(int index)
{
	player[index].isBustCheck();
	player[3].isBustCheck();

	if (!player[index].getIsBust() && !player[3].getIsBust()) {
		if (player[index].getPoint() == player[3].getPoint())
			return 0;
		else if (player[index].getPoint() > player[3].getPoint())
			return 1;
		else
			return -1;
	}
	else if (player[index].getIsBust() && !player[3].getIsBust())
		return -1;
	else if (!player[index].getIsBust() && player[3].getIsBust())
		return 1;
	else if (player[index].getIsBust() && player[3].getIsBust())
		return 0;
}

Player* Rule::ranking()
{
	Player* play = new Player[3];
	for (int i = 0; i < 3; i++) {
		play[i] = player[i];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 2; j >= i + 1; j--)
		{
			if (play[j].getCoin() > play[j - 1].getCoin())
			{
				Player tmp = play[j];
				play[j] = play[j - 1];
				play[j - 1] = tmp;
			}
		}
	}
	return play;
}

void Rule::action(int index,Deck deck)
{
	if (player[index].getPoint() <= 10)
		player[index].addCard(deck.deal());
	else if (10 < player[index].getPoint() && player[index].getPoint() <= 13) {
		int s = rand() % 100;
		if (0 <= s && s < 80) player[index].addCard(deck.deal());
		else player[index].setIsStand(true);
	}
	else if (13 < player[index].getPoint() && player[index].getPoint() <= 16) {
		int s = rand() % 100;
		if (0 <= s && s < 60) player[index].addCard(deck.deal());
		else player[index].setIsStand(true);
	}
	else if (16 < player[index].getPoint() && player[index].getPoint() <= 19) {
		int s = rand() % 100;
		if (0 <= s && s < 40) player[index].addCard(deck.deal());
		else player[index].setIsStand(true);
	}
	else player[index].setIsStand(true);
}