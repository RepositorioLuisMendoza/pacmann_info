#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuerpo.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new juego;
    ui->graphicsView->setFixedSize(700,700);
    scene->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);
    setWindowTitle("Pac Man");

//    enemigo = new enemy(10,120,180); // se crea fantasma
//    addItem(enemigo);

//   paredes_();
//   monedas_();

//    personaje = new cuerpo(150,35,35); // se crea bolita de pacman
//    personaje->select_sprite(0,0);

//    addItem(personaje);

//    timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
//    timer->start(5);

    //game->juego_();

}

MainWindow::~MainWindow()
{
    delete ui;
}

