#ifndef bb
#define bb
#include "Poker.h"
class Deck
{
	private:
		Poker poker[52];
	public:
		Deck();
		void shuffle();
		void setCard();
		Poker deal();
};
#endif 