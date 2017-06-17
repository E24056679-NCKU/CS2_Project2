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
    BasicMinion = -2,
    DerivedMinion = -1,
    ChairMinion = 0,
    ChangMinion,
    ChengMinion,
    JouMinion,
    LeeMinion,
    TsaiMinion
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

    QPointF TargetPos;

signals:
    void died(Minion_t* rmMinion);
    void selectedByMouse(Minion_t* selMinion);
    // ask system to create a Animation
    void request_Animation(QPointF center);
    void request_RangeAttack(Life_t* requester, QPointF center, double range, double damage, LifeTeam targetTeam);

public slots:
    virtual void run();

public:
    virtual void move();
    virtual void attack(Life_t* target); // skill
    virtual void skill();

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

public:
    // the basic image (for minion on battlefield)
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
    // a series of images when the minion is moving
    static QList< QPixmap* > MovingImages;
    // a series of images when the minion is attacking
    static QList< QPixmap* > AttackingImages;
    // below we can add other Image series such as SkillImages
};

class ChairMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    ChairMinion_t();
    ~ChairMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::ChairMinion;

protected:

public:
    // the basic image
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
};

class ChangMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    ChangMinion_t();
    ~ChangMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::ChangMinion;

protected:

public:
    // the basic image
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
};

class ChengMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    ChengMinion_t();
    ~ChengMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::ChengMinion;

protected:

public:
    // the basic image
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
};

class JouMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    JouMinion_t();
    ~JouMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::JouMinion;

protected:

public:
    // the basic image
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
};

class LeeMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    LeeMinion_t();
    ~LeeMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::LeeMinion;

protected:

public:
    // the basic image
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
};

class TsaiMinion_t : public Minion_t
{
    Q_OBJECT
    friend class MinionManager_t;

public:
    TsaiMinion_t();
    ~TsaiMinion_t();

public slots:
    void run();

public:
    void attack(Life_t* target);
    static const MinionType Type = MinionType::TsaiMinion;

protected:

public:
    // the basic image
    static QPixmap* BasicImage;
    // the button's image
    static QPixmap* ButtonImage;
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
    void received_FindAllTarget(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response, int SizeLimit);
    // received signal Life::emit_ArrowAttack()
    void receive_ArrowAttack(Life_t* target, double damage, QPointF pos);
    // received signal Minion::request_Animation
    void received_Animation(QPointF center);
    // received signal Minion::request_RangeAttack
    void received_RangeAttack(Life_t* requester, QPointF center, double range, double damage, LifeTeam targetTeam);

signals:
    // forward signal to BattleManager
    void request_FindTarget(Life_t* requester, LifeTeam tarTeam, Life_t* &response); // response is a reference
    void request_FindAllTarget(Life_t* requester, LifeTeam tarTeam, QList<Life_t*> &response, int SizeLimit);
    void emit_ArrowAttack(Life_t* target, double damage, QPointF pos);
    void request_Animation(QPointF center);
    void request_RangeAttack(Life_t* requester, QPointF center, double range, double damage, LifeTeam targetTeam);

    void emit_MinionRemoved(Minion_t* rmMinion);

protected:

private:
    QSet< Minion_t* > MinionList;

};

#endif
