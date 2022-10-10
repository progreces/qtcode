#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPrinter>
#include"connection.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void paintEvent(QPaintEvent *);
private:
    Ui::MainWindow *ui;
public slots:
    void doprint();
    void doprint2();
    void printPreview(QPrinter * printer);
private:
    connection *m_ptrSql;
};

#endif // MAINWINDOW_H
