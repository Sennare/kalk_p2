#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QWidget>

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
};

#endif // TESTVIEW_H
