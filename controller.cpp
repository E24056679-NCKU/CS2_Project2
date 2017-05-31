#include "controller.h"

ControllerSlot_t::ControllerSlot_t() : QObject()
{

}

ControllerSlot_t::~ControllerSlot_t()
{

}

void ControllerSlot_t::emit_GotSignal_SelectPosition(QPointF Position)
{
    emit gotSignal_SelectPosition(Position);
}

void ControllerSlot_t::emit_GotSignal_SelectMinion(QPointF Position)
{
    emit gotSignal_SelectMinion(Position);
}

void ControllerSlot_t::emit_GotSignal_SelectMinion(Minion_t *selMinion)
{
    emit gotSignal_SelectMinion(selMinion);
}

void ControllerSlot_t::emit_GotSignal_SelectCard(int CardID)
{
    emit gotSignal_SelectCard(CardID);
}
