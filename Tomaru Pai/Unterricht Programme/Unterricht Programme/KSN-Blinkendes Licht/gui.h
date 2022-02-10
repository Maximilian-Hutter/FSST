#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

class Gui : public QMainWindow, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QMainWindow *parent = nullptr);

private slots:
    void on_startButton_clicked();
    void on_SpeedSlider_valueChanged(int value);
    void toggle();


private:
    QTimer* m_timer;
    bool m_status;
    Gpio* m_leds;

};

#endif // GUI_H
