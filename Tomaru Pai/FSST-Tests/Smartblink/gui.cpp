#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);


    m_timer = new QTimer();
    m_status = false;
    //Verbinde: Quelle(Timer aus klasse Timer) -> Zeil (Toggel-Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle); // verbindung Timer -> Gui Label
    m_timer->start(TIMEOUT);
}

void Gui::on_speedSlider_valueChanged(int value)
{
    m_timer->start(1000/value);
}

void Gui::on_blinkButton_clicked()
{
    m_mode = 1;
}

void Gui::on_lauflichtButton_clicked()
{
    m_mode = 0;
    count = 1;
}

void Gui::toggle()
{
    m_status = !m_status;

    switch (m_mode)
    {
        case 0: // Lauflicht
            m_leds->set(count);
            if(count < 8)
            {
                count = count * 2;
            }
            else {
                count = 1;
            }
        break;
        case 1: // Blink
            label -> setNum(m_status); // Gibt aus ob die LED an oder aus ist.
            if(m_status == 1)
            {
                count = 15;
            }else {
                count = 0;
            }
            m_leds->set(count);
        break;
        default: break;
    }
}
