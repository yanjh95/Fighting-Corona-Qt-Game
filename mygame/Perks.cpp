#include "Perks.h"
#include <QGraphicsScene>
#include <stdlib.h>

Perks::Perks(): QGraphicsPixmapItem() {
  int posx = rand() % 700;
  int posy = rand() % 500;
  setPos(posx,posy);
  setPixmap(QPixmap("/root/mygame/images/mask.png"));
}
