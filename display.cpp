#include "display.h"
#include <QDebug>

Display_t::Display_t()
{
    Scene = new MyQGraphicsScene();
    Scene->setSceneRect(0, 0, 800, 600);
    View = new QGraphicsView(Scene);
    View->show();

    // add four card button
    for(int i=0;i<4;++i)
    {
       Button[i] = new Button_t(i);
       Scene->addItem(Button[i]);
    }
}

Display_t::~Display_t()
{
    delete Scene;
    delete View;
    for(int i=0;i<4;++i)
        delete Button[i];
}

void Display_t::gameOver()
{
    View->setScene(nullptr);
    delete Scene;
    GameOverScene = new QGraphicsScene;
    GameOverScene->setSceneRect(0, 0, 800, 600);
    GameOverScene->setBackgroundBrush( QBrush(QImage("./resources/images/GameOver.jpg")) );
    View->setScene(GameOverScene);
}

void Display_t::addItem(QGraphicsItem *Item)
{
    Scene->addItem(Item);
}

void Display_t::removeItem(QGraphicsItem *Item)
{
    Scene->removeItem(Item);
}

void Display_t::addAnimation(QPointF center, int period, QList<QString> &pathList)
{
    this->addItem( dynamic_cast<QGraphicsItem*>(new Animation_t(center, period, pathList)) );
}

ControllableDisplay_t::ControllableDisplay_t()
{
    for(int i=0;i<4;++i)
        connect(Button[i], SIGNAL(selectedByMouse(int)), this, SLOT(emit_ReceivedSignal_SelectCard(int)));
    connect(Scene, SIGNAL(positionSelected(QPointF)), this, SLOT(positionSelected(QPointF)));
}

ControllableDisplay_t::~ControllableDisplay_t()
{

}

void ControllableDisplay_t::minionSelected(Minion_t* selMinion)
{
    qDebug() << "CD got minSel";
    emit receivedSignal_SelectMinion(selMinion);
}

void ControllableDisplay_t::positionSelected(QPointF Position)
{
    qDebug() << "CD got posSel, " << Position.x(), Position.y();
    emit receivedSignal_SelectPosition(Position);
}

void Minion_t::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "press";
    emit selectedByMouse(this);
}

Button_t::Button_t(int _ID) : ID(_ID)
{
    this->setPixmap(QPixmap("./resources/images/Button.jpg"));
    this->setPos(_ID*200, 500);
    this->setZValue(1);
}

Button_t::~Button_t()
{

}

void Button_t::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit selectedByMouse(ID);
}

MyQGraphicsScene::MyQGraphicsScene()
{
    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()), this, SLOT(updateBlackScreen()));
    BlackScreen = new QImage(800, 600, QImage::Format_ARGB32); // the size of the Image is the same as Scene's
    BlackScreen->fill(QColor(0, 0, 0)); // all black
    BlackScreenItem = new QGraphicsPixmapItem( QPixmap::fromImage(*BlackScreen) );
    BlackScreenItem->setZValue(0.9); // BlackScreenItem is at above all items, except Buttons
    BlackScreenItem->setPos(0, 0);
    this->addItem(BlackScreenItem);
    Timer->start( 1000 / Hz ); // 1000ms = Hz * Period
}

MyQGraphicsScene::~MyQGraphicsScene()
{
    delete BlackScreen;
    delete BlackScreenItem;
}

void MyQGraphicsScene::updateBlackScreen()
{
    BlackScreen->fill( QColor(0, 0, 0, 100) ); // completely black
    for(auto &item_ptr : QGraphicsScene::items()) // for each item in QGraphcisScene
    {
        int transparency = 0;
        // Minion can lighten dark area
        Life_t* life = dynamic_cast<Life_t*>(item_ptr);
        if(life != nullptr && life->Team == LifeTeam::MyTeam) // if the item is a Life
        {
            //renderFlashlightEffect(*BlackScreen, life->Center, M_PI/6, 100, 0);


            int newCenter_X = life->Center.x() + life->pixmap().size().width()/4;
            int lb = std::max(0.0, 1.0*newCenter_X - 200.0); // left bound
            int rb = std::min(799.0, 1.0*newCenter_X + 200.0); // right
            int ub = std::max(0.0, life->Center.y() - 200.0); // up
            int db = std::min(599.0, life->Center.y() + 200.0); // down

            int widthOver4 = life->pixmap().size().width() >> 2;
            for(int i=ub;i<=db;++i) // row (y)
            {
                int y = i - life->Center.y();
                int yTimes3 = y*3;
                QRgb* pixel = reinterpret_cast<QRgb*>(BlackScreen->scanLine(i));
                pixel += lb;
                for(int j=lb ; j<=rb ; ++j , ++pixel) // column (x)
                {
                    int x = j - (newCenter_X);
                    if( x < widthOver4)
                        continue;
                    if( y >= 0 && x < yTimes3 )
                        continue;
                    if( y < 0 && x < -yTimes3 )
                        continue;
                    transparency = std::min(255.0, std::max(0.0, 0.006375*x*x + (*pixel>>24) - 255.0)); // 0.006375 = 255.0/40000
                    *pixel = (transparency << 24);
                }
            }

        }

        // Animation can lighten dark area
        transparency = 0;
        Animation_t* ani = dynamic_cast<Animation_t*>(item_ptr);
        if(ani != nullptr) // if the item is a Animation
        {
            int lb = std::max(0.0, ani->Center.x() - 100); // left bound
            int rb = std::min(799.0, ani->Center.x() + 100); // right
            int ub = std::max(0.0, ani->Center.y() - 100); // up
            int db = std::min(599.0, ani->Center.y() + 100); // down

            for(int i=ub;i<=db;++i)
            {
                QRgb* pixel = reinterpret_cast<QRgb*>(BlackScreen->scanLine(i));
                pixel += lb;
                for(int j=lb ; j<=rb ; ++j, ++pixel)
                {
                    *pixel = 0x00FFFFFF;
                }
            }
        }
    }
    BlackScreenItem->setPixmap( QPixmap::fromImage(*BlackScreen) );
}

void MyQGraphicsScene::renderFlashlightEffect(QImage &Image, QPointF Source, double Light_Theta, int LightLen, double Rotate_Theta)
{
    int ImageWidth = Image.width();
    int ImageHeight = Image.height();
    int k = 255.0 / (LightLen*LightLen); // illumination constant
    // transparency = std::min(255.0, std::max(0.0, k*x*x + (*pixel>>24) - 255.0));


    std::complex<double> A_comp( LightLen / std::cos(Light_Theta), 0.0);
    std::complex<double> B_comp( LightLen / std::cos(Light_Theta), 0.0);
    A_comp *= std::polar(1.0,  Light_Theta + Rotate_Theta);
    B_comp *= std::polar(1.0, -Light_Theta + Rotate_Theta);


}

void MyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos().toPoint();
    qDebug() << "scene received event , pos = " << pos ;
    qDebug() << "scene items size = " << QGraphicsScene::items(pos).size();
    if( QGraphicsScene::items(pos).size() == 0 )
    {
        emit positionSelected(pos);
        return;
    }
    if( QGraphicsScene::items(pos).size() == 1 && QGraphicsScene::items(pos)[0] == BlackScreenItem )
    {
        emit positionSelected(pos);
        return;
    }
    QGraphicsScene::mousePressEvent(event); // pass the event to item
}
