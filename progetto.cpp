#include "progetto.h"
#include "ui_progetto.h"
#include "logica/wave.h"
#include<QString>
Progetto::Progetto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Progetto)
{
    ui->setupUi(this);
    QString stringa = "3,4,5,3,6";
    Wave onda1(stringa);
    stringa="3,4,8";
    Wave onda2(stringa);
    /*onda1.pushAmpVal(2);
    onda1.pushAmpVal(-4);
    onda1.pushAmpVal(6);
    onda2.pushAmpVal(1);
    onda2.pushAmpVal(7);
    onda1.setAmpVal(1, 5);
    onda1.removeAmpVal(2);*/
    Wave onda3;
    onda3 = onda1 + onda2;
    ui->label->setText(onda3.getString());
}

Progetto::~Progetto()
{
    delete ui;
}
