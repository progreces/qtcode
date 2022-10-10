#include "connection.h"
#include<QDebug>
#include <QSqlQuery>
#include<QtDebug>
#include <QSqlError>
connection * connection::Ptrconnection=nullptr;
connection::connection(QObject *parent) : QObject(parent)
{
   init();
   auto l=getpersoninfodata();
}

void connection::init()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("192.168.1.254"); // 数据库服务器IP，我用的是本地电脑
    db.setDatabaseName("254");// 数据库名，需要提前在数据库中建立对应的数据库
    db.setUserName("wjwywlb");// 用户名
    db.setPassword("wjwywlb");// 密码
    db.setPort(3308);// 端口号
    if (db.open())
        qDebug() << "sucessful";
    }
}

QList<personinfo> connection::getpersoninfodata()
{
    QList<personinfo> l;
    QSqlQuery sql;
    sql.exec("select * from d_person where NAME like '王__'");

    personinfo info;
    while(sql.next())
    {
        //取出当前记录中的字段值
        info.NAME=sql.value("NAME").toString();
        info.SEX=sql.value("SEX").toString();
        info.CSNY=sql.value("CSNY").toString();
        info.MINZU=sql.value("MINZU").toString();
        info.JIGUAN=sql.value("JIGUAN").toString();
        info.CSD=sql.value("CSD").toString();
        info.WORKTIME=sql.value("WORKTIME").toString();
        info.ZZMM=sql.value("ZZMM").toString();
        info.RDSJ=sql.value("RDSJ").toString();
        info.DUTY=sql.value("DUTY").toString();
        info.CURRENTDUTYTIME=sql.value("CURRENTDUTYTIME").toString();
        info.IDCARD=sql.value("IDCARD").toString();
        info.QRZXL=sql.value("QRZXL").toString();
        info.QRZXW=sql.value("QRZXW").toString();
        info.QRZBYYX=sql.value("QRZBYYX").toString();
        info.QRZZY=sql.value("QRZZY").toString();
        info.ZZXL=sql.value("ZZXL").toString();
        info.ZZXW=sql.value("ZZXW").toString();
        info.ZZBYYX=sql.value("ZZBYYX").toString();
        info.ZZZY=sql.value("ZZZY").toString();
        info.QUESTION=sql.value("QUESTION").toString();
        info.SUPPLEMENTARYMATERIAL=sql.value("SUPPLEMENTARYMATERIAL").toString();
        info.SUPPLEMENTARYTIME=sql.value("SUPPLEMENTARYTIME").toString();
        info.DAZLR=sql.value("DAZLR").toString();
        info.DASHR=sql.value("DASHR").toString();
        info.DAJS=sql.value("DAJS").toString();
        info.BSRQ=sql.value("BSRQ").toString();
        info.SZDACJR=sql.value("SZDACJR").toString();
        info.SZDASHR=sql.value("SZDASHR").toString();
        info.DABSDW=sql.value("DABSDW").toString();
        l.push_back(info);
    }
    return l;
}

