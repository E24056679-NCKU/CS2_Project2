#ifndef BATTLE_H
#define BATTLE_H

#include <cmath>
#include <algorithm>
#include <QPair>
#include <QObject>
#include "minion.h"
#include "tower.h"
#include "arrow.h"

double distance(const QPointF &a, const QPointF &b);
double crossProduct(const QPointF &refP, QPointF p1, QPointF p2);

class BattleManager_t : public QObject
{
    Q_OBJECT
public:
    BattleManager_t();
    ~BattleManager_t();
    void initialize();

public slots:
    // these two functions are for user to add/remove minion
    void addMinion(MinionType Type, MinionTeam Group, QPointF Position);
    void removeMinion(Minion_t* rmMinion);

    // incoming signals from controller1
    void receivedSignal1_SelectPosition(QPointF Position);
    void receivedSignal1_SelectMinion(Minion_t* selMinion);
    void receivedSignal1_SelectCard(int CardID);
    // incoming signals from controller2
    // !! not been implemented yet
    void receivedSignal2_SelectPosition(QPointF Position);
    void receivedSignal2_SelectMinion(Minion_t* selMinion);
    void receivedSignal2_SelectCard(int CardID);

    void emit_ItemAdded(QGraphicsItem* addItem);
    void emit_ItemRemoved(QGraphicsItem* rmItem);

    // Note that reponse is a reference
    void findLifeInRange(Life_t* requester, LifeTeam tarTeam, Life_t* &response);

    void addArrow(Life_t* target, double damage, QPointF pos);



signals:
    void itemAdded(QGraphicsItem* addItem);
    void itemRemoved(QGraphicsItem* rmItem);


protected:
    MinionManager_t* MinionManager;
    TowerManager_t* TowerManager;


    int CardSelected_Player1; // default (no selected) = -1
    MinionType CardtoMinionType_Player1[4]; // store Card[i]'s MinionTypeID
    int CardSelected_Player2; // default (no selected) = -1
    MinionType CardtoMinionType_Player2[4]; // store Card[i]'s MinionTypeID
    Minion_t* MinionSelected_Player1;
    Minion_t* MinionSelected_Player2;

private:

};

#endif // BATTLE_H
