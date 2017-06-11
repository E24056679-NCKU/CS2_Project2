#ifndef BATTLE_H
#define BATTLE_H

#include <cmath>
#include <algorithm>
#include <QPair>
#include <QObject>
#include "minion.h"
#include "tower.h"
#include "arrow.h"
#include "miscellaneous.h"

class BattleManager_t : public QObject
{
    friend class System;
    Q_OBJECT
public:
    BattleManager_t();
    ~BattleManager_t();
    void initialize();

public slots:
    void countDown();

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

    // find one Life in requester's Range, the response is not necessarily be the closest one to requester
    // Note that reponse is a reference
    void findLifeInRange(Life_t* requester, LifeTeam tarTeam, Life_t* &response);
    void findAllLifeInRange(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response, int SizeLimit);

    // create an arrow, then itemAdd() it
    void addArrow(Life_t* target, double damage, QPointF pos);

    // forward to System
    void received_Animation(QPointF center, int period, QList<QString> &pathList);

    void rangeAttack(Life_t* requester, QPointF center, double range, double damage, LifeTeam targetTeam);

signals:
    void gameOver();
    // tell System an item has been created
    void itemAdded(QGraphicsItem* addItem);
    // tell System an item has been removed
    void itemRemoved(QGraphicsItem* rmItem);
    // forward to System
    void request_Animation(QPointF center, int period, QList<QString> &pathList);

protected:
    QTimer* Timer;
    int CountDown;

    MinionManager_t* MinionManager;
    TowerManager_t* TowerManager;


    // the card (out of the four we can selected in screen) selected
    int CardSelected_Player1; // default (no selected) = -1
    // map the selectedCardNumber to MinionType
    MinionType CardtoMinionType_Player1[4]; // store Card[i]'s MinionTypeID

    int CardSelected_Player2; // default (no selected) = -1
    MinionType CardtoMinionType_Player2[4]; // store Card[i]'s MinionTypeID

    // minion selected by user (hero system)
    Minion_t* MinionSelected_Player1;
    Minion_t* MinionSelected_Player2;

private:

};

#endif // BATTLE_H
