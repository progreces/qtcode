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

class Ui_vlMain
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnclose;
    QPushButton *btnMax;
    QPushButton *btnMin;
    QFrame *frame;

    void setupUi(QWidget *vlMain)
    {
        if (vlMain->objectName().isEmpty())
            vlMain->setObjectName(QString::fromUtf8("vlMain"));
        vlMain->resize(400, 300);
        verticalLayout = new QVBoxLayout(vlMain);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        shadowWidget = new QWidget(vlMain);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(shadowWidget);
        verticalLayout_2->setSpacing(6);
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

        btnclose = new QPushButton(shadowWidget);
        btnclose->setObjectName(QString::fromUtf8("btnclose"));
        btnclose->setMinimumSize(QSize(42, 42));
        btnclose->setMaximumSize(QSize(42, 42));

        horizontalLayout->addWidget(btnclose);

        btnMax = new QPushButton(shadowWidget);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        btnMax->setMinimumSize(QSize(42, 42));
        btnMax->setMaximumSize(QSize(42, 42));

        horizontalLayout->addWidget(btnMax);

        btnMin = new QPushButton(shadowWidget);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setMinimumSize(QSize(42, 42));
        btnMin->setMaximumSize(QSize(42, 42));

        horizontalLayout->addWidget(btnMin);


        verticalLayout_2->addLayout(horizontalLayout);

        frame = new QFrame(shadowWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame);


        verticalLayout->addWidget(shadowWidget);


        retranslateUi(vlMain);

        QMetaObject::connectSlotsByName(vlMain);
    } // setupUi

    void retranslateUi(QWidget *vlMain)
    {
        vlMain->setWindowTitle(QApplication::translate("vlMain", "Widget", nullptr));
        label->setText(QApplication::translate("vlMain", "Framless Windows", nullptr));
        btnclose->setText(QString());
        btnMax->setText(QString());
        btnMin->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class vlMain: public Ui_vlMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
