#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

class cuerpo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int r;
    int posx, posy;
    int velocidad = 5;


public:
    cuerpo(int r_, int x, int y);
    void select_sprite(int x, int y);
    void select_sprite_muerte(int x, int y);
    void Move_arriba();
    void Move_abajo();
    void Move_derecha();
    void Move_izquierda();
    void muerte_personaje();
    void verifificacion_(cuerpo& cuerpo);

    int getPosx() const;
    void setPosx(int newPosx);

    int getPosy() const;
    void setPosy(int newPosy);

private:
    QPixmap *complete, *actual, nuevo;
    QTimer *time;
    short image,muerte;
    int ANCHO_ESCENA;
    void actualiza_sprite(short dir);

};
#endif // CUERPO_H
