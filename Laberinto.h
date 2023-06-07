#ifndef LABERINTO_H
#define LABERINTO_H

#include <QGraphicsItem>
#include <QVector>

class Laberinto : public QGraphicsItem
{
public:
    Laberinto(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QGraphicsLineItem*> lineasInternas; // Vector para almacenar las líneas internas

    void generarLineasInternas(); // Genera líneas internas en posiciones aleatorias
};

#endif // LABERINTO_H
