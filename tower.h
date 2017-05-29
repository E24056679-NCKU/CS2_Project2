#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QVector>
#include <QGraphicsPixmapItem>
#include "minion.h"

typedef MinionTeam TowerTeam;

enum TowerType
{
    MainTower = 0,
    NormalTower
};

class Tower_t : public QObject, public QGraphicsPixmapItem
{
public:
    Tower_t();
    ~Tower_t();

signals:
    void died(Tower_t* rmTower);

public slots:
    void attack();

};

class TowerManager_t : public QObject
{
public:
    TowerManager_t();
    ~TowerManager_t();

    void attack();

private:
    Tower_t* TowerList[6];
};

#endif // TOWER_H
