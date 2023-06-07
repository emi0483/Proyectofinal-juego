#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent* event);

    // Setter para las colisiones
    void setColisionIzquierda(bool colision);
    void setColisionDerecha(bool colision);
    void setColisionArriba(bool colision);
    void setColisionAbajo(bool colision);

private:
    bool m_colision_izquierda;
    bool m_colision_derecha;
    bool m_colision_arriba;
    bool m_colision_abajo;
};

#endif // PLAYER_H
