#ifndef KALKSELECTORCONTROLLER_H
#define KALKSELECTORCONTROLLER_H

#include "controllers/controller.h"
#include "views/kalkselectorview.h"

class KalkSelectorController : public Controller
{
private:
    KalkSelectorView* view;
public:
    KalkSelectorController();

    void handle() override;
};

#endif // KALKSELECTORCONTROLLER_H
