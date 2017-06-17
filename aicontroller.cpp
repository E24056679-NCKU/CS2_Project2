#include "aicontroller.h"

AIController_t::AIController_t()
{
    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()), this, SLOT(playRandomly()));
}

AIController_t::~AIController_t()
{
    delete Timer;
}

void AIController_t::playRandomly()
{
    this->emit_ReceivedSignal_SelectCard(0);
    this->emit_ReceivedSignal_SelectPosition( QPointF(500, 175) );
    this->emit_ReceivedSignal_SelectCard(1);
    this->emit_ReceivedSignal_SelectPosition( QPointF(500, 275) );
}
