#include "escenas.h"#include <QApplication>
#include <QMainWindow>
#include <QPixmap>
#include <QPalette>
#include <QBrush>

int main(int argc, char *argv[])
{

}


Escenas::Escenas(int argc, char *argv[])
{
    QMainWindow w;
    w.resize(640, 480);
    QPixmap background("/data:image/png;base64,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");
    // background = background.scaled(w.size(), Qt::IgnoreAspectRatio);
    QPalette pal = w.palette();
    pal.setBrush(QPalette::Background, QBrush(background));
    w.setPalette(pal);
    w.show();
    return app.exec()
}