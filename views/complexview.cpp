#include "complexview.h"
#include "ui_complexview.h"

ComplexView::ComplexView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComplexView)
{
    ui->setupUi(this);

    // Connect all buttons
    connect(ui->btnBack, SIGNAL(clicked()),             this, SIGNAL(signalBack()));

    connect(ui->btnSomma, SIGNAL(clicked()),            this, SLOT(slotCalculate()));
    /*connect(ui->btnSottrazione, SIGNAL(clicked(bool)),      this, SLOT(slotCalculate(Complex::possibleKalk::calcSub)));
    connect(ui->btnMoltiplicazione, SIGNAL(clicked(bool)),  this, SLOT(slotCalculate(Complex::possibleKalk::calcMult)));
    connect(ui->btnDivisione, SIGNAL(clicked(bool)),        this, SLOT(slotCalculate(Complex::possibleKalk::calcDiv)));
    connect(ui->btnConiugato, SIGNAL(clicked(bool)),        this, SLOT(slotCalculate(Complex::possibleKalk::calcConj)));
    connect(ui->btnNorma, SIGNAL(clicked(bool)),            this, SLOT(slotCalculate(Complex::possibleKalk::calcNorm)));
    /*connect(ui->btnInverso, SIGNAL(clicked(bool)),          this, SLOT(slot---()));
    connect(ui->btnMoveToA, SIGNAL(clicked(bool)),          this, SLOT(slot---()));
    connect(ui->btnMoveToB, SIGNAL(clicked(bool)),          this, SLOT(slot---()));*/
}

ComplexView::~ComplexView()
{
    delete ui;
}

void ComplexView::slotCalculate() {
    QString valA = ui->lineEditElementA->text();
    QString valB = ui->lineEditElementB->text();
    // TODO: controlli dei valori ??

    if (sender() == ui->btnSomma) {
        emit signalCalculate(Complex::possibleKalk::calcSum, valA, valB);
    }
}

void ComplexView::slotCalcComplete(Complex res) {
    ui->lineEditElementC->setText(res.getString());
}

/*void ComplexView::slotSum() {
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

void ComplexView::slotDiff() {
    // do something
}
*/
