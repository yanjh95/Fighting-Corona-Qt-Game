#include "Infection.h"
#include <QFont>

Infection::Infection(QGraphicsItem *parent): QGraphicsTextItem(parent){
  // initialize
  infection = 0;
  maxInfection = 35;

  // draw the text
  setPlainText(QString("Infection Level: ") + QString::number(infection) + QString("/") + QString::number(maxInfection));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times",20));
}

void Infection::increase(){
  infection  = infection + 1;
  setPlainText(QString("Infection Level: ") + QString::number(infection) + QString("/") + QString::number(maxInfection));
}

void Infection::decrease(){
  infection  = infection - 1;
  setPlainText(QString("Infection Level: ") + QString::number(infection) + QString("/") + QString::number(maxInfection));
}

int Infection::getInfection(){
  return infection;
}
