#include "gpio.h"
#include <lgpio.h>
#include "config.h"

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    // initialization gpio
    m_handle = lgGpiochipOpen(CHIP);
    int init_state = 0;
    for (int pin : LEDs)
        lgGpioClaimOutput(m_handle, FLAGS, pin, init_state);
}

Gpio::~Gpio()
{
    // LED's Ausschalten
    int state = 0;
    for (int pin : LEDs)
        lgGpioWrite(m_handle, pin, state);
    lgGpiochipClose(m_handle);
}

void Gpio::set(int pin, int state)
{
    lgGpioWrite(m_handle, pin, state);
}

void Gpio::set(unsigned int pattern)
{
    // 1011
    // 0001
    //------ AND
    // 0001
    for (int pin : LEDs) {
        int state = pattern & 0001; // mask out LBS: state = 1,1,0,1
        lgGpioWrite(m_handle, pin, state);
        pattern = pattern >> 1; // bit shift to the right: 1011,0101,0010,0001
    }
}
