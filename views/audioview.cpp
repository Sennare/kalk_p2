#include "audioview.h"
#include "ui_audioview.h"

#include <QDebug>

AudioView::AudioView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioView)
{
    operatoreUno = new Audio();
    operatoreDue = new Audio();
    operatoreTre = new Audio();
}

AudioView::~AudioView()
{
    delete ui;
    delete operatoreUno;
    delete operatoreDue;
    delete operatoreTre;
}

void AudioView::handle() {
    // Something to do here
    ui->setupUi(this);
    show();

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno()));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno()));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno()));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue()));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue()));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue()));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue()));

    connect(ui->btnSommaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola()));
    connect(ui->btnSottrazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola()));
    connect(ui->btnDivisioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola()));
    connect(ui->btnMoltiplicazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola()));
    connect(ui->btnUguaglianzaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola()));

    *operatoreTre = *operatoreUno + *operatoreDue;
    updateOperatore(ui->widgetOndaUno, operatoreUno);
    updateOperatore(ui->widgetOndaDue, operatoreDue);
    updateOperatore(ui->widgetRisultato, operatoreTre);

    ui->widgetOndaUno->xAxis2->setVisible(true);
    ui->widgetOndaUno->xAxis2->setTickLabels(false);
    ui->widgetOndaUno->yAxis2->setVisible(true);
    ui->widgetOndaUno->yAxis2->setTickLabels(false);
}

void AudioView::updateAllOp() {
    updateOperatore(ui->widgetOndaUno, operatoreUno);
    updateOperatore(ui->widgetOndaDue, operatoreDue);
    updateOperatore(ui->widgetRisultato, operatoreTre);
}

void AudioView::updateOperatore(QCustomPlot* cPlot, Audio* audio) {
    cPlot->removeGraph(0);
    cPlot->removeGraph(1);
    cPlot->addGraph();
    cPlot->addGraph();
    cPlot->graph(0)->setPen(QPen(Qt::blue));
    cPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    cPlot->graph(1)->setPen(QPen(Qt::red));
    cPlot->graph(1)->setBrush(QBrush(QColor(0, 255, 0, 20)));

    for (int i=0; i < audio->waveLenght() ; ++i) {
        cPlot->graph(0)->addData(i, audio->getAmpVal(i));
        cPlot->graph(1)->addData(i, audio->getAmpVal(i, Audio::ondeDisponibili::ondaDx));
        qDebug() << "Aggiornata onda:" << audio->getAmpVal((i));
    }

    cPlot->graph(0)->rescaleAxes();
    cPlot->graph(1)->rescaleAxes(true);
    cPlot->replot();
}

void AudioView::slotOpOndaUno() {
    QString valOndaUnoSx = ui->lineEditValoriOndaUnoOndaSx->text();
    QString valOndaUnoDx = ui->lineEditValoriOndaUnoOndaDx->text();
    int indOndaUno = ui->lineEditIndiceOndaUno->text().simplified().toLower().replace( " ", "" ).toInt();
    int lungOndaUno = ui->lineEditLunghezzaOndaUno->text().simplified().toLower().replace( " ", "" ).toInt();

    // controlli vari sul formato degli input
    valOndaUnoSx = valOndaUnoSx.simplified().toLower();
    valOndaUnoSx.replace( " ", "" );
    valOndaUnoDx = valOndaUnoDx.simplified().toLower();
    valOndaUnoDx.replace( " ", "" );
    QStringList listUnoSx = valOndaUnoSx.split(',');
    QStringList listUnoDx = valOndaUnoDx.split(',');

    if (sender() == ui->btnInserisciOndaUno) {
        //operazioneDaEseguire = Audio::operazioniDisponibili::opPush;
        if (listUnoSx.length() != listUnoDx.length()) {
            // trow err
        }else{
            for (int i = 0; i < listUnoSx.length() ; ++i) {
                qDebug() << listUnoSx[i].toDouble() << " - " <<
                            listUnoDx[i].toDouble() << " - " <<
                            indOndaUno+i;
                operatoreUno->pushPoint(listUnoSx[i].toDouble() , listUnoDx[i].toDouble(), (indOndaUno < 0 ? -1 : indOndaUno+i));
            }
            qDebug() << "lol--" << listUnoSx.length()  << "--" << operatoreUno->waveLenght();
            updateAllOp();
        }
    } else if (sender() == ui->btnSostituisciOndaUno){
        //operazioneDaEseguire = Audio::operazioniDisponibili::opSostituzione;
    } else if (sender() == ui->btnOttieniOndaUno) {
        //operazioneDaEseguire = Audio::operazioniDisponibili::opGet;
    } else if (sender() == ui->btnEliminaOndaUno) {
        //operazioneDaEseguire = Audio::operazioniDisponibili::opRemove;
    }


}

/*void AudioView::slotOpOndaUnoEseguita(Audio risultato) {
    ui->lineEditRis->setText(risultato.getString());
}*/

void AudioView::slotOpOndaDue() {
    QString valOndaDueSx = ui->lineEditValoriOndaDueOndaSx->text();
    QString valOndaDueDx = ui->lineEditValoriOndaDueOndaDx->text();
    QString indOndaDue = ui->lineEditIndiceOndaDue->text();
    QString lungOndaDue = ui->lineEditLunghezzaOndaDue->text();

    int operazioneDaEseguire = -1;

    if (sender() == ui->btnInserisciOndaDue) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opPush;
    } else if (sender() == ui->btnSostituisciOndaDue){
        operazioneDaEseguire = Audio::operazioniDisponibili::opSostituzione;
    } else if (sender() == ui->btnOttieniOndaDue) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opGet;
    } else if (sender() == ui->btnEliminaOndaDue) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opRemove;
    }
    /*if (operazioneDaEseguire >= 0) emit signalOpOndaDue(operazioneDaEseguire,
                                                        valOndaDueSx,
                                                        valOndaDueDx,
                                                        indOndaDue,
                                                        lungOndaDue);*/
}

/*void AudioView::slotOpOndaDueEseguita(Audio risultato) {
    ui->lineEditRis->setText(risultato.getString());
}*/

void AudioView::slotCalcola() {
    if (sender() == ui->btnSommaOndeAudio) {
    } else if (sender() == ui->btnSottrazioneOndeAudio){
    } else if (sender() == ui->btnDivisioneOndeAudio) {
    } else if (sender() == ui->btnMoltiplicazioneOndeAudio) {
    } else if (sender() == ui->btnUguaglianzaOndeAudio){
    }
}
