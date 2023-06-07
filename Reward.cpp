#include "Reward.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsItem>
#include "Game.h"

Reward::Reward(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/sprites/items/cajaFuerte.png"));
    //setPixmap(QPixmap(":/images/sprites/items/pizza.png"));

}

