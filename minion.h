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
    QPoint TargetPosition;
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    bool checkDied();

    void findTarget_Tower(Minion_t* requester, TowerTeam tarTeam, Tower_t* &response); // response is a reference
    void findTarget_Minion(Minion_t* requester, MinionTeam tarTeam, Minion_t* &response); // response is a reference

signals:
    void died(Minion_t* rmMinion);
    void selectedByMouse(Minion_t* selMinion);
    void request_FindTarget_Tower(Minion_t* requester, TowerTeam tarTeam, Tower_t* &response); // response is a reference
    void request_FindTarget_Minion(Minion_t* requester, MinionTeam tarTeam, Minion_t* &response); // response is a reference

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
    static QVector< QPixmap* > MovingImages;
    static QVector< QPixmap* > AttackingImages;
};



class MinionManager_t : public QObject
{
    Q_OBJECT

    friend class BattleManager_t;

public:
    MinionManager_t();
    ~MinionManager_t();

public slots:
    Minion_t* addMinion(MinionType Type, MinionTeam Team, QPoint Position);
    void removeMinion(Minion_t* rmMinion);
    // MinionManager_t has no permission to access Display, so give this event to BattleManager
    void receivedMinionDied(Minion_t* rmMinion);
    void received_FindTarget_Tower(Minion_t* requester, TowerTeam tarTeam, Tower_t* &response);
    void received_FindTarget_Minion(Minion_t* requester, MinionTeam tarTeam, Minion_t* &response);

signals:
    void minionDied(Minion_t* rmMinion);
    void request_FindTarget_Tower(Life_t* requester, TowerTeam tarTeam, Tower_t* &response); // response is a reference
    void request_FindTarget_Minion(Life_t* requester, MinionTeam tarTeam, Minion_t* &response); // response is a reference

protected:

private:
    QSet< Minion_t* > MinionList;

};

#endif
