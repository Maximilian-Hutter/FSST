#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

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
};

#endif // WIDGET_H
