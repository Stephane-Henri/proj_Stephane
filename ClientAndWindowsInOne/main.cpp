#include "mainwindow.h"
#include "client.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client *cl = client::getInstance();
    MainWindow w;
    return a.exec();
}
