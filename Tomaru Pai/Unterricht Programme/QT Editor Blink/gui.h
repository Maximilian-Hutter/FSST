#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include <QTimer>

class GUI : public QWidget, private Ui::GUI
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = nullptr); // QWidget *parent = nullptr => Default Wert
private slots:
    void on_startButton_clicked();
private:
    QTimer* m_timer;
    bool m_status;
    void toggle();

};

#endif // GUI_H

