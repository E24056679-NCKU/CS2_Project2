#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QVector>
#include <QGraphicsPixmapItem>
#include "life.h"

typedef LifeTeam TowerTeam;
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
    void findTarget_Minion(Tower_t* requester, MinionTeam tarTeam, Minion_t* &response); // response is a reference
    bool Dead;

signals:
    void died(Tower_t* rmTower);
    void request_FindTarget_Minion(Tower_t* requester, MinionTeam tarTeam, Minion_t* &response); // response is a reference

public slots:
    void run();

};

class TowerManager_t : public QObject
{
    Q_OBJECT

    friend class BattleManager_t;
public:
    TowerManager_t();
    ~TowerManager_t();
    void initializeTowers();

public slots:
    void received_FindTarget_Minion(Tower_t* requester, MinionTeam tarTeam, Minion_t* &response);
    void receivedTowerDied(Tower_t* rmTower);

signals:
    void itemAdded(QGraphicsItem* addItem);
    void itemRemoved(QGraphicsItem* rmItem);
    void request_FindTarget_Minion(Life_t* requester, MinionTeam tarTeam, Minion_t* &response); // response is a reference

private:
    // TL[0] is my main tower; TL[1] is the tower on the left side of TL[0]
    // TL[3] is my main tower; TL[4] is the tower on the left side of TL[3]
    Tower_t* TowerList[6];
};

#endif // TOWER_H
