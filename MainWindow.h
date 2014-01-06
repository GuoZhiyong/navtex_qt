#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtGui>

#include "FlowLayout.hpp"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QPushButton *btn_detail;
    QPushButton *btn_486KHz;
    QPushButton *btn_518KHz;
    QPushButton *btn_4209KHz;
    QPushButton *btn_tts;
    QPushButton *btn_config;
    QPushButton *btn_about;
    QSpacerItem *spacer;
    QVBoxLayout *layout_right;
    QGridLayout *layout_main;

    QVBoxLayout *layout_left;
    QHBoxLayout *layout_left_top;
    QVBoxLayout *layout_left_bottom;

signals:

public slots:

};

#endif // MAINWINDOW_H
