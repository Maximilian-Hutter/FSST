#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <gpio.h>

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void refreshLabels();

private:
    QList<QLabel*> m_pinlabels;
    QTimer* m_timer;
    Gpio* m_inputs;
};

#endif // WIDGET_H
