#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QDebug>
#include "account.h"
#include "display.h"
#include "minion.h"
#include "battle.h"
#include "controller.h"
#include "tower.h"
#include "aicontroller.h"

// for maintaining game , hold minion's container ...
class System : public QObject
{
    Q_OBJECT

    friend int main(int argc, char *argv[]);

public:
    // the two parameters are the controller connected to this System
    System(ControllerSlot_t* Controller1, ControllerSlot_t* Controller2);
    ~System();

protected slots:
    void setAccount(Account_t* account);

    void startGame();
    void receivedGameOver();

    // add/remove item to Display
    void itemAdded(QGraphicsItem* addItem);
    void itemRemoved(QGraphicsItem* rmItem);

    // incoming signals from controller1
    void receivedSignal1_SelectPosition(QPointF Position);
    void receivedSignal1_SelectMinion(Minion_t* selMinion);
    void receivedSignal1_SelectCard(int CardID);
    // incoming signals from controller2
    void receivedSignal2_SelectPosition(QPointF Position);
    void receivedSignal2_SelectMinion(Minion_t* selMinion);
    void receivedSignal2_SelectCard(int CardID);

    // forward to Display
    void addAnimation(QPointF center, int period, QList<QString> &pathList);

protected:
    AccountManager_t* AccountManager;
    Account_t* Account;

    // BattleManager arrange all things about the battlefield
    BattleManager_t* BattleManager;
    // Display arrange all things about display, but only add or remove IMAGE, and mouseClickEvent
    Display_t* Display;
    // ControllerSlot is like the slot in a gaming machine
    ControllerSlot_t* ControllerSlot[2];

private:
    // store the address of ControllableDisplay (if any)
    ControllableDisplay_t* ControllableDisplay;
    AIController_t* AIController;
};

#endif // SYSTEM_H
