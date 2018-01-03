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
};

#endif // NUMBERSCALCULATOR_H
