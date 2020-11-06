#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",20));
}

void Score::increase(){
    score  = score + 1;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
