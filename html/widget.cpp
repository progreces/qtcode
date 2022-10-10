#include "widget.h"
#include"ui_widget.h"
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile file("C:\\Users\\Administrator\\Desktop\\笔记.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray content = file.readAll();
        QMessageBox::information(this,"",content);
        qDebug()<<content<<123<<"test";

        file.close();
    }


    //去掉系统边框
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //阴影边框效果类
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();

    shadow->setBlurRadius(5);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);

    ui->shadowWidget->setGraphicsEffect(shadow);
    //设置父窗口为透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    //this->setGraphicsEffect(shadow);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);

    QPoint y = event->globalPos();
    QPoint x = y-this->z;
    this->move(x);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    QPoint x = this->geometry().topLeft();//窗口左上角相对于桌面左上角的位置，
    QPoint y = event->globalPos();//鼠标相对于桌面左上角的位置
    this->z = y - x;//定值,不变的

}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->z = QPoint();
}

void Widget::on_btnMin_clicked()
{
    this->showMinimized();
}

void Widget::on_btnMax_clicked()
{
    if(this->isMaximized())
    {
        this->showNormal();
    }
    else
    {

       this->showMaximized();
    }
}

void Widget::on_btnclose_clicked()
{
    this->close();
}
