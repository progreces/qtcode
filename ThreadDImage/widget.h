#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mythread.h"
#include<QThread>
#include<QImage>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写绘画事件
    void paintEvent(QPaintEvent *);

    void getImage(QImage temp);//槽函数

    void dealClose();//窗口关闭槽函数
private:
    Ui::Widget *ui;
    QImage image;
    MyThread * myT;//自定义线程对象
    QThread *thread;//子线程
};

#endif // WIDGET_H
