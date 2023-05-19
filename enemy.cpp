#include "enemy.h"


enemy::enemy(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
    imagen = new QPixmap(":/imagenes/pngwing.com.png");
    muerto = 0;

    *imagen = imagen->copy(550, 0, 35 * 1, 35 * 3);
    setPos(300, 76);
    actuali = new QPixmap;
    time = new QTimer;
    connect(time, SIGNAL(timeout()), this, SLOT(up));
    time->start(100);
}

QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void enemy::up()
{
    posy -= 3;
    setPos(posx, posy);
}

void enemy::down()
{
    posy += 3;
    setPos(posx, posy);
}

void enemy::left()
{
    posx -= 3;
    setPos(posx, posy);
}

void enemy::right()
{
    posx += 3;
    setPos(posx, posy);
}
