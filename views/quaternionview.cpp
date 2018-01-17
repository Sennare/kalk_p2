#include "quaternionview.h"
#include "ui_quaternionview.h"

QuaternionView::QuaternionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuaternionView)
{
    ui->setupUi(this);

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

QuaternionView::~QuaternionView()
{
    delete ui;
}

void QuaternionView::errorManager(QString err) {
    // Something to do here

}

void QuaternionView::slotCalculate() {
    QString valA = ui->lineEditElementA->text();
    QString valB = ui->lineEditElementB->text();
    // TODO: controlli dei valori ??

    int operazione = -1;
    if(sender() == ui->btnSomma) {
        operazione = Quaternion::possibleKalk::calcSum;
    }else if(sender() == ui->btnSottrazione) {
        operazione = Quaternion::possibleKalk::calcSub;
    }else if(sender() == ui->btnMoltiplicazione) {
        operazione = Quaternion::possibleKalk::calcMult;
    }else if(sender() == ui->btnDivisione) {
        operazione = Quaternion::possibleKalk::calcDiv;
    }else if(sender() == ui->btnInverso) {
        operazione = Quaternion::possibleKalk::calcInverse;
    }else if(sender() == ui->btnNorma) {
        operazione = Quaternion::possibleKalk::calcNorm;
    }else if(sender() == ui->btnConiugato) {
        operazione = Quaternion::possibleKalk::calcConj;
    }else if(sender() == ui->btnMoveToA) {
        ui->lineEditElementA->setText( ui->lineEditElementC->text() );
    }else if(sender() == ui->btnMoveToB) {
        ui->lineEditElementB->setText( ui->lineEditElementC->text() );
    }

    if (operazione >= 0) emit signalCalculate(operazione, valA, valB);
}

void QuaternionView::slotCalcComplete(Quaternion res) {
    ui->lineEditElementC->setText(res.getString());
}
