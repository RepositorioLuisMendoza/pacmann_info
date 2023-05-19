#include "cuerpo.h"
#include "juego.h"

cuerpo ::cuerpo(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
    complete = new QPixmap(":/imagenes/pngwing.com.png");
    image = 0;
    int ANCHO_ESCENA = 500;


    *complete = complete->copy(415, 0, 25 * 1, 25 * 12);
    setPos(150, 76);
    actual = new QPixmap;
    time = new QTimer;
    //connect(time, SIGNAL(timeout()), this, SLOT(actualiza_sprite()));
    time->start(100);
}

void cuerpo::select_sprite(int x, int y)
{
    *actual = complete->copy(25 * x, 25 * y, 25, 25);
    setPixmap(*actual);
}

void cuerpo::actualiza_sprite(short dir)
{

    if (image<=2)
    {
        select_sprite(0,image+3*dir);
        image++;
    }
    else
    {
        image=0;
    }
}






void cuerpo::Move_arriba()
{
    posy -= 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite(3);
    //setRotation(-80);
}

void cuerpo::Move_abajo()
{
    posy += 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite(1);
    //setRotation(80);
}

void cuerpo::Move_izquierda()
{
    posx -= 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite(2);
    //setRotation(180);
}

void cuerpo::Move_derecha()
{
    posx += 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite(0);
    //setRotation(0);

}

void cuerpo::muerte_personaje()
{

    while (muerte<11)
    {
        select_sprite(0,muerte);
        muerte++;
    }
    muerte=0;
}
