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

    void handle() override;

    void errorManager(QString);

private:
    Ui::ComplexView *ui;

    Complex *op1;
    Complex *op2;
    Complex *op3;

public slots:
    void slotCalculate();

signals:
    void signalBack();
    void signalCalculate(int, QString, QString);
    void signalCalcComplete(Complex);
};

#endif // COMPLEXVIEW_H
