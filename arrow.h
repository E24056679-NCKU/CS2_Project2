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

public:
    Arrow_t(Life_t *_Target, double _Damage, QPointF _Pos);
    ~Arrow_t();
    double Damage;
    QPointF Pos;
    const static int Hz = 10;
    const static double Speed; // how far an arrow can move in a tick, scalar

protected slots:
    void timerTick();

protected:
    QTimer* Timer;
    Life_t* Target;

private:

};

#endif // ARROW_T_H
