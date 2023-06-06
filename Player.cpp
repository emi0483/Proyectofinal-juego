#include <QGraphicsScene>
#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QPainter>

Player::Player(const Qstring &filename, QGraphicsItem* parent);
{
    setPixmap(QPixmap(":/imagenes/sprites/MC/inicial.png"));
    mFilename= filename;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        if(pos().x()>-170)  setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x()<570) setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_W){
        if (pos().y()>100) setPos(x(),y()-10);

    }
    else if (event->key() == Qt::Key_S){
        if (pos().y()<320) setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x(),y()); //se volvió loco despues de añadir los graficos, tocó restarle a cada posicion en ensayo y error
        scene()->addItem(bullet);

    }
class Playerelipse : public QGraphicsEllipseItem
{
public:
    Player() : QGraphicsEllipseItem(-10, -10, 20, 20) {
        setBrush(Qt::red);
    }

    void keyPressEvent(QKeyEvent* event) override {
        if (event->key() == Qt::Key_Right) {
            setPos(x() + 10, y());
        } else if (event->key() == Qt::Key_Left) {
            setPos(x() - 10, y());
        } else if (event->key() == Qt::Key_Up) {
            setPos(x(), y() - 10);
        } else if (event->key() == Qt::Key_Down) {
            setPos(x(), y() + 10);
        }
    }
};
class Object : public QGraphicsEllipseItem
{
public:
    Object() : QGraphicsEllipseItem(-30, -30, 60, 60) {
        setPos(200, 200);
        setBrush(Qt::blue);
    }
};
}
void Player::spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

