#include "tower.h"
#include "minion.h"

Tower_t::Tower_t() : Life_t()
{
    this->setZValue(-1);
    this->LType = LifeType::Tower;
    this->setEnabled(0);

    //DBG
    this->HP = 100;
}

Tower_t::~Tower_t()
{

}

void Tower_t::findTarget(Life_t *&response)
{
    LifeTeam tarTeam;
    if( this->Team == TowerTeam::MyTeam )
        tarTeam = LifeTeam::OpsTeam;
    else if( this->Team == TowerTeam::OpsTeam )
        tarTeam = LifeTeam::MyTeam;

    //DBG
    tarTeam = LifeTeam::MyTeam;

    emit request_FindTarget( dynamic_cast<Life_t*>(this) , tarTeam, response);
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

    // DBG
    this->Range = 300;
    this->Damage = 1;

    Life_t* tarLife;
    findTarget(tarLife);

    // qDebug() << "Reference tower at " << this->Pos;
    if(tarLife == nullptr)
    {
        // qDebug() << "not found";
    }
    else
    {
        // qDebug() << "tower found minion at " << tarLife->Pos;
        // DBG
        arrowAttack(tarLife);
    }
}

void Tower_t::attack(Life_t *target)
{

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
        connect(TowerList[i], SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(received_FindTarget(Life_t*,LifeTeam,Life_t*&)));
        connect(TowerList[i], SIGNAL(died(Tower_t*)), this, SLOT(receivedTowerDied(Tower_t*)));
        connect(TowerList[i], SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(receive_arrowAttack(Life_t*,double,QPointF)));
        TowerList[i]->Timer->start(1000);
    }
}

void TowerManager_t::receivedTowerDied(Tower_t *rmTower)
{
    for(int i=0;i<6;++i)
        if( TowerList[i] == rmTower )
            TowerList[i] = nullptr;
    delete rmTower;
}

void TowerManager_t::received_FindTarget(Life_t *requester, LifeTeam tarTeam, Life_t *&response)
{
    emit request_FindTarget(requester, tarTeam, response);
}

void TowerManager_t::receive_arrowAttack(Life_t *target, double damage, QPointF pos)
{
    emit emit_ArrowAttack(target, damage, pos);
}
