#include "progetto.h"
#include "ui_progetto.h"
#include "real.h"
#include "complex.h"
#include <QApplication>
#include <QPushButton>
#include <QString>

Progetto::Progetto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Progetto)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT (slotButtonClicked()));
}

Progetto::~Progetto()
{
    delete ui;
}

void Progetto::slotButtonClicked() {
    /*Complex a(4, 3);
    Complex b(3, -2);
    Complex c = a/b;*/
    Real r1(2.8);
    Real r2(7.3);
    Real rf = r1+r2;
    ui->label->setText(rf.getString());
}
