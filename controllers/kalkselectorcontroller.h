#ifndef KALKSELECTORCONTROLLER_H
#define KALKSELECTORCONTROLLER_H

#include "controllers/controller.h"
#include "views/kalkselectorview.h"

class KalkSelectorController : public Controller
{
    Q_OBJECT
private:
    KalkSelectorView* view;
public:
    KalkSelectorController();
    ~KalkSelectorController();

    void handle() override;

private slots:
    void slotOpenKalk(int);

signals:
    void signalOpenKalk(int);
};

#endif // KALKSELECTORCONTROLLER_H
