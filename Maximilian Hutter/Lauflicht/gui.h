#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include <QTimer>

class Gui : public QMainWindow, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QMainWindow *parent = nullptr);
private slots:
    void on_startButton_clicked();
    void on_SpeedSlider_valueChanged(int value);

private:
    QTimer* m_timer;
    bool m_status;
    void toggle();
};

#endif // GUI_H
