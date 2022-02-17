#include "widget.h"
#include "config.h"
#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include <QtDebug>
#include <gpio.h>

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
        QLabel* label = new QLabel("GPIO " + QString::number(pin));
        grid->addWidget(label, row, 0);
        QLabel* state = new QLabel("0");
        state->setStyleSheet("background-color: gray");
        state->setStyleSheet("color: gray");
        state->setAlignment(Qt::AlignCenter);
        grid->addWidget(state, row++, 1);
        m_pinlabels.push_back(state);
    }


    // GPIO hardware setup
    m_inputs = new Gpio(this);

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
    int i = 0;
    QString color;
    for (int pin : BUTTONS)
    {
        if (!m_inputs->get(pin))
            color = "background-color: red";
        else
            color = "background-color: black";
        m_pinlabels[i]->setStyleSheet(color);
        m_pinlabels[i++]->setText(QString::number(!m_inputs->get(pin)));
    }

}
