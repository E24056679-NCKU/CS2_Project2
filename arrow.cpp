#include "arrow.h"

Arrow_t::Arrow_t(Life_t *_Target, double _Damage, QPointF _Pos) : QObject(), QGraphicsPixmapItem(), Target(_Target), Damage(_Damage), Pos(_Pos)
{
    this->setPixmap( QPixmap("./resources/images/arrow.png") );
    Timer = new QTimer();
    connect(Timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    this->Timer->start(100);
}

Arrow_t::~Arrow_t()
{
    delete Timer;
}

void Arrow_t::setTarget(Life_t *Target)
{

}

void Arrow_t::selfDestruct()
{
    emit died(this);
}

void Arrow_t::timerTick()
{
    if( this->collidesWithItem( dynamic_cast<QGraphicsItem*>(Target) ) == true )
    {
        Target->HP -= this->Damage;
        emit died(this);
    }
    else
    {
        // calculate next velocity vector
        QPointF Vec_ThisToTar = QPointF(Target->Pos.x() - this->Pos.x() , Target->Pos.y() - this->Pos.y());
        double Vec_ThisToTar_Len = qSqrt(Vec_ThisToTar.x()*Vec_ThisToTar.x() + Vec_ThisToTar.y()*Vec_ThisToTar.y());
        QPointF Velocity = Vec_ThisToTar / Vec_ThisToTar_Len; // = UnitVec * speed
        this->Pos += Velocity;
        this->setPos(this->Pos);
    }
}


ArrowManager_t::ArrowManager_t()
{

}

ArrowManager_t::~ArrowManager_t()
{

}

void ArrowManager_t::removeArrowsByTarget(Life_t *Target)
{
    for(auto it = ArrowList.begin() ; it != ArrowList.end() ; )
    {
        Arrow_t* arrow = *it;
        if( arrow->Target == Target )
        {
            arrow->selfDestruct();
            it = ArrowList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

Arrow_t ArrowManager_t::addArrow(Life_t *Target, double Damage, QPointF Pos)
{
    Arrow_t* newArrow = new Arrow_t(Target, Damage, Pos);
    this->ArrowList.push_back(newArrow);
    connect(newArrow, SIGNAL(died(Arrow_t*)), this, SLOT(receivedArrowDied(Arrow_t*)));
}

void ArrowManager_t::receivedArrowDied(Arrow_t *rmArrow)
{
    emit itemRemoved( dynamic_cast<QGraphicsItem*>(rmArrow) );
    for(auto it = ArrowList.begin() ; it != ArrowList.end() ; ++it)
    {
        Arrow_t* arrow = *it;
        if( arrow == rmArrow )
        {
            it = ArrowList.erase(it);
            break;
        }
    }
    delete rmArrow;
}
