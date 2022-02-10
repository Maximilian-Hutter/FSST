#include "widget.h"
#include "config.h"
#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Button Monitor");
    resize(600,200);
    // Wenn man nur Widget vorkonfiguriert (was wir machen sollten)
    // QGridLayout* grid = new QGridLayout(this);

    // wenn man window statt widget konfiguriert...
    QWidget* centralwidget = new QWidget(this);
    this->setCentralWidget(centralwidget);
    QGridLayout* grid = new QGridLayout(centralwidget);

    int row = 0;
    for (int pin : BUTTONS) {
        QLabel* led = new QLabel("GPIO " + QString::number(pin));
        grid->addWidget(led, row++, 0);
        m_pinlabels.push_back(led);
    }

    // Timer Setup
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Widget::refreshLabels); // Verbindung timer mit dem Widget
    m_timer->start(TREFRESH);   //periodischer Timer, laeuft alle TREFRESH ms ab
}

Widget::~Widget()
{

}

void Widget::refreshLabels()
{
    qDebug() << "timer!";
}
