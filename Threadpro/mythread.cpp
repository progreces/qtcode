#include "mythread.h"
#include<QThread>
#include<QDebug>
#include<QMessageBox>
MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyThread::myTimeout()
{
    while( !isStop)
    {

        QThread::sleep(1);
        emit mySignal();
        //QMessageBox::aboutQt(NULL);

        qDebug()<<"子线程号:"<<QThread::currentThreadId;
       if(true == isStop)
       {
           break;
       }
    }
}

void MyThread::setFlag(bool f1ag)
{
    isStop = f1ag;
}
