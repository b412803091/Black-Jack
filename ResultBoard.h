#pragma once
#include<QWidget>
#include<QLabel>
#include "MyButton.h"
#include "MyLabel.h"
#include "Player.h"

class ResultBoard :public QWidget {
	Q_OBJECT

public:
	ResultBoard();
	~ResultBoard();
	ResultBoard(int, int, int, int, QWidget*);
	void setRank(Player*);
private:
	MyLabel* topBar;
	QWidget* resultBoard2;
	MyButton* vButton;

	MyLabel* rank1_coin;
	MyLabel* rank2_coin;
	MyLabel* rank3_coin;
	MyLabel* rank1_player;
	MyLabel* rank2_player;
	MyLabel* rank3_player;
public slots:
	void showRB();

};