#include "Init.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>


Init::Init(QWidget *parent) {

  // create the scene
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  setBackgroundBrush(QBrush(QImage("/root/mygame/images/room.png")));
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(800,600);

  // create the player
  player = new Player();
  player->setPixmap(QPixmap("/root/mygame/images/wipe.png"));
  player->setPos(400,300);
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  scene->addItem(player);

  // score
  score = new Score();
  scene->addItem(score);
  score->setPos(0,0);

  // infection
  infection = new Infection();
  scene->addItem(infection);
  infection->setPos(0,20);

  // spawn Virus
  spawnTimer = new QTimer();
  QObject::connect(spawnTimer, SIGNAL(timeout()), player, SLOT(spawnVirus()));
  spawnTimer->start(2000);

  // spawn Perks or Masks
  PerksTimer = new QTimer();
  QObject::connect(PerksTimer, SIGNAL(timeout()), player, SLOT(spawnPerks()));
  PerksTimer->start(10000);

  // END GAME MESSAGE
  endGameMessage = new QGraphicsTextItem();
  show();
}
