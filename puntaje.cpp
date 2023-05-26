
#include "puntaje.h"

puntaje::puntaje()
{
    incremento_ = 0;
    puntajeLabel = new QLabel(nullptr);
    puntajeLabel->setText("Puntaje: 0");
    puntajeLabel->move(10, 10);
}
void puntaje :: aumentar_puntaje()
{
    incremento_ +=1;
    puntajeLabel->setText("Puntaje: " + QString::number(incremento_));
}
