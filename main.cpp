#include <QtGui>
#include <QSplashScreen>
#include <QTest>
#include <QTextCodec>
#include <QTranslator>
#include "mainwin.h"

#include <sys/ioctl.h>
#include <fcntl.h>

#include "common.h"

#include "eventspy.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    trans=new QTranslator();
    qDebug()<<"load chn.qm "<<trans->load("chn.qm",qApp->applicationDirPath());
    qApp->installTranslator(trans);


    fd_tts=::open("/dev/xf5251_drv",O_RDWR);
    if(fd_tts<0)
    {
        qDebug()<<"open tts failed";
    }

    fd_gpio=::open("/dev/gpio_drv",O_RDWR);
    if(fd_gpio<0)
    {
        qDebug()<<"open gpio_drv failed";
    }
    ::ioctl(fd_gpio,0x0,0);

    EventSpy *spy = new EventSpy;
    app.installEventFilter(spy);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/res/navtex.png"));
    splash->show();
    splash->setFont(QFont("ubuntu",16));
    splash->showMessage(QObject::tr("Load Window...     "),Qt::AlignVCenter|Qt::AlignHCenter,Qt::yellow);
    MainWin win;

    //QTest::qSleep(3000);
    splash->showMessage(QObject::tr("Display Window...     "),Qt::AlignHCenter|Qt::AlignVCenter,Qt::red);
    win.show();
    splash->finish(&win);
    delete splash;
    return app.exec();
}


