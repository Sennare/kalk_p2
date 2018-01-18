#ifndef QUATERNIONVIEW_H
#define QUATERNIONVIEW_H

#include <QWidget>
#include <QString>
#include "views/view.h"
#include "logica/quaternion.h"

namespace Ui {
class QuaternionView;
}

class QuaternionView : public QWidget, public View
{
    Q_OBJECT

public:
    explicit QuaternionView(QWidget *parent = 0);
    ~QuaternionView();

    void handle() override;

    void errorManager(QString);
private:
    Ui::QuaternionView *ui;

    enum tipiCalcolo {
        sum, sub, mult, div
    };
    Quaternion* op1;
    Quaternion* op2;
    Quaternion* op3;
    int operationStep;
    tipiCalcolo operation;

    void appendToLog(QString);

    void calcola();

public slots:
    void slotCalculate();

signals:
    void signalBack();
    void signalCalculate(int, QString, QString);
    void signalCalcComplete(Quaternion);
};

#endif // QUATERNIONVIEW_H
