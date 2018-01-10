#ifndef COMPLEXVIEW_H
#define COMPLEXVIEW_H

#include <QWidget>
#include <QString>
#include "logica/complex.h"

namespace Ui {
class ComplexView;
}

class ComplexView : public QWidget
{
    Q_OBJECT

public:
    explicit ComplexView(QWidget *parent = 0);
    ~ComplexView();

private:
    Ui::ComplexView *ui;

public slots:
    void slotCalculate();
    void slotCalcComplete(Complex);

    /*void slotSum();
    void slotDiff();
    void slotMult();
    void slotDiv();
    void slotInverse();
    void slotConjugate();
    void slotNorm();
    void slotMoveToA();
    void slotMoveToB();*/

signals:
    void signalBack();
    void signalCalculate(int, QString, QString);
    void signalCalcComplete(Complex);
};

#endif // COMPLEXVIEW_H
