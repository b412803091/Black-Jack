#pragma once
#include<QLabel>

class MyLabel:public QLabel  {
public:
	MyLabel();
	MyLabel(QString, int, int, int, int, QWidget*);
};