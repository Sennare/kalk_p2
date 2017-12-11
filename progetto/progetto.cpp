#include "progetto.h"
#include "ui_progetto.h"

Progetto::Progetto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Progetto)
{
    ui->setupUi(this);
}

Progetto::~Progetto()
{
    delete ui;
}
