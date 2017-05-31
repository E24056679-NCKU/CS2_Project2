#include <QDebug>
#include "minion.h"
#include "tower.h"

// abstract Minion
Minion_t::Minion_t() : Life_t()
{
    this->setZValue(0);
    this->LType = LifeType::Minion;
}

Minion_t::~Minion_t()
{

}

bool Minion_t::checkDied()
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

void Minion_t::findTarget_Tower(Minion_t *requester, TowerTeam tarTeam, Tower_t* &response)
{
    emit request_FindTarget_Tower(requester, tarTeam, response);
}

void Minion_t::findTarget_Minion(Minion_t *requester, MinionTeam tarTeam, Minion_t* &response)
{
    emit request_FindTarget_Minion(requester, tarTeam, response);
}

void Minion_t::run()
{
    qDebug() << "Error, abstract Minion's run has been executed";
}

void Minion_t::move()
{
    qDebug() << "Error, abstract Minion's move has been executed";
}

void Minion_t::attack(Life_t *target)
{
    qDebug() << "Error, abstract Minion's attack has been executed";
}

MinionManager_t::MinionManager_t() : QObject()
{

}

MinionManager_t::~MinionManager_t()
{
    for(auto &i : MinionList)
        delete i;
}

Minion_t *MinionManager_t::addMinion(MinionType Type, MinionTeam Team, QPointF Position)
{
    Minion_t* newMinion;
    switch(Type)
    {
        case BasicMinion :

            break;

        case DerivedMinion :
            newMinion = dynamic_cast<Minion_t*>(new DerivedMinion_t());
            MinionList.insert( newMinion );
            break;


    }
    newMinion->Team = Team;
    newMinion->Pos = Position;
    newMinion->Center = QPointF(newMinion->Pos.x() + newMinion->pixmap().size().width()/2 , newMinion->Pos.y() + newMinion->pixmap().size().height()/2);
    newMinion->setPos( newMinion->Pos );
    connect(newMinion, SIGNAL(died(Minion_t*)), this, SLOT(receivedMinionDied(Minion_t*)));
    connect(newMinion, SIGNAL(request_FindTarget_Minion(Minion_t*, MinionTeam, Minion_t*&)), this, SLOT(received_FindTarget_Minion(Minion_t*, MinionTeam, Minion_t*&)));
    connect(newMinion, SIGNAL(request_FindTarget_Tower(Minion_t*, TowerTeam, Tower_t*&)), this, SLOT(received_FindTarget_Tower(Minion_t*, TowerTeam,Tower_t*&)));
    return newMinion;
}

void MinionManager_t::removeMinion(Minion_t* rmMinion)
{
    auto it = this->MinionList.find(rmMinion);
    if(it != this->MinionList.end())
    {
        this->MinionList.erase(it);
        delete rmMinion;
    }
}

void MinionManager_t::receivedMinionDied(Minion_t *rmMinion)
{
    emit minionDied(rmMinion);
    // removeMinion(rmMinion); // not to use this line, BattleManager will call removeMinion to remove this minion
}

void MinionManager_t::received_FindTarget_Tower(Minion_t *requester, TowerTeam tarTeam, Tower_t *&response)
{
    emit request_FindTarget_Tower( dynamic_cast<Life_t*>(requester), tarTeam, response);
}

void MinionManager_t::received_FindTarget_Minion(Minion_t *requester, MinionTeam tarTeam, Minion_t *&response)
{
    emit request_FindTarget_Minion( dynamic_cast<Life_t*>(requester), tarTeam, response);
}


// DerivedMinion
QPixmap* DerivedMinion_t::BasicImage = nullptr;
QVector< QPixmap* > DerivedMinion_t::MovingImages = QVector< QPixmap* >();
QVector< QPixmap* > DerivedMinion_t::AttackingImages = QVector< QPixmap* >();

DerivedMinion_t::DerivedMinion_t() : Minion_t()
{
    if( DerivedMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        DerivedMinion_t::BasicImage = new QPixmap("./resources/images/DerivedMinion.png");
        for( int i=1 ; i<=0 ; ++i )
        {
            char path[100];
            strcpy(path, "./resources/images/DerivedMinion_move_x.png");
            int len = strlen(path);
            path[len-5] = i + '0';
            DerivedMinion_t::MovingImages.push_back( new QPixmap(path) );
        }
        for( int i=1 ; i<=0 ; ++i)
        {
            char path[100];
            strcpy(path, "./resources/images/DerivedMinion_attack_x.png");
            int len = strlen(path);
            path[len-5] = i + '0';
            DerivedMinion_t::AttackingImages.push_back( new QPixmap(path) );
        }
    }
    this->setPixmap( * (this->BasicImage) );

    // DEBUG
    this->Range = 50;

    this->Timer->start(1000);
}

DerivedMinion_t::~DerivedMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void DerivedMinion_t::run()
{
    Minion_t* tar;
    findTarget_Minion( dynamic_cast<Minion_t*>(this), this->Team, tar);

    /* DEBUG
    qDebug() << "Reference point at " << this->Pos;
    if(tar == nullptr)
    {
        qDebug() << "not found";
    }
    else
    {
        qDebug() << "found " << tar->Pos;
    }
    */
}

void DerivedMinion_t::move()
{

}

void DerivedMinion_t::attack(Life_t *target)
{

}
