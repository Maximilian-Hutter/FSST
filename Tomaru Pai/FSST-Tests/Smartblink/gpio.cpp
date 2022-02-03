#include "gpio.h"

#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    // Starte GPIO Pin Ausgänge
    m_handle = lgGpiochipOpen(0);
    int pin_state = 0;   // Setze den PinMode beim starten als "0"

    for(int pin : LEDS)     // Alle LEDs auf pin_state setzen
        lgGpioClaimOutput(m_handle, LFLAGS, pin, pin_state);
}

Gpio::~Gpio()
{
    // LED's beim schließen des Programmes auf 0 Schalten und Speicher frei geben
    int pin_state = 0;
    for(int pin : LEDS)
        lgGpioWrite(m_handle, pin, pin_state);

    lgGpiochipClose(m_handle);  // Gibt speicher frei
}

void Gpio::set(int pin, bool position)
{   // Blinker
    lgGpioWrite(m_handle, pin, position);
}

void Gpio::set(unsigned int pattern)
{   // Lauflicht
    int pos = 0;
    bool value;
    unsigned int start_status = 0b0001;  // Startwert, wie das Lauflicht anfangen soll
    for(auto pin : LEDS)
    {
        // Bitshiften um das Lauflicht zu machen
        value = start_status & pattern>>pos;
        lgGpioWrite(m_handle, pin, value);
        pos++;
    }
}
