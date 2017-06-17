#ifndef AICONTROLLER_T_H
#define AICONTROLLER_T_H

#include "controller.h"
#include <QTimer>

class AIController_t : public ControllerSlot_t
{
    Q_OBJECT
public:
    AIController_t();
    ~AIController_t();
    QTimer* Timer;

public slots:
    void playRandomly();
};

#endif // AICONTROLLER_T_H
