#include "quaternionview.h"
#include "ui_quaternionview.h"

QuaternionView::QuaternionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuaternionView)
{
    // Nothing to do here
    op1 = new Quaternion();
    op2 = new Quaternion();
    op3 = new Quaternion();
    operationStep = 0;
}

QuaternionView::~QuaternionView()
{
    delete ui;
    delete op1;
    delete op2;
    delete op3;
}

void QuaternionView::handle() {
    ui->setupUi(this);
    ui->labelLog->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    show();

    // Connect all buttons
    connect(ui->btnBack, SIGNAL(clicked()),             this, SIGNAL(signalBack()));

    connect(ui->btnSomma, SIGNAL(clicked()),            this, SLOT(slotCalculate()));
    connect(ui->btnSottrazione, SIGNAL(clicked()),      this, SLOT(slotCalculate()));
    connect(ui->btnMoltiplicazione, SIGNAL(clicked()),  this, SLOT(slotCalculate()));
    connect(ui->btnDivisione, SIGNAL(clicked()),        this, SLOT(slotCalculate()));
    connect(ui->btnInverso, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
    connect(ui->btnConiugato, SIGNAL(clicked()),        this, SLOT(slotCalculate()));
    connect(ui->btnNorma, SIGNAL(clicked()),            this, SLOT(slotCalculate()));

    connect(ui->btnCalcola, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
}

void QuaternionView::errorManager(QString err) {
    // Something to do here

}

void QuaternionView::appendToLog(QString str) {
    ui->labelLog->setText(
        ui->labelLog->text().append("<p>").append(str).append("</p>"));
}

void QuaternionView::calcola() {
    switch (operation) {
    case tipiCalcolo::sum:
        *op3 = *op1 + *op2;
        break;
    case tipiCalcolo::sub:
        *op3 = *op1 - *op2;
        break;
    case tipiCalcolo::mult:
        *op3 = *op1 * *op2;
        break;
    case tipiCalcolo::div:
        *op3 = *op1 / *op2;
        break;
    }
    appendToLog(op3->getString());
    ui->lineEditCurrent->setText(op3->getString());
}

void QuaternionView::slotCalculate() {
    // TODO: controlli dei valori ??

    if (operationStep == 0) {
        ++operationStep;
        ui->labelLog->setText("");
        if(sender() == ui->btnSomma) {
            op1->string(ui->lineEditCurrent->text());
            operation = tipiCalcolo::sum;
            appendToLog(op1->getString());
            appendToLog("+");
            ui->lineEditCurrent->setText("");
        }else if(sender() == ui->btnSottrazione) {
            op1->string(ui->lineEditCurrent->text());
            operation = tipiCalcolo::sub;
            appendToLog(op1->getString());
            appendToLog("-");
            ui->lineEditCurrent->setText("");
        }else if(sender() == ui->btnMoltiplicazione) {
            op1->string(ui->lineEditCurrent->text());
            operation = tipiCalcolo::mult;
            appendToLog(op1->getString());
            appendToLog("*");
            ui->lineEditCurrent->setText("");
        }else if(sender() == ui->btnDivisione) {
            op1->string(ui->lineEditCurrent->text());
            operation = tipiCalcolo::div;
            appendToLog(op1->getString());
            appendToLog("/");
            ui->lineEditCurrent->setText("");
        }else if(sender() == ui->btnInverso) {
            op3->string(ui->lineEditCurrent->text());
            appendToLog(op3->getString());
            *op3 = op3->inverse();
            appendToLog("Inverso:");
            appendToLog(op3->getString());
            ui->lineEditCurrent->setText(op3->getString());
            operationStep = 0;
        }else if(sender() == ui->btnNorma) {
            op3->string(ui->lineEditCurrent->text());
            appendToLog(op3->getString());
            *op3 = op3->norm();
            appendToLog("Norma:");
            appendToLog(op3->getString());
            ui->lineEditCurrent->setText(op3->getString());
            operationStep = 0;
        }else if(sender() == ui->btnConiugato) {
            op3->string(ui->lineEditCurrent->text());
            appendToLog(op3->getString());
            *op3 = op3->conjugate();
            appendToLog("Coniugato:");
            appendToLog(op3->getString());
            ui->lineEditCurrent->setText(op3->getString());
            operationStep = 0;
        }
    }else if(operationStep == 1) {
        if(sender() == ui->btnCalcola) {
            op2->string(ui->lineEditCurrent->text());
            appendToLog(op2->getString());
            appendToLog("=");
            calcola();
            operationStep = 0;
        }
    }
}
