#ifndef LIFE_T_H
#define LIFE_T_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QTimer>
#include <QList>

#include <QDebug>

enum LifeTeam
{
    MyTeam = 0,
    OpsTeam, // opponent's group
    NoTeam // NoTeam can attack other teams, while other teams cannot attack NoTeam
};

enum LifeType
{
    Tower = 0,
    Minion
};

class Life_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Life_t();
    virtual ~Life_t();
    QPointF Pos;
    QPointF Center;
    double HP;
    double Damage;
    double Range;
    double Speed;
    LifeTeam Team;
    LifeType LType;

signals:
    void died(Life_t* rmLife);

public slots:
    virtual void run() = 0;

public:
    virtual bool checkDied();

protected:
    QTimer* Timer;

private:


};

#endif // LIFE_T_H
