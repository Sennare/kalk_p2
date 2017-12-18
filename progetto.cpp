#include "progetto.h"
#include "ui_progetto.h"
#include <QApplication>
#include <QPushButton>

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
    ui->label->setText("clicked");
}
