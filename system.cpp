#include "system.h"

System::System(ControllerSlot_t* Controller1 = nullptr, ControllerSlot_t* Controller2 = nullptr)
{
    // initialize mininos' image
    ChairMinion_t();
    ChangMinion_t();
    ChengMinion_t();
    JouMinion_t();
    LeeMinion_t();
    TsaiMinion_t();


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
    connect(ControllerSlot[0], SIGNAL(receivedSignal_KeyPressed(int)), this, SLOT(receivedSignal1_KeyPressed(int)));

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
    connect(ControllerSlot[1], SIGNAL(receivedSignal_KeyPressed(int)), this, SLOT(receivedSignal2_KeyPressed(int)));

    BattleManager = new BattleManager_t();
    connect(BattleManager, SIGNAL(gameOver(int,int)), this, SLOT(receivedGameOver(int,int)));
    connect(BattleManager, SIGNAL(itemAdded(QGraphicsItem*)), this, SLOT(itemAdded(QGraphicsItem*)));
    connect(BattleManager, SIGNAL(itemRemoved(QGraphicsItem*)), this, SLOT(itemRemoved(QGraphicsItem*)));
    connect(BattleManager, SIGNAL(request_Animation(QPointF)), this, SLOT(addAnimation(QPointF)));
    connect(BattleManager, SIGNAL(changeButtonImage(int,MinionType)), this, SLOT(changeButtonImage(int,MinionType)));
    // not until now can item created by BattleManager be added to scene
    BattleManager->initialize(); // for initializing towers

    AccountManager = new AccountManager_t;
    Display->MenuDisplay->AccountManager = AccountManager;
    connect(Display->MenuDisplay, SIGNAL(setupCompleted(QList<int>)), this, SLOT(startGame(QList<int>)));
    connect(Display->MenuDisplay, SIGNAL(accountLogined(Account_t*)), this, SLOT(setAccount(Account_t*)));


    // create score, countdown, and skillbutton(for android)
    Display->Scene->addWidget(BattleManager->Player1Score_Label);
    Display->Scene->addWidget(BattleManager->Player2Score_Label);
    Display->Scene->addWidget(BattleManager->CountDown_Label);
    Display->Scene->addWidget(BattleManager->Skill_Button);
}

System::~System()
{
    delete AccountManager;
    delete BattleManager;
    delete Display;
    // ControllerSlot[] is not built in this class, it shouldn't be deleted here
}

void System::setAccount(Account_t* account)
{
    this->Account = account;
}

void System::startGame(QList<int> cardSelected)
{
    Display->changetoGameScene();
    BattleManager->setupCards(cardSelected, BattleManager->Player1);
    BattleManager->Timer->start(10); // start game

    //DBG
    // BattleManager->addMinion(MinionType::DerivedMinion, MinionTeam::MyTeam, QPointF(400, 300));
}

void System::receivedGameOver(int score1, int score2)
{
    delete BattleManager; // must be delete first
    Account->Money += score1;
    AccountManager->saveFile();
    if( score1 > score2 )
        Display->changetoGameOverScene(1);
    else if(score1 < score2 )
        Display->changetoGameOverScene(2);
    else
        Display->changetoGameOverScene(0);
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

void System::receivedSignal1_SelectCard(int ButtonID)
{
    BattleManager->receivedSignal1_SelectCard(ButtonID);
}

void System::receivedSignal1_KeyPressed(int key)
{
    BattleManager->receivedSignal1_KeyPressed(key);
}

void System::receivedSignal2_SelectPosition(QPointF Position)
{
    BattleManager->receivedSignal2_SelectPosition(Position);
}

void System::receivedSignal2_SelectMinion(Minion_t *selMinion)
{
    BattleManager->receivedSignal2_SelectMinion(selMinion);
}

void System::receivedSignal2_SelectCard(int ButtonID)
{
    BattleManager->receivedSignal2_SelectCard(ButtonID);
}

void System::receivedSignal2_KeyPressed(int key)
{
    BattleManager->receivedSignal2_KeyPressed(key);
}

void System::addAnimation(QPointF center)
{
    Display->addAnimation(center);
}

void System::changeButtonImage(int ButtonID, MinionType minionType)
{
    if( minionType == -1 )
    {
        Display->Button[ ButtonID ]->setPixmap( QPixmap("./resources/images/Button.jpg") );
    }
    else if( minionType == MinionType::ChairMinion )
    {
        Display->Button[ ButtonID ]->setPixmap( *ChairMinion_t::ButtonImage );
    }
    else if( minionType == MinionType::ChangMinion )
    {
        Display->Button[ ButtonID ]->setPixmap( *ChangMinion_t::ButtonImage );
    }
    else if( minionType == MinionType::ChengMinion )
    {
        Display->Button[ ButtonID ]->setPixmap( *ChengMinion_t::ButtonImage );
    }
    else if( minionType == MinionType::JouMinion )
    {
        Display->Button[ ButtonID ]->setPixmap( *JouMinion_t::ButtonImage );
    }
    else if( minionType == MinionType::LeeMinion )
    {
        Display->Button[ ButtonID ]->setPixmap( *LeeMinion_t::ButtonImage );
    }
    else if( minionType == MinionType::TsaiMinion )
    {
        Display->Button[ ButtonID ]->setPixmap( *TsaiMinion_t::ButtonImage );
    }
}
