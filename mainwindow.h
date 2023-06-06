#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class MainWindow;
QT_END_NAMESPACE

class Escenainicial;
class Hilo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void update();

private:
    Ui::MainWindow *ui;
    Escenainicial *mEscenainicial;
    Hilo *mHilo;
};
#endif // MAINWINDOW_H
