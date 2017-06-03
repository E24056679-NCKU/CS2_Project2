#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QDebug>
#include "display.h"
#include "minion.h"
#include "battle.h"
#include "controller.h"
#include "tower.h"

// for maintaining game , hold minion's container ...
class System : public QObject
{
    Q_OBJECT

    friend int main(int argc, char *argv[]);

public:
    System(ControllerSlot_t* Controller1, ControllerSlot_t* Controller2);
    ~System();

protected slots:
    void itemAdded(QGraphicsItem* addItem);
    void itemRemoved(QGraphicsItem* rmItem);

    // incoming signals from controller1
    void receivedSignal1_SelectPosition(QPointF Position);
    // void receivedSignal1_SelectMinion(QPointF Position);
    void receivedSignal1_SelectMinion(Minion_t* selMinion);
    void receivedSignal1_SelectCard(int CardID);
    void receivedSignal2_SelectPosition(QPointF Position);
    // void receivedSignal2_SelectMinion(QPointF Position);
    void receivedSignal2_SelectMinion(Minion_t* selMinion);
    void receivedSignal2_SelectCard(int CardID);

protected:
    // BattleManager arrange all things about the battlefield
    BattleManager_t* BattleManager;
    // Display arrange all things about display, but only add or remove IMAGE
    Display_t* Display;
    // ControllerSlot is like the slot in a gaming machine
    ControllerSlot_t* ControllerSlot[2];

private:
    // store the address of ControllableDisplay (if any)
    ControllableDisplay_t* ControllableDisplay;
};

#endif // SYSTEM_H
