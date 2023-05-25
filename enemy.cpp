#include "enemy.h"
#include <QTimer>
#include <QPixmap>

enemy::enemy(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx, posy);
    imagen = new QPixmap(":/imagenes/pngwing.com.png");
    muerto = 0;
    *imagen = imagen->copy(550, 0, 25 * 1, 25 * 8);
    setPos(300, 76);
    actuali = new QPixmap;
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(down()));
    time->start(100);
}

void enemy::select_sprite_enemy(int x, int y)
{
    *actuali = imagen->copy(24 * x, 24 * y, 24, 24);
    setPixmap(*actuali);
}

void enemy::actualiza_sprite_enemy(short dir)
{
    if (muerto <= 2)
    {
        select_sprite_enemy(0, muerto + 2 * dir);
        muerto++;
    }
    else
    {
        muerto = 0;
    }
}

void enemy::up()
{
    posy -= 3;
    setPos(posx, posy);
    actualiza_sprite_enemy(1);
}

void enemy::down()
{
    posy += 3;
    setPos(posx, posy);
    actualiza_sprite_enemy(2);
}

void enemy::left()
{
    posx -= 3;
    setPos(posx, posy);
    actualiza_sprite_enemy(3);
}

void enemy::right()
{
    posx += 3;
    setPos(posx, posy);
    actualiza_sprite_enemy(4);
}
