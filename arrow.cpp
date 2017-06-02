#include "arrow.h"

const double Arrow_t::Speed = 10;

Arrow_t::Arrow_t(Life_t *_Target, double _Damage, QPointF _Pos) : QObject(), QGraphicsPixmapItem(), Damage(_Damage), Pos(_Pos)
{
    Target = _Target;
    this->setPos(this->Pos);
    this->setPixmap( QPixmap("./resources/images/Arrow.png") );
    Timer = new QTimer();
    connect(Timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    this->Timer->start(100);
}

Arrow_t::~Arrow_t()
{
    delete Timer;
}

void Arrow_t::selfDestruct()
{
    this->Timer->stop();
    emit died(this);
}

void Arrow_t::timerTick()
{
    if( this->collidesWithItem( dynamic_cast<QGraphicsItem*>(Target) ) == true )
    {
        Target->HP -= this->Damage;
        this->selfDestruct();
    }
    else
    {
        // calculate next velocity vector
        QPointF Vec_ThisToTar = QPointF(Target->Center.x() - this->Pos.x() , Target->Center.y() - this->Pos.y());
        double Vec_ThisToTar_Len = qSqrt(Vec_ThisToTar.x()*Vec_ThisToTar.x() + Vec_ThisToTar.y()*Vec_ThisToTar.y());
        QPointF Velocity = Speed * Vec_ThisToTar / Vec_ThisToTar_Len; // = UnitVec * speed
        this->Pos += Velocity;
        this->setPos(this->Pos);
    }
}


ArrowManager_t::ArrowManager_t()
{

}

ArrowManager_t::~ArrowManager_t()
{
    for(auto &i : this->ArrowList)
        delete i;
}

void ArrowManager_t::removeArrowsByTarget(Life_t *Target)
{
    for(auto it = ArrowList.begin() ; it != ArrowList.end() ; )
    {
        Arrow_t* arrow = *it;
        if( arrow->Target == Target )
        {
            arrow->Timer->stop();
            emit itemRemoved( dynamic_cast<QGraphicsItem*>(arrow) );
            delete arrow;
            it = ArrowList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

Arrow_t* ArrowManager_t::addArrow(Life_t *Target, double Damage, QPointF Pos)
{
    Arrow_t* newArrow = new Arrow_t(Target, Damage, Pos);
    this->ArrowList.push_back(newArrow);
    connect(newArrow, SIGNAL(died(Arrow_t*)), this, SLOT(receivedArrowDied(Arrow_t*)));
    return newArrow;
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
