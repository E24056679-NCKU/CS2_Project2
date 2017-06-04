#ifndef ANIMATION_H
#define ANIMATION_H

#include <QList>
#include <QPoint>
#include <QPointF>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

// at a certain position, and change pixmap rapidly
// center must be fixed, and Animation will auto adjust Position of the PixmapItem
class Animation_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Animation_t(QPointF center, int ms, QList<QString> &pathList); // each image lasts ms milliseconds, pathList stores the path of each image
    ~Animation_t();
    QPointF Center; // the fixed center of this animation

public slots:
    void nextImage(); // change to next image, connected with Timer::timeout()

protected:
    QTimer* Timer;
    QList<QString> PathList; // the Images' path
};

#endif // ANIMATION_H
