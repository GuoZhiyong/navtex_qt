/********************************************************************************
** Form generated from reading UI file 'panel_serial.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_SERIAL_H
#define UI_PANEL_SERIAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel_serial
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *edt_send;
    QPushButton *btn_serialport_send;

    void setupUi(QWidget *panel_serial)
    {
        if (panel_serial->objectName().isEmpty())
            panel_serial->setObjectName(QString::fromUtf8("panel_serial"));
        panel_serial->resize(529, 421);
        verticalLayout = new QVBoxLayout(panel_serial);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(panel_serial);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout->addWidget(textBrowser);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edt_send = new QLineEdit(panel_serial);
        edt_send->setObjectName(QString::fromUtf8("edt_send"));

        horizontalLayout_2->addWidget(edt_send);

        btn_serialport_send = new QPushButton(panel_serial);
        btn_serialport_send->setObjectName(QString::fromUtf8("btn_serialport_send"));

        horizontalLayout_2->addWidget(btn_serialport_send);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(panel_serial);

        QMetaObject::connectSlotsByName(panel_serial);
    } // setupUi

    void retranslateUi(QWidget *panel_serial)
    {
        panel_serial->setWindowTitle(QApplication::translate("panel_serial", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("panel_serial", "\346\216\245\346\224\266\345\214\272", 0, QApplication::UnicodeUTF8));
        btn_serialport_send->setText(QApplication::translate("panel_serial", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class panel_serial: public Ui_panel_serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_SERIAL_H
