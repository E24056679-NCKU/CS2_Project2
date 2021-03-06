#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include <QtGlobal>
#include <QPoint>
#include <QtMath>

inline double distance(const QPointF &a, const QPointF &b)
{
    double dx = a.x() - b.x();
    double dy = a.y() - b.y();
    return qSqrt(dx*dx+dy*dy);
}

inline double crossProduct(const QPointF &refP, QPointF p1, QPointF p2)
{
    p1 -= refP;
    p2 -= refP;
    return p1.x()*p2.y() - p1.y()*p2.x();
}

inline bool equal_QPointF(const QPointF &a, const QPointF &b)
{
    return qFabs(a.x()-b.x()) <= 1e-7 && qFabs(a.y()-b.y()) <= 1e-7;
}

inline void round_QPointF(QPointF &p)
{
    p.setX( qRound(p.x()) );
    p.setY( qRound(p.y()) );
}

inline void round_QPointF(QPointF &&p)
{
    p.setX( qRound(p.x()) );
    p.setY( qRound(p.y()) );
}

inline bool isBetweenTwoLine(const QPointF &tar, const QPointF &o, const QPointF &a, const QPointF &b)
{
    return ( crossProduct(o, a, tar) * crossProduct(o, b, tar) ) < 0;
}

#endif // MISCELLANEOUS_H
