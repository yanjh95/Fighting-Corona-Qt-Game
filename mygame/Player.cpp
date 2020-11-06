#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Target.h"
#include <QList>
#include "Init.h"
#include <typeinfo>
#include <QTimer>
#include "Perks.h"

extern Init *init;

void Player::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Left) {
    if (pos().x() > 0) {
      setPos(x() - 10,y());
    }
  }
  else if (event->key() == Qt::Key_Right) {
    if (pos().x() + 50 < 800) {
      setPos(x() + 10,y());
    }
  }
  else if (event->key() == Qt::Key_Up) {
    if (pos().y() > 0) {
      setPos(x(), y() - 10);
    }
  }
  else if (event->key() == Qt::Key_Down) {
    if (pos().y() + 50 < 600) {
      setPos(x(), y() + 10);
    }
  }

  QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
      if (typeid(*(colliding_items[i])) == typeid(Target)) {

        // increase the score
        init->score->increase();

        //remove item from scene
        scene()->removeItem(colliding_items[i]);
        delete colliding_items[i];

        //decrease infection
        init->infection->decrease();

        return;
      }
      else if (typeid(*(colliding_items[i])) == typeid(Perks)) {
        //add to max infection
        init->infection->maxInfection += 1;
        //remove item from scene
        scene()->removeItem(colliding_items[i]);
        delete colliding_items[i];

        return;
      }
    }
}

void Player::spawnPerks() {
  //add Masks
  Perks *perks = new Perks();
  scene()->addItem(perks);
}

void Player::spawnVirus() {
  // add virus in the scene
  Target *target = new Target();
  scene()->addItem(target);

  //add infection count
  init->infection->increase();

  //increase spawn rate
  init->spawnTimer->stop();
  int tmp = init->score->getScore();
  if(tmp > 150) {
    tmp = 150;
  }
  init->spawnTimer->start(250 - tmp + 2000 /(1 + init->infection->getInfection()/2));

  //check if got infected
  if(init->infection->getInfection() > init->infection->maxInfection) {

    //message setBackground
    QGraphicsRectItem *backGround = new QGraphicsRectItem();
    backGround->setRect(0,0,650,100);
    backGround->setPos(80,280);
    backGround->setBrush(Qt::black);
    scene()->addItem(backGround);
    //message
    init->endGameMessage->setPlainText(QString("You Have Been Infected!"));
    init->endGameMessage->setDefaultTextColor(Qt::red);
    init->endGameMessage->setFont(QFont("times",50));
    scene()->addItem(init->endGameMessage);
    init->endGameMessage->setPos(100,300);
    init->spawnTimer->stop();
  }
}
