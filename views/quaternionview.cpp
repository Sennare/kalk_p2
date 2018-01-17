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
    connect(ui->btnMoveToA, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
    connect(ui->btnMoveToB, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
}

void QuaternionView::errorManager(QString err) {
    // Something to do here

}

void QuaternionView::slotCalculate() {
    op1->string(ui->lineEditElementA->text());
    op2->string(ui->lineEditElementB->text());
    // TODO: controlli dei valori ??

    bool operazione = true;
    if(sender() == ui->btnSomma) {
        *op3 = *op1 + *op2;
    }else if(sender() == ui->btnSottrazione) {
        *op3 = *op1 - *op2;
    }else if(sender() == ui->btnMoltiplicazione) {
        *op3 = *op1 * *op2;
    }else if(sender() == ui->btnDivisione) {
        *op3 = *op1 / *op2;
    }else if(sender() == ui->btnInverso) {
        *op3 = op1->inverse();
    }else if(sender() == ui->btnNorma) {
        *op3 = op1->norm();
    }else if(sender() == ui->btnConiugato) {
        *op3 = op1->conjugate();
    }else if(sender() == ui->btnMoveToA) {
        operazione = false;
        ui->lineEditElementA->setText( ui->lineEditElementC->text() );
    }else if(sender() == ui->btnMoveToB) {
        operazione = false;
        ui->lineEditElementB->setText( ui->lineEditElementC->text() );
    }

    if (operazione) ui->lineEditElementC->setText(op3->getString());
}
