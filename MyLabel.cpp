#include "MyLabel.h"

MyLabel::MyLabel() {
	
}
MyLabel::MyLabel(QString color, int mx, int my, int x, int y, QWidget* parent) {
	setParent(parent);
	setStyleSheet(color);
	move(mx, my);
	resize(x, y);

	setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QFont font;
	font.setPointSize(16);
	font.setWeight(QFont::Bold);
	setFont(font);
}