/********************************************************************************
** Form generated from reading UI file 'panel_detail.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_DETAIL_H
#define UI_PANEL_DETAIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel_detail
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *panel_detail)
    {
        if (panel_detail->objectName().isEmpty())
            panel_detail->setObjectName(QString::fromUtf8("panel_detail"));
        panel_detail->resize(598, 442);
        QFont font;
        font.setPointSize(16);
        panel_detail->setFont(font);
        label = new QLabel(panel_detail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 31));
        label_2 = new QLabel(panel_detail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 30, 54, 12));
        label_4 = new QLabel(panel_detail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 50, 101, 41));
        label_5 = new QLabel(panel_detail);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 90, 111, 41));
        textBrowser = new QTextBrowser(panel_detail);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 140, 561, 281));

        retranslateUi(panel_detail);

        QMetaObject::connectSlotsByName(panel_detail);
    } // setupUi

    void retranslateUi(QWidget *panel_detail)
    {
        panel_detail->setWindowTitle(QApplication::translate("panel_detail", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("panel_detail", "ID", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("panel_detail", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("panel_detail", "\345\247\213\345\217\221\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("panel_detail", "\346\216\245\346\224\266\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class panel_detail: public Ui_panel_detail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_DETAIL_H
