#ifndef BATTLE_H
#define BATTLE_H

#include <cmath>
#include <algorithm>
#include <QPair>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include "minion.h"
#include "tower.h"
#include "arrow.h"
#include "miscellaneous.h"

class BattleManager_t : public QObject
{
    friend class System;
    Q_OBJECT
public:
    static const int Player1 = 1;
    static const int Player2 = 2;

    BattleManager_t();
    ~BattleManager_t();
    void initialize();
    void setupCards(QList<int> cardSelected, int Player);
    void updateCard(int usedCardIdx, int Player); // replace the used card with new card

    int Player1Score;
    int Player2Score;

    QLabel* Player1Score_Label;
    QLabel* Player2Score_Label;
    QLabel* CountDown_Label;
    QPushButton* Skill_Button;

public slots:
    void countDown();

    // these two functions are for user to add/remove minion
    void addMinion(MinionType Type, MinionTeam Group, QPointF Position);
    void removeMinion(Minion_t* rmMinion);

    // incoming signals from controller1
    void receivedSignal1_SelectPosition(QPointF Position);
    void receivedSignal1_SelectMinion(Minion_t* selMinion);
    void receivedSignal1_SelectCard(int ButtonID);
    void receivedSignal1_KeyPressed(int key);
    // incoming signals from controller2
    // !! not been implemented yet
    void receivedSignal2_SelectPosition(QPointF Position);
    void receivedSignal2_SelectMinion(Minion_t* selMinion);
    void receivedSignal2_SelectCard(int ButtonID);
    void receivedSignal2_KeyPressed(int key);

    void emit_ItemAdded(QGraphicsItem* addItem);
    void emit_ItemRemoved(QGraphicsItem* rmItem);

    // find one Life in requester's Range, the response is not necessarily be the closest one to requester
    // Note that reponse is a reference
    void findLifeInRange(Life_t* requester, LifeTeam tarTeam, Life_t* &response);
    void findAllLifeInRange(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response, int SizeLimit);

    // create an arrow, then itemAdd() it
    void addArrow(Life_t* target, double damage, QPointF pos);

    // forward to System
    void received_Animation(QPointF center);

    void rangeAttack(Life_t* requester, QPointF center, double range, double damage, LifeTeam targetTeam);

    void received_MinionRemoved(Minion_t* rmMinion);

    void skillButtonClicked();

signals:
    void gameOver(int score1, int score2);
    // tell System an item has been created
    void itemAdded(QGraphicsItem* addItem);
    // tell System an item has been removed
    void itemRemoved(QGraphicsItem* rmItem);
    // forward to System
    void request_Animation(QPointF center);
    // change the button's image to newMinion's image
    void changeButtonImage(int ButtonID, MinionType minionType);

protected:
    QTimer* Timer;
    int CountDown;

    MinionManager_t* MinionManager;
    TowerManager_t* TowerManager;


    // the card (out of the four we can selected in screen) selected
    int CardSelected_Player1; // default (no selected) = -1
    // map the selectedCardNumber to MinionType
    // MinionType CardtoMinionType_Player1[4]; // store Card[i]'s MinionTypeID

    int CardSelected_Player2; // default (no selected) = -1
    // MinionType CardtoMinionType_Player2[4]; // store Card[i]'s MinionTypeID

    // minion selected by user (hero system)
    Minion_t* MinionSelected_Player1;
    Minion_t* MinionSelected_Player2;

    // cards which player chose at the menu
    int CardSet_Player1[4]; // -1 if no card
    int CardInDeck_Player1[4]; // -1 if no card
    int CardSet_Player2[4]; // -1 if no card
    int CardInDeck_Player2[4]; // -1 if no card


private:

};

#endif // BATTLE_H
