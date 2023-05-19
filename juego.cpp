#include "juego.h"

juego::juego()
{
    QPixmap imagen;
    QBrush l;
    QImage r;
    r.load(":/imagenes/fondo.jpeg");
    l.setTextureImage(r);
    imagen.load(":/imagenes/fondo.jpeg");
    bolita_amarilla = new cuerpo(250,150,35);
    bolita_amarilla->setPos(155,105);
    //setBackgroundBrush(l);
    bolita_amarilla->select_sprite(0,0);
    addItem(bolita_amarilla);

    //setFocus();//conecta las teclas
}

void juego::keyPressEvent(QKeyEvent *event)
{
    // Movimiento de la bolita amarilla según las teclas de flecha
    if (event->type() == QKeyEvent::KeyPress) {
        switch (event->key()) {
            case Qt::Key_W:
                bolita_amarilla->Move_arriba();
                break;
            case Qt::Key_S:
                bolita_amarilla->Move_abajo();
                break;
            case Qt::Key_A:
                bolita_amarilla->Move_izquierda();
                break;
            case Qt::Key_D:
                bolita_amarilla->Move_derecha();
                break;
            default:
                QGraphicsScene::keyPressEvent(event);
        }
    }
}


