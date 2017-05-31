#include "battle.h"

BattleManager_t::BattleManager_t() : QObject()
{
    MinionManager = new MinionManager_t();
    connect(MinionManager, SIGNAL(minionDied(Minion_t*)), this, SLOT(removeMinion(Minion_t*)));
    connect(MinionManager, SIGNAL(request_FindTarget_Minion(Life_t*,MinionTeam,Minion_t*&)), this, SLOT(findMinionInRange(Life_t*,MinionTeam,Minion_t*&)));
    connect(MinionManager, SIGNAL(request_FindTarget_Tower(Life_t*,TowerTeam,Tower_t*&)), this, SLOT(findTowerInRange(Life_t*,TowerTeam,Tower_t*&)));

    TowerManager = new TowerManager_t();
    connect(TowerManager, SIGNAL(itemAdded(QGraphicsItem*)), this, SLOT(emit_ItemAdded(QGraphicsItem*)));
    connect(TowerManager, SIGNAL(itemRemoved(QGraphicsItem*)), this, SLOT(emit_ItemRemoved(QGraphicsItem*)));
    connect(TowerManager, SIGNAL(request_FindTarget_Minion(Life_t*,MinionTeam,Minion_t*&)), this, SLOT(findMinionInRange(Life_t*,MinionTeam,Minion_t*&)));

    ArrowManager = new ArrowManager_t();
    connect(ArrowManager, SIGNAL(itemRemoved(QGraphicsItem*)), this, SLOT(emit_ItemRemoved(QGraphicsItem*)));
}

BattleManager_t::~BattleManager_t()
{
    delete MinionManager;
    delete TowerManager;
    delete ArrowManager;
}

void BattleManager_t::initialize()
{
    TowerManager->initializeTowers();
}

void BattleManager_t::emit_ItemAdded(QGraphicsItem *addItem)
{
    emit itemAdded( addItem );
}

void BattleManager_t::emit_ItemRemoved(QGraphicsItem *rmItem)
{
    emit itemRemoved( rmItem );
}

void BattleManager_t::findMinionInRange(Life_t *requester, MinionTeam tarTeam, Minion_t* &response)
{
    response = nullptr;

    double refX, refY;
    refX = requester->Center.x();
    refY = requester->Center.y();

    for(Minion_t* tar_ptr : this->MinionManager->MinionList)
    {
        if( tar_ptr->Team != tarTeam || tar_ptr == requester )
            continue;
        double tarX = tar_ptr->Pos.x();
        double tarY = tar_ptr->Pos.y();
        double dx = tarX - refX;
        double dy = tarY - refY;
        if( dx*dx + dy*dy <= requester->Range * requester->Range )
        {
            response = tar_ptr;
            return;
        }
    }
}

void BattleManager_t::findTowerInRange(Life_t *requester, TowerTeam tarTeam, Tower_t *&response)
{
    response = nullptr;

    double refX = requester->Pos.x();
    double refY = requester->Pos.y();
    for(int i=0;i<6;++i)
    {
        Tower_t* tar_ptr = this->TowerManager->TowerList[i];
        if( tar_ptr->Team != tarTeam || tar_ptr == requester || tar_ptr->Dead == true )
            continue;

        double tarX[2] = {tar_ptr->Pos.x(), tar_ptr->Pos.x()+100}; // four corner of tower
        double tarY[2] = {tar_ptr->Pos.y(), tar_ptr->Pos.y()+100};
        if(i % 3 == 0) // if tar is main tower
        {
            tarX[1] += 50;
            tarY[1] += 50;
        }

        for(int a=0;a<2;++a)
        {
            for(int b=0;b<2;++b)
            {
                double dx = tarX[a] - refX;
                double dy = tarY[b] - refY;
                if( dx*dx + dy*dy <= requester->Range * requester->Range )
                {
                    response = tar_ptr;
                    return;
                }
            }
        }
    }
}

void BattleManager_t::addMinion(MinionType Type, MinionTeam Group, QPointF Position)
{
    emit minionAdded(MinionManager->addMinion(Type, Group, Position));
}

void BattleManager_t::removeMinion(Minion_t *rmMinion)
{
    emit minionRemoved(rmMinion);
    ArrowManager->removeArrowsByTarget(rmMinion); // those arrows which point to rmMinion should be destruct
    MinionManager->removeMinion(rmMinion);
}

void BattleManager_t::gotSignal1_SelectPosition(QPointF Position)
{
    if(CardSelected_Player1 == -1 && MinionSelected_Player1 != nullptr)
    {

    }
    else if(CardSelected_Player1!= -1 && MinionSelected_Player1 == nullptr)
    {
        // create new minion

        // these two lines are used to test connection with ControllableDisplay
        qDebug() << "BM, sig1, pos, DBG";
        this->addMinion( MinionType::DerivedMinion , MinionTeam::MyTeam, Position);


        // !! recover this line, this->addMinion( CardtoMinionType_Player1[CardSelected_Player1] , MinionTeam::MyTeam, Position);
    }
}

void BattleManager_t::gotSignal1_SelectMinion(QPointF Position)
{
    CardSelected_Player1 = -1;
}

void BattleManager_t::gotSignal1_SelectMinion(Minion_t *selMinion)
{
    MinionSelected_Player1 = selMinion;
    CardSelected_Player1 = -1;
}

void BattleManager_t::gotSignal1_SelectCard(int CardID)
{
    MinionSelected_Player1 = nullptr;
    CardSelected_Player1 = CardID;
}

void BattleManager_t::gotSignal2_SelectPosition(QPointF Position)
{

}

void BattleManager_t::gotSignal2_SelectMinion(QPointF Position)
{

}

void BattleManager_t::gotSignal2_SelectMinion(Minion_t *selMinion)
{
    CardSelected_Player2 = -1;
    MinionSelected_Player2 = selMinion;
}

void BattleManager_t::gotSignal2_SelectCard(int CardID)
{

}
