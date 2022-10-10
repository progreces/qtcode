#include "filemd5.h"
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QCryptographicHash>
#include<QApplication>
#include<QDir>
FileMd5::FileMd5(QObject *parent) : QObject(parent)
{

}

void FileMd5::checkDumplate(const QString &path)
{
    //写代码检测文件重复
    QHash<QByteArray,QStringList> ret;
    QStringList files = getFiles(path);
    for (int i=0;i<files.count();++i)
    {
       QString fileName = files.at(i);
       QByteArray md5 = getFileMd5(fileName);
       qDebug()<< "fileName:" <<fileName<<"md5"<<md5;

       ret[md5].append(fileName);
    }
    emit gotDumplate(ret);
}

QStringList FileMd5::getFiles(const QString &path)
{
    QStringList ret;
    QDir dir(path);
    //.表示当前根目录,..表示上一级根目录
    QFileInfoList infolist = dir.entryInfoList(QDir::Files |QDir::Dirs|QDir::NoDotAndDotDot);
    for (int i=0;i<infolist.count();++i) {
       QFileInfo info =infolist.at(i);
       if(info.isDir())
       {
           QString subDir = info.absoluteFilePath();
           //如果是目录，就启用getfile,传入目录，参数
           QStringList files = getFiles(subDir);


           ret.append(files);
       }
       else
       {
           QString fileName = info.absoluteFilePath();
           ret.append(fileName);
       }
    }
    return ret;
}

QByteArray FileMd5::getFileMd5(const QString &fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
        QByteArray content = file.read(100*1024*1024);
        hash.addData(content);
        qApp->processEvents();
        }
        QByteArray md5 = hash.result().toHex();
       //QByteArray content=file.readAll();
        //QMessageBox::information(this,"",content);

       //QByteArray md5 = QCryptographicHash::hash(content,QCryptographicHash::Md5);
       //qDebug()<<md5<<" "<<md5.toHex();
       file.close();
    }
    return QByteArray();


}
