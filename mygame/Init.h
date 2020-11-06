#ifndef INIT_H
#define INIT_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include <Infection.h>
#include "Target.h"

class Init: public QGraphicsView {

public:
    Init(QWidget *parent = 0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Infection *infection;
    QTimer *spawnTimer;
    QTimer *PerksTimer;
    QGraphicsTextItem *endGameMessage;

};

#endif
