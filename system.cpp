#include "system.h"

System::System(ControllerSlot_t* Controller1 = nullptr, ControllerSlot_t* Controller2 = nullptr)
{
    BattleManager = new BattleManager_t();
    connect(BattleManager, SIGNAL(minionAdded(Minion_t*)), this, SLOT(minionAdded(Minion_t*)));
    connect(BattleManager, SIGNAL(minionRemoved(Minion_t*)), this, SLOT(minionRemoved(Minion_t*)));

    if(Controller1 == nullptr)
    {
        ControllableDisplay = new ControllableDisplay_t;
        Display = dynamic_cast<Display_t*>(ControllableDisplay);
        ControllerSlot[0] = dynamic_cast<ControllerSlot_t*>(ControllableDisplay);

        // connect Controller
        connect(ControllableDisplay, SIGNAL(gotSignal_SelectCard(int)), this, SLOT(gotSignal1_SelectCard(int)));
        connect(ControllableDisplay, SIGNAL(gotSignal_SelectMinion(Minion_t*)), this, SLOT(gotSignal1_SelectMinion(Minion_t*)));
        connect(ControllableDisplay, SIGNAL(gotSignal_SelectMinion(QPoint)), this, SLOT(gotSignal1_SelectMinion(QPoint)));
        connect(ControllableDisplay, SIGNAL(gotSignal_SelectPosition(QPoint)), this, SLOT(gotSignal1_SelectPosition(QPoint)));
    }
    else
    {
        ControllableDisplay = nullptr;
        Display = new Display_t();
        ControllerSlot[0] = Controller1;
    }

    if(Controller2 == nullptr)
    {
        /*
        AIController = new AIController_t;
        connect(Controller2, SIGNAL(gotSignal_SelectCard(int)), this, SLOT(gotSignal2_SelectCard(int)));
        connect(Controller2, SIGNAL(gotSignal_SelectMinion(Minion_t*)), this, SLOT(gotSignal2_SelectMinion(Minion_t*)));
        connect(Controller2, SIGNAL(gotSignal_SelectMinion(QPoint)), this, SLOT(gotSignal2_SelectMinion(QPoint)));
        connect(Controller2, SIGNAL(gotSignal_SelectPosition(QPoint)), this, SLOT(gotSignal2_SelectPosition(QPoint)));
        */
    }
    else
    {
        ControllerSlot[1] = Controller1;
    }

    // connect ...
}

System::~System()
{
    delete BattleManager;
    delete Display;
    // ControllerSlot[] is not built in this class, it shouldn't be delete here
}

void System::minionAdded(Minion_t *newMinion)
{
    Display->addItem(newMinion);

    // connect minion with ControllableDisplay
    if( ControllableDisplay != nullptr )
    {
        connect(newMinion, SIGNAL(selectedByMouse(Minion_t*)), ControllableDisplay, SLOT(emit_GotSignal_SelectMinion(Minion_t*)));
    }
}

void System::minionRemoved(Minion_t *rmMinion)
{
    Display->removeItem(rmMinion);
}

void System::gotSignal1_SelectPosition(QPoint Position)
{
    BattleManager->gotSignal1_SelectPosition(Position);
}

void System::gotSignal1_SelectMinion(QPoint Position)
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

void System::gotSignal2_SelectPosition(QPoint Position)
{
    BattleManager->gotSignal2_SelectPosition(Position);
}

void System::gotSignal2_SelectMinion(QPoint Position)
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
