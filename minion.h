#ifndef MINION_H
#define MINION_H

#include <QString>
#include <QVector>
#include <QSet>
#include "life.h"

#include <QDebug>

typedef LifeTeam MinionTeam; // LifeTeam = MinionTeam = TowerTeam
typedef LifeTeam TowerTeam;

class Tower_t;

// TypeID of a Minion
enum MinionType
{
    BasicMinion = 0,
    DerivedMinion
};

// abstract minion
// the mousePressEvent of QGraphicsPixmapItem is not defined in this file, it's in display.cpp because ControllableDisplay needs it
class Minion_t : public Life_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    Minion_t();
    virtual ~Minion_t();
    // for hero system
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    // find one target in Range
    //virtual void findTarget(Life_t* &response); // response is a reference

    bool checkDied();

signals:
    void died(Minion_t* rmMinion);
    void selectedByMouse(Minion_t* selMinion);
    // ask system to create a Animation
    void request_Animation(QPointF center, int ms, QList<QString> &pathList);

public slots:
    virtual void run();

public:
    virtual void move();
    virtual void attack(Life_t* target);

protected:

private:


};

// a derived minion example as a instruction in designing new minion
class DerivedMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    DerivedMinion_t();
    ~DerivedMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::DerivedMinion;

protected:

private:
    // the basic image (for card)
    static QPixmap* BasicImage;
    // a series of images when the minion is moving
    static QList< QPixmap* > MovingImages;
    // a series of images when the minion is attacking
    static QList< QPixmap* > AttackingImages;
    // below we can add other Image series such as SkillImages
};


// manager of minions
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
    // received signal Minion::died()
    void receivedMinionDied(Minion_t* rmMinion);
    // received signal Life::findtarget()
    void received_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    // received signal Life::emit_ArrowAttack()
    void receive_arrowAttack(Life_t* target, double damage, QPointF pos);
    // received signal Minion::request_Animation
    void received_Animation(QPointF center, int ms, QList<QString> &pathList);

signals:
    // forward signal to BattleManager
    void request_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void emit_ArrowAttack(Life_t* target, double damage, QPointF pos);
    void request_Animation(QPointF center, int ms, QList<QString> &pathList);

protected:

private:
    QSet< Minion_t* > MinionList;

};

#endif
