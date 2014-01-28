/********************************************************************************
** Form generated from reading UI file 'listwidget_item.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGET_ITEM_H
#define UI_LISTWIDGET_ITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(463, 74);
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/mail_1_close.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(pushButton);

        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\200\271\345\254\251\347\266\213"));
        font.setPointSize(24);
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\200\271\345\254\251\347\266\213"));
        font1.setPointSize(16);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/spk_blue_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label_5->setText(QApplication::translate("Form", "TA74", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "2014-03-15 12:34:56", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "2014-05-27 12:34:56", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGET_ITEM_H
