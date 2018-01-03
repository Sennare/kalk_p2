#include "numberscalculator.h"
#include "ui_numberscalculator.h"

NumbersCalculator::NumbersCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumbersCalculator)
{
    ui->setupUi(this);
}

NumbersCalculator::~NumbersCalculator()
{
    delete ui;
}
