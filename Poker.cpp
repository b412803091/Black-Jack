#include"Poker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Poker::setNumber(int nNumber)
{
	cardNumber = nNumber;
}
void Poker::setColor(int nColor)
{
	cardColor = nColor;
}
const int Poker::getNumber()
{
	return cardNumber;
}
const int Poker::getColor()
{
	return cardColor;
}
void Poker::setAll(int nColor, int nNumber)
{
	cardNumber = nNumber;
	cardColor = nColor;
}

