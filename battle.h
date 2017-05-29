#ifndef BATTLE_H
#define BATTLE_H

#include <QPair>
#include <QObject>
#include "minion.h"
#include "tower.h"

class BattleManager_t : public QObject
{
    Q_OBJECT
public:
    BattleManager_t();
    ~BattleManager_t();

public slots:
    void addMinion(MinionType Type, MinionTeam Group, QPoint Position);
    void removeMinion(Minion_t* rmMinion);

    // incoming signals from controller1
    void gotSignal1_SelectPosition(QPoint Position);
    void gotSignal1_SelectMinion(QPoint Position);
    void gotSignal1_SelectMinion(Minion_t* selMinion);
    void gotSignal1_SelectCard(int CardID);
    // incoming signals from controller2
    // !! not implemented yet
    void gotSignal2_SelectPosition(QPoint Position);
    void gotSignal2_SelectMinion(QPoint Position);
    void gotSignal2_SelectMinion(Minion_t* selMinion);
    void gotSignal2_SelectCard(int CardID);

signals:
    void minionAdded(Minion_t* newMinion);
    void minionRemoved(Minion_t* rmMinion);

protected:
    MinionManager_t* MinionManager;
    TowerManager_t* TowerManager;

    int CardSelected_Player1; // default (no selected) = -1
    MinionType CardtoMinionType_Player1[4]; // store Card[i]'s MinionTypeID
    int CardSelected_Player2; // default (no selected) = -1
    MinionType CardtoMinionType_Player2[4]; // store Card[i]'s MinionTypeID

private:

};

#endif // BATTLE_H
