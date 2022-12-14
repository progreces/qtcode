#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"mythread.h"
#include<QThread>
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void dealSignal();
    void dealClose();
signals:
    void startTread();//启动子线程的信号


private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

private:
    Ui::MyWidget *ui;
    MyThread *myT;
    QThread *thread;
};

#endif // MYWIDGET_H
