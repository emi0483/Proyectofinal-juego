#ifndef REWARD_H
#define REWARD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Reward : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Reward(QGraphicsItem* parent = nullptr);

};

#endif // REWARD_H
