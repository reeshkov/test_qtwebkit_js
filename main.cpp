#include "gui.h"
//#include <QCoreApplication>
#include <QApplication>


int main(int argc, char *argv[])
{
  //QCoreApplication a(argc, argv);
  QApplication a(argc, argv); //, QApplication::GuiServer);
  gui g(&a);
  return a.exec();
}
