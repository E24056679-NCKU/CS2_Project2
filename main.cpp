#include <QApplication>
#include "system.h"

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    System system(nullptr, nullptr);
    system.BattleManager->addMinion(MinionType::DerivedMinion, MinionTeam::MyTeam, QPointF(400, 300));

    // animation test
    QList<QString> PL;
    PL.push_back( "./resources/images/Arrow.png" );
    PL.push_back( "./resources/images/Button.png" );
    PL.push_back( "./resources/images/C.png" );
    PL.push_back( "./resources/images/DerivedMinion.png" );
    PL.push_back( "./resources/images/MainTower.png" );
    PL.push_back( "./resources/images/Tower.png" );
    system.addAnimation(QPointF(200, 200), 250, PL);

    return prog.exec();
}
