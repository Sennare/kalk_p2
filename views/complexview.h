#ifndef COMPLEXVIEW_H
#define COMPLEXVIEW_H

#include <QWidget>
#include <QString>
#include "views/view.h"
#include "logica/complex.h"

namespace Ui {
class ComplexView;
}

class ComplexView : public QWidget, public View
{
    Q_OBJECT

public:
    explicit ComplexView(QWidget *parent = 0);
    ~ComplexView();

    virtual void initialize();
    void handle();

    void errorManager(QString);

protected:
    Complex* op1;
    Complex* op2;
    Complex* op3;

private:
    Ui::ComplexView *ui;

    enum tipiCalcolo {
        sum, sub, mult, div
    };
    int operationStep;
    tipiCalcolo operation;

    void appendToLog(QString);

    void calcola();

public slots:
    void slotCalculate();

signals:
    void signalBack();
};

#endif // COMPLEXVIEW_H
