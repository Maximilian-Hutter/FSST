#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "gpio.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void updateButtonState();

private:
    QList<QLabel*> m_input_display;
    QTimer* m_timer;
    gpio* m_gpio;

};

#endif // WIDGET_H
