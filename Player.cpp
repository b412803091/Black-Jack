#include "Player.h"
#include<iostream>
using namespace std;

int Player::playerCount = 0;

Player::Player() :coin(1000), point(0), handCardsSize(0), handCards(new Card[handCardsSize]) {
	playerCount++;
}
Player::~Player() {
	playerCount--;
}
void Player::setCoin(int newC) {
	coin = newC;
}
int Player::getCoin() {
	return coin;
}
void Player::setPoint(int newP) {
	point = newP;
}
int Player::getPoint() {
	return point;
}
int Player::getPlayerCount() {
	return playerCount;
}
void Player::printHandCards() {
	for (int i = 0; i < handCardsSize; i++) {
		cout << handCards[i].getSuit() << " " << handCards[i].getSymbol() << endl;
	}
}
void Player::addCard(Deck deck) {
	Card* old = handCards;
	handCards = new Card[++handCardsSize];
	for (int i = 0; i < handCardsSize; i++) {
		handCards[i] = old[i];
	}
	handCards[handCardsSize - 1] = deck.getLastCard();
	delete old;
}
void Player::sumPoint() {
	for (int i = 0; i < handCardsSize; i++) {
		point += handCards[i].Point();
	}
}
void Player::addCoin() {
	coin += 100;
}
void Player::subtract() {
	coin -= 100;
}
void Player::clearCard() {
	handCardsSize = 0;
	handCards = new Card[++handCardsSize];
}
