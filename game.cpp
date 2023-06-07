#include "game.h"
#include "Ciudad.h"
#include <QGraphicsScene>
#include "Player.h"
#include "NPC.h"

Game::Game(QWidget* parent)
{
    //crear la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    //set the scene
    setScene(scene);

    //crear la ciudad
    Ciudad* ciudad = new Ciudad();

    //la añadimos a la escena
    scene->addItem(ciudad);

    //anadir jugador
    Player* player = new Player();
    player->setPos(0,240);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    NPC* npc = new NPC();
    npc->setPos(400,230);
    scene->addItem(npc);
}

