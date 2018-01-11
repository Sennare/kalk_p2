#ifndef QUATERNIONCONTROLLER_H
#define QUATERNIONCONTROLLER_H

#include <QObject>
#include "controllers/controller.h"
#include "views/quaternionview.h"
#include "exce_kalk.h"

class QuaternionController : public Controller
{
    Q_OBJECT
private:
    QuaternionView* view;
public:
    QuaternionController();
    ~QuaternionController();

    void handle() override;

private slots:
    void slotBack();

    void slotCalculate(int, QString, QString);

signals:
    void signalBack();
    void signalCalcComplete(Quaternion);
};

#endif // QUATERNIONCONTROLLER_H
