#include"connection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QFileDialog>
#include <QFileInfo>
#include <QPageSetupDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  ,m_ptrSql(nullptr)
{
    ui->setupUi(this);

    QAction *action_print=new QAction("打印",this);
    QAction *action_printpreview=new QAction("打印预览",this);

    connect(action_print,&QAction::triggered,this,&MainWindow::doprint);
    connect(action_printpreview,&QAction::triggered,this,&MainWindow::doprint2);

    ui->menuBar->addAction(action_print);
    ui->menuBar->addAction(action_printpreview);


    m_ptrSql=connection::getinstance();
    m_ptrSql->init();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doprint()
{
    // 创建打印机对象
    QPrinter printer;
    // 创建打印对话框
    QPrintDialog dlg(&printer, this);

    //如果编辑器中有选中区域，则打印选中区域
    dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);

    //页面相关设置
//    printer.setPaperSize(QPrinter::Custom);//自定义大小
//    printer.setPageSizeMM(QSizeF(80,15));//自定义纸张尺寸
    // 如果在对话框中按下了打印按钮，则执行打印操作
    if (dlg.exec() == QDialog::Accepted) {
        QPainter painter;//创建画笔
        painter.begin(&printer);//绘制到打印机上
        //painter.drawText(1,20,ui->lineEdit->text());//绘制文本，其他的类似
        painter.end();
    }
}
void MainWindow::doprint2()
{
    QPrinter printer;
    // 创建打印预览对话框
    QPrintPreviewDialog preview(&printer, this);

    //页面相关设置
//    printer.setPaperSize(QPrinter::Custom);//自定义大小
//    //printer.setPaperSize(QSizeF(size.height(),size.width()),QPrinter::Point);
//    printer.setPageSizeMM(QSizeF(85,15));

    // 当要生成预览页面时，发射paintRequested()信号
    connect(&preview, SIGNAL(paintRequested(QPrinter*)),
                  this,SLOT(printPreview(QPrinter*)));
    preview.exec();
}
void MainWindow::printPreview(QPrinter * printer)
{


        QPainter p;
        p.begin(printer);//创建一个空白页
        //定义画笔
        QPen pen;
        pen.setWidth(2);//设置线宽
        pen.setColor(Qt::gray);//rgb设置颜色
        p.setPen(pen);

        QFont font("Microsoft YaHei", 12, QFont::Bold, false);//设置字体
        p.setFont(font);
        QList<personinfo> lpersons = m_ptrSql->getpersoninfodata();
        p.drawText(130,165,lpersons[0].NAME);
        p.drawText(335,165,lpersons[0].SEX);
        p.drawText(525,165,lpersons[0].CSNY);
        p.drawText(130,210,lpersons[0].MINZU);
        p.drawText(335,210,lpersons[0].JIGUAN);
        p.drawText(525,210,lpersons[0].CSD);
        p.drawText(120,260,lpersons[0].WORKTIME);
        p.drawText(325,255,lpersons[0].ZZMM);
        p.drawText(525,255,lpersons[0].RDSJ);
        p.drawText(130,320,lpersons[0].DUTY);
        p.drawText(130,390,lpersons[0].CURRENTDUTYTIME);
        p.drawText(350,390,lpersons[0].IDCARD);
        p.drawText(263,445,lpersons[0].QRZXL);
        p.drawText(263,485,lpersons[0].QRZXW);
        p.drawText(510,445,lpersons[0].QRZBYYX);
        p.drawText(510,485,lpersons[0].QRZZY);
        p.drawText(263,535,lpersons[0].ZZXL);
        p.drawText(263,575,lpersons[0].ZZXW);
        p.drawText(510,535,lpersons[0].ZZBYYX);
        p.drawText(510,575,lpersons[0].ZZZY);
        p.drawText(130,680,lpersons[0].QUESTION);
        p.drawText(130,830,lpersons[0].SUPPLEMENTARYMATERIAL);
        p.drawText(130,915,lpersons[0].SUPPLEMENTARYTIME);
        p.drawText(135,975,lpersons[0].DAZLR);
        p.drawText(335,975,lpersons[0].DASHR);
        p.drawText(525,970,lpersons[0].DAJS);
        p.drawText(675,975,lpersons[0].BSRQ);
        p.drawText(135,1035,lpersons[0].SZDACJR);
        p.drawText(335,1035,lpersons[0].SZDASHR);
        p.drawText(510,1030,lpersons[0].DABSDW);
        //画矩形
        //p.drawRect(0,0,700,800);

        QPen text;
        text.setWidth(5);//设置线宽
        text.setColor(Qt::black);//rgb设置颜色
        p.setPen(text);
        QFont font3("Microsoft YaHei", 24, QFont::Bold, false);//设置字体
        p.setFont(font3);
        p.drawText(200,70,tr("干部数字档案基本信息表"));
        QPen next;
        next.setWidth(2);//设置线宽
        next.setColor(Qt::gray);//rgb设置颜色
        p.setPen(next);
        QFont font4("Microsoft YaHei", 12, QFont::Bold, false);//设置字体
        p.setFont(font4);
        p.drawRect(20,130,725,920);
        p.drawLine(110,130,110,1050);
        p.drawLine(20,180,745,180);
        p.drawText(40,165,tr("姓 名"));
        p.drawLine(200,130,200,280);//竖线控制
        p.drawLine(300,130,300,280);//竖线控制

        p.drawText(225,165,tr("性 别"));
        p.drawLine(400,130,400,280);
        p.drawLine(500,130,500,280);
        p.drawText(415,165,tr("出生年月"));

        //第二行线
        p.drawLine(20,220,745,220);
        p.drawText(40,210,tr("民 族"));
        p.drawText(225,210,tr("籍 贯"));
        p.drawText(415,210,tr("出 生 地"));
        p.drawLine(20,280,745,280);
        p.drawText(40,245,tr("参 加"));
        p.drawText(30,265,tr("工作时间"));
        p.drawText(215,255,tr("政治面貌"));
        p.drawText(415,255,tr("入党时间"));
        p.drawLine(20,350,745,350);
        p.drawText(30,310,tr("工作单位"));
        p.drawText(30,330,tr("及 职 务"));

        //第三行线
        p.drawLine(20,410,745,410);
        p.drawLine(200,350,200,600);
         p.drawText(30,390,tr("现职时间"));
        p.drawLine(300,350,300,410);
        p.drawText(215,390,tr("身份证号"));
        QPen pen1;
        pen1.setWidth(2);//设置线宽
        pen1.setColor(Qt::gray);//rgb设置颜色

        //把画笔交给画家
        p.setPen(pen1);


        //学历学位
        p.drawLine(20,600,745,600);
        p.setPen(Qt::black);
        p.drawLine(110,500,745,500);
        QPen pen2;
        pen2.setWidth(2);//设置线宽
        pen2.setColor(Qt::gray);//rgb设置颜色

        //把画笔交给画家
        p.setPen(pen2);

        p.drawLine(400,410,400,600);
        p.drawLine(500,410,500,600);
        p.drawLine(200,460,400,460);
        p.drawLine(500,460,745,460);
        p.drawLine(200,550,400,550);
        p.drawLine(500,550,745,550);


        p.drawText(30,510,tr("学历学位"));
        p.drawText(130,450,tr("全日制"));
        p.drawText(133,475,tr("教 育"));
        p.drawText(415,450,tr("毕业院校"));
        p.drawText(415,475,tr("系及专业"));

        p.drawText(120,565,tr("在职教育"));
        p.drawText(415,545,tr("毕业院校"));
        p.drawText(415,575,tr("系及专业"));


        //遗留问题
        p.drawLine(20,800,745,800);
        p.drawText(30,660,tr("干部档案"));
        p.drawText(30,690,tr("遗留问题"));
        p.drawText(30,720,tr("或需要说"));
        p.drawText(30,750,tr("明的情况"));


        //补充材料情况
        p.drawLine(20,930,745,930);
        p.drawText(30,830,tr("补充材料"));
        p.drawText(40,860,tr("情况"));

        //补充时间
        p.drawLine(20,880,745,880);
        p.drawText(30,910,tr("补充时间"));

        //档案整理人
        p.drawLine(20,995,745,995);
        p.drawLine(200,930,200,1050);
        p.drawLine(300,930,300,1050);
        p.drawLine(400,930,400,1050);
        p.drawLine(500,930,500,1050);
        p.drawLine(600,930,600,995);
        p.drawLine(670,930,670,995);
        p.drawText(40,960,tr("档 案"));
        p.drawText(35,980,tr("整理人"));
        p.drawText(230,960,tr("档 案"));
        p.drawText(225,980,tr("审核人"));
        p.drawText(415,970,tr("档案卷数"));
        p.drawText(615,960,tr("报送"));
        p.drawText(615,980,tr("日期"));
        p.drawText(25,1020,tr("数字档案"));
        p.drawText(25,1040,tr("采 集 人"));
        p.drawText(215,1020,tr("数字档案"));
        p.drawText(215,1040,tr("审 核 人"));
        p.drawText(415,1030,tr("报送单位"));
        p.end();
        //ui->textEdit->print(printer);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setBrush(Qt::white);

    //定义画笔
    QPen pen;
    pen.setWidth(2);//设置线宽
    pen.setColor(Qt::gray);//rgb设置颜色

    //把画笔交给画家
    p.setPen(pen);


    //画矩形
    p.drawRect(0,0,800,900);
    QFont font("Microsoft YaHei", 12, QFont::Bold, false);//设置字体
    p.setFont(font);
    QPen text;
    text.setWidth(5);//设置线宽
    text.setColor(Qt::black);//rgb设置颜色
    p.setPen(text);
    QFont font3("Microsoft YaHei", 24, QFont::Bold, false);//设置字体
    p.setFont(font3);
    p.drawText(200,40,tr("干部数字档案基本信息表"));
    QPen next;
    next.setWidth(2);//设置线宽
    next.setColor(Qt::gray);//rgb设置颜色
    p.setPen(next);
    QFont font4("Microsoft YaHei", 12, QFont::Bold, false);//设置字体
    p.setFont(font4);
    p.drawRect(20,80,750,750);
    p.drawLine(110,80,110,830);
    p.drawLine(20,115,770,115);
    p.drawText(40,105,tr("姓 名"));
    p.drawLine(200,80,200,185);//竖线控制
    p.drawLine(300,80,300,185);//竖线控制
    p.drawText(225,105,tr("性 别"));
    p.drawLine(400,80,400,185);
    p.drawLine(500,80,500,185);
    p.drawText(410,105,tr("出生年月"));

    //第二行线
    p.drawLine(20,150,770,150);
    p.drawText(40,140,tr("民 族"));
    p.drawText(225,140,tr("籍 贯"));
    p.drawText(410,140,tr("出 生 地"));
    p.drawLine(20,185,770,185);
    p.drawText(40,165,tr("参 加"));
    p.drawText(25,180,tr("工作时间"));
    p.drawText(215,175,tr("政治面貌"));
    p.drawText(410,175,tr("入党时间"));
    p.drawLine(20,230,770,230);
    p.drawText(25,205,tr("工作单位"));
    p.drawText(25,220,tr("及 职 务"));

    //第三行线
    p.drawLine(20,270,770,270);
    p.drawLine(200,230,200,400);
     p.drawText(25,255,tr("现职时间"));
    p.drawLine(300,230,300,270);
    p.drawText(215,255,tr("身份证号"));
    QPen pen1;
    pen1.setWidth(2);//设置线宽
    pen1.setColor(Qt::gray);//rgb设置颜色

    //把画笔交给画家
    p.setPen(pen1);


    //学历学位
    p.drawLine(20,400,770,400);
    p.setPen(Qt::black);
    p.drawLine(110,340,770,340);
    QPen pen2;
    pen2.setWidth(2);//设置线宽
    pen2.setColor(Qt::gray);//rgb设置颜色

    //把画笔交给画家
    p.setPen(pen2);

    p.drawLine(400,270,400,400);
    p.drawLine(500,270,500,400);
    p.drawLine(200,305,400,305);
    p.drawLine(500,305,770,305);
    p.drawLine(200,370,400,370);
    p.drawLine(500,370,770,370);


    p.drawText(25,340,tr("学历学位"));
    p.drawText(130,300,tr("全日制"));
    p.drawText(130,325,tr("教 育"));
    p.drawText(415,300,tr("毕业院校"));
    p.drawText(415,320,tr("系及专业"));

    p.drawText(120,375,tr("在职教育"));
    p.drawText(415,365,tr("毕业院校"));
    p.drawText(415,385,tr("系及专业"));


    //遗留问题
    p.drawLine(20,600,770,600);
    p.drawText(25,460,tr("干部档案"));
    p.drawText(25,490,tr("遗留问题"));
    p.drawText(25,520,tr("或需要说"));
    p.drawText(25,550,tr("明的情况"));


    //补充材料情况
    p.drawLine(20,680,770,680);
    p.drawText(25,640,tr("补充材料"));
    p.drawText(40,660,tr("情况"));

    //补充时间
    p.drawLine(20,720,770,720);
    p.drawText(25,710,tr("补充时间"));

    //档案整理人
    p.drawLine(20,780,770,780);
    p.drawLine(200,720,200,830);
    p.drawLine(300,720,300,830);
    p.drawLine(400,720,400,830);
    p.drawLine(500,720,500,830);
    p.drawLine(600,720,600,780);
    p.drawLine(670,720,670,780);
    p.drawText(40,750,tr("档 案"));
    p.drawText(35,770,tr("整理人"));
    p.drawText(230,750,tr("档 案"));
    p.drawText(225,770,tr("审核人"));
    p.drawText(415,760,tr("档案卷数"));
    p.drawText(615,750,tr("报送"));
    p.drawText(615,770,tr("日期"));
    p.drawText(25,800,tr("数字档案"));
    p.drawText(25,820,tr("采 集 人"));
    p.drawText(215,800,tr("数字档案"));
    p.drawText(215,820,tr("审 核 人"));
    p.drawText(415,810,tr("报送单位"));


}
