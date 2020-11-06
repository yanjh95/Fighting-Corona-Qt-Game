#ifndef INFECTION_H
#define INFECTION_H

#include <QGraphicsTextItem>

class Infection: public QGraphicsTextItem {

public:
  Infection(QGraphicsItem *parent = 0);
  void increase();
  void decrease();
  int getInfection();
  int infection;
  int maxInfection;

};

#endif
