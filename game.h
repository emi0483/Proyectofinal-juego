#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget* parent=0);

private:
    QGraphicsScene* scene;
};

#endif // GAME_H
