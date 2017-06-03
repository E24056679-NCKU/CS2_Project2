#ifndef MINION_H
#define MINION_H

#include <QString>
#include <QVector>
#include <QSet>
#include "life.h"

#include <QDebug>

typedef LifeTeam MinionTeam;
typedef LifeTeam TowerTeam;

class Tower_t;

enum MinionType
{
    BasicMinion = 0,
    DerivedMinion
};

// abstract minion
// the events of QGraphicsPixmapItem is not implemented in this file
// they are in Display.cpp because ControllableDisplay needs them
class Minion_t : public Life_t
{
    Q_OBJECT

    friend class MinionManager_t;

public:
    Minion_t();
    virtual ~Minion_t();
    QPointF TargetPosition;
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    bool checkDied();

    virtual void findTarget(Life_t* &response); // response is a reference

signals:
    void died(Minion_t* rmMinion);
    void selectedByMouse(Minion_t* selMinion);
    void request_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference

public slots:
    virtual void run();

public:
    virtual void move();
    virtual void attack(Life_t* target);

protected:

private:


};

class DerivedMinion_t : public Minion_t
{
    Q_OBJECT

public:
    DerivedMinion_t();
    ~DerivedMinion_t();

    // run() decides *this to move or attack

public slots:
    void run();

public:
    void move();
    void attack(Life_t* target);
    static const MinionType Type = MinionType::DerivedMinion;

protected:

private:
    static QPixmap* BasicImage;
    static QList< QPixmap* > MovingImages;
    static QList< QPixmap* > AttackingImages;
};



class MinionManager_t : public QObject
{
    Q_OBJECT

    friend class BattleManager_t;

public:
    MinionManager_t();
    ~MinionManager_t();

public slots:
    Minion_t* addMinion(MinionType Type, MinionTeam Team, QPointF Position);
    void removeMinion(Minion_t* rmMinion);
    // MinionManager_t has no permission to access Display, so give this event to BattleManager
    void receivedMinionDied(Minion_t* rmMinion);
    void received_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void receive_arrowAttack(Life_t* target, double damage, QPointF pos);

signals:
    void request_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void emit_ArrowAttack(Life_t* target, double damage, QPointF pos);

protected:

private:
    QSet< Minion_t* > MinionList;

};

#endif
