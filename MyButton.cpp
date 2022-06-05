#include "MyButton.h"

MyButton::MyButton() {

}
MyButton::MyButton(QString text, int mx, int my, int x, int y, QWidget* parent) {
    setParent(parent);
    move(mx, my);
    resize(x, y);
    setText(text);
}

void MyButton::mousePressEvent(QMouseEvent* e) {
    emit clicked();
}