#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QCryptographicHash>
#include<QApplication>
#include<QDir>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread.start();
    md5.moveToThread(&thread);


    this->setWindowFlags(Qt::FramelessWindowHint);

    //阴影边框效果类
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();

    shadow->setBlurRadius(5);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);

    //ui->shadowWidget->setGraphicsEffect(shadow);
     //this->setGraphicsEffect(shadow);
    //设置父窗口为透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    connect(&md5, SIGNAL(gotDumplate(Qhash<QByteArray,QStringList>)),this,SLOT(onGotDumplate(Qhash<QByteArray,QStringList>)));
    connect(this,SIGNAL(checkDumplate(QString)),);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
     QPoint y = event->globalPos();//鼠标相对于桌面左上角的位置，鼠标全局位置
    QPoint x = y - z;
    this->move(x);


}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QPoint y = event->globalPos();//鼠标相对于桌面左上角的位置，鼠标全局位置
     QPoint x = this->geometry().topLeft();//窗口左上角相对于桌面左上角的位置，窗口位置
    this->z = y-x;//定值不变的



}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
   QWidget::mouseReleaseEvent(event);
   this->z = QPoint();
}





void Widget::on_btnClose_clicked()
{
    this->close();
}

void Widget::on_btnMax_clicked()
{
    if(this->isMaximized())
    {
        ui->vlMan->setMargin(9);
        this->showNormal();
    }
    else {
        ui->vlMan->setMargin(0);
        this->showMaximized();
    }
}

void Widget::on_btnMin_clicked()
{
    this->showMinimized();
}

void Widget::on_btnOpenfileText_clicked()
{
    QFile file("C:\\Users\\Administrator\\Desktop\\笔记.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
        QByteArray content = file.read(100*1024*1024);
        hash.addData(content);
        qApp->processEvents();
        }
        QByteArray md5 = hash.result();
       //QByteArray content=file.readAll();
        //QMessageBox::information(this,"",content);

       //QByteArray md5 = QCryptographicHash::hash(content,QCryptographicHash::Md5);
       //qDebug()<<md5<<" "<<md5.toHex();
       file.close();
    }
}

void Widget::on_btnGetFiles_clicked()
{
    emit checkDumplate("C:/Users/Administrator/Desktop/笔记.txt");
     //md5.checkDumplate("C:/Users/Administrator/Desktop/笔记.txt");

}

void Widget::onGotDumplate(const QHash<QByteArray, QStringList> &dumplates)
{

    for (QHash<QByteArray,QStringList>::const_iterator itr = dumplates.begin();itr != dumplates.end();++itr) {
       qDebug()<<"md5:"<<itr.key()<<"count:"<<itr.value().count();
       if(itr.value().count() >1)
       {
           qDebug()<<"file:"<<itr.value();
       }
    }
}
