#include "ganaste.h"
#include "ui_ganaste.h"

ganaste::ganaste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ganaste)
{
    ui->setupUi(this);
}

ganaste::~ganaste()
{
    delete ui;
}
