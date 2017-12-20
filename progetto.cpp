#include "progetto.h"
#include "ui_progetto.h"
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
    Complex a(4, 3);
    Complex b(3, -2);
    Complex c = a/b;
    ui->label->setText(c.getStr());
}
