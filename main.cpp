#include <QApplication>
#include "system.h"

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    System system(nullptr, nullptr);
    system.BattleManager->addMinion(MinionType::DerivedMinion, MinionTeam::MyTeam, QPoint(400, 300));

    return prog.exec();
}
