#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QVector>
#include <QGraphicsPixmapItem>
#include "life.h"

typedef LifeTeam TowerTeam; // LifeTeam = TowerTeam = MinionTeam
typedef LifeTeam MinionTeam;

class Minion_t;

enum TowerType
{
    MainTower = 0,
    NormalTower
};

class Tower_t : public Life_t
{
    Q_OBJECT

    friend class TowerManager_t;

public:
    Tower_t();
    ~Tower_t();

    bool checkDied();

signals:
    void died(Tower_t* rmTower);

public slots:
    void run();
    void attack(Life_t* target);

};

class TowerManager_t : public QObject
{
    Q_OBJECT
    friend class BattleManager_t;

public:
    TowerManager_t();
    ~TowerManager_t();
    // create and setup 6 towers
    void initializeTowers();

public slots:
    void receivedTowerDied(Tower_t* rmTower);
    void received_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void received_FindAllTarget(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response);
    void receive_arrowAttack(Life_t* target, double damage, QPointF pos);

signals:
    void itemAdded(QGraphicsItem* addItem);
    void request_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void request_FindAllTarget(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response);
    void emit_ArrowAttack(Life_t* target, double damage, QPointF pos);

private:
    // TL[0] is my main tower; TL[1] is the tower on the left side of TL[0]
    // TL[3] is my main tower; TL[4] is the tower on the left side of TL[3]
    Tower_t* TowerList[6];
    // if TowerList[i] died , TowerList[i] will be changed to nullptr
};

#endif // TOWER_H
