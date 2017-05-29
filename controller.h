#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPoint>
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
    void emit_GotSignal_SelectPosition(QPoint Position);
    void emit_GotSignal_SelectMinion(QPoint Position);
    void emit_GotSignal_SelectMinion(Minion_t* selMinion);
    void emit_GotSignal_SelectCard(int CardID);

signals:
    void gotSignal_SelectPosition(QPoint Position);
    // due to technical restriction, use Position to find which Minion is selected
    void gotSignal_SelectMinion(QPoint Position);
    void gotSignal_SelectMinion(Minion_t* selMinion);
    void gotSignal_SelectCard(int CardID); // CardID is 0~3

private:

};

#endif // CONTROLLER_H
