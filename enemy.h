#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class QTimer;

class enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    enemy(int r_, int x, int y);

public slots:
    void up();
    void down();
    void left();
    void right();

private:
    int r;
    int posx, posy;
    QPixmap *imagen, *actuali;
    QTimer *time;
    short cambio, muerto;
    void select_sprite_enemy(int x, int y);
    void actualiza_sprite_enemy(short dir);
};

#endif // ENEMY_H
