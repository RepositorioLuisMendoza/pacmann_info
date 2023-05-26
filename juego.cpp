#include "juego.h"

juego::juego()
{
    QBrush l;
    QImage r;
    r.load(":/imagenes/fondo.jpeg");
    l.setTextureImage(r);
    setBackgroundBrush(l);
    incremento_ = 0;


    cuenta=0;

    enemigo = new enemy(10,120,180); // se crea fantasma
    //enemigo->setPos(400,0);

    addItem(enemigo);

    paredes_();
    monedas_();

    personaje = new cuerpo(150,7,306); // se crea bolita de pacman
    personaje->select_sprite(0,0);

    addItem(personaje);

    timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(5);
    //personaje->ganaste();
    //timer->stop();
    //personaje->perdiste();


}

void juego::keyPressEvent(QKeyEvent *evento)
{

    if (personaje->collidesWithItem(enemigo))
    {
        //personaje->muerte_personaje();
        //removeItem(personaje);
        personaje->perdiste();
        //personaje->ganaste();
    }


    if(evento->key()==Qt::Key_D){
        if (personaje->collidesWithItem(enemigo))
        {
            //personaje->muerte_personaje();
            //removeItem(personaje);
            personaje->perdiste();
            //personaje->ganaste();
        }

        if (personaje->getPosx() >= 695 && personaje->getPosy() == 306){
            personaje->setPosx(4);
        }
         //Evaluacion de colision con monedas
         if (personaje->getPosx() <= 7 && personaje->getPosx() == 306){
             personaje->setPos(695,306);



         }
         personaje->Move_derecha();
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                 //puntaje->aumentar_puntaje(); // incremento de puntaje
                 //timer->stop();
                cuenta+=1;
                if (cuenta>=120)
                {personaje->ganaste();}

                 removeItem(monedas.at(i));
                 monedas.removeAt(i);

                 i--;
                 }
         }
        //Colicion con muros
        for (int i = 0;i < paredes.size();i++) {
             if(personaje->collidesWithItem(paredes.at(i))){
                personaje->Move_izquierda();




                 //personaje->setPos(pos);

             }
        }
    }
    else if(evento->key()==Qt::Key_S){
        // personaje->verifificacion_(*personaje);
         personaje->Move_abajo();
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                 // puntaje_->incremento(); // incremento de puntaje
                 removeItem(monedas.at(i));
                 monedas.removeAt(i);
                 cuenta+=1;
                 if (cuenta>=120)
                 {
                     personaje->ganaste();
                 }
                 i--;
                 }
         }
        //Colicion con muros
        for (int i = 0;i < paredes.size();i++) {
             if(personaje->collidesWithItem(paredes.at(i))){
                 personaje->Move_arriba();
                 //personaje->ganaste();
             }
        }
    }
    else if (evento->key()==Qt::Key_W){
       // personaje->verifificacion_(*personaje);
        personaje->Move_arriba();
         for (int i = 0;i < monedas.size();i++) {
              if(personaje->collidesWithItem(monedas.at(i))){
                 // puntaje_->incremento(); // incremento de puntaje
                 removeItem(monedas.at(i)); // eliminar moneda de esena
                 monedas.removeAt(i);
                 cuenta+=1;
                 if (cuenta>=120)
                 {
                     personaje->ganaste();
                 }

                 i--;
                 }
        }
        //Colicion con muros
        for (int i = 0;i < paredes.size();i++) {
             if(personaje->collidesWithItem(paredes.at(i))){
                personaje->Move_abajo();
                }
            }
        }
    else if (evento->key()==Qt::Key_A){

        if (personaje->getPosx() <= 4 && personaje->getPosy() == 306){
            personaje->setPosx(695);
        }
        personaje->Move_izquierda();
        for (int i = 0;i < monedas.size();i++) {
             if(personaje->collidesWithItem(monedas.at(i))){
                // puntaje_->incremento(); // incremento de puntaje
                 removeItem(monedas.at(i)); // eliminar moneda de esena
                 monedas.removeAt(i);
                 cuenta+=1;
                 if (cuenta>=120)
                 {
                     personaje->ganaste();
                 }
                 i--;
                }
            }
         //Colicion con muros
         for (int i = 0;i < paredes.size();i++) {
              if(personaje->collidesWithItem(paredes.at(i))){
                 personaje->Move_derecha();
                 }
            }
     }
}


QList<moneda *> juego::eliminarMonedas(QList<moneda *> monedas, int pos)
{
    QList<moneda *> aux;
    for (int i = 0;i < monedas.size() ; i++) {
        if(i != pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
    if (monedas.isEmpty())
    {
        personaje->ganaste();
        timer->stop();
    }
}




void juego::crear_pared(int x, int y, int ancho, int alto)
{
    paredes.push_back(new pared(x,y,ancho,alto));
    addItem(paredes.back());
}

void juego::crear_monedas(int x, int y, int ancho, int alto)
{
    monedas.push_back(new moneda(x,y,ancho,alto));
    addItem(monedas.back());
}

void juego::paredes_()
{
    crear_pared(0,0,700,34);
    crear_pared(0,0,34,233);
    crear_pared(666,0,34,233);
    crear_pared(0,398,34,700);
    crear_pared(666,400,34,300);
    crear_pared(0,667,700,34);
    crear_pared(257,267,74,34);
    crear_pared(257,267,34,99);
    crear_pared(257,267,34,99);
    crear_pared(409,300,34,66);
    crear_pared(369,267,74,34);
    crear_pared(33,199,114,34);
    crear_pared(113,233,34,65);
    crear_pared(0,267,148,34);
    crear_pared(0,333,148,34);
    crear_pared(114,366,34,65);
    crear_pared(0,399,148,34);
    crear_pared(551,200,149,34);
    crear_pared(551,200,34,100);
    crear_pared(551,267,149,34);
    crear_pared(551,333,34,100);
    crear_pared(551,399,149,34);
    crear_pared(72,66,75,34);
    crear_pared(184,66,112,34);
    crear_pared(404,66,112,34);
    crear_pared(552,66,75,34);
    crear_pared(72,134,75,34);
    crear_pared(552,134,75,34);
    crear_pared(184,333,34,100);
    crear_pared(479,333,34,100);
    crear_pared(184,466,112,34);
    crear_pared(404,466,112,34);
    crear_pared(72,466,75,34);
    crear_pared(114,466,34,100);
    crear_pared(551,466,75,34);
    crear_pared(551,466,34,100);
    crear_pared(257,134,186,34);
    crear_pared(330,166,34,64);
    crear_pared(218,200,75,34);
    crear_pared(184,134,34,166);
    crear_pared(404,200,75,34);
    crear_pared(479,134,34,166);
    crear_pared(330,433,34,67);
    crear_pared(257,399,186,34);
    crear_pared(257,533,186,34);
    crear_pared(330,566,34,67);
    crear_pared(479,533,34,66);
    crear_pared(404,599,223,34);
    crear_pared(184,533,34,66);
    crear_pared(72,599,224,34);
    crear_pared(331,34,34,66);
    crear_pared(34,533,40,34);
    crear_pared(626,533,40,34);
    crear_pared(552,333,200,34);
    crear_pared(286,333,148,34);
}

void juego::monedas_()
{
    crear_monedas(50,46,10,10);
    crear_monedas(159,46,10,10);
    crear_monedas(210,46,10,10);
    crear_monedas(260,46,10,10);
    crear_monedas(305,46,10,10);
    crear_monedas(380,46,10,10);
    crear_monedas(430,46,10,10);
    crear_monedas(470,46,10,10);
    crear_monedas(528,46,10,10);
    crear_monedas(580,46,10,10);
    crear_monedas(638,46,10,10);
    crear_monedas(50,78,10,10);
    crear_monedas(159,78,10,10);
    crear_monedas(305,78,10,10);
    crear_monedas(380,78,10,10);
    crear_monedas(528,78,10,10);
    crear_monedas(638,78,10,10);
    crear_monedas(50,110,10,10);
    crear_monedas(103,110,10,10);
    crear_monedas(159,110,10,10);
    crear_monedas(210,110,10,10);
    crear_monedas(260,110,10,10);
    crear_monedas(305,110,10,10);
    crear_monedas(380,110,10,10);
    crear_monedas(430,110,10,10);
    crear_monedas(483,110,10,10);
    crear_monedas(531,110,10,10);
    crear_monedas(580,110,10,10);
    crear_monedas(644,110,10,10);
    crear_monedas(50,145,10,10);
    crear_monedas(159,145,10,10);
    crear_monedas(531,145,10,10);
    crear_monedas(644,145,10,10);
    crear_monedas(50,176,10,10);
    crear_monedas(103,176,10,10);
    crear_monedas(159,176,10,10);
    crear_monedas(260,176,10,10);
    crear_monedas(305,176,10,10);
    crear_monedas(380,176,10,10);
    crear_monedas(430,176,10,10);
    crear_monedas(531,176,10,10);
    crear_monedas(580,176,10,10);
    crear_monedas(644,176,10,10);
    crear_monedas(305,212,10,10);
    crear_monedas(380,212,10,10);
    crear_monedas(531,212,10,10);
    crear_monedas(260,244,10,10);
    crear_monedas(305,244,10,10);
    crear_monedas(380,244,10,10);
    crear_monedas(430,244,10,10);
    crear_monedas(531,244,10,10);
    crear_monedas(50,308,10,10);
    crear_monedas(103,308,10,10);
    crear_monedas(159,308,10,10);
    crear_monedas(531,308,10,10);
    crear_monedas(580,308,10,10);
    crear_monedas(644,308,10,10);
    crear_monedas(531,342,10,10);
    crear_monedas(260,375,10,10);
    crear_monedas(305,375,10,10);
    crear_monedas(380,375,10,10);
    crear_monedas(430,375,10,10);
    crear_monedas(531,375,10,10);
    crear_monedas(531,408,10,10);
    crear_monedas(50,444,10,10);
    crear_monedas(103,444,10,10);
    crear_monedas(159,444,10,10);
    crear_monedas(210,444,10,10);
    crear_monedas(260,444,10,10);
    crear_monedas(305,444,10,10);
    crear_monedas(380,444,10,10);
    crear_monedas(430,444,10,10);
    crear_monedas(483,444,10,10);
    crear_monedas(531,444,10,10);
    crear_monedas(580,444,10,10);
    crear_monedas(644,444,10,10);
    crear_monedas(50,474,10,10);
    crear_monedas(159,474,10,10);
    crear_monedas(305,474,10,10);
    crear_monedas(380,474,10,10);
    crear_monedas(531,474,10,10);
    crear_monedas(644,474,10,10);
    crear_monedas(50,510,10,10);
    crear_monedas(159,510,10,10);
    crear_monedas(210,510,10,10);
    crear_monedas(260,510,10,10);
    crear_monedas(305,510,10,10);
    crear_monedas(380,510,10,10);
    crear_monedas(430,510,10,10);
    crear_monedas(483,510,10,10);
    crear_monedas(531,510,10,10);
    crear_monedas(644,510,10,10);
    crear_monedas(159,540,10,10);
    crear_monedas(531,540,10,10);
    crear_monedas(50,574,10,10);
    crear_monedas(103,574,10,10);
    crear_monedas(159,574,10,10);
    crear_monedas(260,574,10,10);
    crear_monedas(305,574,10,10);
    crear_monedas(380,574,10,10);
    crear_monedas(430,574,10,10);
    crear_monedas(531,574,10,10);
    crear_monedas(580,574,10,10);
    crear_monedas(644,574,10,10);
    crear_monedas(50,608,10,10);
    crear_monedas(305,608,10,10);
    crear_monedas(380,608,10,10);
    crear_monedas(644,608,10,10);
    crear_monedas(50,642,10,10);
    crear_monedas(103,642,10,10);
    crear_monedas(159,642,10,10);
    crear_monedas(210,642,10,10);
    crear_monedas(260,642,10,10);
    crear_monedas(305,642,10,10);
    crear_monedas(380,642,10,10);
    crear_monedas(430,642,10,10);
    crear_monedas(483,642,10,10);
    crear_monedas(531,642,10,10);
    crear_monedas(580,642,10,10);
    crear_monedas(644,642,10,10);

}

void juego::moveEnemy()
{
    enemigo->up();

        for (int i = 0;i < paredes.size();i++)
        {
            if(enemigo->collidesWithItem(paredes.at(i)))
            {
                enemigo->down();
            }
        }

        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->up();
             }
        }

        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->up();
             }
        }

        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->up();
             }
        }


        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->up();
             }
        }

}





