#ifndef ARROW_T_H
#define ARROW_T_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QtMath>
#include "life.h"

class Arrow_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    friend class ArrowManager_t;
public:
    Arrow_t(Life_t *_Target, double _Damage, QPointF _Pos);
    ~Arrow_t();
    void selfDestruct();
    double Damage;
    QPointF Pos;
    const static double Speed; // how far an arrow can move in a tick

signals:
    void died(Arrow_t* rmArrow);

protected slots:
    void timerTick();

protected:
    QTimer* Timer;
    Life_t* Target;

private:

};

class ArrowManager_t : public QObject
{
    Q_OBJECT
    friend class BattleManager_t;

public:
    ArrowManager_t();
    ~ArrowManager_t();
    // when the Target has died, this function should be call to remove all arrows which point to Target
    void removeArrowsByTarget(Life_t* Target);

public slots:
    Arrow_t* addArrow(Life_t* Target, double Damage, QPointF Pos);

    void receivedArrowDied(Arrow_t* rmArrow);

signals:
    void itemAdded(QGraphicsItem* item);
    void itemRemoved(QGraphicsItem* item);

protected:
    QList<Arrow_t*> ArrowList;
};

#endif // ARROW_T_H
