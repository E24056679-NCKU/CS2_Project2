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

bool Life_t::checkDied()
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
