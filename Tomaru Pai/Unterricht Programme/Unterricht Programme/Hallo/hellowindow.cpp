#include "hellowindow.h"
#include <QDebug>

HelloWindow::HelloWindow(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void HelloWindow::on_sendbutton_clicked()
{
    QString name = nameInput->text();
    qDebug() << name;
    greetinglabel->setText(name + ", du bist ein Sussy Baka");
}


iiiiiiiiiiiiiiiiiiiiiiii
qwertzuiopüasdfghjklöäyxcvbnm
