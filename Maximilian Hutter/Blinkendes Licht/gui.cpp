#include "gui.h"
#include <QDebug>

Gui::Gui(QMainWindow *parent) :
    QMainWindow(parent)
{
    setupUi(this);  // grafische Oberfläche
    m_leds = new Gpio(this);

    m_timer = new QTimer(this);
    m_status = false;
    //Verbinde: Quelle(Timer aus klasse Timer) -> Zeil (Toggel-Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);
}

void Gui::on_startButton_clicked()
{
    m_timer->start(1000/SpeedSlider->value());
}

void Gui::toggle()
{
    qDebug() << "toggle";
    // Aufgabe bis zum naechste Makl
    m_status = !m_status; // Signal umkehren 1 => 0 / 0 => 1

    /*
    // Variante 1:
    blinkLable->setNum(m_status);
    for (int pin : LEDS)
        m_leds->set(pin, m_status);
    */
    // Variante 2:
    unsigned int pattern = 0b1010;
    if (m_status == true)
        pattern = ~pattern;

    m_leds->set(pattern);
}

void Gui::on_SpeedSlider_valueChanged(int value)
{
    if(m_timer->isActive())
            m_timer->start(1000/value); // Silder 1...10 -> 1000... 100ms period
}
