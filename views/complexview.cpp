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
    connect(ui->btnSottrazione, SIGNAL(clicked()),      this, SLOT(slotCalculate()));
    connect(ui->btnMoltiplicazione, SIGNAL(clicked()),  this, SLOT(slotCalculate()));
    connect(ui->btnDivisione, SIGNAL(clicked()),        this, SLOT(slotCalculate()));
    connect(ui->btnInverso, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
    connect(ui->btnConiugato, SIGNAL(clicked()),        this, SLOT(slotCalculate()));
    connect(ui->btnNorma, SIGNAL(clicked()),            this, SLOT(slotCalculate()));
    connect(ui->btnMoveToA, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
    connect(ui->btnMoveToB, SIGNAL(clicked()),          this, SLOT(slotCalculate()));
    /*
    connect(ui->btnMoveToA, SIGNAL(clicked(bool)),          this, SLOT(slot---()));
    connect(ui->btnMoveToB, SIGNAL(clicked(bool)),          this, SLOT(slot---()));*/
}

ComplexView::~ComplexView()
{
    delete ui;
}

void ComplexView::errorManager(int err, bool param) {
    switch (err) {
    case Complex::errorType::errorStringNotValid:
        if (param)
            ui->lineEditElementB;
        else
            ui->lineEditElementA;
        break;
    default:
        break;
    }
}

void ComplexView::slotCalculate() {
    QString valA = ui->lineEditElementA->text();
    QString valB = ui->lineEditElementB->text();
    // TODO: controlli dei valori ??

    int operazione = -1;
    if(sender() == ui->btnSomma) {
        operazione = Complex::possibleKalk::calcSum;
    }else if(sender() == ui->btnSottrazione) {
        operazione = Complex::possibleKalk::calcSub;
    }else if(sender() == ui->btnMoltiplicazione) {
        operazione = Complex::possibleKalk::calcMult;
    }else if(sender() == ui->btnDivisione) {
        operazione = Complex::possibleKalk::calcDiv;
    }else if(sender() == ui->btnInverso) {
        operazione = Complex::possibleKalk::calcInverse;
    }else if(sender() == ui->btnNorma) {
        operazione = Complex::possibleKalk::calcNorm;
    }else if(sender() == ui->btnConiugato) {
        operazione = Complex::possibleKalk::calcConj;
    }else if(sender() == ui->btnMoveToA) {
        ui->lineEditElementA->setText( ui->lineEditElementC->text() );
    }else if(sender() == ui->btnMoveToB) {
        ui->lineEditElementB->setText( ui->lineEditElementC->text() );
    }

    if (operazione >= 0) emit signalCalculate(operazione, valA, valB);
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
