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

void MyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos().toPoint();
    if( QGraphicsScene::items(pos).size() == 0 )
    {
        emit positionSelected(pos);
        return;
    }
    QGraphicsScene::mousePressEvent(event); // pass the event to item
}
