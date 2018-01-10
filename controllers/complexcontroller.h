#ifndef COMPLEXCONTROLLER_H
#define COMPLEXCONTROLLER_H

#include <QObject>
#include "controllers/controller.h"
#include "views/complexview.h"

class ComplexController : public Controller
{
    Q_OBJECT
private:
    ComplexView* view;
public:
    ComplexController();
    ~ComplexController();

    void handle() override;

private slots:
    void slotBack();

    void slotCalculate(int, QString, QString);

signals:
    void signalBack();
    void signalCalcComplete(Complex);
};

#endif // COMPLEXCONTROLLER_H
