#include "audioview.h"
#include "ui_audioview.h"


AudioView::AudioView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioView)
{
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));

    connect(ui->btnSommaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnSottrazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnDivisioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnMoltiplicazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnUguaglianzaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));

    // Setup grafici
    /*ui->widgetOndaUno->addGraph();
    ui->widgetOndaUno->graph(0)->setPen(QPen(Qt::blue));
    ui->widgetOndaUno->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }

    ui->widgetOndaUno->xAxis2->setVisible(true);
    ui->widgetOndaUno->xAxis2->setTickLabels(false);
    ui->widgetOndaUno->yAxis2->setVisible(true);
    ui->widgetOndaUno->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->widgetOndaUno->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widgetOndaUno->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widgetOndaUno->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widgetOndaUno->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    ui->widgetOndaUno->graph(0)->setData(x, y0);
    ui->widgetOndaUno->graph(0)->rescaleAxes();*/
}

AudioView::~AudioView()
{
    delete ui;
}

void AudioView::updateOperatore(QVector<QVector<double>*> valori, int operatore) {
    switch (operatore) {
    case 1:
        { // onda 1
            ui->widgetOndaUno->removeGraph(0);
            ui->widgetOndaUno->removeGraph(1);
            ui->widgetOndaUno->addGraph();
            ui->widgetOndaUno->addGraph();

            QVector<double> x(valori[0]->length());
            for (int i=0; i<valori[0]->length(); ++i)
            { x[i] = i; }
            auto it = valori.begin();
            for ( ; it != valori.end(); ++it) {
                ui->widgetOndaUno->graph(0)->setData(x, *valori[0]);
                ui->widgetOndaUno->graph(1)->setData(x, *valori[1]);
            }
            ui->widgetOndaUno->graph(0)->rescaleAxes();
            ui->widgetOndaUno->graph(1)->rescaleAxes(true);
        }
        break;
    }
}

void AudioView::slotOpOndaUno() {
    QString valOndaUnoSx = ui->lineEditValoriOndaUnoOndaSx->text();
    QString valOndaUnoDx = ui->lineEditValoriOndaUnoOndaDx->text();
    QString indOndaUno = ui->lineEditIndiceOndaUno->text();
    QString lungOndaUno = ui->lineEditLunghezzaOndaUno->text();

    int operazioneDaEseguire = -1;

    if (sender() == ui->btnInserisciOndaUno) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opPush;
    } else if (sender() == ui->btnSostituisciOndaUno){
        operazioneDaEseguire = Audio::operazioniDisponibili::opSostituzione;
    } else if (sender() == ui->btnOttieniOndaUno) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opGet;
    } else if (sender() == ui->btnEliminaOndaUno) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opRemove;
    }

    if (operazioneDaEseguire >= 0) emit signalOpOndaUno(operazioneDaEseguire,
                                                        valOndaUnoSx,
                                                        valOndaUnoDx,
                                                        indOndaUno,
                                                        lungOndaUno);
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
    if (operazioneDaEseguire >= 0) emit signalOpOndaDue(operazioneDaEseguire,
                                                        valOndaDueSx,
                                                        valOndaDueDx,
                                                        indOndaDue,
                                                        lungOndaDue);
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
