#include "tower.h"
#include "minion.h"

Tower_t::Tower_t() : Life_t()
{
    this->setZValue(-1);
    this->LType = LifeType::Tower;

    this->Hz = 1;
}

Tower_t::~Tower_t()
{

}

bool Tower_t::checkDied()
{
    if(this->HP <= 0)
    {
        emit died(this);
        return true;
    }
    else
    {
        return false;
    }
}

void Tower_t::run()
{
    if(this->checkDied())
        return;

    QList<Life_t*> tarLifeList;
    findAllTarget(tarLifeList, 3);

    for( auto &i : tarLifeList )
        attack(i);
}

void Tower_t::attack(Life_t *target)
{
    arrowAttack(target);
}

TowerManager_t::TowerManager_t() : QObject()
{

}

TowerManager_t::~TowerManager_t()
{
    for(int i=0;i<6;++i)
        if(TowerList[i] != nullptr)
            delete TowerList[i];
}

void TowerManager_t::initializeTowers()
{
    for(int i=0;i<6;++i)
    {
        TowerList[i] = new Tower_t();
        if(i % 3) // normal tower
        {
            TowerList[i]->HP = 1000;
            TowerList[i]->Damage = 50;
            TowerList[i]->Range = 200;
            TowerList[i]->TType = TowerType::NormalTower;
            TowerList[i]->setPixmap(QPixmap("./resources/images/Tower.jpg"));
        }
        else
        {
            TowerList[i]->HP = 3000;
            TowerList[i]->Damage = 100;
            TowerList[i]->Range = 300;
            TowerList[i]->TType = TowerType::MainTower;
            TowerList[i]->setPixmap(QPixmap("./resources/images/MainTower.jpg"));
        }
        emit itemAdded( dynamic_cast<QGraphicsItem*>(TowerList[i]) );
    }
    TowerList[0]->Pos = QPointF(0, 175);
    TowerList[1]->Pos = QPointF(100, 25);
    TowerList[2]->Pos = QPointF(100, 375);
    TowerList[3]->Pos = QPointF(650, 175);
    TowerList[4]->Pos = QPointF(550, 375);
    TowerList[5]->Pos = QPointF(550, 25);
    for(int i=0;i<6;++i)
    {
        TowerList[i]->Center = QPointF(TowerList[i]->Pos.x() + TowerList[i]->pixmap().size().width()/2 , TowerList[i]->Pos.y() + TowerList[i]->pixmap().size().height()/2);
    }

    for(int i=0;i<6;++i)
    {
        TowerList[i]->setPos(TowerList[i]->Pos);
        if( i < 3 )
            TowerList[i]->Team = TowerTeam::MyTeam;
        else
            TowerList[i]->Team = TowerTeam::OpsTeam;
        connect(TowerList[i], SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(received_FindTarget(Life_t*,LifeTeam,Life_t*&)));
        connect(TowerList[i], SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&,int)), this, SLOT(received_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&,int)));
        connect(TowerList[i], SIGNAL(died(Tower_t*)), this, SLOT(receivedTowerDied(Tower_t*)));
        connect(TowerList[i], SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(receive_arrowAttack(Life_t*,double,QPointF)));
        TowerList[i]->Timer->start(1000 / TowerList[i]->Hz);
    }
}

void TowerManager_t::receivedTowerDied(Tower_t *rmTower)
{
    emit emit_TowerRemoved( rmTower );
    for(int i=0;i<6;++i)
        if( TowerList[i] == rmTower )
            TowerList[i] = nullptr;
    delete rmTower;
}

void TowerManager_t::received_FindTarget(Life_t *requester, LifeTeam tarTeam, Life_t *&response)
{
    emit request_FindTarget(requester, tarTeam, response);
}

void TowerManager_t::received_FindAllTarget(Life_t *requester, LifeTeam tarTeam, QList<Life_t *> &response, int SizeLimit)
{
    emit request_FindAllTarget(requester, tarTeam, response, SizeLimit);
}

void TowerManager_t::receive_arrowAttack(Life_t *target, double damage, QPointF pos)
{
    emit emit_ArrowAttack(target, damage, pos);
}
