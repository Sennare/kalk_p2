#ifndef KALKSELECTORVIEW_H
#define KALKSELECTORVIEW_H

#include <QMainWindow>
#include "application.h"

namespace Ui {
class KalkSelectorView;
}

class KalkSelectorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit KalkSelectorView(QWidget *parent = 0);
    ~KalkSelectorView();

private:
    Ui::KalkSelectorView *ui;

private slots:
    void slotOpenComplex();

signals:
    void signalOpenKalk(int);
};

#endif // KALKSELECTORVIEW_H
