#include "animation.h"

Animation_t::Animation_t(QPointF Center, QString filename, QSet<Animation_t*> * parentSet)
{
    this->ParentSet = parentSet;
    this->ParentSet->insert(this);
    this->setGeometry(Center.x() - 25, Center.y() - 25, 50, 50);
    this->Center = Center;
    Timer = new QTimer;
    Gif = new QMovie(filename);
    this->setMovie(Gif);
    connect(Timer, SIGNAL(timeout()), this, SLOT(countDown()));
    Gif->start();
    Timer->start(1);
}

Animation_t::~Animation_t()
{
    delete Timer;
    delete Gif;
}

void Animation_t::countDown()
{
    if( Gif->currentFrameNumber() == Gif->frameCount() - 1 )
    {
        Gif->stop();
        Timer->stop();
        // emit animationEnd(this);
        ParentSet->erase( ParentSet->find(this) );
        delete this;
    }
}

/*
Animation_t::Animation_t(QPointF center, int period, QList<QString> &pathList)
{
    this->Center = center;
    Timer = new QTimer;
    PathList = pathList;
    this->setPixmap( QPixmap(*pathList.begin()) ); // set the Pixmap to the first image

    // pos = center - side_len/2
    QPointF pos = this->Center - QPointF(1.0*this->pixmap().size().width()/2 , 1.0*this->pixmap().size().height()/2); // set the position of the image
    this->setPos(pos);

    connect(Timer, SIGNAL(timeout()), this, SLOT(nextImage()));
    Timer->start(period);
}

Animation_t::~Animation_t()
{
    delete Timer;
}

void Animation_t::nextImage()
{
    static QList<QString>::iterator it = PathList.begin();
    ++it; //
    if( it != PathList.end() )
    {
        this->setPixmap( QPixmap(*it) );
        QPointF pos = this->Center - QPointF(1.0*this->pixmap().size().width()/2 , 1.0*this->pixmap().size().height()/2);
        this->setPos(pos);
    }
    else
    {
        Timer->stop();
        delete this;
    }
}
*/
