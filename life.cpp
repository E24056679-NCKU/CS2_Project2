#include "life.h"

Life_t::Life_t() : QObject(), QGraphicsPixmapItem()
{
    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()), this, SLOT(run()));
    // this->setFlag(QGraphicsItem::ItemIsFocusable);
}

Life_t::~Life_t()
{
    delete Timer;
}

void Life_t::arrowAttack(Life_t *target)
{
    emit emit_ArrowAttack(target, this->Damage, this->Center);
}
