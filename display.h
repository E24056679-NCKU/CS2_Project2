#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QGraphicsSceneMouseEvent>
#include "controller.h"
#include "minion.h"

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


class MyQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
signals:
    void positionSelected(QPoint Position);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
};


class Display_t
{
public:
    Display_t();
    virtual ~Display_t();

    void addItem(QGraphicsItem* Item);
    void removeItem(QGraphicsItem* Item);

protected:
    MyQGraphicsScene* Scene;
    QGraphicsView* View;
    Button_t* Button[4];

private:


};

// ControllerSlot_t (which is QObject) must be inherited first
class ControllableDisplay_t : public ControllerSlot_t, public Display_t
{
    Q_OBJECT
public:
    ControllableDisplay_t();
    ~ControllableDisplay_t();

public slots:
    void minionSelected(Minion_t* selMinion);
    void positionSelected(QPoint Position);

protected:

private:

};

#endif // DISPLAY_H
