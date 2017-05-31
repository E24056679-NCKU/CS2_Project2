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
    // minion must be handle exceptionally because it need to be connected with InputtableDisplay
    void minionAdded(Minion_t* newMinion);
    void minionRemoved(Minion_t* rmMinion);
    void itemAdded(QGraphicsItem* addItem);
    void itemRemoved(QGraphicsItem* rmItem);

    // incoming signals from controller1
    void gotSignal1_SelectPosition(QPointF Position);
    void gotSignal1_SelectMinion(QPointF Position);
    void gotSignal1_SelectMinion(Minion_t* selMinion);
    void gotSignal1_SelectCard(int CardID);
    void gotSignal2_SelectPosition(QPointF Position);
    void gotSignal2_SelectMinion(QPointF Position);
    void gotSignal2_SelectMinion(Minion_t* selMinion);
    void gotSignal2_SelectCard(int CardID);

protected:
    // BattleManager arrange all things about the battlefield
    BattleManager_t* BattleManager;
    // Display arrange all things about display, but only add or remove IMAGE
    Display_t* Display;
    // ControllerSlot is like the slot in a game machine
    ControllerSlot_t* ControllerSlot[2];

private:
    // store the address of ControllableDisplay (if any)
    ControllableDisplay_t* ControllableDisplay;
};

#endif // SYSTEM_H
