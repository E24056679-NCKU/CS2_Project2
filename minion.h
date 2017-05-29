#ifndef MINION_H
#define MINION_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QSet>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPoint>

#include <QDebug>

enum MinionTeam
{
    MyTeam = 0,
    OpsTeam, // opponent's group
    NoTeam // NoTeam can attack other teams, while other teams cannot attack NoTeam
};

enum MinionType
{
    BasicMinion = 0,
    DerivedMinion
};

// abstract minion
// the events of QGraphicsPixmapItem is not implemented in this file
// they are in Display.cpp because ControllableDisplay needs them
class Minion_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class MinionManager_t;

public:
    Minion_t();
    virtual ~Minion_t();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    void died(Minion_t* rmMinion);
    void selectedByMouse(Minion_t* selMinion);

public slots:
    virtual void run() = 0;

public:
    virtual void move() = 0;
    virtual void attack(Minion_t* target) = 0;
    bool checkDied();

protected:
    QPoint Pos;
    double HP;
    double Damage;
    double Range;
    double Speed;
    MinionTeam Group;
    QTimer* Timer;

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
    void attack(Minion_t* target);
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

public:
    MinionManager_t();
    ~MinionManager_t();

public slots:
    Minion_t* addMinion(MinionType Type, MinionTeam Group, QPoint Position);
    void removeMinion(Minion_t* rmMinion);
    // MinionManager_t has no permission to access Display, so give this event to BattleManager
    void receivedMinionDied(Minion_t* rmMinion);

signals:
    void minionDied(Minion_t* rmMinion);

protected:

private:
    QSet< Minion_t* > MinionList;

};

#endif
