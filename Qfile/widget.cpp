#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QFileDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonRread_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");

    if(path.isEmpty() == false)
    {
        //文件对象
        QFile file(path);


        //打开文件,只读方式
        bool isOk = file.open(QIODevice::ReadOnly);

        if(isOk == true)
        {
            //读文件
            QByteArray array = file.readAll();

            //显示到编辑区
            ui->textEdit->setText(array);
        }
        //关闭文件
        file.close();
    }
}
