#ifndef NUMBERSCALCULATOR_H
#define NUMBERSCALCULATOR_H

#include <QWidget>

namespace Ui {
class NumbersCalculator;
}

class NumbersCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit NumbersCalculator(QWidget *parent = 0);
    ~NumbersCalculator();

private:
    Ui::NumbersCalculator *ui;

private slots:
    void slotSum();
    void slotDiff();
    void slotMult();
    void slotDiv();
    void slotInverse();
    void slotConjugate();
    void slotNorm();
    void slotMoveToA();
    void slotMoveToB();
};

#endif // NUMBERSCALCULATOR_H
