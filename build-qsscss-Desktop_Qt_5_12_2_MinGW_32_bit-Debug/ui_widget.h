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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *vlMan;
    QWidget *shadowWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnMin;
    QPushButton *btnMax;
    QPushButton *btnClose;
    QFrame *frame;
    QPushButton *btnOpenfileText;
    QPushButton *btnGetFiles;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(683, 459);
        vlMan = new QVBoxLayout(Widget);
        vlMan->setSpacing(6);
        vlMan->setContentsMargins(11, 11, 11, 11);
        vlMan->setObjectName(QString::fromUtf8("vlMan"));
        shadowWidget = new QWidget(Widget);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(255, 255, 255);\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(shadowWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(shadowWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        btnMin = new QPushButton(shadowWidget);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMin->sizePolicy().hasHeightForWidth());
        btnMin->setSizePolicy(sizePolicy1);
        btnMin->setMinimumSize(QSize(0, 42));
        btnMin->setMaximumSize(QSize(42, 42));
        btnMin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"     border:600e;\n"
"	\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"     \n"
"	\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"     \n"
"}"));

        horizontalLayout->addWidget(btnMin);

        btnMax = new QPushButton(shadowWidget);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        sizePolicy1.setHeightForWidth(btnMax->sizePolicy().hasHeightForWidth());
        btnMax->setSizePolicy(sizePolicy1);
        btnMax->setMinimumSize(QSize(42, 42));
        btnMax->setMaximumSize(QSize(42, 42));
        btnMax->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"     border:600e;\n"
"	\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"     \n"
"	background-color: rgb(85, 170, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"     \n"
"	background-color: rgb(59, 177, 177);\n"
"	\n"
"}"));

        horizontalLayout->addWidget(btnMax);

        btnClose = new QPushButton(shadowWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        sizePolicy1.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy1);
        btnClose->setMinimumSize(QSize(42, 42));
        btnClose->setMaximumSize(QSize(42, 42));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"     border:600e;\n"
"	\n"
"	background-color: rgb(255, 85, 0);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"     \n"
"	background-color: rgb(255, 170, 0);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"     \n"
"	background-color: rgb(255, 136, 125);\n"
"}"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout);

        frame = new QFrame(shadowWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btnOpenfileText = new QPushButton(frame);
        btnOpenfileText->setObjectName(QString::fromUtf8("btnOpenfileText"));
        btnOpenfileText->setGeometry(QRect(130, 130, 75, 23));
        btnGetFiles = new QPushButton(frame);
        btnGetFiles->setObjectName(QString::fromUtf8("btnGetFiles"));
        btnGetFiles->setGeometry(QRect(280, 130, 75, 23));

        verticalLayout_2->addWidget(frame);


        vlMan->addWidget(shadowWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Framless Windows", nullptr));
        btnMin->setText(QString());
        btnMax->setText(QString());
        btnClose->setText(QString());
        btnOpenfileText->setText(QApplication::translate("Widget", "Text", nullptr));
        btnGetFiles->setText(QApplication::translate("Widget", "get files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
