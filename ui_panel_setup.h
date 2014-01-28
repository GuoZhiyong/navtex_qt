/********************************************************************************
** Form generated from reading UI file 'panel_setup.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_SETUP_H
#define UI_PANEL_SETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel_setup
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *panel_setup)
    {
        if (panel_setup->objectName().isEmpty())
            panel_setup->setObjectName(QString::fromUtf8("panel_setup"));
        panel_setup->resize(507, 387);
        horizontalLayout = new QHBoxLayout(panel_setup);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(panel_setup);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        retranslateUi(panel_setup);

        QMetaObject::connectSlotsByName(panel_setup);
    } // setupUi

    void retranslateUi(QWidget *panel_setup)
    {
        panel_setup->setWindowTitle(QApplication::translate("panel_setup", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("panel_setup", "\350\277\231\346\230\257\350\256\276\347\275\256\351\241\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class panel_setup: public Ui_panel_setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_SETUP_H
