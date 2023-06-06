#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>
#include <QGraphicsItem>
#include <QSizeF>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(const QString &filename, QGraphicsItem *parent= nullptr);
    void keyPressEvent(QKeyEvent* event);





private:


public slots:
    void spawn();


#endif // PLAYER_H
