#include "coloredwaveview.h"
#include "ui_coloredwaveview.h"
#include <QDebug>

ColoredWaveView::ColoredWaveView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColoredWaveView)
{
    ui->setupUi(this);
    operatoreUno = new ColoredWave();
    operatoreDue = new ColoredWave();
    operatoreTre = new ColoredWave();
}

ColoredWaveView::~ColoredWaveView()
{
    delete ui;
    delete operatoreUno;
    delete operatoreDue;
    delete operatoreTre;
}

void ColoredWaveView::handle() {
    //ui->setupUi(this);
    show();

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->horizontalSliderROndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno()));
    connect(ui->horizontalSliderGOndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno()));
    connect(ui->horizontalSliderBOndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno()));


    connect(ui->btnInserisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->btnSostituisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->btnOttieniOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->btnEliminaOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->horizontalSliderROndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue()));
    connect(ui->horizontalSliderGOndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue()));
    connect(ui->horizontalSliderBOndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue()));

    connect(ui->btnSommaOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));
    connect(ui->btnSottrazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));
    connect(ui->btnDivisioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));
    connect(ui->btnMoltiplicazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));

    //Assi cartesiani
    ui->widgetOndaUno->xAxis2->setVisible(true);
    ui->widgetOndaUno->xAxis2->setTickLabels(false);
    ui->widgetOndaUno->yAxis2->setVisible(true);
    ui->widgetOndaUno->yAxis2->setTickLabels(false);
    ui->widgetOndaDue->xAxis2->setVisible(true);
    ui->widgetOndaDue->xAxis2->setTickLabels(false);
    ui->widgetOndaDue->yAxis2->setVisible(true);
    ui->widgetOndaDue->yAxis2->setTickLabels(false);
    ui->widgetRisultato->xAxis2->setVisible(true);
    ui->widgetRisultato->xAxis2->setTickLabels(false);
    ui->widgetRisultato->yAxis2->setVisible(true);
    ui->widgetRisultato->yAxis2->setTickLabels(false);
}

void ColoredWaveView::updateAllOp(){
    updateOperatore(ui->widgetOndaUno, operatoreUno);
    updateOperatore(ui->widgetOndaDue, operatoreDue);
    updateOperatore(ui->widgetRisultato, operatoreTre);
}

void ColoredWaveView::updateOperatore(QCustomPlot* cPlot, ColoredWave* cWave) {
    cPlot->clearGraphs();
    cPlot->addGraph();
    cPlot->graph(0)->setPen(QPen(Qt::black));
    cPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    for(int i=0; i<cWave->waveLenght(); ++i){
        cPlot->graph(0)->addData(i, cWave->getAmpVal(i));
    }
    cPlot->graph(0)->rescaleAxes(true);
    cPlot->replot();
}

void ColoredWaveView::slotOpOndaColorataUno(){
    QString valOndaUno = ui->lineEditValoriOndaUno->text().simplified().toLower().replace( " ", "") ;
    int indOndaUno = ui->lineEditIndiceOndaUno->text().simplified().toLower().replace( " ", "" ). toInt();
    QStringList listaUno = valOndaUno.split(',');

    int valROndaUno = ui->lineEditROndaUno->text().simplified().toLower().replace( " ", "").toInt();
    int valGOndaUno = ui->lineEditGOndaUno->text().simplified().toLower().replace( " ", "").toInt();
    int valBOndaUno = ui->lineEditBOndaUno->text().simplified().toLower().replace( " ", "").toInt();
    Color colore(valROndaUno, valGOndaUno, valBOndaUno);

    if (sender() == ui->btnInserisciOndaUno){
        for(int i = 0; i < listaUno.length(); ++i) {
            int indTarget = (indOndaUno<0 ? -1 : indOndaUno+i);
            operatoreUno->pushPoint(listaUno[i].toDouble(), colore, indTarget, true);
            qDebug()<<listaUno[i]<< "-" << colore.GetColore() <<"-"<< operatoreUno->waveLenght();
        }
        updateAllOp();
    } else if(sender() == ui->btnSostituisciOndaUno) {
        if (indOndaUno < 0) indOndaUno = 0;
        for (int i=0; i<listaUno.length(); ++i){
            int indTarget = (indOndaUno<0 ? 0 : indOndaUno+i);
            operatoreUno->pushPoint(listaUno[i].toDouble(), colore.GetColore(), indTarget, false);
        }
        updateAllOp();
    } else if (sender() == ui->btnOttieniOndaUno) {
        QString onda, comma;
        for (int i= indOndaUno; i<listaUno.length(); ++i) {
            onda.append(comma);
            onda.append(QString::number(operatoreUno->getAmpVal(i)));
            comma = ", ";
        }
        ui->lineEditValoriOndaUno->setText(onda);
    }
}

void ColoredWaveView::slotOpOndaColorataDue() {
    QString valOndaDue = ui->lineEditValoriOndaDue->text().simplified().toLower().replace( " ", "") ;
    int indOndaDue = ui->lineEditIndiceOndaDue->text().simplified().toLower().replace( " ", "" ). toInt();
    QStringList listaDue = valOndaDue.split(',');

    int valROndaDue = ui->lineEditROndaDue->text().simplified().toLower().replace( " ", "").toInt();
    int valGOndaDue = ui->lineEditGOndaDue->text().simplified().toLower().replace( " ", "").toInt();
    int valBOndaDue = ui->lineEditBOndaDue->text().simplified().toLower().replace( " ", "").toInt();
    Color colore(valROndaDue, valGOndaDue, valBOndaDue);

    if (sender() == ui->btnInserisciOndaDue){
        for(int i = 0; i < listaDue.length(); ++i) {
            int indTarget = (indOndaDue<0 ? -1 : indOndaDue+i);
            operatoreDue->pushPoint(listaDue[i].toDouble(), colore, indTarget, true);
            qDebug()<<listaDue[i]<< "-" << colore.GetColore() <<"-"<< operatoreDue->waveLenght();
        }
        updateAllOp();
    } else if(sender() == ui->btnSostituisciOndaDue) {
        if (indOndaDue < 0) indOndaDue = 0;
        for (int i=0; i<listaDue.length(); ++i){
            int indTarget = (indOndaDue<0 ? 0 : indOndaDue+i);
            operatoreDue->pushPoint(listaDue[i].toDouble(), colore.GetColore(), indTarget, false);
        }
        updateAllOp();
    }
}

void ColoredWaveView::slotCalcolaOndaColorata(){
    if (sender() == ui->btnSommaOndeColorate) {
        *operatoreTre = *operatoreUno + *operatoreDue;
    } else if (sender() == ui->btnSottrazioneOndeColorate){
        *operatoreTre = *operatoreUno - *operatoreDue;
    } else if (sender() == ui->btnDivisioneOndeColorate) {
        *operatoreTre = *operatoreUno / *operatoreDue;
    } else if (sender() == ui->btnMoltiplicazioneOndeColorate) {
        *operatoreTre = *operatoreUno * *operatoreDue;
    }
    updateOperatore(ui->widgetRisultato, operatoreTre);
}
