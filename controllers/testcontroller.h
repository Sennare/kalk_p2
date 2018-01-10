#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "controllers/controller.h"
#include "views/testview.h"

class TestController : public Controller
{
    Q_OBJECT
private:
    TestView* view;
public:
    TestController();
    ~TestController();

    void handle() override;

private slots:
    void slotBack();

signals:
    void signalBack();
};

#endif // TESTCONTROLLER_H
