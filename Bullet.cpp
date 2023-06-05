#include "Bullet.h"
#include <QTimer> //Incluye la biblioteca QTimer, que proporciona una funcionalidad de temporizador.
#include <QGraphicsScene> // Incluye la biblioteca QGraphicsScene, que proporciona una escena 2D para representar gráficos.
#include <Enemy.h>
#include <Qlist> //Incluye la biblioteca QList, que proporciona una lista de elementos.
#include "Game.h"

extern Game* game; // Declara una variable externa global llamada "game" de tipo puntero a un objeto de la clase "Game".
 //Esta variable se define en otro lugar del programa y se utiliza para acceder a otros componentes del juego, como el puntaje.

Bullet::Bullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent) 
//Toma un puntero a un objeto QGraphicsItem como argumento y establece una imagen de mapa de bits para la bala.
{
    setPixmap(QPixmap(":/imagenes/sprites/explocion/Dibujo 3.png"));

    QTimer* timer = new QTimer(this); //Crea un nuevo temporizador QTimer y lo asigna a la variable "timer". Se establece el objeto actual ("this") como el padre del temporizador.
    connect(timer, SIGNAL(timeout()), this, SLOT(move())); //Conecta la señal de tiempo de espera del temporizador a la ranura "move()" de la clase "Bullet". 
    //Esto significa que cada vez que el temporizador emita la señal de tiempo de espera, se llamará a la función "move()".
    timer->start(50); //Inicia el temporizador con un intervalo de tiempo de 50 milisegundos.

}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); 
    //Crea una lista de punteros a elementos gráficos llamada "colliding_items" y la inicializa con los elementos gráficos con los que la bala está colisionando en la escena.
    for(int i=0, n = colliding_items.size(); i < n; ++i){ //Itera sobre la lista de elementos colisionantes.
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){ // Verifica si el elemento colisionante actual es de tipo "Enemy" comparando los tipos utilizando la función "typeid".
            //increase score
            game->score->increase();

            //remove  them from the scene
            scene()->removeItem(colliding_items[i]); //Accede a la escena a la que pertenece la bala y elimina el elemento colisionante de la escena.
            scene()->removeItem(this);

            //delete  them from de heap
            delete colliding_items[i];
            delete this;
            return;
        }

    }

    setPos(x(),y()-10);
    if (pos().y()+boundingRect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
