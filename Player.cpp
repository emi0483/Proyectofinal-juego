#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent),
    m_colision_izquierda(false),
    m_colision_derecha(false),
    m_colision_arriba(false),
    m_colision_abajo(false)
{
    setPixmap(QPixmap(":/images/sprites/personajes/inicial.png"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_A) {
        if (!m_colision_izquierda)
            setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_D) {
        if (!m_colision_derecha)
            setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_W) {
        if (!m_colision_arriba)
            setPos(x(), y() - 10);
    } else if (event->key() == Qt::Key_S) {
        if (!m_colision_abajo)
            setPos(x(), y() + 10);
    }
}

void Player::setColisionIzquierda(bool colision)
{
    m_colision_izquierda = colision;
}

void Player::setColisionDerecha(bool colision)
{
    m_colision_derecha = colision;
}

void Player::setColisionArriba(bool colision)
{
    m_colision_arriba = colision;
}

void Player::setColisionAbajo(bool colision)
{
    m_colision_abajo = colision;
}
