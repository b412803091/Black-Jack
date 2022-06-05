#ifndef aa
#define aa
#include <string>
using namespace std;
class Poker
{
private:
	int cardColor;
	int cardNumber;
public:
	void setAll(int, int);
	void setColor(int);
	void setNumber(int);
	const int getColor();
	const int getNumber();
};
#endif 