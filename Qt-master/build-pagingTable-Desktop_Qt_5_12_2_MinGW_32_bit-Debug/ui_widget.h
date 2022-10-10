/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *currentPageLabel;
    QLabel *label_2;
    QLabel *countPageLabel;
    QPushButton *upPushButton;
    QPushButton *downPushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(538, 403);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        currentPageLabel = new QLabel(Widget);
        currentPageLabel->setObjectName(QString::fromUtf8("currentPageLabel"));

        horizontalLayout->addWidget(currentPageLabel);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        countPageLabel = new QLabel(Widget);
        countPageLabel->setObjectName(QString::fromUtf8("countPageLabel"));

        horizontalLayout->addWidget(countPageLabel);

        upPushButton = new QPushButton(Widget);
        upPushButton->setObjectName(QString::fromUtf8("upPushButton"));

        horizontalLayout->addWidget(upPushButton);

        downPushButton = new QPushButton(Widget);
        downPushButton->setObjectName(QString::fromUtf8("downPushButton"));

        horizontalLayout->addWidget(downPushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\357\274\232", nullptr));
        currentPageLabel->setText(QApplication::translate("Widget", "0", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\200\273\351\241\265\346\225\260\357\274\232", nullptr));
        countPageLabel->setText(QApplication::translate("Widget", "0", nullptr));
        upPushButton->setText(QApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        downPushButton->setText(QApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
