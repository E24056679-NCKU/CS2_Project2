#include "aicontroller.h"

AIController_t::AIController_t() : ControllerSlot_t()
{
    Timer = new QTimer;
}

AIController_t::~AIController_t()
{
    delete Timer;
}
