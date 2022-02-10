#ifndef GPIO_H
#define GPIO_H

#include <QObject>
const QList<int> LEDS = {18,23,24,25};  // QList<int> ... Liste von Integer
const int LFLAGS = 0;
const int CHIP = 0;

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);   // Construktor
    ~Gpio(); // Destructor
    void set(int pin, int state);
    void set(unsigned int pattern); //0b1010

signals:

public slots:

private:
    int m_handle;
};

#endif // GPIO_H
