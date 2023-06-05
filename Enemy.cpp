#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsItem>
#include "Game.h"

extern Game* game; 
//Declara una variable externa global llamada "game" de tipo puntero a un objeto de la clase "Game". Esta variable se define en otro lugar del programa y se utiliza para acceder a otros componentes del juego, como la salud.



Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
//Toma un puntero a un objeto QGraphicsItem como argumento y establece la posición y la imagen del enemigo.
{
    //set random position
    int randomPos =rand() % 750 + (-200); // + (-200) //enera una posición aleatoria para el enemigo en el rango de -200 a 549
    setPos(randomPos,-190); // La coordenada x se establece como la posición aleatoria generada y la coordenada y se establece en -190
    setPixmap(QPixmap(":/imagenes/sprites/explocion/albondiga.png")); //Establece la imagen del enemigo utilizando un archivo de imagen.

    QTimer* timer = new QTimer(this); //Crea un nuevo temporizador QTimer y lo asigna a la variable "timer". Se establece el objeto actual ("this") como el padre del temporizador.
    connect(timer, SIGNAL(timeout()), this, SLOT(move())); //Conecta la señal de tiempo de espera del temporizador a la ranura "move()" de la clase "Enemy". 
    //Esto significa que cada vez que el temporizador emita la señal de tiempo de espera, se llamará a la función "move()".
    timer->start(50);
}

void Enemy::move()
{
    //Genera una velocidad aleatoria para el enemigo en el rango de 3 a 12. La función rand() devuelve un número entero aleatorio y el operador % se utiliza para obtener el resto de la división del número aleatorio por 10. 
//Luego, se le suma 3 para obtener el rango deseado.
    int randomVel = rand() % 10 + 3; //
    setPos(x(),y()+randomVel); //Actualiza la posición del enemigo moviéndolo hacia abajo según la velocidad aleatoria generada.
    if (pos().y() > 360){ //Verifica si la posición y del enemigo supera el valor de 360. Esto indica que el enemigo ha llegado a la parte inferior de la escena.
        //decrease the health
        game->health->decrease(); //Accede al objeto "health" del objeto "game" (que es una variable externa global) y llama a la función "decrease()" para disminuir la salud del jugador.

        scene()->removeItem(this); //Accede a la escena a la que pertenece el enemigo y lo elimina de la escena.
        delete this;
    }
}
