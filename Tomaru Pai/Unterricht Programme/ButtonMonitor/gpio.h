#ifndef GPIO_H
#define GPIO_H

#include <QObject>

class gpio : public QObject
{
    Q_OBJECT
public:
    explicit gpio(QObject *parent = nullptr); // constructor
    ~gpio(); // destructor for clean-up
    void set(int pin, bool value);
    void set(unsigned int pattern);
    bool get(int pin);

signals:

public slots:

private:
    int m_handle;
};

#endif // GPIO_H
