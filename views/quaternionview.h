#ifndef QUATERNIONVIEW_H
#define QUATERNIONVIEW_H

#include <QWidget>
#include <QString>
#include "logica/quaternion.h"

namespace Ui {
class QuaternionView;
}

class QuaternionView : public QWidget
{
    Q_OBJECT

public:
    explicit QuaternionView(QWidget *parent = 0);
    ~QuaternionView();

    void errorManager(QString);
private:
    Ui::QuaternionView *ui;

public slots:
    void slotCalculate();
    void slotCalcComplete(Quaternion);

signals:
    void signalBack();
    void signalCalculate(int, QString, QString);
    void signalCalcComplete(Quaternion);
};

#endif // QUATERNIONVIEW_H
