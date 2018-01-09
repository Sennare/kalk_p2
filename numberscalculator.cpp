#include "numberscalculator.h"
#include "ui_numberscalculator.h"
#include "complex.h"
#include "quaternion.h"

NumbersCalculator::NumbersCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumbersCalculator)
{
    ui->setupUi(this);

    // Connect all buttons
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotSum()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotDiff()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotMult()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotDiv()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotInverse()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotConjugate()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotNorm()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotMoveToA()));
    connect(ui->btnSomma, SIGNAL(clicked(bool)), this, SLOT(slotMoveToB()));
}

NumbersCalculator::~NumbersCalculator()
{
    delete ui;
}

void NumbersCalculator::slotSum() {
    // do something
    if (ui->rbtnComplex->isChecked()) {
        Complex vA, vB, vC;
        vA = ui->lineEditElementA->text();
        vB = ui->lineEditElementB->text();
        vC = vA + vB;
        ui->lineEditElementC->setText( vC.getString() );
    }else{
        Quaternion vA, vB, vC;
        vA = ui->lineEditElementA->text();
        vB = ui->lineEditElementB->text();
        vC = vA + vB;
        ui->lineEditElementC->setText( vC.getString() );
    }
}

void NumbersCalculator::slotDiff() {
    // do something
}

void NumbersCalculator::slotMult() {
    // do something
}

void NumbersCalculator::slotDiv() {
    // do something
}

void NumbersCalculator::slotInverse() {
    // do something
}

void NumbersCalculator::slotConjugate() {
    // do something
}

void NumbersCalculator::slotNorm() {
    // do something
}

void NumbersCalculator::slotMoveToA() {
    // do something
}

void NumbersCalculator::slotMoveToB() {
    // do something
}
