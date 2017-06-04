#include "display.h"
#include <QDebug>

Display_t::Display_t()
{
    Scene = new MyQGraphicsScene();
    Scene->setSceneRect(0, 0, 800, 600);
    View = new QGraphicsView(Scene);
    View->show();

    // add four card button
    for(int i=0;i<4;++i)
    {
       Button[i] = new Button_t(i);
       Scene->addItem(Button[i]);
    }
}

Display_t::~Display_t()
{
    delete Scene;
    delete View;
    for(int i=0;i<4;++i)
        delete Button[i];
}

void Display_t::addItem(QGraphicsItem *Item)
{
    Scene->addItem(Item);
}

void Display_t::removeItem(QGraphicsItem *Item)
{
    Scene->removeItem(Item);
}

void Display_t::addAnimation(QPointF center, int ms, QList<QString> &pathList)
{
    this->addItem( dynamic_cast<QGraphicsItem*>(new Animation_t(center, ms, pathList)) );
}

ControllableDisplay_t::ControllableDisplay_t()
{
    for(int i=0;i<4;++i)
        connect(Button[i], SIGNAL(selectedByMouse(int)), this, SLOT(emit_ReceivedSignal_SelectCard(int)));
    connect(Scene, SIGNAL(positionSelected(QPointF)), this, SLOT(positionSelected(QPointF)));
}

ControllableDisplay_t::~ControllableDisplay_t()
{

}

void ControllableDisplay_t::minionSelected(Minion_t* selMinion)
{
    qDebug() << "CD got minSel";
    emit receivedSignal_SelectMinion(selMinion);
}

void ControllableDisplay_t::positionSelected(QPointF Position)
{
    qDebug() << "CD got posSel, " << Position.x(), Position.y();
    emit receivedSignal_SelectPosition(Position);
}

void Minion_t::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "press";
    emit selectedByMouse(this);
}

Button_t::Button_t(int _ID) : ID(_ID)
{
    this->setPixmap(QPixmap("./resources/images/Button.png"));
    this->setPos(_ID*200, 500);
    this->setZValue(1);
}

Button_t::~Button_t()
{

}

void Button_t::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit selectedByMouse(ID);
}

MyQGraphicsScene::MyQGraphicsScene()
{
    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()), this, SLOT(updateBlackScreen()));
    BlackScreen = new QImage(800, 600, QImage::Format_ARGB32);
    BlackScreen->fill(QColor(0, 0, 0));
    BlackScreenItem = new QGraphicsPixmapItem( QPixmap::fromImage(*BlackScreen) );
    BlackScreenItem->setZValue(0.9);
    BlackScreenItem->setPos(0, 0);
    this->addItem(BlackScreenItem);
    Timer->start(50); // 20Hz
}

MyQGraphicsScene::~MyQGraphicsScene()
{
    delete BlackScreen;
}

void MyQGraphicsScene::updateBlackScreen()
{
    BlackScreen->fill(QColor(0, 0, 0, 100)); // completely black
    for(auto &item_ptr : QGraphicsScene::items())
    {
        // Minion can lighten dark area
        Minion_t* minion = dynamic_cast<Minion_t*>(item_ptr);
        if(minion != nullptr && minion->Team == MinionTeam::MyTeam)
        {
            int lb = std::max(0.0, minion->Center.x() - 100); // left bound
            int rb = std::min(799.0, minion->Center.x() + 100); // right
            int ub = std::max(0.0, minion->Center.y() - 100); // up
            int db = std::min(599.0, minion->Center.y() + 100); // down

            for(int i=lb;i<=rb;++i)
            {
                for(int j=ub;j<=db;++j)
                {
                    BlackScreen->setPixelColor(i, j, QColor(255, 255, 255, 0)); // transparent
                }
            }
        }

        // Animation can lighten dark area
        Animation_t* ani = dynamic_cast<Animation_t*>(item_ptr);
        if(ani != nullptr)
        {
            int lb = std::max(0.0, ani->Center.x() - 100); // left bound
            int rb = std::min(799.0, ani->Center.x() + 100); // right
            int ub = std::max(0.0, ani->Center.y() - 100); // up
            int db = std::min(599.0, ani->Center.y() + 100); // down

            for(int i=lb;i<=rb;++i)
            {
                for(int j=ub;j<=db;++j)
                {
                    BlackScreen->setPixelColor(i, j, QColor(255, 255, 255, 0)); // transparent
                }
            }
        }
    }
    BlackScreenItem->setPixmap( QPixmap::fromImage(*BlackScreen) );
}

void MyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos().toPoint();
    qDebug() << "scene received event , pos = " << pos ;
    qDebug() << "scene items size = " << QGraphicsScene::items(pos).size();
    if( QGraphicsScene::items(pos).size() <= 1 )
    {
        emit positionSelected(pos);
        return;
    }
    QGraphicsScene::mousePressEvent(event); // pass the event to item
}
