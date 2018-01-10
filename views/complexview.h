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

    void errorManager(int, bool = false);

private:
    Ui::ComplexView *ui;

public slots:
    void slotCalculate();
    void slotCalcComplete(Complex);

signals:
    void signalBack();
    void signalCalculate(int, QString, QString);
    void signalCalcComplete(Complex);
};

#endif // COMPLEXVIEW_H
