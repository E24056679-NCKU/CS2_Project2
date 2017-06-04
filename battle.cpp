#include "battle.h"

BattleManager_t::BattleManager_t() : QObject()
{
    MinionManager = new MinionManager_t();
    connect(MinionManager, SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(findLifeInRange(Life_t*,LifeTeam,Life_t*&)));
    connect(MinionManager, SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&)), this, SLOT(findAllLifeInRange(Life_t*,LifeTeam,QList<Life_t*>&)));
    connect(MinionManager, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(addArrow(Life_t*,double,QPointF)));
    connect(MinionManager, SIGNAL(request_Animation(QPointF,int,QList<QString>&)), this, SLOT(received_Animation(QPointF,int,QList<QString>&)));
    connect(MinionManager, SIGNAL(request_RangeAttack(Life_t*,QPointF,double,double,LifeTeam)), this, SLOT(rangeAttack(Life_t*,QPointF,double,double,LifeTeam)));

    TowerManager = new TowerManager_t();
    connect(TowerManager, SIGNAL(itemAdded(QGraphicsItem*)), this, SLOT(emit_ItemAdded(QGraphicsItem*)));
    connect(TowerManager, SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(findLifeInRange(Life_t*,LifeTeam,Life_t*&)));
    connect(TowerManager, SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&)), this, SLOT(findAllLifeInRange(Life_t*,LifeTeam,QList<Life_t*>&)));
    connect(TowerManager, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(addArrow(Life_t*,double,QPointF)));

}

BattleManager_t::~BattleManager_t()
{
    delete MinionManager;
    delete TowerManager;
}

void BattleManager_t::initialize()
{
    TowerManager->initializeTowers();
}

void BattleManager_t::emit_ItemAdded(QGraphicsItem *addItem)
{
    emit itemAdded( addItem );
}

void BattleManager_t::emit_ItemRemoved(QGraphicsItem *rmItem)
{
    emit itemRemoved( rmItem );
}

void BattleManager_t::addArrow(Life_t *target, double damage, QPointF pos)
{
    itemAdded( dynamic_cast<QGraphicsItem*>(new Arrow_t(target, damage, pos)) );
}

void BattleManager_t::received_Animation(QPointF center, int ms, QList<QString> &pathList)
{
    emit request_Animation(center, ms, pathList);
}

void BattleManager_t::rangeAttack(Life_t* requester, QPointF center, double range, double damage, LifeTeam targetTeam)
{
    // for each tower
    for(int i=0;i<6;++i)
    {
        Tower_t* tar_ptr = this->TowerManager->TowerList[i];
        if( tar_ptr == nullptr || tar_ptr->Team != targetTeam || tar_ptr == requester )
            continue;

        double tarHeight = tar_ptr->pixmap().size().height();
        double tarWidth = tar_ptr->pixmap().size().width();
        if( tar_ptr->Range + std::sqrt(tarHeight*tarHeight+tarWidth*tarWidth)/2 < distance(tar_ptr->Center, center) ) // obviously impossible in range, this line aims to prevent the following commands from being executed
            continue;

        double tarX[2] = {tar_ptr->Center.x() - tarWidth/2  ,  tar_ptr->Center.x() + tarWidth/2}; // four corner of tower
        double tarY[2] = {tar_ptr->Center.y() - tarHeight/2  ,  tar_ptr->Center.y() + tarHeight/2}; // four corner of tower
        QPointF tarCorner[4];
        for(int a=0;a<2;++a) // create four points for four corner
            for(int b=0;b<2;++b)
                tarCorner[a*2 + b] = QPointF(tarX[a], tarY[b]);

        double minDist = 1e9; // minimum distance between tower and minion
        // for each cornor; minimum dist may be dist(corner, point) or dist(side, point)
        for(int i=0;i<4;++i)
        {
            minDist = std::min(minDist, distance(center, tarCorner[i]));

            if( crossProduct(center, tarCorner[i], tarCorner[(i+1)%4]) > 0   &&   crossProduct(center, tarCorner[(i+1)%4], tarCorner[i]) < 0 ) // % 4 is to change 4 to 0
                minDist = std::min(minDist, fabs( crossProduct(center, tarCorner[i], tarCorner[(i+1)%4]) ) / distance(tarCorner[i], tarCorner[(i+1)%4]) ); // use the area of triangle to calculate distance to line

            if( minDist <= range )
            {
                tar_ptr->HP -= damage;
                break;
            }
        }
    }

    // then each minion
    for(Minion_t* tar_ptr : this->MinionManager->MinionList)
    {
        if( tar_ptr->Team != targetTeam || tar_ptr == requester )
            continue;

        const QPointF& tarPos = tar_ptr->Center;
        if( distance(center, tarPos) <= range )
        {
            tar_ptr->HP -= damage;
        }
    }
}

void BattleManager_t::addMinion(MinionType Type, MinionTeam Group, QPointF Position)
{
    emit_ItemAdded( dynamic_cast<QGraphicsItem*>(MinionManager->addMinion(Type, Group, Position)) );
}

void BattleManager_t::removeMinion(Minion_t *rmMinion)
{
    MinionManager->removeMinion(rmMinion);
}

inline double distance(const QPointF &a, const QPointF &b)
{
    double dx = a.x() - b.x();
    double dy = a.y() - b.y();
    return std::sqrt(dx*dx+dy*dy);
}

inline double crossProduct(const QPointF &refP, QPointF p1, QPointF p2)
{
    p1 -= refP;
    p2 -= refP;
    return p1.x()*p2.y() - p1.y()*p2.x();
}

void BattleManager_t::findLifeInRange(Life_t *requester, LifeTeam tarTeam, Life_t* &response)
{
    response = nullptr;

    const QPointF& refPos = requester->Center;

    // for each tower
    for(int i=0;i<6;++i)
    {
        if( dynamic_cast<Tower_t*>(requester) != nullptr ) // if the requester is tower, leave this loop
            break;

        Tower_t* tar_ptr = this->TowerManager->TowerList[i];
        if( tar_ptr == nullptr || tar_ptr->Team != tarTeam || tar_ptr == requester )
            continue;

        double tarHeight = tar_ptr->pixmap().size().height();
        double tarWidth = tar_ptr->pixmap().size().width();
        if( tar_ptr->Range + std::sqrt(tarHeight*tarHeight+tarWidth*tarWidth)/2 < distance(tar_ptr->Center, refPos) ) // obviously impossible in range, this line aims to prevent the following commands from being executed
            continue;

        double tarX[2] = {tar_ptr->Center.x() - tarWidth/2  ,  tar_ptr->Center.x() + tarWidth/2}; // four corner of tower
        double tarY[2] = {tar_ptr->Center.y() - tarHeight/2  ,  tar_ptr->Center.y() + tarHeight/2}; // four corner of tower
        QPointF tarCorner[4];
        for(int a=0;a<2;++a) // create four points for four corner
            for(int b=0;b<2;++b)
                tarCorner[a*2 + b] = QPointF(tarX[a], tarY[b]);

        double minDist = 1e9; // minimum distance between tower and minion
        // for each cornor; minimum dist may be dist(corner, point) or dist(line, point)
        for(int i=0;i<4;++i)
        {
            minDist = std::min(minDist, distance(refPos, tarCorner[i]));

            if( crossProduct(refPos, tarCorner[i], tarCorner[(i+1)%4]) > 0   &&   crossProduct(refPos, tarCorner[(i+1)%4], tarCorner[i]) < 0 ) // % 4 is to change 4 to 0
                minDist = std::min(minDist, fabs( crossProduct(refPos, tarCorner[i], tarCorner[(i+1)%4]) ) / distance(tarCorner[i], tarCorner[(i+1)%4]) ); // use the area of triangle to calculate distance to line

            if( minDist <= requester->Range )
            {
                response = dynamic_cast<Life_t*>(tar_ptr);
                return;
            }
        }
    }

    // then each minion
    for(Minion_t* tar_ptr : this->MinionManager->MinionList)
    {
        if( tar_ptr->Team != tarTeam || tar_ptr == requester )
            continue;

        const QPointF& tarPos = tar_ptr->Center;
        if( distance(refPos, tarPos) <= requester->Range )
        {
            response = dynamic_cast<Life_t*>(tar_ptr);
            return;
        }
    }
}

void BattleManager_t::findAllLifeInRange(Life_t *requester, LifeTeam tarTeam, QList<Life_t*> &response)
{
        response.clear();

        const QPointF& refPos = requester->Center;

        // for each tower
        for(int i=0;i<6;++i)
        {
            if( dynamic_cast<Tower_t*>(requester) != nullptr ) // if the requester is tower, leave this loop
                break;

            Tower_t* tar_ptr = this->TowerManager->TowerList[i];
            if( tar_ptr == nullptr || tar_ptr->Team != tarTeam || tar_ptr == requester )
                continue;

            double tarHeight = tar_ptr->pixmap().size().height();
            double tarWidth = tar_ptr->pixmap().size().width();
            if( tar_ptr->Range + std::sqrt(tarHeight*tarHeight+tarWidth*tarWidth)/2 < distance(tar_ptr->Center, refPos) ) // obviously impossible in range, this line aims to prevent the following commands from being executed
                continue;

            double tarX[2] = {tar_ptr->Center.x() - tarWidth/2  ,  tar_ptr->Center.x() + tarWidth/2}; // four corner of tower
            double tarY[2] = {tar_ptr->Center.y() - tarHeight/2  ,  tar_ptr->Center.y() + tarHeight/2}; // four corner of tower
            QPointF tarCorner[4];
            for(int a=0;a<2;++a) // create four points for four corner
                for(int b=0;b<2;++b)
                    tarCorner[a*2 + b] = QPointF(tarX[a], tarY[b]);

            double minDist = 1e9; // minimum distance between tower and minion
            // for each cornor; minimum dist may be dist(corner, point) or dist(line, point)
            for(int i=0;i<4;++i)
            {
                minDist = std::min(minDist, distance(refPos, tarCorner[i]));

                if( crossProduct(refPos, tarCorner[i], tarCorner[(i+1)%4]) > 0   &&   crossProduct(refPos, tarCorner[(i+1)%4], tarCorner[i]) < 0 ) // % 4 is to change 4 to 0
                    minDist = std::min(minDist, fabs( crossProduct(refPos, tarCorner[i], tarCorner[(i+1)%4]) ) / distance(tarCorner[i], tarCorner[(i+1)%4]) ); // use the area of triangle to calculate distance to line

                if( minDist <= requester->Range )
                {
                    response.push_back( dynamic_cast<Life_t*>(tar_ptr) );
                    break;
                }
            }
        }

        // then each minion
        for(Minion_t* tar_ptr : this->MinionManager->MinionList)
        {
            if( tar_ptr->Team != tarTeam || tar_ptr == requester )
                continue;

            const QPointF& tarPos = tar_ptr->Center;
            if( distance(refPos, tarPos) <= requester->Range )
            {
                response.push_back( dynamic_cast<Life_t*>(tar_ptr) );
                continue;
            }
        }
}

void BattleManager_t::receivedSignal1_SelectPosition(QPointF Position)
{
    if(CardSelected_Player1 == -1 && MinionSelected_Player1 != nullptr)
    {

    }
    else if(CardSelected_Player1!= -1 && MinionSelected_Player1 == nullptr)
    {
        // create new minion

        // DBG
        // these two lines are used to test connection with ControllableDisplay
        qDebug() << "BM, sig1, pos, DBG";
        this->addMinion( MinionType::DerivedMinion , MinionTeam::MyTeam, Position);


        // !! recover this line, this->addMinion( CardtoMinionType_Player1[CardSelected_Player1] , MinionTeam::MyTeam, Position);
    }
}

void BattleManager_t::receivedSignal1_SelectMinion(Minion_t *selMinion)
{
    qDebug() << "BM, sig1, selMini, DBG";
    MinionSelected_Player1 = selMinion;
    CardSelected_Player1 = -1;
}

void BattleManager_t::receivedSignal1_SelectCard(int CardID)
{
    MinionSelected_Player1 = nullptr;
    CardSelected_Player1 = CardID;
}

void BattleManager_t::receivedSignal2_SelectPosition(QPointF Position)
{

}

void BattleManager_t::receivedSignal2_SelectMinion(Minion_t *selMinion)
{
    CardSelected_Player2 = -1;
    MinionSelected_Player2 = selMinion;
}

void BattleManager_t::receivedSignal2_SelectCard(int CardID)
{

}
