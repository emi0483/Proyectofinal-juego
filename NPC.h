#ifndef NPC_H
#define NPC_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class NPC : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    NPC(QGraphicsItem* parent = nullptr);

public slots:
    void colision();
};

#endif // NPC_H
