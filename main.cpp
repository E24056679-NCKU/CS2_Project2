#include <QApplication>
#include <QMovie>
#include "system.h"

#include "account.h"

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    System system(nullptr, nullptr);

    /*
    // animation test
    QList<QString> PL;
    PL.push_back( "./resources/images/Arrow.jpg" );
    PL.push_back( "./resources/images/Button.jpg" );
    PL.push_back( "./resources/images/C.jpg" );
    PL.push_back( "./resources/images/DerivedMinion.jpg" );
    PL.push_back( "./resources/images/MainTower.jpg" );
    PL.push_back( "./resources/images/Tower.jpg" );
    system.addAnimation(QPointF(200, 200), 250, PL);
    */

    return prog.exec();
}
