#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPoint>
#include"lession.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

     void mouseMoveEvent(QMouseEvent * event);
     void mousePressEvent(QMouseEvent * event);
     void mouseReleaseEvent(QMouseEvent * event);

private slots:
     void on_btnMin_clicked();

     void on_btnMax_clicked();

     void on_btnclose_clicked();

private:
    Ui::Widget *ui;
    QPoint z;
};

#endif // WIDGET_H
