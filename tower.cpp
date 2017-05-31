#include "tower.h"
#include "minion.h"

Tower_t::Tower_t() : Life_t()
{
    this->setZValue(-1);
    this->LType = LifeType::Tower;
    this->Dead = false;
}

Tower_t::~Tower_t()
{

}

void Tower_t::findTarget_Minion(Tower_t *requester, MinionTeam tarTeam, Minion_t *&response)
{
    emit request_FindTarget_Minion(requester, tarTeam, response);
}

void Tower_t::run()
{
    Minion_t* tar;
    findTarget_Minion( this, this->Team, tar);

    qDebug() << "Reference tower at " << this->Pos;
    if(tar == nullptr)
    {
        qDebug() << "not found";
    }
    else
    {
        qDebug() << "found " << tar->Pos;
    }
}

TowerManager_t::TowerManager_t() : QObject()
{

}

TowerManager_t::~TowerManager_t()
{
    for(int i=0;i<6;++i)
        delete TowerList[i];
}

void TowerManager_t::initializeTowers()
{
    for(int i=0;i<6;++i)
    {
        TowerList[i] = new Tower_t();
        if(i % 3)
        {
            TowerList[i]->setPixmap(QPixmap("./resources/images/Tower.png"));
        }
        else
        {
            TowerList[i]->setPixmap(QPixmap("./resources/images/MainTower.png"));
        }
        emit itemAdded( dynamic_cast<QGraphicsItem*>(TowerList[i]) );
    }
    TowerList[0]->Pos = QPointF(0, 175);
    TowerList[1]->Pos = QPointF(100, 25); // center = pos + (50, 50) for normal tower
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
        TowerList[i]->Range = 100;
        TowerList[i]->Team = TowerTeam::MyTeam;
        connect(TowerList[i], SIGNAL(request_FindTarget_Minion(Tower_t*,MinionTeam,Minion_t*&)), this, SLOT(received_FindTarget_Minion(Tower_t*,MinionTeam,Minion_t*&)));
        connect(TowerList[i], SIGNAL(died(Tower_t*)), this, SLOT(receivedTowerDied(Tower_t*)));
        TowerList[i]->Timer->start(1000);
    }
}

void TowerManager_t::received_FindTarget_Minion(Tower_t *requester, MinionTeam tarTeam, Minion_t *&response)
{
    emit request_FindTarget_Minion( dynamic_cast<Life_t*>(requester), tarTeam, response);
}

void TowerManager_t::receivedTowerDied(Tower_t *rmTower)
{
    // !!!! not to delete rmTower now, they should be delete when TowerManager is destructed
    rmTower->Timer->stop();
    rmTower->Dead = true;
    emit itemRemoved(rmTower);
}
