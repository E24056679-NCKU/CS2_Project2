#ifndef ANIMATION_H
#define ANIMATION_H

#include <QList>
#include <QPoint>
#include <QPointF>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

// at a certain position, and change pixmap rapidly
// at the time animation end, it will emit a signal "animationsEnds" to tell scene to removeItem, then finally Animation will delete itself (delete this)
// so no need to use a container to manage animations
class Animation_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Animation_t(QPointF pos, int ms, QList<QString> &pathList); // each image last ms milliseconds, pathList stores the path of each image
    ~Animation_t();

public slots:
    void nextImage();

signals:
    void animationEnds(Animation_t* rmAni);

protected:
    QTimer* Timer;
    QList<QString> PathList;
};

#endif // ANIMATION_H
