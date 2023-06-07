#include "NPC.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include "Player.h"
#include <QDebug>

NPC::NPC(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    int randomPosX = rand() % 750 + 100;
    int randomPosY = rand() % 320 + 210;
    setPos(randomPosX, randomPosY);
    setPixmap(QPixmap(":/images/sprites/personajes/npc.png"));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(colision()));
    timer->start(33);
}

void NPC::colision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    Player* player = dynamic_cast<Player*>(scene()->focusItem());
    if (!player)
        return;

    bool colision_izquierda = false;
    bool colision_derecha = false;
    bool colision_arriba = false;
    bool colision_abajo = false;

    for (int i = 0; i < colliding_items.size(); ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            qDebug() << "colision";
            qDebug() << "deberia ofrecer la misión y opción de aceptar o declinar";

                // Obtener la posición del jugador y del NPC
                QPointF jugador_pos = colliding_items[i]->pos();
            QPointF npc_pos = pos();

            // Determinar la dirección de la colisión
            if (jugador_pos.x() < npc_pos.x())
                colision_izquierda = true;
            else if (jugador_pos.x() > npc_pos.x())
                colision_derecha = true;

            if (jugador_pos.y() < npc_pos.y())
                colision_arriba = true;
            else if (jugador_pos.y() > npc_pos.y())
                colision_abajo = true;

            break;
        }
    }

    // Establecer las colisiones en el jugador
    player->setColisionIzquierda(colision_izquierda);
    player->setColisionDerecha(colision_derecha);
    player->setColisionArriba(colision_arriba);
    player->setColisionAbajo(colision_abajo);
}
