#include "controller.h"

ControllerSlot_t::ControllerSlot_t() : QObject()
{

}

ControllerSlot_t::~ControllerSlot_t()
{

}

void ControllerSlot_t::emit_ReceivedSignal_SelectPosition(QPointF Position)
{
    emit receivedSignal_SelectPosition(Position);
}

void ControllerSlot_t::emit_ReceivedSignal_SelectMinion(Minion_t *selMinion)
{
    emit receivedSignal_SelectMinion(selMinion);
}

void ControllerSlot_t::emit_ReceivedSignal_SelectCard(int ButtonID)
{
    emit receivedSignal_SelectCard(ButtonID);
}

void ControllerSlot_t::emit_ReceivedSignal_KeyPressed(int key)
{
    emit receivedSignal_KeyPressed(key);
}
