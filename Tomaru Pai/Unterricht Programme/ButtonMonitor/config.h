#ifndef CONFIG_H
#define CONFIG_H

// Configuration data

#include <QList>

// Raspberry Hat BULME
const QList<int> LEDS = {18, 23, 24, 25}; // Output pins
const QList<int> BUTTONS = {22, 27, 17}; // Input pins

// Chip configuration Raspberry specific
const int LFLAGS = 0;
const int CHIP = 0;

// Update interval for reading pin state
const int T_UPDATE = 20; //  ms

#endif // CONFIG_H
