#include "tower.h"

Tower_t::Tower_t()
{

}

Tower_t::~Tower_t()
{

}

TowerManager_t::TowerManager_t() : QObject()
{
    for(int i=0;i<6;++i)
    {
        TowerList[i] = new Tower_t();
        TowerList[i]->setPos(i*100, i*100);
        TowerList[i]->setPixmap(QPixmap("./resources/images/C.png"));
    }
}

TowerManager_t::~TowerManager_t()
{
    for(int i=0;i<6;++i)
        delete TowerList[i];
}
