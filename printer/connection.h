#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
struct personinfo//信息数据库字段
{
   QString NAME;//姓名
   QString SEX;//性别
   QString CSNY;//出生年月
   QString MINZU;//民族
   QString JIGUAN;//籍贯
   QString CSD;//出生地
   QString WORKTIME;//工作时间
   QString ZZMM;//政治面貌
   QString RDSJ;//入党时间
   QString DUTY;//工作单位及职务
   QString CURRENTDUTYTIME;//现职时间
   QString IDCARD;//身份证
   QString QRZXL;//全日制学历
   QString QRZXW;//全日制学位
   QString QRZBYYX;//全日制毕业院校
   QString QRZZY;//全日制专业
   QString ZZXL;//在职学历
   QString ZZXW;//在职学位
   QString ZZBYYX;//在职毕业院校
   QString ZZZY;//在职专业
   QString QUESTION;//遗留问题
   QString SUPPLEMENTARYMATERIAL;//补充材料情况
   QString SUPPLEMENTARYTIME;//补充时间
   QString DAZLR;//档案整理人
   QString DASHR;//档案审核人
   QString DAJS;//档案卷数
   QString BSRQ;//报送日期
   QString SZDACJR;//数字档案采集人
   QString SZDASHR;//数字档案审核人
   QString DABSDW;//档案报送单位
};

class connection : public QObject
{
    Q_OBJECT
public:
    static connection *Ptrconnection;
    static connection *getinstance()
    {
        if(nullptr==Ptrconnection)
        {
           Ptrconnection =new connection;
        }
        return Ptrconnection;
    }
    explicit connection(QObject *parent = nullptr);
    void init();
    QList<personinfo> getpersoninfodata();

signals:

public slots:
};

#endif // CONNECTION_H
