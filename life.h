#ifndef LIFE_T_H
#define LIFE_T_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QTimer>
#include <QList>
#include "animation.h"

#include <QDebug>

enum LifeTeam
{
    MyTeam = 0,
    OpsTeam, // opponent's group
    NoTeam
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
    int Hz;

signals:
    // when a Minion die, emit this signal to tell MinionManager to delete the minion
    void died(Life_t* rmLife);
    void emit_ArrowAttack(Life_t* target, double damage, QPointF pos);
    // send to Manager, then Manager forward it to BattleManager
    void request_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void request_FindAllTarget(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response);

public slots:
    // run is connected to Timer::timeout
    virtual void run() = 0; // every life has its own run(), so make it abstract
    // attack other minion, may be skill or not skill.
    virtual void attack(Life_t* target) = 0; // there might be lots of types of attack, so make it abstrct
    // launch an arrow to attack target
    virtual void arrowAttack(Life_t* target); // simply shoot, so no need abstract

    // Note that reponse is a reference
    virtual void findTarget(Life_t* &response); // response is a reference
    // find all target in range
    virtual void findAllTarget(QList<Life_t*> &response);

public:
    // check whether a life died
    virtual bool checkDied() = 0;

protected:
    QTimer* Timer;

private:


};

#endif // LIFE_T_H
