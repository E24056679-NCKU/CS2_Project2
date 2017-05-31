#include "tower.h"
#include "minion.h"

Tower_t::Tower_t() : Life_t()
{
    this->setZValue(-1);
    this->LType = LifeType::Tower;
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
    TowerList[0]->Pos = QPoint(0, 175);
    TowerList[0]->Center = QPoint(75, 250); // center = pos + (75, 75) for main tower
    TowerList[1]->Pos = QPoint(100, 25); // center = pos + (50, 50) for normal tower
    TowerList[1]->Center = QPoint(150, 75);
    TowerList[2]->Pos = QPoint(100, 375);
    TowerList[2]->Center = QPoint(150, 425);
    TowerList[3]->Pos = QPoint(650, 175);
    TowerList[3]->Center = QPoint(725, 250);
    TowerList[4]->Pos = QPoint(550, 375);
    TowerList[4]->Center = QPoint(600, 425);
    TowerList[5]->Pos = QPoint(550, 25);
    TowerList[5]->Center = QPoint(600, 75);

    for(int i=0;i<6;++i)
    {
        TowerList[i]->setPos(TowerList[i]->Pos);
        TowerList[i]->Range = 100;
        TowerList[i]->Team = TowerTeam::MyTeam;
        connect(TowerList[i], SIGNAL(request_FindTarget_Minion(Tower_t*,MinionTeam,Minion_t*&)), this, SLOT(received_FindTarget_Minion(Tower_t*,MinionTeam,Minion_t*&)));
        TowerList[i]->Timer->start(1000);
    }
}

void TowerManager_t::received_FindTarget_Minion(Tower_t *requester, MinionTeam tarTeam, Minion_t *&response)
{
    emit request_FindTarget_Minion( dynamic_cast<Life_t*>(requester), tarTeam, response);
}
