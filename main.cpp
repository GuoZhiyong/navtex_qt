
#include <QtGui>
#include <QSplashScreen>
#include <QTest>

#include "main.h"
#include "mainwin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/res/navtex.png"));
    splash->show();
    splash->setFont(QFont("ubuntu",16));
    splash->showMessage("加载窗体        ",Qt::AlignVCenter|Qt::AlignHCenter,Qt::yellow);
    MainWin win;

    //QTest::qSleep(3000);
    splash->showMessage("显示窗体",Qt::AlignBottom|Qt::AlignVCenter,Qt::red);

    win.show();
    splash->finish(&win);
    delete splash;
    return a.exec();
}


