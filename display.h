#ifndef DISPLAY_H
#define DISPLAY_H

#include <algorithm>
#include <QObject>
#include <QSet>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QGraphicsSceneMouseEvent>
#include "animation.h"
#include "controller.h"
#include "life.h"
#include "minion.h"

// Button at the downside of screen
class Button_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button_t(int _ID);
    ~Button_t();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void selectedByMouse(int ID);

private:
    int ID;

};


// for BlackScreen and overriding mousePressEvent
class MyQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyQGraphicsScene();
    ~MyQGraphicsScene();

public slots:
    // rendering the BlackScreen(QImage) and update PixmapItem
    void updateBlackScreen();

signals:
    void positionSelected(QPointF Position);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    QImage* BlackScreen;
    QGraphicsPixmapItem* BlackScreenItem;
    QTimer* Timer; // for updating BlackScreen
    const static int Hz = 20; // frequecy of updating BlackScreen, i.e., run updateBlackScreen()
};


class Display_t
{
public:
    Display_t();
    virtual ~Display_t();

    void addItem(QGraphicsItem* Item);
    void removeItem(QGraphicsItem* Item);

    void addAnimation(QPointF center, int ms, QList<QString> &pathList);

protected:
    MyQGraphicsScene* Scene;
    QGraphicsView* View;
    Button_t* Button[4];

private:


};


// ControllableDisplay is like a touchscreen, it's an output source and also a input source
class ControllableDisplay_t : public ControllerSlot_t, public Display_t // ControllerSlot_t (which is a QObject) must be inherited first
{
    Q_OBJECT
public:
    ControllableDisplay_t();
    ~ControllableDisplay_t();

public slots:
    void minionSelected(Minion_t* selMinion);
    void positionSelected(QPointF Position);

protected:

private:

};

#endif // DISPLAY_H
