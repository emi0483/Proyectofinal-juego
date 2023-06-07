#include "Laberinto.h"
#include <QPainter>
#include <QRandomGenerator>
#include <QGraphicsRectItem>

Laberinto::Laberinto(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    generarLineasInternas();
}

QRectF Laberinto::boundingRect() const
{
    return QRectF(0,0,800,600); // Define los límites del laberinto
}

void Laberinto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,800,600, QPixmap(":/images/sprites/background/laberinto.png")); // Dibuja el fondo del laberinto

    // Dibuja las líneas internas
    for (QGraphicsLineItem* linea : lineasInternas) {
        linea->paint(painter, option, widget);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Laberinto::generarLineasInternas()
{

    QGraphicsLineItem* linea1 = new QGraphicsLineItem(35,5,35,78);
    lineasInternas.append(linea1);
}
