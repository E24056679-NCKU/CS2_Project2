#include "system.h"

System::System(ControllerSlot_t* Controller1 = nullptr, ControllerSlot_t* Controller2 = nullptr)
{
    if(Controller1 == nullptr)
    {
        ControllableDisplay = new ControllableDisplay_t;
        Display = dynamic_cast<Display_t*>(ControllableDisplay);
        ControllerSlot[0] = dynamic_cast<ControllerSlot_t*>(ControllableDisplay);
    }
    else
    {
        ControllableDisplay = nullptr;
        Display = new Display_t();
        ControllerSlot[0] = Controller1;
    }
    // connect Controller
    connect(ControllerSlot[0], SIGNAL(receivedSignal_SelectCard(int)), this, SLOT(receivedSignal1_SelectCard(int)));
    connect(ControllerSlot[0], SIGNAL(receivedSignal_SelectMinion(Minion_t*)), this, SLOT(receivedSignal1_SelectMinion(Minion_t*)));
    connect(ControllerSlot[0], SIGNAL(receivedSignal_SelectPosition(QPointF)), this, SLOT(receivedSignal1_SelectPosition(QPointF)));

    if(Controller2 == nullptr)
    {
        AIController = new AIController_t;
        ControllerSlot[1] = dynamic_cast<ControllerSlot_t*>(AIController);
    }
    else
    {
        AIController = nullptr;
        ControllerSlot[1] = Controller1;
    }
    // connect controller
    connect(ControllerSlot[1], SIGNAL(receivedSignal_SelectCard(int)), this, SLOT(receivedSignal1_SelectCard(int)));
    connect(ControllerSlot[1], SIGNAL(receivedSignal_SelectMinion(Minion_t*)), this, SLOT(receivedSignal1_SelectMinion(Minion_t*)));
    connect(ControllerSlot[1], SIGNAL(receivedSignal_SelectPosition(QPointF)), this, SLOT(receivedSignal1_SelectPosition(QPointF)));

    BattleManager = new BattleManager_t();
    connect(BattleManager, SIGNAL(gameOver()), this, SLOT(receivedGameOver()));
    connect(BattleManager, SIGNAL(itemAdded(QGraphicsItem*)), this, SLOT(itemAdded(QGraphicsItem*)));
    connect(BattleManager, SIGNAL(itemRemoved(QGraphicsItem*)), this, SLOT(itemRemoved(QGraphicsItem*)));
    connect(BattleManager, SIGNAL(request_Animation(QPointF,int,QList<QString>&)), this, SLOT(addAnimation(QPointF,int,QList<QString>&)));
    // not until now can item created by BattleManager be added to scene
    BattleManager->initialize(); // for initializing towers
}

System::~System()
{
    delete BattleManager;
    delete Display;
    // ControllerSlot[] is not built in this class, it shouldn't be deleted here
}

void System::receivedGameOver()
{
    delete BattleManager; // must be delete first
    Display->gameOver();
}

void System::itemAdded(QGraphicsItem *addItem)
{
    Display->addItem( addItem );

    // if addItem is a Minion_t, connect it with ControllableDisplay
    if( ControllableDisplay != nullptr )
    {
        Minion_t* newMinion = dynamic_cast<Minion_t*>(addItem);
        if( newMinion != nullptr)
            connect(newMinion, SIGNAL(selectedByMouse(Minion_t*)), ControllableDisplay, SLOT(emit_ReceivedSignal_SelectMinion(Minion_t*)));
    }

}

void System::itemRemoved(QGraphicsItem *rmItem)
{
    Display->removeItem( rmItem );
}

void System::receivedSignal1_SelectPosition(QPointF Position)
{
    BattleManager->receivedSignal1_SelectPosition(Position);
}

void System::receivedSignal1_SelectMinion(Minion_t *selMinion)
{
    BattleManager->receivedSignal1_SelectMinion(selMinion);
}

void System::receivedSignal1_SelectCard(int CardID)
{
    BattleManager->receivedSignal1_SelectCard(CardID);
}

void System::receivedSignal2_SelectPosition(QPointF Position)
{
    BattleManager->receivedSignal2_SelectPosition(Position);
}

void System::receivedSignal2_SelectMinion(Minion_t *selMinion)
{
    BattleManager->receivedSignal2_SelectMinion(selMinion);
}

void System::receivedSignal2_SelectCard(int CardID)
{
    BattleManager->receivedSignal2_SelectCard(CardID);
}

void System::addAnimation(QPointF center, int period, QList<QString> &pathList)
{
    Display->addAnimation(center, period, pathList);
}
