#include <QtGui>
#include <QSplashScreen>
#include <QTest>
#include <QTextCodec>
#include <QTranslator>
#include "mainwin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/res/navtex.png"));
    splash->show();
    splash->setFont(QFont("ubuntu",16));
    splash->showMessage(QObject::tr("加载窗体        "),Qt::AlignVCenter|Qt::AlignHCenter,Qt::yellow);
    MainWin win;

    //QTest::qSleep(3000);
    splash->showMessage(QObject::tr("显示窗体        "),Qt::AlignHCenter|Qt::AlignVCenter,Qt::red);
    win.show();
    splash->finish(&win);
    delete splash;
    return app.exec();
}


