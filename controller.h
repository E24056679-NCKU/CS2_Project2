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
    void emit_ReceivedSignal_SelectPosition(QPointF Position);
    //void emit_ReceivedSignal_SelectMinion(QPointF Position);
    void emit_ReceivedSignal_SelectMinion(Minion_t* selMinion);
    void emit_ReceivedSignal_SelectCard(int CardID);

signals:
    void receivedSignal_SelectPosition(QPointF Position);
    // due to technical restriction, use Position to find which Minion is selected
    //void receivedSignal_SelectMinion(QPointF Position);
    void receivedSignal_SelectMinion(Minion_t* selMinion);
    void receivedSignal_SelectCard(int CardID); // CardID is 0~3

private:

};

#endif // CONTROLLER_H
