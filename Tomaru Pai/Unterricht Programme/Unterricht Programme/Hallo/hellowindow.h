#ifndef HELLOWINDOW_H
#define HELLOWINDOW_H

#include "ui_hellowindow.h"

class HelloWindow : public QWidget, private Ui::HelloWindow // Mehrfachvererbung
{
    Q_OBJECT

public:
    explicit HelloWindow(QWidget *parent = nullptr);
private slots:
    void on_sendbutton_clicked();
};

#endif // HELLOWINDOW_H
