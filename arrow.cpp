#include "arrow.h"

const double Arrow_t::Speed = 10;

Arrow_t::Arrow_t(Life_t *_Target, double _Damage, QPointF _Pos) : QObject(), QGraphicsPixmapItem(), Damage(_Damage), Pos(_Pos)
{
    this->setParent(_Target); // if the Target is deleted, this arrow should be deleted too
    Target = _Target;
    this->setPos(this->Pos);
    this->setPixmap( QPixmap("./resources/images/Arrow.jpg") );
    Timer = new QTimer();
    connect(Timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    this->Timer->start(1000 / Hz);
}

Arrow_t::~Arrow_t()
{
    delete Timer;
}

void Arrow_t::timerTick()
{
    if( this->collidesWithItem( dynamic_cast<QGraphicsItem*>(Target) ) == true )
    {
        Target->HP -= this->Damage;
        delete this;
    }
    else
    {
        // this arrow will change its direction when the targets' position changed
        // calculate next velocity vector
        QPointF Vec_ThisToTar = QPointF(Target->Center.x() - this->Pos.x() , Target->Center.y() - this->Pos.y());
        double Vec_ThisToTar_Len = distance(QPointF(0, 0), Vec_ThisToTar);
        QPointF Velocity = Speed * Vec_ThisToTar / Vec_ThisToTar_Len; // = UnitVec * speed, it's a vector
        this->Pos += Velocity;
        this->setPos(this->Pos);
    }
}
