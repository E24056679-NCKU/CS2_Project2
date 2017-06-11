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
    // these three functions are for Controller Designer to send signal
    // i.e., when the Controller finish its signal processing, it should call one of these function to emit signal
    void emit_ReceivedSignal_SelectPosition(QPointF Position);
    void emit_ReceivedSignal_SelectMinion(Minion_t* selMinion);
    void emit_ReceivedSignal_SelectCard(int CardID);

signals:
    // emit signals to System , then System will forward the signal to BattleManager
    void receivedSignal_SelectPosition(QPointF Position);
    void receivedSignal_SelectMinion(Minion_t* selMinion);
    void receivedSignal_SelectCard(int CardID); // CardID = [0,3]

private:

};

#endif // CONTROLLER_H
