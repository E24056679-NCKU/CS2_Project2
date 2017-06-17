#ifndef ANIMATION_H
#define ANIMATION_H

#include <QList>
#include <QPoint>
#include <QPointF>
#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QMovie>
#include <QSet>
#include <QGraphicsPixmapItem>

/*
// at a certain position, and change pixmap rapidly
// center must be fixed, and Animation will auto adjust Position of the PixmapItem
class Animation_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Animation_t(QPointF center, int period, QList<QString> &pathList); // each image lasts period milliseconds, pathList stores the path of each image
    ~Animation_t();
    QPointF Center; // the fixed center of this animation

public slots:
    void nextImage(); // change to next image, connected with Timer::timeout()

protected:
    QTimer* Timer;
    QList<QString> PathList; // the Images' path
};
*/


class Animation_t : public QLabel
{
    Q_OBJECT
public:
    Animation_t(QPointF Center, QString filename, QSet<Animation_t*> * parentSet);
    ~Animation_t();
    QTimer* Timer;
    QMovie* Gif;
    QPointF Center;
    QSet<Animation_t*> * ParentSet;

public slots:
    void countDown();

signals:
    void animationEnd(Animation_t*);
};

#endif // ANIMATION_H
