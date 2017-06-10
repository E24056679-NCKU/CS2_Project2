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

void Minion_t::run()
{
    qDebug() << "Error, abstract Minion's run has been executed";
}

void Minion_t::move()
{
    this->Pos.setX( this->Pos.x() + this->Speed);
    this->Center.setX( this->Pos.x() + this->Speed ); // !! remember to set Center, or fog will go wrong
    this->setPos(this->Pos);

    // if out of boundary
    if( this->Center.x() < 0 || this->Center.x() > 800)
        emit died(this);
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
    connect(newMinion, SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&)), this, SLOT(received_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&)));
    connect(newMinion, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(receive_ArrowAttack(Life_t*,double,QPointF)));
    connect(newMinion, SIGNAL(request_Animation(QPointF,int,QList<QString>&)), this, SLOT(received_Animation(QPointF,int,QList<QString>&)));
    connect(newMinion, SIGNAL(request_RangeAttack(Life_t*,QPointF,double,double,LifeTeam)), this, SLOT(received_RangeAttack(Life_t*,QPointF,double,double,LifeTeam)));
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

void MinionManager_t::received_FindAllTarget(Life_t *requester, LifeTeam tarTeam, QList<Life_t *> &response)
{
    emit request_FindAllTarget(requester, tarTeam, response);
}

void MinionManager_t::receive_ArrowAttack(Life_t *target, double damage, QPointF pos)
{
    emit emit_ArrowAttack(target, damage, pos);
}

void MinionManager_t::received_Animation(QPointF center, int period, QList<QString> &pathList)
{
    emit request_Animation(center, period, pathList);
}

void MinionManager_t::received_RangeAttack(Life_t *requester, QPointF center, double range, double damage, LifeTeam targetTeam)
{
    emit request_RangeAttack(requester, center, range, damage, targetTeam);
}


// DerivedMinion
QPixmap* DerivedMinion_t::BasicImage = nullptr;
QList< QPixmap* > DerivedMinion_t::MovingImages = QList< QPixmap* >();
QList< QPixmap* > DerivedMinion_t::AttackingImages = QList< QPixmap* >();

DerivedMinion_t::DerivedMinion_t() : Minion_t()
{
    if( DerivedMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        DerivedMinion_t::BasicImage = new QPixmap("./resources/images/DerivedMinion.jpg");

        // import moving images
        for( int i=1 ; i<=0 ; ++i )
        {
            DerivedMinion_t::MovingImages.push_back( new QPixmap( QString("./resources/images/DerivedMinion_move_") + i + ".jpg" ) );
        }

        // import attacking images
        for( int i=1 ; i<=0 ; ++i)
            DerivedMinion_t::AttackingImages.push_back( new QPixmap( QString("./resources/images/DerivedMinion_attack_") + i + ".jpg" ) );
    }
    this->setPixmap( * (this->BasicImage) );

    // DBG
    this->Range = 0;
    this->HP = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

DerivedMinion_t::~DerivedMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void DerivedMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    //DBG
    this->Damage = 1;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        //DBG
        this->Speed = 10;

        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            // DBG
            //arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            // DBG
            arrowAttack(tarLife);
        }
    }
}

void DerivedMinion_t::attack(Life_t *target)
{

}
