#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QString>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QTimer>

#include "juego.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }


QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    juego *scene;
    QTimer *timer;

    cuerpo *personaje;
    enemy *enemigo;

    QList<moneda *> monedas;
    QList <pared*> paredes;

//juego *game;



public slots:



};
#endif // MAINWINDOW_H
