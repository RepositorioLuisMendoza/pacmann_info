#ifndef JUEGO_H
#define JUEGO_H
#include <QGraphicsScene>
#include "cuerpo.h"
#include <QKeyEvent>
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

#include "cuerpo.h"
#include "enemy.h"
#include "pared.h"
#include "moneda.h"
#include "puntaje.h"
#include "database.h"



class juego : public QGraphicsScene
{
public:
    juego();
    void juego_();
    void paredes_ ();
    void monedas_();

protected:
    void keyPressEvent(QKeyEvent *evento);

private:
    cuerpo *personaje;
    enemy *enemigo;

    QList<moneda *> monedas;
    QList <pared*> paredes;
    QTimer *timer;

    QList<moneda *> eliminarMonedas(QList<moneda *> monedas,int pos);
    void crear_pared(int x, int y, int ancho, int alto);
    void crear_monedas (int x, int y, int ancho, int alto);
    void teletransportacion();

public slots:
    void moveEnemy();
};

#endif // JUEGO_H





