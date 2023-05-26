#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QLabel>
#include <QString>
class puntaje
{
public:
    puntaje();
    void aumentar_puntaje();


private:
    QLabel* puntajeLabel;
    int incremento_;
};

#endif // PUNTAJE_H
