#include <QApplication>
#include <QMovie>
#include "system.h"

#include "account.h"

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    System system(nullptr, nullptr);

    return prog.exec();
}
