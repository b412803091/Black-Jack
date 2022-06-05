#include "blackJack_QT.h"
#include <QGroupBox>
#include <QLabel>

int turnCount = 0;

blackJack_QT::blackJack_QT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    buttonSetting();
    initializeGame();
}

void blackJack_QT::buttonSetting() {
    hitButton = new MyButton(QString("Hit"), 750, 175, 75, 36, this);
    QObject::connect(hitButton, SIGNAL(clicked()), this, SLOT(hitCard()));
    standButton = new MyButton(QString("Stand"), 850, 175, 75, 36, this);
    QObject::connect(standButton, SIGNAL(clicked()), this, SLOT(standCard()));
    nextRoundButton = new MyButton(QString("Next \n Round"), 750, 230, 75, 60, this);
    QObject::connect(nextRoundButton, SIGNAL(clicked()), this, SLOT(nextRound()));
    restartButton = new MyButton(QString("Restart"), 750, 310, 175, 36, this);
    QObject::connect(restartButton, SIGNAL(clicked()), this, SLOT(restart()));

    QFont font;
    font.setPointSize(16);
    font.setWeight(QFont::Bold);
    hitButton->setFont(font);
    standButton->setFont(font);
    nextRoundButton->setFont(font);
    restartButton->setFont(font);
}

void blackJack_QT::initializeGame() {
    turnCount = 0;

    hitButton->setEnabled(false);
    standButton->setEnabled(false);
    restartButton->setEnabled(false);

    Player p;
    for (int i = 0; i < 4; i++) {
        p = Player();
        p.setPlayerID(i + 1);
        rule.setPlay(p, i);
    }

    ui.playerCoinLabel1->setText(QString::number(rule.getPlay(0).getCoin()));
    ui.playerCoinLabel1->setStyleSheet("background: #FFFFB9");
    ui.playerCoinLabel2->setText(QString::number(rule.getPlay(0).getCoin()));
    ui.playerCoinLabel2->setStyleSheet("background: #FFFFB9"); 
    ui.playerCoinLabel3->setText(QString::number(rule.getPlay(0).getCoin()));
    ui.playerCoinLabel3->setStyleSheet("background: #FFFFB9");

    ui.pointLabel1->setStyleSheet("background: #BEBEBE");
    ui.pointLabel2->setStyleSheet("background: #BEBEBE");
    ui.pointLabel3->setStyleSheet("background: #BEBEBE");
    ui.pointLabel4->setStyleSheet("background: #BEBEBE");

    ui.compareLabel1->setVisible(false);
    ui.compareLabel2->setVisible(false);
    ui.compareLabel3->setVisible(false);

    resultboard = new ResultBoard(300, 100, 400, 500, this);
    resultboard->setVisible(false);

    clearCardsImage();
    for (int i = 0; i < 4; i++) {
        printPlayerPoint(i);
    }

    bet();
}

void blackJack_QT::bet() {
    ui.radioButton->setEnabled(true);
    ui.radioButton_2->setEnabled(true);
    ui.radioButton_3->setEnabled(true);

    nextRoundButton->setEnabled(true);
}

void blackJack_QT::nextRound() {
    ++turnCount;
    ui.radioButton->setEnabled(false);
    ui.radioButton_2->setEnabled(false);
    ui.radioButton_3->setEnabled(false);
    nextRoundButton->setEnabled(false);

    Player p;
    int coin, num;
    for (int i = 0; i < 4; i++) {
        coin = rule.getPlay(i).getCoin();
        num = rule.getPlay(i).getPlayerID();
        p = Player();
        p.setPlayerID(num);
        p.setCoin(coin);
        rule.setPlay(p, i);
    }
    clearCardsImage();
    firstTurn();
}

void blackJack_QT::firstTurn() {
    deck.setCard();
    deck.shuffle();

    ui.compareLabel1->setVisible(false);
    ui.compareLabel2->setVisible(false);
    ui.compareLabel3->setVisible(false);
    hitButton->setEnabled(true);
    standButton->setEnabled(true);

    Player p1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            p1 = rule.getPlay(j);
            p1.addCard(deck.deal());
            rule.setPlay(p1, j);

            printCardImage(j);
        }
    }
}

void blackJack_QT::hitCard() {
    Player p = rule.getPlay(0);
    p.addCard(deck.deal());
    rule.setPlay(p, 0);

    printCardImage(0);
    statusCheck();
}

void blackJack_QT::standCard() {
    Player p = rule.getPlay(0);
    p.setIsStand(true);
    rule.setPlay(p, 0);

    statusCheck();
}

void blackJack_QT::printCardImage(int playerN) {
    QImage image(QString("./image/1.png"));
    image = image.copy(90 * (rule.getPlay(playerN).getLastHandCard().getNumber()-1),
                                131 * rule.getPlay(playerN).getLastHandCard().getColor(), 90, 131);
    switch (playerN) {
    case 0:
        switch (rule.getPlay(playerN).getHandCardsSize()) {
        case 1:
            ui.p1_c1->setPixmap(QPixmap::fromImage(image));
            break;
        case 2:
            ui.p1_c2->setPixmap(QPixmap::fromImage(image));
            break;
        case 3:
            ui.p1_c3->setPixmap(QPixmap::fromImage(image));
            break;
        case 4:
            ui.p1_c4->setPixmap(QPixmap::fromImage(image));
            break;
        case 5:
            ui.p1_c5->setPixmap(QPixmap::fromImage(image));
            break;
        }
        break;
    case 1:
        switch (rule.getPlay(playerN).getHandCardsSize()) {
        case 1:
            ui.p2_c1->setPixmap(QPixmap::fromImage(image));
            break;
        case 2:
            ui.p2_c2->setPixmap(QPixmap::fromImage(image));
            break;
        case 3:
            ui.p2_c3->setPixmap(QPixmap::fromImage(image));
            break;
        case 4:
            ui.p2_c4->setPixmap(QPixmap::fromImage(image));
            break;
        case 5:
            ui.p2_c5->setPixmap(QPixmap::fromImage(image));
            break;
        }
        break;
    case 2:
        switch (rule.getPlay(playerN).getHandCardsSize()) {
        case 1:
            ui.p3_c1->setPixmap(QPixmap::fromImage(image));
            break;
        case 2:
            ui.p3_c2->setPixmap(QPixmap::fromImage(image));
            break;
        case 3:
            ui.p3_c3->setPixmap(QPixmap::fromImage(image));
            break;
        case 4:
            ui.p3_c4->setPixmap(QPixmap::fromImage(image));
            break;
        case 5:
            ui.p3_c5->setPixmap(QPixmap::fromImage(image));
            break;
        }
        break;
    case 3:
        switch (rule.getPlay(playerN).getHandCardsSize()) {
        case 1:
            ui.bank_c1->setPixmap(QPixmap::fromImage(image));
            break;
        case 2:
            ui.bank_c2->setPixmap(QPixmap::fromImage(image));
            break;
        case 3:
            ui.bank_c3->setPixmap(QPixmap::fromImage(image));
            break;
        case 4:
            ui.bank_c4->setPixmap(QPixmap::fromImage(image));
            break;
        case 5:
            ui.bank_c5->setPixmap(QPixmap::fromImage(image));
            break;
        }
        break;
    }
    printPlayerPoint(playerN);
}

void blackJack_QT::printPlayerPoint(int playerN) {
    switch (playerN) {
    case 0:
        ui.pointLabel1->setText(QString::number(rule.getPlay(playerN).getPoint()));
        break;
    case 1:
        ui.pointLabel2->setText(QString::number(rule.getPlay(playerN).getPoint()));
        break;
    case 2:
        ui.pointLabel3->setText(QString::number(rule.getPlay(playerN).getPoint()));
        break;
    case 3:
        ui.pointLabel4->setText(QString::number(rule.getPlay(playerN).getPoint()));
        break;
    }
}

void blackJack_QT::statusCheck() {
    Player p1 = rule.getPlay(0);
    p1.isBustCheck();
    rule.setPlay(p1, 0);

    if (rule.getPlay(0).getIsBust() || rule.getPlay(0).getHandCardsSize() > 4) {
        hitButton->setEnabled(false);
        p1 = rule.getPlay(0);
        p1.setIsStand(true);
        rule.setPlay(p1, 0);
    }
    if (rule.getPlay(0).getPoint() == 21) {
        hitButton->setEnabled(false);
    }
    if (rule.getPlay(0).getIsStand()){
        hitButton->setEnabled(false);
        standButton->setEnabled(false);

        npcTurn();
    }
}

void blackJack_QT::npcTurn() {
    for (int i = 1; i < 4; i++) {
        while (!rule.getPlay(i).getIsStand()) {
            rule.action(i, deck);
            printCardImage(i);
        }
    }

    QImage win(QString("./image/win.png"));
    QImage draw(QString("./image/draw.png"));
    QImage lose(QString("./image/lose.png"));
    for (int i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            switch (rule.compare(i)) {
            case 1:
                ui.compareLabel1->setPixmap(QPixmap::fromImage(win));
                break;
            case 0:
                ui.compareLabel1->setPixmap(QPixmap::fromImage(draw));
                break;
            case -1:
                ui.compareLabel1->setPixmap(QPixmap::fromImage(lose));
                break;
            }
            break;
        case 1:
            switch (rule.compare(i)) {
            case 1:
                ui.compareLabel2->setPixmap(QPixmap::fromImage(win));
                break;
            case 0:
                ui.compareLabel2->setPixmap(QPixmap::fromImage(draw));
                break;
            case -1:
                ui.compareLabel2->setPixmap(QPixmap::fromImage(lose));
                break;
            }
            break;
        case 2:
            switch (rule.compare(i)) {
            case 1:
                ui.compareLabel3->setPixmap(QPixmap::fromImage(win));
                break;
            case 0:
                ui.compareLabel3->setPixmap(QPixmap::fromImage(draw));
                break;
            case -1:
                ui.compareLabel3->setPixmap(QPixmap::fromImage(lose));
                break;
            }
            break;
        }
    }
    ui.compareLabel1->setVisible(true);
    ui.compareLabel2->setVisible(true);
    ui.compareLabel3->setVisible(true);
    coinResult();

    if (turnCount < 5)
        bet();
    else
        endGame();
}

void blackJack_QT::endGame() {
    restartButton->setEnabled(true);
    resultboard->setVisible(true);
    resultboard->setRank(rule.ranking());
}

void blackJack_QT::coinResult() {
    Player p;
    int coins = 0;
    if (ui.radioButton->isChecked())
        coins = 50;
    else if (ui.radioButton_2->isChecked())
        coins = 100;
    else if (ui.radioButton_3->isChecked())
        coins = 200;
    p = rule.getPlay(0);
    p.addCoin(coins * rule.compare(0));
    rule.setPlay(p, 0);

    for (int i = 1; i < 3; i++) {
        coins = (rand() % 4 + 1) * 50;
        p = rule.getPlay(i);
        p.addCoin(coins * rule.compare(i));
        rule.setPlay(p, i);
    }
    ui.playerCoinLabel1->setText(QString::number(rule.getPlay(0).getCoin()));
    ui.playerCoinLabel2->setText(QString::number(rule.getPlay(1).getCoin()));
    ui.playerCoinLabel3->setText(QString::number(rule.getPlay(2).getCoin()));
}

void blackJack_QT::clearCardsImage() {
    ui.p1_c1->clear();
    ui.p1_c2->clear();
    ui.p1_c3->clear();
    ui.p1_c4->clear();
    ui.p1_c5->clear();

    ui.p2_c1->clear();
    ui.p2_c2->clear();
    ui.p2_c3->clear();
    ui.p2_c4->clear();
    ui.p2_c5->clear();

    ui.p3_c1->clear();
    ui.p3_c2->clear();
    ui.p3_c3->clear();
    ui.p3_c4->clear();
    ui.p3_c5->clear();

    ui.bank_c1->clear();
    ui.bank_c2->clear();
    ui.bank_c3->clear();
    ui.bank_c4->clear();
    ui.bank_c5->clear();
}

void blackJack_QT::restart() {
    delete resultboard;
    initializeGame();
}