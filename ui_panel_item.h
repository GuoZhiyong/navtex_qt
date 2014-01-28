/********************************************************************************
** Form generated from reading UI file 'panel_item.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_ITEM_H
#define UI_PANEL_ITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel_item
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QFrame *line;

    void setupUi(QWidget *panel_item)
    {
        if (panel_item->objectName().isEmpty())
            panel_item->setObjectName(QString::fromUtf8("panel_item"));
        panel_item->resize(326, 47);
        verticalLayout_2 = new QVBoxLayout(panel_item);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 0, 4, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(panel_item);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/mail_1_close.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(panel_item);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(panel_item);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(panel_item);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(panel_item);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/spk_blue_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(panel_item);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(panel_item);

        QMetaObject::connectSlotsByName(panel_item);
    } // setupUi

    void retranslateUi(QWidget *panel_item)
    {
        panel_item->setWindowTitle(QApplication::translate("panel_item", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label->setText(QApplication::translate("panel_item", "TA74", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("panel_item", "<html><head/><body><p>2014-04-23 15:13:56</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("panel_item", "2014-05 22 13:14:25", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class panel_item: public Ui_panel_item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_ITEM_H
