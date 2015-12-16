#ifndef GUI_H
#define GUI_H

#include <QDebug>

#include <QObject>
#include <QWebView>
#include <QWebFrame>
#include <QWebSettings>

#include <QTimer>

class gui : public QObject
{
  Q_OBJECT
public:
  explicit gui(QObject *parent = 0);
  ~gui();

signals:
  void testSignal(int);

public slots:
  void debug(QString);
private:
  QWebView *view;
  QWebFrame *frame;

  QTimer timer;
  int count;
private slots:
  void PageLoaded(bool);
  void PageAddJSObject();
  void simulator();
};

#endif // GUI_H
