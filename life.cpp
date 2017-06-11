#include "life.h"

Life_t::Life_t() : QObject(), QGraphicsPixmapItem()
{
    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()), this, SLOT(run()));
}

Life_t::~Life_t()
{
    delete Timer;
}

void Life_t::arrowAttack(Life_t *target)
{
    emit emit_ArrowAttack(target, this->Damage, this->Center);
}

void Life_t::findTarget(Life_t *&response)
{
    LifeTeam tarTeam;
    if( this->Team == LifeTeam::MyTeam )
        tarTeam = LifeTeam::OpsTeam;
    else if( this->Team == LifeTeam::OpsTeam )
        tarTeam = LifeTeam::MyTeam;

    // DBG
    tarTeam = LifeTeam::MyTeam;

    emit request_FindTarget( dynamic_cast<Life_t*>(this) , tarTeam, response);
}

void Life_t::findAllTarget(QList<Life_t *> &response, int SizeLimit)
{
    LifeTeam tarTeam;
    if( this->Team == LifeTeam::MyTeam )
        tarTeam = LifeTeam::OpsTeam;
    else if( this->Team == LifeTeam::OpsTeam )
        tarTeam = LifeTeam::MyTeam;

    // DBG
    tarTeam = LifeTeam::MyTeam;

    emit request_FindAllTarget( dynamic_cast<Life_t*>(this) , tarTeam, response, SizeLimit);
}
