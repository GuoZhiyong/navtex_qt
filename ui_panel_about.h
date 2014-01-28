/********************************************************************************
** Form generated from reading UI file 'panel_about.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_ABOUT_H
#define UI_PANEL_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel_about
{
public:
    QLabel *label;

    void setupUi(QWidget *panel_about)
    {
        if (panel_about->objectName().isEmpty())
            panel_about->setObjectName(QString::fromUtf8("panel_about"));
        panel_about->resize(400, 300);
        label = new QLabel(panel_about);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 130, 171, 16));

        retranslateUi(panel_about);

        QMetaObject::connectSlotsByName(panel_about);
    } // setupUi

    void retranslateUi(QWidget *panel_about)
    {
        panel_about->setWindowTitle(QApplication::translate("panel_about", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("panel_about", "\350\277\231\346\230\257\345\205\263\344\272\216\351\241\265\351\235\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class panel_about: public Ui_panel_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_ABOUT_H
