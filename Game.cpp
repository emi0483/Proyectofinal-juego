#include "Game.h"
#include "Enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget* parent) //Toma un puntero a QWidget como argumento, que se utiliza como padre del objeto Game
{
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    //setBackgroundBrush(QBrush(":/imagenes/sprites/BackGrounds/ciudad2.png"));

    setScene(scene); //Se crea una nueva escena gráfica (QGraphicsScene) y se establece su rectángulo de escena en las coordenadas (0,0) con un ancho de 800 y una altura de 600 píxeles
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Desactiva politicas de movimiento 
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //desactiva lopliticas de movimiento
    setFixedSize(880,608);

    player = new Player(); //Se crea un nuevo objeto Player y se establece su posición en (-150, 200) en la escena. Este objeto representará al jugador del juego.
    player->setPos(-150,200);

    player->setFlag(QGraphicsItem::ItemIsFocusable); //Se establecen las propiedades del objeto player para que pueda recibir el enfoque y responder a eventos de teclado. 
    //Esto permitirá al jugador controlar el objeto player con las teclas.
    player->setFocus();

    scene->addItem(player);

    //Se crean objetos Score y Health, que se utilizan para mostrar la puntuación y la salud del jugador en el juego. Estos objetos se agregan a la escena y se establece su posición.
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x()+140,health->y());
    scene->addItem(health);

    //Se crea un objeto QTimer que se utilizará para generar eventos de tiempo en intervalos regulares. 
    //Luego se establece una conexión entre la señal timeout() del temporizador y la ranura spawn() del objeto player. 
    //Esto significa que cada vez que el temporizador expire   
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
}
