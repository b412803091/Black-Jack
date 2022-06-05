#pragma once
#include <QPushButton>


class MyButton:public QPushButton {
	Q_OBJECT

public:
	MyButton();
	MyButton(QString,int, int, int, int, QWidget*);
protected:
	void mousePressEvent(QMouseEvent*);
signals:
	void clicked();
};