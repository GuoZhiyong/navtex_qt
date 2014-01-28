/********************************************************************************
** Form generated from reading UI file 'panel_info.ui'
**
** Created: Tue Jan 28 15:48:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_INFO_H
#define UI_PANEL_INFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel_info
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *scroll_widget;

    void setupUi(QScrollArea *panel_info)
    {
        if (panel_info->objectName().isEmpty())
            panel_info->setObjectName(QString::fromUtf8("panel_info"));
        panel_info->resize(536, 436);
        panel_info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        panel_info->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 517, 434));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scroll_widget = new QWidget(scrollAreaWidgetContents);
        scroll_widget->setObjectName(QString::fromUtf8("scroll_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scroll_widget->sizePolicy().hasHeightForWidth());
        scroll_widget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(scroll_widget);

        panel_info->setWidget(scrollAreaWidgetContents);

        retranslateUi(panel_info);

        QMetaObject::connectSlotsByName(panel_info);
    } // setupUi

    void retranslateUi(QScrollArea *panel_info)
    {
        panel_info->setWindowTitle(QApplication::translate("panel_info", "ScrollArea", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class panel_info: public Ui_panel_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_INFO_H
