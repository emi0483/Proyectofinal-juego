#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public  QGraphicsView
{

public:
    Game(QWidget* parent=0);
    QGraphicsScene* scene;
    Player* player; //Es un puntero a un objeto Player, que representa al jugador en el juego
    Score* score; //Es un puntero a un objeto Score, que se utiliza para mantener y mostrar la puntuación del juego.
    Health* health; // Es un puntero a un objeto Health, que se utiliza para mantener y mostrar la salud del jugador.
};

#endif // GAME_H
