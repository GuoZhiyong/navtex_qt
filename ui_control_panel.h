/********************************************************************************
** Form generated from reading UI file 'control_panel.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_PANEL_H
#define UI_CONTROL_PANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_control_panel
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btn_pnl_detail;
    QPushButton *btn_pnl_info;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cb_486;
    QCheckBox *cb_518;
    QCheckBox *cb_4209;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_pnl_serialport;
    QPushButton *btn_pnl_setup;
    QPushButton *btn_pnl_about;

    void setupUi(QWidget *control_panel)
    {
        if (control_panel->objectName().isEmpty())
            control_panel->setObjectName(QString::fromUtf8("control_panel"));
        control_panel->resize(138, 430);
        control_panel->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(control_panel);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, 0);
        btn_pnl_detail = new QPushButton(control_panel);
        btn_pnl_detail->setObjectName(QString::fromUtf8("btn_pnl_detail"));
        QFont font;
        font.setPointSize(20);
        btn_pnl_detail->setFont(font);

        verticalLayout->addWidget(btn_pnl_detail);

        btn_pnl_info = new QPushButton(control_panel);
        btn_pnl_info->setObjectName(QString::fromUtf8("btn_pnl_info"));
        btn_pnl_info->setFont(font);

        verticalLayout->addWidget(btn_pnl_info);

        btn_prev = new QPushButton(control_panel);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setFont(font);
        btn_prev->setCursor(QCursor(Qt::ArrowCursor));

        verticalLayout->addWidget(btn_prev);

        btn_next = new QPushButton(control_panel);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setFont(font);

        verticalLayout->addWidget(btn_next);

        groupBox = new QGroupBox(control_panel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setPointSize(16);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cb_486 = new QCheckBox(groupBox);
        cb_486->setObjectName(QString::fromUtf8("cb_486"));

        verticalLayout_2->addWidget(cb_486);

        cb_518 = new QCheckBox(groupBox);
        cb_518->setObjectName(QString::fromUtf8("cb_518"));

        verticalLayout_2->addWidget(cb_518);

        cb_4209 = new QCheckBox(groupBox);
        cb_4209->setObjectName(QString::fromUtf8("cb_4209"));

        verticalLayout_2->addWidget(cb_4209);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_pnl_serialport = new QPushButton(control_panel);
        btn_pnl_serialport->setObjectName(QString::fromUtf8("btn_pnl_serialport"));
        btn_pnl_serialport->setFont(font);

        verticalLayout->addWidget(btn_pnl_serialport);

        btn_pnl_setup = new QPushButton(control_panel);
        btn_pnl_setup->setObjectName(QString::fromUtf8("btn_pnl_setup"));
        btn_pnl_setup->setFont(font);

        verticalLayout->addWidget(btn_pnl_setup);

        btn_pnl_about = new QPushButton(control_panel);
        btn_pnl_about->setObjectName(QString::fromUtf8("btn_pnl_about"));
        btn_pnl_about->setFont(font);

        verticalLayout->addWidget(btn_pnl_about);


        retranslateUi(control_panel);

        QMetaObject::connectSlotsByName(control_panel);
    } // setupUi

    void retranslateUi(QWidget *control_panel)
    {
        control_panel->setWindowTitle(QApplication::translate("control_panel", "Form", 0, QApplication::UnicodeUTF8));
        btn_pnl_detail->setText(QApplication::translate("control_panel", "\346\237\245\347\234\213", 0, QApplication::UnicodeUTF8));
        btn_pnl_info->setText(QApplication::translate("control_panel", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_prev->setText(QApplication::translate("control_panel", "\344\270\212\344\270\200\346\235\241", 0, QApplication::UnicodeUTF8));
        btn_next->setText(QApplication::translate("control_panel", "\344\270\213\344\270\200\346\235\241", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("control_panel", "\351\242\221\346\256\265\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        cb_486->setText(QApplication::translate("control_panel", "486kHz", 0, QApplication::UnicodeUTF8));
        cb_518->setText(QApplication::translate("control_panel", "518kHz", 0, QApplication::UnicodeUTF8));
        cb_4209->setText(QApplication::translate("control_panel", "4209kHz", 0, QApplication::UnicodeUTF8));
        btn_pnl_serialport->setText(QApplication::translate("control_panel", "\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        btn_pnl_setup->setText(QApplication::translate("control_panel", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_pnl_about->setText(QApplication::translate("control_panel", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class control_panel: public Ui_control_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_PANEL_H
