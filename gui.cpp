#include "gui.h"

gui::gui(QObject *parent) : QObject(parent)
{
  QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
  QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
  view = new QWebView();
  connect(this,SIGNAL(destroyed()),view,SLOT(deleteLater()));


  connect(view,SIGNAL(loadFinished(bool)),this,SLOT(PageLoaded(bool)));

  frame = view->page()->mainFrame();
  connect(frame,SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(PageAddJSObject()));
  frame->addToJavaScriptWindowObject("gui", this);

  const char s[]={TESTDIR};
  QString path(s);

  #if (QT_VERSION < 0x050000)
    path += "/test.html";
  #else
    path = "file://"+path+"/test.html";
  #endif

  qDebug() << "Set page:" << QUrl( path );
  view->setUrl(QUrl( path ));
  qDebug() << "Loading page:" << view->url();

  view->resize(800, 600);
  view->show();

  count = 0;
  timer.setInterval(1000);
  connect(&timer,SIGNAL(timeout()),this,SLOT(simulator()) );
  timer.start();
}

gui::~gui()
{
  view->close();
}

void gui::PageLoaded(bool ok){
  if(ok){
    qDebug() << "PageLoaded";
  }else{
    qWarning() << "Loading FAIL! " << view->url();
  }
}

void gui::PageAddJSObject(){
  qDebug() << "PageAddJSObject";
  view->page()->mainFrame()->addToJavaScriptWindowObject("gui", this);
}

void gui::debug(QString text) // DEBUG
{
  qDebug() << "JS: "<< text;
}

void gui::simulator() // DEBUG
{
  emit testSignal(count);
  count++;
}
