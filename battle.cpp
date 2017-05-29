#include "battle.h"

BattleManager_t::BattleManager_t() : QObject()
{
    MinionManager = new MinionManager_t();
    connect(MinionManager, SIGNAL(minionDied(Minion_t*)), this, SLOT(removeMinion(Minion_t*)));

    TowerManager = new TowerManager_t();

}

BattleManager_t::~BattleManager_t()
{
    delete MinionManager;
    delete TowerManager;
}

void BattleManager_t::addMinion(MinionType Type, MinionTeam Group, QPoint Position)
{
    emit minionAdded(MinionManager->addMinion(Type, Group, Position));
}

void BattleManager_t::removeMinion(Minion_t *rmMinion)
{
    emit minionRemoved(rmMinion);
    MinionManager->removeMinion(rmMinion);
}

void BattleManager_t::gotSignal1_SelectPosition(QPoint Position)
{
    if(CardSelected_Player1 == -1)
        return;
    // create new minion
    this->addMinion( CardtoMinionType_Player1[CardSelected_Player1] , MinionTeam::MyTeam, Position);
}

void BattleManager_t::gotSignal1_SelectMinion(QPoint Position)
{
    CardSelected_Player1 = -1;
}

void BattleManager_t::gotSignal1_SelectMinion(Minion_t *selMinion)
{
    CardSelected_Player1 = -1;
}

void BattleManager_t::gotSignal1_SelectCard(int CardID)
{
    CardSelected_Player1 = CardID;
}

void BattleManager_t::gotSignal2_SelectPosition(QPoint Position)
{

}

void BattleManager_t::gotSignal2_SelectMinion(QPoint Position)
{

}

void BattleManager_t::gotSignal2_SelectMinion(Minion_t *selMinion)
{

}

void BattleManager_t::gotSignal2_SelectCard(int CardID)
{

}
