#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem // Declaración de la clase "Bullet" que hereda públicamente de QObject y QGraphicsPixmapItem.
{
    Q_OBJECT

public:
    Bullet(QGraphicsItem* parent=0); 
//Declaración del constructor de la clase "Bullet". Toma un puntero a un objeto QGraphicsItem como argumento y tiene un valor predeterminado de 0 (puntero nulo).

public slots:
    void move(); //Declaración de la ranura "move()", que se llama cuando se produce una señal relacionada con el movimiento de la bala.
};


#endif // BULLET_H
