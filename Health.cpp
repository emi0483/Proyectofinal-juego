#include "Health.h"
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    health=3; //El valor incial de salud es 3

    //draw the text
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Health::decrease() //El método decrease() se utiliza para disminuir el valor de health en 1
{
    health--;
    setPlainText(QString("Health: ")+QString::number(health));

}

int Health::getHealth()
{
    return health;
}
