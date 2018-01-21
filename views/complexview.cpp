#include "complexview.h"
#include "ui_complexview.h"
#include <QFile>
#include <QMessageBox>

ComplexView::ComplexView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComplexView)
{
    // Nothing to do here
    QFile file (":/Resources/Resources/stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);
}

ComplexView::~ComplexView()
{
    delete ui;
    delete op1;
    delete op2;
    delete op3;
}

void ComplexView::initialize() {
    op1 = new Complex();
    op2 = new Complex();
    op3 = new Complex();
}

void ComplexView::handle() {
    // Setup iniziali
    ui->setupUi(this);
    initialize();
    operationStep = 0;

    // Sistemiamo un po' la grafica
    ui->labelLog->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    ui->lineEditCurrent->setAlignment(Qt::AlignRight);
    manageKeys();

    show(); // Mostriamo il tutto altrimenti abbiamo fatto questo per niente

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

    connect(ui->btnClearE, SIGNAL(clicked()),           this, SLOT(slotEditCurrent()));
    connect(ui->btnClear, SIGNAL(clicked()),            this, SLOT(slotEditCurrent()));
    connect(ui->btnBackspace, SIGNAL(clicked()),        this, SLOT(slotEditCurrent()));

    // Connetto il tastierino
    connect(ui->widgetTastierino, TastierinoView::signalKeyPressed, this, ComplexView::slotKeyPressed);
}

void ComplexView::errorManager(QString err) {
    // Something to do here

}

void ComplexView::logAppend(QString str) {
    ui->labelLog->setText(
        ui->labelLog->text().append("<p>").append(str).append("</p>"));
}

void ComplexView::logReset() {
    ui->labelLog->setText("0");
}

void ComplexView::manageKeys() {
    bool isZero = (operationStep == 0 ? true : false );
    ui->btnSomma->setEnabled(isZero);
    ui->btnSottrazione->setEnabled(isZero);
    ui->btnMoltiplicazione->setEnabled(isZero);
    ui->btnDivisione->setEnabled(isZero);
    ui->btnCalcola->setEnabled(!isZero); // Sarà attivo solo in fase 1 a differenza degli altri
    ui->btnInverso->setEnabled(isZero);
    ui->btnNorma->setEnabled(isZero);
    ui->btnConiugato->setEnabled(isZero);

    style()->unpolish(ui->btnSomma);
    style()->polish(ui->btnSomma);
    style()->unpolish(ui->btnSottrazione);
    style()->polish(ui->btnSottrazione);
    style()->unpolish(ui->btnMoltiplicazione);
    style()->polish(ui->btnMoltiplicazione);
    style()->unpolish(ui->btnDivisione);
    style()->polish(ui->btnDivisione);
    style()->unpolish(ui->btnCalcola);
    style()->polish(ui->btnCalcola);
    style()->unpolish(ui->btnInverso);
    style()->polish(ui->btnInverso);
    style()->unpolish(ui->btnNorma);
    style()->polish(ui->btnNorma);
    style()->unpolish(ui->btnConiugato);
    style()->polish(ui->btnConiugato);
}

void ComplexView::calcola() {
    try {
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
        logAppend(op3->getString());
        ui->lineEditCurrent->setText(op3->getString());
        ui->lineEditCurrent->setFocus();
    }catch (exce_kalk e) {
        // Errore
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.exec();
    }
}

void ComplexView::slotCalculate() {
    // TODO: controlli dei valori ??
    try {
        if (operationStep == 0) {
            logAppend("-------");
            if(sender() == ui->btnSomma) {
                ++operationStep;
                op1->string(ui->lineEditCurrent->text());
                operation = tipiCalcolo::sum;
                logAppend(op1->getString());
                logAppend("+");
                ui->lineEditCurrent->setText("");
            }else if(sender() == ui->btnSottrazione) {
                ++operationStep;
                op1->string(ui->lineEditCurrent->text());
                operation = tipiCalcolo::sub;
                logAppend(op1->getString());
                logAppend("-");
                ui->lineEditCurrent->setText("");
            }else if(sender() == ui->btnMoltiplicazione) {
                ++operationStep;
                op1->string(ui->lineEditCurrent->text());
                operation = tipiCalcolo::mult;
                logAppend(op1->getString());
                logAppend("*");
                ui->lineEditCurrent->setText("");
            }else if(sender() == ui->btnDivisione) {
                ++operationStep;
                op1->string(ui->lineEditCurrent->text());
                operation = tipiCalcolo::div;
                logAppend(op1->getString());
                logAppend("/");
                ui->lineEditCurrent->setText("");
            }else if(sender() == ui->btnInverso) {
                op3->string(ui->lineEditCurrent->text());
                logAppend(op3->getString());
                *op3 = op3->inverse();
                logAppend("Inverso:");
                logAppend(op3->getString());
                ui->lineEditCurrent->setText(op3->getString());
            }else if(sender() == ui->btnNorma) {
                op3->string(ui->lineEditCurrent->text());
                logAppend(op3->getString());
                *op3 = op3->norm();
                logAppend("Norma:");
                logAppend(op3->getString());
                ui->lineEditCurrent->setText(op3->getString());
            }else if(sender() == ui->btnConiugato) {
                op3->string(ui->lineEditCurrent->text());
                logAppend(op3->getString());
                *op3 = op3->conjugate();
                logAppend("Coniugato:");
                logAppend(op3->getString());
                ui->lineEditCurrent->setText(op3->getString());
            }
        }else if(operationStep == 1) {
            if(sender() == ui->btnCalcola) {
                op2->string(ui->lineEditCurrent->text());
                logAppend(op2->getString());
                logAppend("=");
                calcola();
                operationStep = 0;
            }
        }
        ui->lineEditCurrent->setFocus();
    }catch (exce_kalk e) {
        // Errore
        operationStep = 0;
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.exec();
    }
    manageKeys();
}

void ComplexView::slotEditCurrent() {
    if(sender() == ui->btnClearE) {
        ui->lineEditCurrent->setText("");
    }else if(sender() == ui->btnClear) {
        logReset();
        ui->lineEditCurrent->setText("");
        operationStep = 0;
    }else if(sender() == ui->btnBackspace) {
        QString current = ui->lineEditCurrent->text();
        if (current.size() > 0) {
            current.resize(current.size() - 1);
        }
        ui->lineEditCurrent->setText( current );
    }
    manageKeys();
}

void ComplexView::slotKeyPressed(QString premuto) {
    premuto.prepend(ui->lineEditCurrent->text());
    ui->lineEditCurrent->setText(premuto);
}
