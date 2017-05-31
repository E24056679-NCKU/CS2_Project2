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
    connect(ControllerSlot[0], SIGNAL(gotSignal_SelectCard(int)), this, SLOT(gotSignal1_SelectCard(int)));
    connect(ControllerSlot[0], SIGNAL(gotSignal_SelectMinion(Minion_t*)), this, SLOT(gotSignal1_SelectMinion(Minion_t*)));
    connect(ControllerSlot[0], SIGNAL(gotSignal_SelectMinion(QPointF)), this, SLOT(gotSignal1_SelectMinion(QPointF)));
    connect(ControllerSlot[0], SIGNAL(gotSignal_SelectPosition(QPointF)), this, SLOT(gotSignal1_SelectPosition(QPointF)));

    if(Controller2 == nullptr)
    {
        /*
        AIController = new AIController_t;
        connect(Controller2, SIGNAL(gotSignal_SelectCard(int)), this, SLOT(gotSignal2_SelectCard(int)));
        connect(Controller2, SIGNAL(gotSignal_SelectMinion(Minion_t*)), this, SLOT(gotSignal2_SelectMinion(Minion_t*)));
        connect(Controller2, SIGNAL(gotSignal_SelectMinion(QPointF)), this, SLOT(gotSignal2_SelectMinion(QPointF)));
        connect(Controller2, SIGNAL(gotSignal_SelectPosition(QPointF)), this, SLOT(gotSignal2_SelectPosition(QPointF)));
        */
    }
    else
    {
        ControllerSlot[1] = Controller1;
    }
    // connect controller
    /*
    connect(ControllerSlot[1], SIGNAL(gotSignal_SelectCard(int)), this, SLOT(gotSignal1_SelectCard(int)));
    connect(ControllerSlot[1], SIGNAL(gotSignal_SelectMinion(Minion_t*)), this, SLOT(gotSignal1_SelectMinion(Minion_t*)));
    connect(ControllerSlot[1], SIGNAL(gotSignal_SelectMinion(QPointF)), this, SLOT(gotSignal1_SelectMinion(QPointF)));
    connect(ControllerSlot[1], SIGNAL(gotSignal_SelectPosition(QPointF)), this, SLOT(gotSignal1_SelectPosition(QPointF)));
    */

    // connect ...


    BattleManager = new BattleManager_t();
    connect(BattleManager, SIGNAL(minionAdded(Minion_t*)), this, SLOT(minionAdded(Minion_t*)));
    connect(BattleManager, SIGNAL(minionRemoved(Minion_t*)), this, SLOT(minionRemoved(Minion_t*)));
    connect(BattleManager, SIGNAL(itemAdded(QGraphicsItem*)), this, SLOT(itemAdded(QGraphicsItem*)));
    connect(BattleManager, SIGNAL(itemRemoved(QGraphicsItem*)), this, SLOT(itemRemoved(QGraphicsItem*)));
    BattleManager->initialize();
}

System::~System()
{
    delete BattleManager;
    delete Display;
    // ControllerSlot[] is not built in this class, it shouldn't be delete here
}

void System::minionAdded(Minion_t *newMinion)
{
    Display->addItem( dynamic_cast<QGraphicsItem*>(newMinion) );

    // connect minion with ControllableDisplay
    if( ControllableDisplay != nullptr )
    {
        connect(newMinion, SIGNAL(selectedByMouse(Minion_t*)), ControllableDisplay, SLOT(emit_GotSignal_SelectMinion(Minion_t*)));
    }
}

void System::minionRemoved(Minion_t *rmMinion)
{
    Display->removeItem( dynamic_cast<QGraphicsItem*>(rmMinion) );
}

void System::itemAdded(QGraphicsItem *addItem)
{
    Display->addItem( addItem );
}

void System::itemRemoved(QGraphicsItem *rmItem)
{
    Display->addItem( rmItem );
}

void System::gotSignal1_SelectPosition(QPointF Position)
{
    BattleManager->gotSignal1_SelectPosition(Position);
}

void System::gotSignal1_SelectMinion(QPointF Position)
{
    BattleManager->gotSignal1_SelectMinion(Position);
}

void System::gotSignal1_SelectMinion(Minion_t *selMinion)
{
    BattleManager->gotSignal1_SelectMinion(selMinion);
}

void System::gotSignal1_SelectCard(int CardID)
{
    BattleManager->gotSignal1_SelectCard(CardID);
}

void System::gotSignal2_SelectPosition(QPointF Position)
{
    BattleManager->gotSignal2_SelectPosition(Position);
}

void System::gotSignal2_SelectMinion(QPointF Position)
{
    BattleManager->gotSignal2_SelectMinion(Position);
}

void System::gotSignal2_SelectMinion(Minion_t *selMinion)
{
    BattleManager->gotSignal2_SelectMinion(selMinion);
}

void System::gotSignal2_SelectCard(int CardID)
{
    BattleManager->gotSignal2_SelectCard(CardID);
}
