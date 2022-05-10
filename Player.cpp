#include "Player.h"
#include<iostream>
using namespace std;

int Player::playerCount = 0;

Player::Player() :coin(1000), handCardsSize(0), handCards(new Card[handCardsSize]) {
	playerCount++;
}
Player::~Player() {
	playerCount--;
}
void Player::setCoin(int newC) {
	coin = newC;
}
int Player::getCoin() const {
	return coin;
}
int Player::getPoint() const {
	int point = 0;
	for (int i = 0; i < handCardsSize; i++) {
		point += handCards[i].Point();
	}
	return point;
}
int Player::getPlayerCount() const {
	return playerCount;
}
void Player::printHandCards() const {
	for (int i = 0; i < handCardsSize; i++) {
		cout << handCards[i].getSuit() << " " << handCards[i].getSymbol() << endl;
	}
}
void Player::addCard(Deck& deck) {
	Card* old = handCards;
	handCards = new Card[++handCardsSize];
	for (int i = 0; i < handCardsSize; i++) {
		handCards[i] = old[i];
	}
	handCards[handCardsSize - 1] = deck.getLastCard();
	delete old;
}
void Player::addCoin(int much) {
	coin += much;
}
void Player::subtractCoin(int much) {
	coin -= much;
}
void Player::clearCard() {
	handCardsSize = 0;
	handCards = new Card[++handCardsSize];
}
