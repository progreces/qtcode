#include "widget.h"
#include <QApplication>
//#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置编码为utf-8.
//    QTextCodec *codec= QTextCodec::codecForName("utf-8");
//    QTextCodec::setCodecForLocale(codec);
    Widget w;
    w.show();

    return a.exec();
}
