#include "display.h"
#include <QDebug>

Display_t::Display_t()
{
    View = new QGraphicsView();

    MenuDisplay = new MenuDisplay_t(View);

    this->setupGameScene();

    this->changetoLoginScene();
    View->show();
}

void Display_t::setupGameScene()
{
    Scene = new MyQGraphicsScene();
    Scene->setSceneRect(0, 0, 800, 600);

    // add four card button
    for(int i=0;i<4;++i)
    {
       Button[i] = new Button_t(i);
       Scene->addItem(Button[i]);
    }
}

MenuDisplay_t::MenuDisplay_t(QGraphicsView *ParentView)
{
    this->ParentView = ParentView;
    this->setupCardManageScene();
    this->setupGameOverScene();
    this->setupLoginScene();
    this->setupRankScene();
}

MenuDisplay_t::~MenuDisplay_t()
{
    delete CardManageScene;
    delete GameOverScene;
    delete LoginScene;
}

void MenuDisplay_t::setupLoginScene()
{
    LoginScene = new QGraphicsScene();
    LoginScene->setSceneRect(0, 0, 800, 600);

    this->LoginScene_Input_Account = new QTextEdit;
    LoginScene->addWidget( this->LoginScene_Input_Account);
    LoginScene_Input_Account->setGeometry(300, 200, 200, 75);

    this->LoginScene_Input_Password = new QTextEdit;
    LoginScene->addWidget( this->LoginScene_Input_Password);
    LoginScene_Input_Password->setGeometry(300, 300, 200, 75);

    this->LoginScene_Button_Rank = new QPushButton;
    LoginScene->addWidget( this->LoginScene_Button_Rank );
    LoginScene_Button_Rank->setGeometry(700, 0, 100, 50);
    LoginScene_Button_Rank->setText("Rank");
    connect(LoginScene_Button_Rank, SIGNAL(pressed()), this, SLOT(LoginScene_RankClicked()));

    this->LoginScene_Button_Submit = new QPushButton;
    LoginScene->addWidget( this->LoginScene_Button_Submit );
    LoginScene_Button_Submit->setGeometry(350, 400, 100, 50);
    LoginScene_Button_Submit->setText("Submit");
    connect(LoginScene_Button_Submit, SIGNAL(pressed()), this, SLOT(LoginScene_SubmitClicked()));

    this->LoginScene_Button_Create = new QPushButton;
    LoginScene->addWidget( this->LoginScene_Button_Create );
    LoginScene_Button_Create->setGeometry(350, 450, 100, 50);
    LoginScene_Button_Create->setText("Create");
    connect(LoginScene_Button_Create, SIGNAL(pressed()), this, SLOT(LoginScene_CreateClicked()));

    this->LoginScene_Label = new QLabel;
    LoginScene->addWidget( this->LoginScene_Label );
    LoginScene_Label->setGeometry(250, 100, 300, 50);
    LoginScene_Label->setText("HI");
}

void MenuDisplay_t::setupCardManageScene()
{
    CardManageScene = new QGraphicsScene;
    CardManageScene->setSceneRect(0, 0, 800, 600);
}

void MenuDisplay_t::setupGameOverScene()
{
    GameOverScene = new QGraphicsScene;
    GameOverScene->setSceneRect(0, 0, 800, 600);
    GameOverScene->setBackgroundBrush( QBrush(QImage("./resources/images/GameOver.jpg")) );
}

void MenuDisplay_t::setupRankScene()
{
    RankScene = new QGraphicsScene;
    RankScene->setSceneRect(0, 0, 800, 600);

    this->RankScene_Button_LoginScene = new QPushButton();
    RankScene->addWidget( RankScene_Button_LoginScene );
    RankScene_Button_LoginScene->setGeometry(700, 0, 100, 50);
    RankScene_Button_LoginScene->setText("Back");
    connect(RankScene_Button_LoginScene, SIGNAL(pressed()), this, SLOT(RankScene_LoginSceneClicked()));
}

void Display_t::changetoGameScene()
{
    View->setScene( this->Scene );
}

void Display_t::changetoLoginScene()
{
    MenuDisplay->changetoLoginScene();
}

void Display_t::changetoCardManageScene()
{
    MenuDisplay->changetoCardManageScene();
}

void Display_t::changetoGameOverScene()
{
    MenuDisplay->changetoGameOverScene();
}

void MenuDisplay_t::changetoLoginScene()
{
    ParentView->setScene( this->LoginScene );
}

void MenuDisplay_t::LoginScene_SubmitClicked()
{
    QString username = LoginScene_Input_Account->toPlainText();
    QString password = LoginScene_Input_Password->toPlainText();

    Account_t* findRes = AccountManager->selectAccount( username );
    if( findRes == nullptr )
    {
        this->LoginScene_Label->setText("Wrong Username or Password");
        return;
    }
    else if( findRes->Password != password )
    {
        this->LoginScene_Label->setText("Wrong Username or Password");
        return;
    }
    this->LoginScene_Label->setText("Login Succeeded");
    emit accountLogined(findRes);
    this->changetoCardManageScene();
}

void MenuDisplay_t::LoginScene_CreateClicked()
{
    QString username = LoginScene_Input_Account->toPlainText();
    QString password = LoginScene_Input_Password->toPlainText();

    if(username.contains(' ') || password.contains(' '))
    {
        this->LoginScene_Label->setText("Invalid Username or Password");
        return;
    }
    else if( AccountManager->selectAccount(username) != nullptr )
    {
        this->LoginScene_Label->setText("Account Already Exist");
        return;
    }

    int card[6] = {0, 0, 0, 0, 0, 0};
    Account_t newAccount( username, password, 100, card);
    AccountManager->addAccount(newAccount);
    this->LoginScene_Label->setText("Account Created");
}

void MenuDisplay_t::LoginScene_RankClicked()
{
    this->changetoRankScene();
}

void MenuDisplay_t::changetoRankScene()
{
    static QList<QLabel*> LabelList;
    for(auto &i : LabelList)
        delete i;
    LabelList.clear();

    QMultiMap<int, QString> UserList;
    for(auto &i : AccountManager->AccountList)
    {
        UserList.insert( i->Money , i->Username );
    }

    int idx = 0;
    for(auto it = UserList.end() ; it != UserList.begin() ; )
    {
        --it;
        QLabel* newLabel1 = new QLabel;
        this->RankScene->addWidget(newLabel1);
        newLabel1->setText( it.value());
        newLabel1->setGeometry(20, 20*idx+20, 500, 15);

        QLabel* newLabel2 = new QLabel;
        this->RankScene->addWidget(newLabel2);
        newLabel2->setText( QString::number(it.key()) );
        newLabel2->setGeometry(300, 20*idx+20, 200, 15);

        LabelList.push_back(newLabel1);
        LabelList.push_back(newLabel2);
        idx++;
    }
    ParentView->setScene( this->RankScene );
}

void MenuDisplay_t::RankScene_LoginSceneClicked()
{
    this->changetoLoginScene();
}

void MenuDisplay_t::changetoCardManageScene()
{

    ParentView->setScene( this->CardManageScene );
}

void MenuDisplay_t::changetoGameOverScene()
{
    ParentView->setScene( this->GameOverScene );
}

Display_t::~Display_t()
{
    delete Scene;
    delete View;
    delete MenuDisplay;
    for(int i=0;i<4;++i)
        if( Button[i] != nullptr )
            delete Button[i];
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

/*
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
*/

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
