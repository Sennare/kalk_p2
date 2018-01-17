#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QWidget>
#include "views/view.h"
#include "views/utils/qcustomplot.h"

namespace Ui {
class TestView;
}

class TestView : public QWidget, public View
{
    Q_OBJECT

public:
    explicit TestView(QWidget *parent = 0);
    ~TestView();

    void handle() override;

private:
    Ui::TestView *ui;

private slots:
    void slotBackPressed();

signals:
    void signalBack();
};

#endif // TESTVIEW_H
