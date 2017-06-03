#include "animation.h"

Animation_t::Animation_t(QPointF pos, int ms, QList<QString> &pathList)
{
    Timer = new QTimer;
    PathList = pathList;
    this->setPos(pos);
    this->setPixmap( QPixmap(*pathList.begin()) );
    connect(Timer, SIGNAL(timeout()), this, SLOT(nextImage()));
    Timer->start(ms);
}

Animation_t::~Animation_t()
{
    delete Timer;
}

void Animation_t::nextImage()
{
    static QList<QString>::iterator it = PathList.begin();
    ++it;
    if( it != PathList.end() )
    {
        this->setPixmap( QPixmap(*it) );
    }
    else
    {
        Timer->stop();
        emit animationEnds(this); // ask scene to remove this
        delete this; // perhaps dangerous
    }
}
