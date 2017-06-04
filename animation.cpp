#include "animation.h"

Animation_t::Animation_t(QPointF center, int ms, QList<QString> &pathList)
{
    this->Center = center;
    Timer = new QTimer;
    PathList = pathList;
    this->setPixmap( QPixmap(*pathList.begin()) );

    // pos = center - side_len/2
    QPointF pos = this->Center - QPointF(1.0*this->pixmap().size().width()/2 , 1.0*this->pixmap().size().height()/2);
    this->setPos(pos);

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
        QPointF pos = this->Center - QPointF(1.0*this->pixmap().size().width()/2 , 1.0*this->pixmap().size().height()/2);
        this->setPos(pos);
    }
    else
    {
        Timer->stop();
        delete this; // perhaps dangerous
    }
}
