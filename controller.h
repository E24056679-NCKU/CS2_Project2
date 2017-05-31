#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPointF>
#include "minion.h"

// this is the universal plot for different controller
// each controller should inherit ControllerSlot_t
class ControllerSlot_t : public QObject
{
    Q_OBJECT
public:
    ControllerSlot_t();
    virtual ~ControllerSlot_t();

protected slots:
    void emit_GotSignal_SelectPosition(QPointF Position);
    void emit_GotSignal_SelectMinion(QPointF Position);
    void emit_GotSignal_SelectMinion(Minion_t* selMinion);
    void emit_GotSignal_SelectCard(int CardID);

signals:
    void gotSignal_SelectPosition(QPointF Position);
    // due to technical restriction, use Position to find which Minion is selected
    void gotSignal_SelectMinion(QPointF Position);
    void gotSignal_SelectMinion(Minion_t* selMinion);
    void gotSignal_SelectCard(int CardID); // CardID is 0~3

private:

};

#endif // CONTROLLER_H
