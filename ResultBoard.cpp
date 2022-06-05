#include "ResultBoard.h"

ResultBoard::ResultBoard() {
	
}

ResultBoard::~ResultBoard() {

}

ResultBoard::ResultBoard(int mx, int my,int x, int y, QWidget* parent) {
    setParent(parent);
    move(mx, my);
    resize(x, y);

    topBar = new MyLabel("background: #9D9D9D", 0, 0, 400, 23, this);
    topBar->setText(QString("ResultBoard"));

    resultBoard2 = new QWidget;
    resultBoard2->setParent(this);
    resultBoard2->move(0, 23);
    resultBoard2->resize(x, y-23);
    resultBoard2->setStyleSheet("background: #BDBDBD");

    vButton = new MyButton("Visible", 0, 0, 40, 23, this);
    QObject::connect(vButton, SIGNAL(clicked()), this, SLOT(showRB()));

    MyLabel* tl1 = new MyLabel("background: #FFFFFF", 50, 100, 50, 36, resultBoard2);
    MyLabel* tl2 = new MyLabel("background: #FFFFFF", 50, 200, 50, 36, resultBoard2);
    MyLabel* tl3 = new MyLabel("background: #FFFFFF", 50, 300, 50, 36, resultBoard2);
    tl1->setText("1st");
    tl2->setText("2nd");
    tl3->setText("3rd");

    rank1_player = new MyLabel("background: #FFFFFF", 150, 100, 100, 36, resultBoard2);
    rank2_player = new MyLabel("background: #FFFFFF", 150, 200, 100, 36, resultBoard2);
    rank3_player = new MyLabel("background: #FFFFFF", 150, 300, 100, 36, resultBoard2);

    rank1_coin = new MyLabel("background: #FFFFB9", 275, 100, 75, 36, resultBoard2);
    rank2_coin = new MyLabel("background: #FFFFB9", 275, 200, 75, 36, resultBoard2);
    rank3_coin = new MyLabel("background: #FFFFB9", 275, 300, 75, 36, resultBoard2);
}

void ResultBoard::setRank(Player* rank) {
    for (int i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            switch (rank[i].getPlayerID()) {
            case 1:
                rank1_player->setText("Player !!!");
                rank1_coin->setText(QString::number(rank[i].getCoin()));
                break;
            case 2:
                rank1_player->setText("NPC_1 !!!");
                rank1_coin->setText(QString::number(rank[i].getCoin()));
                break;
            case 3:
                rank1_player->setText("NPC_2 !!!");
                rank1_coin->setText(QString::number(rank[i].getCoin()));
                break;
            }
            break;
        case 1:
            switch (rank[i].getPlayerID()) {
            case 1:
                rank2_player->setText("Player !!!");
                rank2_coin->setText(QString::number(rank[i].getCoin()));
                break;
            case 2:
                rank2_player->setText("NPC_1 !!!");
                rank2_coin->setText(QString::number(rank[i].getCoin()));
                break;
            case 3:
                rank2_player->setText("NPC_2 !!!");
                rank2_coin->setText(QString::number(rank[i].getCoin()));
                break;
            }
            break;
        case 2:
            switch (rank[i].getPlayerID()) {
            case 1:
                rank3_player->setText("Player !!!");
                rank3_coin->setText(QString::number(rank[i].getCoin()));
                break;
            case 2:
                rank3_player->setText("NPC_1 !!!");
                rank3_coin->setText(QString::number(rank[i].getCoin()));
                break;
            case 3:
                rank3_player->setText("NPC_2 !!!");
                rank3_coin->setText(QString::number(rank[i].getCoin()));
                break;
            }
            break;
        }
    }
}

void ResultBoard::showRB() {
    if(!resultBoard2->isVisible()){
        resultBoard2->setVisible(true);
        topBar->setVisible(true);
    }
    else{
        resultBoard2->setVisible(false);
        topBar->setVisible(false);
    }
}