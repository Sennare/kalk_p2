#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QWidget>
#include "views/utils/qcustomplot.h"

namespace Ui {
class TestView;
}

class TestView : public QWidget
{
    Q_OBJECT

public:
    explicit TestView(QWidget *parent = 0);
    ~TestView();

private:
    Ui::TestView *ui;

private slots:
    void slotBackPressed();
signals:
    void signalBack();
};

#endif // TESTVIEW_H
