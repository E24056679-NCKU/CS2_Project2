#include "battle.h"

BattleManager_t::BattleManager_t() : QObject()
{
    CountDown = 30000; // (30000/100) s = 300s
    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()), this, SLOT(countDown()));

    MinionManager = new MinionManager_t();
    connect(MinionManager, SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(findLifeInRange(Life_t*,LifeTeam,Life_t*&)));
    connect(MinionManager, SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&,int)), this, SLOT(findAllLifeInRange(Life_t*,LifeTeam,QList<Life_t*>&,int)));
    connect(MinionManager, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(addArrow(Life_t*,double,QPointF)));
    connect(MinionManager, SIGNAL(request_Animation(QPointF)), this, SLOT(received_Animation(QPointF)));
    connect(MinionManager, SIGNAL(request_RangeAttack(Life_t*,QPointF,double,double,LifeTeam)), this, SLOT(rangeAttack(Life_t*,QPointF,double,double,LifeTeam)));
    connect(MinionManager, SIGNAL(emit_MinionRemoved(Minion_t*)), this, SLOT(received_MinionRemoved(Minion_t*)));

    TowerManager = new TowerManager_t();
    connect(TowerManager, SIGNAL(itemAdded(QGraphicsItem*)), this, SLOT(emit_ItemAdded(QGraphicsItem*)));
    connect(TowerManager, SIGNAL(request_FindTarget(Life_t*,LifeTeam,Life_t*&)), this, SLOT(findLifeInRange(Life_t*,LifeTeam,Life_t*&)));
    connect(TowerManager, SIGNAL(request_FindAllTarget(Life_t*,LifeTeam,QList<Life_t*>&,int)), this, SLOT(findAllLifeInRange(Life_t*,LifeTeam,QList<Life_t*>&,int)));
    connect(TowerManager, SIGNAL(emit_ArrowAttack(Life_t*,double,QPointF)), this, SLOT(addArrow(Life_t*,double,QPointF)));

    this->MinionSelected_Player1 = nullptr;
    this->MinionSelected_Player2 = nullptr;
    this->CardSelected_Player1 = -1;
    this->CardSelected_Player2 = -1;
    this->Player1Score = 0;
    this->Player2Score = 0;

    this->Player1Score_Label = new QLabel;
    Player1Score_Label->setGeometry(0, 0, 50, 25);
    Player1Score_Label->setText("0");
    this->Player2Score_Label = new QLabel;
    Player2Score_Label->setGeometry(750, 0, 50, 25);
    Player2Score_Label->setText("0");
    this->CountDown_Label = new QLabel;
    CountDown_Label->setGeometry(387, 0, 50, 25);
    CountDown_Label->setText("0");
    this->Skill_Button = new QPushButton;
    Skill_Button->setGeometry(0, 25, 50, 25);
    Skill_Button->setText("Skill");
    connect(Skill_Button, SIGNAL(pressed()), this, SLOT(skillButtonClicked()));
}

BattleManager_t::~BattleManager_t()
{
    delete Timer;
    delete MinionManager;
    delete TowerManager;
}

void BattleManager_t::initialize()
{
    TowerManager->initializeTowers();
}

void BattleManager_t::setupCards(QList<int> cardSelected, int Player)
{
    if(Player == this->Player1)
    {
        for(int i=0;i<cardSelected.size();++i)
        {
            this->CardSet_Player1[i] = cardSelected[i];
            this->CardInDeck_Player1[i] = cardSelected[i];

            // update button image
            emit changeButtonImage(i, static_cast<MinionType>(CardInDeck_Player1[i]));
        }
        for(int i=cardSelected.size();i<4;++i)
        {
            this->CardSet_Player1[i] = -1;
            this->CardInDeck_Player1[i] = -1;
            emit changeButtonImage(i, static_cast<MinionType>(-1));
        }
    }
    else if(Player == this->Player2)
    {
        for(int i=0;i<cardSelected.size();++i)
        {
            this->CardSet_Player2[i] = cardSelected[i];
            this->CardInDeck_Player2[i] = cardSelected[i];
        }
        for(int i=cardSelected.size();i<4;++i)
        {
            this->CardSet_Player2[i] = -1;
            this->CardInDeck_Player2[i] = -1;
        }
    }
}

void BattleManager_t::updateCard(int usedCardIdx, int Player)
{
    if(Player == this->Player1)
    {
        while( -1 != (CardInDeck_Player1[ usedCardIdx ] = CardSet_Player1[(qrand()%4)]) )
            ;
        emit changeButtonImage(usedCardIdx, static_cast<MinionType>(CardInDeck_Player1[usedCardIdx]) );
    }
    else if(Player == this->Player2)
    {
        while( -1 != (CardInDeck_Player2[ usedCardIdx ] = CardSet_Player2[(qrand()%4)]) )
            ;
        emit changeButtonImage(usedCardIdx, static_cast<MinionType>(CardInDeck_Player2[usedCardIdx]) );
    }
}

void BattleManager_t::countDown()
{
    --CountDown;
    CountDown_Label->setText( QString::number(CountDown/100) );
    Player1Score_Label->setText( QString::number(Player1Score) );
    Player2Score_Label->setText( QString::number(Player2Score) );
    if(CountDown == 0)
    {
        Timer->stop();
        emit gameOver(Player1Score, Player2Score);
    }
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

void BattleManager_t::received_Animation(QPointF center)
{
    Player1Score -= 10;
    emit request_Animation(center);
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
        if( range + std::sqrt(tarHeight*tarHeight+tarWidth*tarWidth)/2 < distance(tar_ptr->Center, center) ) // obviously impossible in range, this line aims to prevent the following commands from being executed
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

            if( crossProduct(center, tarCorner[i], tarCorner[(i+1)%4]) * crossProduct(center, tarCorner[(i+1)%4], tarCorner[i]) < 0 ) // % 4 is to change 4 to 0
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

void BattleManager_t::received_MinionRemoved(Minion_t *rmMinion)
{
    if( rmMinion == this->MinionSelected_Player1 )
        MinionSelected_Player1 = nullptr;
    else if( rmMinion == this->MinionSelected_Player2 )
        MinionSelected_Player2 = nullptr;
}

void BattleManager_t::skillButtonClicked()
{
    this->receivedSignal1_KeyPressed( Qt::Key_Space );
}

void BattleManager_t::addMinion(MinionType Type, MinionTeam Group, QPointF Position)
{
    emit_ItemAdded( dynamic_cast<QGraphicsItem*>(MinionManager->addMinion(Type, Group, Position)) );
}

void BattleManager_t::removeMinion(Minion_t *rmMinion)
{
    MinionManager->removeMinion(rmMinion);
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
        if( requester->Range + std::sqrt(tarHeight*tarHeight+tarWidth*tarWidth)/2 < distance(tar_ptr->Center, refPos) ) // obviously impossible in range, this line aims to prevent the following commands from being executed
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

            if( crossProduct(refPos, tarCorner[i], tarCorner[(i+1)%4]) * crossProduct(refPos, tarCorner[(i+1)%4], tarCorner[i]) < 0 ) // % 4 is to change 4 to 0
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

void BattleManager_t::findAllLifeInRange(Life_t *requester, LifeTeam tarTeam, QList<Life_t*> &response, int SizeLimit)
{
        response.clear();

        const QPointF& refPos = requester->Center;

        // for each tower
        for(int i=0;i<6;++i)
        {
            if( response.size() >= SizeLimit )
                break;

            if( dynamic_cast<Tower_t*>(requester) != nullptr ) // if the requester is tower, leave this loop
                break;

            Tower_t* tar_ptr = this->TowerManager->TowerList[i];
            if( tar_ptr == nullptr || tar_ptr->Team != tarTeam || tar_ptr == requester )
                continue;

            double tarHeight = tar_ptr->pixmap().size().height();
            double tarWidth = tar_ptr->pixmap().size().width();
            if( requester->Range + std::sqrt(tarHeight*tarHeight+tarWidth*tarWidth)/2 < distance(tar_ptr->Center, refPos) ) // obviously impossible in range, this line aims to prevent the following commands from being executed
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

                if( crossProduct(refPos, tarCorner[i], tarCorner[(i+1)%4]) * crossProduct(refPos, tarCorner[(i+1)%4], tarCorner[i]) < 0 ) // % 4 is to change 4 to 0
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
            if( response.size() >= SizeLimit )
                break;

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
    // !!
    // CardInDeck_Player1[ CardSelected_Player1 ]
    // this is the minion's id
    // !!

    if(CardSelected_Player1 == -1 && MinionSelected_Player1 != nullptr)
    {
        // hero
        this->MinionSelected_Player1->TargetPos = QPointF( qRound(Position.x()) , qRound(Position.y()) );
    }
    else if(CardSelected_Player1!= -1 && MinionSelected_Player1 == nullptr)
    {
        // create new minion

        // DBG
        // these two lines are used to test connection with ControllableDisplay
        this->addMinion( static_cast<MinionType>(CardInDeck_Player1[CardSelected_Player1]) , MinionTeam::MyTeam, Position);
    }

    //updateCard(CardSelected_Player1, this->Player1);
}

void BattleManager_t::receivedSignal1_SelectMinion(Minion_t *selMinion)
{
    qDebug() << "BM, sig1, selMini, DBG";
    if(MinionSelected_Player1 != nullptr)
        MinionSelected_Player1->TargetPos = QPointF(1000, MinionSelected_Player1->TargetPos.y()); // reset original selected minion's targetpos
    MinionSelected_Player1 = selMinion;
    CardSelected_Player1 = -1;
}

void BattleManager_t::receivedSignal1_SelectCard(int ButtonID)
{
    MinionSelected_Player1 = nullptr;
    CardSelected_Player1 = ButtonID;
}

void BattleManager_t::receivedSignal1_KeyPressed(int key)
{
    if( MinionSelected_Player1 != nullptr && key == Qt::Key_Space ) // hero launch skill
    {
        qDebug() << "launch";
        MinionSelected_Player1->skill();
    }
}

void BattleManager_t::receivedSignal2_SelectPosition(QPointF Position)
{
    /*
    if(CardSelected_Player2 == -1 && MinionSelected_Player2 != nullptr)
    {

    }
    else if(CardSelected_Player2!= -1 && MinionSelected_Player2 == nullptr)
    {
        // create new minion

        // DBG
        // these two lines are used to test connection with ControllableDisplay
        qDebug() << "BM, sig2, pos, DBG";
        this->addMinion( MinionType::DerivedMinion , MinionTeam::OpsTeam, Position);


        // !! recover this line, this->addMinion( CardtoMinionType_Player1[CardSelected_Player1] , MinionTeam::MyTeam, Position);
    }
    */
}

void BattleManager_t::receivedSignal2_SelectMinion(Minion_t *selMinion)
{
    /*
    qDebug() << "BM, sig1, selMini, DBG";
    CardSelected_Player2 = -1;
    MinionSelected_Player2 = selMinion;
    */
}

void BattleManager_t::receivedSignal2_SelectCard(int ButtonID)
{
    /*
    MinionSelected_Player2 = nullptr;
    CardSelected_Player2 = ButtonID;
    */
}

void BattleManager_t::receivedSignal2_KeyPressed(int key)
{

}
