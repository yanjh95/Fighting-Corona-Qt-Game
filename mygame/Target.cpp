#include "Target.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Target::Target(): QObject(), QGraphicsPixmapItem() {
  int posx = rand() % 700;
  int posy = rand() % 500;
  setPos(posx,posy);
  setPixmap(QPixmap("/root/mygame/images/covid.png"));

  // change how virus looks
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(size()));
}

void Target::size() {
  // did not implement
}
