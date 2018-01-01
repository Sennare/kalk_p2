#include "progetto.h"
#include "ui_progetto.h"
#include "real.h"
#include "complex.h"
#include "quaternion.h"
#include <QApplication>
#include <QPushButton>
#include <QString>

Progetto::Progetto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Progetto)
{
    ui->setupUi(this);

    connect(ui->realSum,    SIGNAL(clicked(bool)), this, SLOT (slotRealSum()));
    connect(ui->realSottr,  SIGNAL(clicked(bool)), this, SLOT (slotRealSottr()));
    connect(ui->realPer,    SIGNAL(clicked(bool)), this, SLOT (slotRealMult()));
    connect(ui->realDiv,    SIGNAL(clicked(bool)), this, SLOT (slotRealDiv()));
    connect(ui->complexSum, SIGNAL(clicked(bool)), this, SLOT (slotComplexSum()));
    connect(ui->complexSottr, SIGNAL(clicked(bool)), this, SLOT (slotComplexSottr()));
    connect(ui->complexPer, SIGNAL(clicked(bool)), this, SLOT (slotComplexPer()));
    connect(ui->complexDiv, SIGNAL(clicked(bool)), this, SLOT (slotComplexDiv()));
    connect(ui->quaternionSum, SIGNAL(clicked(bool)), this, SLOT (slotQuaternionSum()));
    connect(ui->quaternionSottr, SIGNAL(clicked(bool)), this, SLOT (slotQuaternionSottr()));
    connect(ui->quaternionPer, SIGNAL(clicked(bool)), this, SLOT (slotQuaternionPer()));
    connect(ui->quaternionDiv, SIGNAL(clicked(bool)), this, SLOT (slotQuaternionDiv()));
}

Progetto::~Progetto()
{
    delete ui;
}
/*Complex a(4, 3);
Complex b(3, -2);
Complex c = a/b;*/
Real r1(2.8);
Real r2(7.3);

void Progetto::slotRealSum() {
    Real rf = r1+r2;
    ui->label->setText(rf.getString());
}

void Progetto::slotRealSottr() {
    Real rf = r1-r2;
    ui->label->setText(rf.getString());
}

void Progetto::slotRealMult() {
    Real rf = r1*r2;
    ui->label->setText(rf.getString());
}

void Progetto::slotRealDiv() {
    Real rf = r1/r2;
    ui->label->setText(rf.getString());
}

// COMPLEX
Complex c1(4, 3);
Complex c2(5, -2);

void Progetto::slotComplexSum() {
    Complex rf = c1+c2;
    ui->label->setText(rf.getString());
}

void Progetto::slotComplexSottr() {
    Complex rf = c1-c2;
    ui->label->setText(rf.getString());
}

void Progetto::slotComplexPer() {
    Complex rf = c1*c2;
    ui->label->setText(rf.getString());
}

void Progetto::slotComplexDiv() {
    Complex rf = c1/c2;
    ui->label->setText(rf.getString());
}

// QUATERNION
Quaternion q1(4, 3, 7, 2);
Quaternion q2(5, -2, 2, -1);

void Progetto::slotQuaternionSum() {
    Quaternion rf = q1+q2;
    ui->label->setText(rf.getString());
}

void Progetto::slotQuaternionSottr() {
    Quaternion rf = q1-q2;
    ui->label->setText(rf.getString());
}

void Progetto::slotQuaternionPer() {
    Quaternion rf = q1*q2;
    ui->label->setText(rf.getString());
}

void Progetto::slotQuaternionDiv() {
    Quaternion rf = q1/q2;
    ui->label->setText(rf.getString());
}
