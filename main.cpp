
#include <QtGui>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *gbk = QTextCodec::codecForName("gb18030");
    QTextCodec *utf8 = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForTr(utf8);
    QTextCodec::setCodecForLocale(gbk);

    MainWindow *win = new MainWindow;
    win->resize(800,600);
    win->show();

/*
    QWidget window;

    QLabel* title = new QLabel("Custom widgets on a QListWidget");
    title->setAlignment(Qt::AlignHCenter);

    QListWidget* list = new QListWidget;
    list->addItem("foo");

    QListWidgetItem* item;
    item = new QListWidgetItem(list);
    list->addItem(item);
    QPushButton* button = new QPushButton("hey");
    item->setSizeHint(button->minimumSizeHint());
    list->setItemWidget(item, button);

    list->addItem("bar");

    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->addWidget(title);
    layout->addWidget(list);

    window.setLayout(layout);
    //window.resize(QSize(800,600));
    window.resize(800,600);
    window.show();
*/



    return a.exec();
}
