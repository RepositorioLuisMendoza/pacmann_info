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
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    cuerpo *bolita_amarilla;
};

#endif // JUEGO_H








