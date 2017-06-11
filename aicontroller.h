#ifndef AICONTROLLER_T_H
#define AICONTROLLER_T_H

#include "controller.h"
#include <QTimer>

class AIController_t : public ControllerSlot_t
{
public:
    AIController_t();
    ~AIController_t();
    void randomlyPlay();

protected:
    QTimer* Timer;

};

#endif // AICONTROLLER_T_H
