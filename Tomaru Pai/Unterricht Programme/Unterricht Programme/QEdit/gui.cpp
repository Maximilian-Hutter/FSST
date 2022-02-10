#include "gui.h"
#include <QDebug>

GUI::GUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_timer = new QTimer();
    // Verbinde: Quelle (Timeout aus klasse Timer) -> Ziel (Toggle Funktion aus der Klasse GUI)
    connect(m_timer, &QTimer::timeout, this, &GUI::toggle);
}

void GUI::on_startButton_clicked()
{
    m_timer -> start(1000);
}
void GUI::toggle()
{
    m_status = !m_status;
    if (m_status)
        blinkLabel->setNum(1);
    else
        blinkLabel->setNum(0);
}
