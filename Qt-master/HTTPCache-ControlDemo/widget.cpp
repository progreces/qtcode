#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tcpServer = new QTcpServer(this);
    m_tcpServer->listen(QHostAddress::Any, 81);
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
    connect(m_tcpServer, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(errorStringSlot()));
}

Widget::~Widget()
{
    delete ui;
    m_tcpServer->close();
}

void Widget::newConnectionSlot()
{
    qDebug() << "newConnectionSlot() called!";
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(sendMsg()));
}

void Widget::errorStringSlot()
{
    qDebug() << m_tcpServer->errorString();
}

void Widget::sendMsg()
{
    QString urlStr = m_tcpSocket->readLine();

    qDebug() << urlStr;
    if(urlStr.contains("/script.js")){

//        QString contentStr = "console.log(\"script loaded\")";
//        QString str = "HTTP/1.1 200 OK\r\n";
//        str.append("Server:nginx\r\n");
//        str.append("Content-Type:text/javascript\r\n");
//        str.append("Cache-Control: max-age=2000\r\n");
//        str.append("Connection:keep-alive\r\n");
//        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
//        str.append(contentStr);
//        m_tcpSocket->write(str.toStdString().c_str());
    }
    else{
        QString contentStr = "<html>"
                     "<head>"
                     "<title>"
                     "Hello"
                     "</title>"
                     "</head>"
                     "<body>"
                     "<h1>Hello World</h1>"
                     "</body>"
                     "</html>";

        QString str = "HTTP/1.1 200 OK\r\n";
        str.append("Server:nginx\r\n");
        str.append("Content-Type:text/html;charset=UTF-8\r\n");
        str.append("Cache-Control: max-age=2000\r\n");
        str.append("Connection:keep-alive\r\n");
        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
        str.append(contentStr);
        m_tcpSocket->write(str.toStdString().c_str());
    }
}
