#include "cuerpo.h"
#include "juego.h"

int cuerpo::getPosx() const
{
    return posx;
}

void cuerpo::setPosx(int newPosx)
{
    posx = newPosx;
}

int cuerpo::getPosy() const
{
    return posy;
}

void cuerpo::setPosy(int newPosy)
{
    posy = newPosy;
}

cuerpo ::cuerpo(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
    complete = new QPixmap(":/imagenes/pngwing.com.png");
    image = 0;
    muerte = 0;
    nuevo = complete->copy(170, 0, 24*1, 24*11);
    *complete = complete->copy(415, 0, 24 * 1, 24 * 12);
    setPos(150, 76);
    actual = new QPixmap;
    time = new QTimer;
    //connect(time, SIGNAL(timeout()), this, SLOT(actualiza_sprite()));
    time->start(100);
}

void cuerpo::select_sprite(int x, int y)
{
    *actual = complete->copy(24 * x, 24 * y, 24, 24);
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



void cuerpo::verifificacion_( cuerpo& cuerpo )
{
    if (cuerpo.getPosx() <7 && cuerpo.getPosy() > 313) {
        cuerpo.setX(695);
        cuerpo.setY(318);
    }
}




void cuerpo::select_sprite_muerte(int x, int y)
{
    nuevo = complete->copy(24 * x, 24 * y, 24, 24);
    setPixmap(nuevo);
}



void cuerpo::muerte_personaje()
{

    while (muerte<11)
    {
        select_sprite_muerte(0,muerte);
        muerte++;
    }
    muerte=0;
}
