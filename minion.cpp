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

void Minion_t::findTarget(Life_t *&response)
{
    LifeTeam tarTeam;
    if( this->Team == MinionTeam::MyTeam )
        tarTeam = LifeTeam::OpsTeam;
    else if( this->Team == MinionTeam::OpsTeam )
        tarTeam = LifeTeam::MyTeam;

    // DBG
    tarTeam = LifeTeam::MyTeam;

    emit request_FindTarget( dynamic_cast<Life_t*>(this) , tarTeam, response);
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
    connect(newMinion, SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(received_FindTarget(Life_t*,LifeTeam,Life_t*&)));
    connect(newMinion, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(receive_arrowAttack(Life_t*,double,QPointF)));
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
    removeMinion(rmMinion);
}

void MinionManager_t::received_FindTarget(Life_t *requester, LifeTeam tarTeam, Life_t *&response)
{
    emit request_FindTarget(requester, tarTeam, response);
}

void MinionManager_t::receive_arrowAttack(Life_t *target, double damage, QPointF pos)
{
    emit emit_ArrowAttack(target, damage, pos);
}


// DerivedMinion
QPixmap* DerivedMinion_t::BasicImage = nullptr;
QList< QPixmap* > DerivedMinion_t::MovingImages = QList< QPixmap* >();
QList< QPixmap* > DerivedMinion_t::AttackingImages = QList< QPixmap* >();

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

    // DBG
    this->Range = 50;
    this->HP = 50;

    this->Timer->start(1000);
}

DerivedMinion_t::~DerivedMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void DerivedMinion_t::run()
{
    if(this->checkDied())
        return;

    qDebug() << "minion hp" << this->HP;

    //DBG
    this->Damage = 1;

    Life_t* tarLife;
    findTarget(tarLife);

    //qDebug() << "Reference point at " << this->Pos;
    if(tarLife == nullptr)
    {
        //qDebug() << "not found";
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) )
        {
            qDebug() << "found Minion at " << tarLife->Pos;
            // DBG
            //arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) )
        {
            qDebug() << "found Tower at " << tarLife->Pos;
            // DBG
            arrowAttack(tarLife);
        }
    }
}

void DerivedMinion_t::move()
{

}

void DerivedMinion_t::attack(Life_t *target)
{

}
