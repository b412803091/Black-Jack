#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_blackJack_QT.h"
#include "MyButton.h"
#include "Rule.h"
#include <QToolButton>
#include "ResultBoard.h"

class blackJack_QT : public QMainWindow
{
    Q_OBJECT

public:
    blackJack_QT(QWidget *parent = Q_NULLPTR);
    void buttonSetting();
    void initializeGame();
    void bet();
    void firstTurn();
    void printCardImage(int);
    void printPlayerPoint(int);
    void statusCheck();
    void npcTurn();
    void endGame();
    void coinResult();
    void clearCardsImage();
private:
    Ui::blackJack_QTClass ui;

    Rule rule;
    Deck deck;
    MyButton* hitButton;
    MyButton* standButton;
    MyButton* nextRoundButton;
    MyButton* restartButton;
    ResultBoard* resultboard;
public slots:
    void nextRound();
    void hitCard();
    void standCard();
    void restart();
};
