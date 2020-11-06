#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Target: public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

public:
  Target();

public slots:
  void size();
};

#endif
