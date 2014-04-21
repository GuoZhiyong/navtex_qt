#include "eventspy.h"
#include <QEvent>
#include "common.h"

#include <sys/ioctl.h>

EventSpy::EventSpy(QObject *parent) : QObject(parent)
{

}




bool EventSpy::eventFilter(QObject *obj, QEvent *event)
{
    //qDebug("%d", event->type());
 //   int buf1[2]={33,1};
 //   int buf2[2]={196,1};

    //if(event->type()==QEvent::SockAct)
    if((event->type()==QEvent::MouseButtonPress)||(event->type()==QEvent::KeyPress))
    {
        qDebug("%d", event->type());
        ::ioctl(fd_gpio,0x0,0);  //更新显示背光计时
        //::write(fd_gpio,buf1,8); //按键背光亮
        //::write(fd_gpio,buf2,8); //LCD背光亮
    }
    return QObject::eventFilter(obj, event);
}
