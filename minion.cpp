#include <QDebug>
#include <QtMath>
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
    double theta = qAtan( qAbs(this->TargetPos.y() - this->Center.y()) / qAbs(this->TargetPos.x() - this->Center.x()) );
    int dx = this->Speed * qCos(theta);
    int dy = this->Speed * qSin(theta);
    if( this->TargetPos.x() < this->Center.x() )
        dx = -dx;
    if( this->TargetPos.y() < this->Center.y() )
        dy = -dy;

    this->Pos.setX( this->Pos.x() + dx);
    this->Center.setX( this->Center.x() + dx ); // !! remember to set Center, or fog will go wrong
    this->Pos.setY( this->Pos.y() + dy);
    this->Center.setY( this->Center.y() + dy ); // !! remember to set Center, or fog will go wrong
    this->setPos(this->Pos);

    // if out of boundary
    if( this->Center.x() < 0 || this->Center.x() > 800)
        emit died(this);
}

void Minion_t::attack(Life_t *target)
{
    qDebug() << "Error, abstract Minion's attack has been executed";
}

void Minion_t::skill()
{
    LifeTeam tarTeam = this->Team == LifeTeam::MyTeam ? LifeTeam::OpsTeam : LifeTeam::MyTeam;
    QList<Life_t*> attackee;
    this->request_FindAllTarget(this, tarTeam, attackee, 9999);
    for(auto &i : attackee)
    {
        i->HP -= this->Damage;
        this->request_Animation( i->Center );
    }
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

        case ChairMinion :
            newMinion = dynamic_cast<Minion_t*>(new ChairMinion_t());
            MinionList.insert( newMinion );
            break;
        case ChangMinion :
            newMinion = dynamic_cast<Minion_t*>(new ChangMinion_t());
            MinionList.insert( newMinion );
            break;
        case ChengMinion :
            newMinion = dynamic_cast<Minion_t*>(new ChengMinion_t());
            MinionList.insert( newMinion );
            break;
        case JouMinion :
            newMinion = dynamic_cast<Minion_t*>(new JouMinion_t());
            MinionList.insert( newMinion );
            break;
        case LeeMinion :
            newMinion = dynamic_cast<Minion_t*>(new LeeMinion_t());
            MinionList.insert( newMinion );
            break;
        case TsaiMinion :
            newMinion = dynamic_cast<Minion_t*>(new TsaiMinion_t());
            MinionList.insert( newMinion );
            break;

    }
    newMinion->Team = Team;
    newMinion->Pos = Position;
    if( newMinion->Team == MinionTeam::MyTeam )
        newMinion->TargetPos = QPointF(1000, newMinion->Pos.y());
    else if( newMinion->Team == MinionTeam::OpsTeam )
        newMinion->TargetPos = QPointF(-1000, newMinion->Pos.y());
    newMinion->Center = QPointF(newMinion->Pos.x() + newMinion->pixmap().size().width()/2 , newMinion->Pos.y() + newMinion->pixmap().size().height()/2);
    newMinion->setPos( newMinion->Pos );
    connect(newMinion, SIGNAL(died(Minion_t*)), this, SLOT(receivedMinionDied(Minion_t*)));
    connect(newMinion, SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(received_FindTarget(Life_t*,LifeTeam,Life_t*&)));
    connect(newMinion, SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&,int)), this, SLOT(received_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&,int)));
    connect(newMinion, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(receive_ArrowAttack(Life_t*,double,QPointF)));
    connect(newMinion, SIGNAL(request_Animation(QPointF)), this, SLOT(received_Animation(QPointF)));
    connect(newMinion, SIGNAL(request_RangeAttack(Life_t*,QPointF,double,double,LifeTeam)), this, SLOT(received_RangeAttack(Life_t*,QPointF,double,double,LifeTeam)));
    return newMinion;
}

void MinionManager_t::removeMinion(Minion_t* rmMinion)
{
    emit emit_MinionRemoved(rmMinion);
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

void MinionManager_t::received_FindAllTarget(Life_t *requester, LifeTeam tarTeam, QList<Life_t *> &response, int SizeLimit)
{
    emit request_FindAllTarget(requester, tarTeam, response, SizeLimit);
}

void MinionManager_t::receive_ArrowAttack(Life_t *target, double damage, QPointF pos)
{
    emit emit_ArrowAttack(target, damage, pos);
}

void MinionManager_t::received_Animation(QPointF center)
{
    emit request_Animation(center);
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

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
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

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void DerivedMinion_t::attack(Life_t *target)
{
}


// ChairMinion_t
QPixmap* ChairMinion_t::BasicImage = nullptr;
QPixmap* ChairMinion_t::ButtonImage = nullptr;

ChairMinion_t::ChairMinion_t() : Minion_t()
{
    if( ChairMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        ChairMinion_t::BasicImage = new QPixmap("./resources/images/chair_minion.jpg");
        ChairMinion_t::ButtonImage = new QPixmap("./resources/images/chair_button.jpg");
    }
    this->setPixmap( * (this->BasicImage) );

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

ChairMinion_t::~ChairMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void ChairMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void ChairMinion_t::attack(Life_t *target)
{
}


// ChangMinion_t
QPixmap* ChangMinion_t::BasicImage = nullptr;
QPixmap* ChangMinion_t::ButtonImage = nullptr;

ChangMinion_t::ChangMinion_t() : Minion_t()
{
    if( ChangMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        ChangMinion_t::BasicImage = new QPixmap("./resources/images/chang_minion.jpg");
        ChangMinion_t::ButtonImage = new QPixmap("./resources/images/chang_button.jpg");
    }
    this->setPixmap( * (this->BasicImage) );

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

ChangMinion_t::~ChangMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void ChangMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void ChangMinion_t::attack(Life_t *target)
{
}


// ChengMinion_t
QPixmap* ChengMinion_t::BasicImage = nullptr;
QPixmap* ChengMinion_t::ButtonImage = nullptr;

ChengMinion_t::ChengMinion_t() : Minion_t()
{
    if( ChengMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        ChengMinion_t::BasicImage = new QPixmap("./resources/images/cheng_minion.jpg");
        ChengMinion_t::ButtonImage = new QPixmap("./resources/images/cheng_button.jpg");
    }
    this->setPixmap( * (this->BasicImage) );

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

ChengMinion_t::~ChengMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void ChengMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void ChengMinion_t::attack(Life_t *target)
{
}


// JouMinion_t
QPixmap* JouMinion_t::BasicImage = nullptr;
QPixmap* JouMinion_t::ButtonImage = nullptr;

JouMinion_t::JouMinion_t() : Minion_t()
{
    if( JouMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        JouMinion_t::BasicImage = new QPixmap("./resources/images/jou_minion.jpg");
        JouMinion_t::ButtonImage = new QPixmap("./resources/images/jou_button.jpg");
    }
    this->setPixmap( * (this->BasicImage) );

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

JouMinion_t::~JouMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void JouMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void JouMinion_t::attack(Life_t *target)
{
}


// LeeMinion_t
QPixmap* LeeMinion_t::BasicImage = nullptr;
QPixmap* LeeMinion_t::ButtonImage = nullptr;

LeeMinion_t::LeeMinion_t() : Minion_t()
{
    if( LeeMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        LeeMinion_t::BasicImage = new QPixmap("./resources/images/lee_minion.jpg");
        LeeMinion_t::ButtonImage = new QPixmap("./resources/images/lee_button.jpg");
    }
    this->setPixmap( * (this->BasicImage) );

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

LeeMinion_t::~LeeMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void LeeMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void LeeMinion_t::attack(Life_t *target)
{
}


// TsaiMinion_t
QPixmap* TsaiMinion_t::BasicImage = nullptr;
QPixmap* TsaiMinion_t::ButtonImage = nullptr;

TsaiMinion_t::TsaiMinion_t() : Minion_t()
{
    if( TsaiMinion_t::BasicImage == nullptr ) // construct Pixmaps if they haven't been constructed
    {
        TsaiMinion_t::BasicImage = new QPixmap("./resources/images/tsai_minion.jpg");
        TsaiMinion_t::ButtonImage = new QPixmap("./resources/images/tsai_button.jpg");
    }
    this->setPixmap( * (this->BasicImage) );

    this->Speed = 10;
    this->Range = 100;
    this->HP = 50;
    this->Damage = 10;
    this->Hz = 1;

    this->Timer->start(1000 / Hz);
}

TsaiMinion_t::~TsaiMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void TsaiMinion_t::run()
{
    if(this->checkDied()) //  if the minion died, then checkDied() will emit signal "died()" to MinionManager, then this will be deleted
        return;

    Life_t* tarLife; // receive the response of findTarget()
    findTarget(tarLife);

    if(tarLife == nullptr) // none is in Range
    {
        move();
    }
    else
    {
        if( dynamic_cast<Minion_t*>(tarLife) ) // if the response is a Minion
        {
            arrowAttack(tarLife);
        }
        else if( dynamic_cast<Tower_t*>(tarLife) ) // if the response is a Tower
        {
            arrowAttack(tarLife);
        }
    }
}

void TsaiMinion_t::attack(Life_t *target)
{
}
