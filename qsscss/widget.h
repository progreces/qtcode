#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPoint>
#include<QDir>
#include<QFileInfo>
#include<QHash>
#include<QMap>
#include"filemd5.h"
#include<QThread>
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


signals:
    void checkDumplate(const QString &path);


private slots:
    void on_btnClose_clicked();

    void on_btnMax_clicked();

    void on_btnMin_clicked();

    void on_btnOpenfileText_clicked();

    void on_btnGetFiles_clicked();

    void onGotDumplate(const QHash<QByteArray,QStringList> &dumplates);



private:
    Ui::Widget *ui;
    QPoint z;
    //md5, (file,file)
    QHash<QByteArray,QStringList> fileMd5;
    FileMd5 md5;
    QThread thread;
};

#endif // WIDGET_H
