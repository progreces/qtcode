#ifndef QTMYSQL_H
#define QTMYSQL_H

#include <QObject>

class QtMySQL : public QObject
{
    Q_OBJECT
public:
    explicit QtMySQL(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QTMYSQL_H