#include <QDebug>
#include "minion.h"\

// abstract Minion
Minion_t::Minion_t() : QObject(), QGraphicsPixmapItem()
{
    Timer = new QTimer;
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    // this->setZValue(1);
}

Minion_t::~Minion_t()
{
    delete Timer;
    qDebug() << "Minion_t dtor";
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

MinionManager_t::MinionManager_t() : QObject()
{

}

MinionManager_t::~MinionManager_t()
{
    for(auto &i : MinionList)
        delete i;
    qDebug() << "MinionManager_t dtor";
}

Minion_t *MinionManager_t::addMinion(MinionType Type, MinionTeam Group, QPoint Position)
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
    newMinion->Group = Group;
    newMinion->setPos(Position);
    connect(newMinion, SIGNAL(died(Minion_t*)), this, SLOT(receivedMinionDied(Minion_t*)));
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
        for( int i=1 ; i<=2 ; ++i )
        {
            char path[100];
            strcpy(path, "./resources/images/DerivedMinion_move_x.png");
            int len = strlen(path);
            path[len-5] = i + '0';
            DerivedMinion_t::MovingImages.push_back( new QPixmap(path) );
        }
        for( int i=1 ; i<=2 ; ++i)
        {
            char path[100];
            strcpy(path, "./resources/images/DerivedMinion_attack_x.png");
            int len = strlen(path);
            path[len-5] = i + '0';
            DerivedMinion_t::AttackingImages.push_back( new QPixmap(path) );
        }
    }
    this->setPixmap( * (this->BasicImage) );
    this->setScale(0.1);
    this->setPos(400, 300);

    connect(Timer, SIGNAL(timeout()), this, SLOT(run()));
    Timer->start(100);
    this->HP = 100;
}

DerivedMinion_t::~DerivedMinion_t()
{
    // need not delete BasicImage, MovingImages...... because they are static
}

void DerivedMinion_t::run()
{
    // this->setPos(this->x()+10, this->y()+10);
    // this->HP -= 10;
    // this->checkDied();
}

void DerivedMinion_t::move()
{

}

void DerivedMinion_t::attack(Minion_t *target)
{

}
