#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>


//para seleccionar origen de archivo a abrir
#include <QFileDialog>
//para cargar imagenes y proporciones
#include <QPixmap>
//para ver cantidades de color
#include <QColor>
//para transparencias de foto
#include <QPainter>


#include <iostream>//libreria pruebas
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mEscenainicial = new Escenainicial(this);
    mHilo = new Hilo (this);
    ui->graphicsView->setEscenainicial(mEscenainicial);
    layout()->setMargin(0);

    conect(mHilo, &Hilo::already;[&](){ emit update(); });
    conect (this, &MainWindow::update, mEscenainicial, &Escenainicial::onUpdate);
    mHilo->start(MSEC, QThread::HighestPriority);


}

MainWindow::~MainWindow()
{
    delete ui;
}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;

    QGraphicsView view;
    view.setRenderHint(QPainter::Antialiasing);
    view.setScene(new Scene(&mainWindow));
    mainWindow.setCentralWidget(&view);

    mainWindow.show();

    return app.exec();
}
