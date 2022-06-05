#include "Player.h"
#include<iostream>
using namespace std;

Player::Player() :coin(1000), handCardsSize(0), handCards(new Poker[handCardsSize])
				,isBust(false),isStand(false),playerID(0) {

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
		if (handCards[i].getNumber() < 11 && handCards[i].getNumber() > 1)
			point += handCards[i].getNumber();
		else if (handCards[i].getNumber() > 10)
			point += 10;
	}
	for (int i = 0; i < handCardsSize; i++) {
		if (handCards[i].getNumber() == 1 && point < 11)
			point += 11;
		else if (handCards[i].getNumber() == 1)
			point++;
	}
	return point;
}
void Player::setHandCards(Poker* newH) {
	handCards = newH;
}
Poker Player::getHandCard(int index) const {
	if (index >= 0 && index < handCardsSize)
		return handCards[index];
	else
		NULL;
}
Poker Player::getLastHandCard() const {
	return handCards[handCardsSize - 1];
}
void Player::setHandCardsSize(int newS) {
	handCardsSize = newS;
}
int Player::getHandCardsSize() const {
	return handCardsSize;
}
void Player::addCard(Poker card) {
	Poker* old = handCards;
	handCards = new Poker[++handCardsSize];
	if(handCardsSize!=1){
		for (int i = 0; i < handCardsSize; i++) {
			handCards[i] = old[i];
		}
	}
	handCards[handCardsSize -1] = card;
	delete old;
}
void Player::addCoin(int much) {
	coin += much;
}
void Player::clearCard() {
	handCardsSize = 0;
	delete handCards;
	handCards = new Poker[handCardsSize];
}
void Player::isBustCheck() {
	if (getPoint() > 21) {
		setIsBust(true);
		setIsStand(true);
	}
}
int Player::getPlayerID() const {
	return playerID;
}
bool Player::getIsBust() const {
	return isBust;
}
bool Player::getIsStand() const {
	return isStand;
}
void Player::setIsBust(bool x) {
	isBust = x;
}
void Player::setIsStand(bool x) {
	isStand = x;
}
void Player::setPlayerID(int newID) {
	playerID = newID;
}