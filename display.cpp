#include "display.h"
#include <QDebug>
#include <QtGlobal>
#include <QTime>

Display_t::Display_t()
{
    View = new QGraphicsView();

    MenuDisplay = new MenuDisplay_t(View);

    this->setupGameScene();

    this->changetoLoginScene();
    View->QWidget::setFixedSize(850, 650);

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
    this->setupCardBuyScene();
    this->setupBlackJackScene();
}

MenuDisplay_t::~MenuDisplay_t()
{
    delete CardManageScene;
    delete GameOverScene;
    delete LoginScene;
    delete RankScene;
    delete CardBuyScene;
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

    CardManageScene_Button_BuyCard = new QPushButton;
    CardManageScene->addWidget( this->CardManageScene_Button_BuyCard );
    CardManageScene_Button_BuyCard->setGeometry(700, 500, 50, 50);
    CardManageScene_Button_BuyCard->setText("Get Cards");
    connect(CardManageScene_Button_BuyCard, SIGNAL(pressed()), this, SLOT(CardManageScene_BuyClicked()));


    for(int i=0;i<6;++i)
    {
        this->CardManageScene_Button_Card[i] = new QPushButton;
        CardManageScene->addWidget( this->CardManageScene_Button_Card[i] );
        CardManageScene_Button_Card[i]->setGeometry(250*(i%3)+100, 175 + 250*(i/3), 50, 50);
        CardManageScene_Button_Card[i]->setText("Select");
    }
    connect(CardManageScene_Button_Card[0], SIGNAL(pressed()), this, SLOT(CardManageScene_Choose0Clicked()));
    connect(CardManageScene_Button_Card[1], SIGNAL(pressed()), this, SLOT(CardManageScene_Choose1Clicked()));
    connect(CardManageScene_Button_Card[2], SIGNAL(pressed()), this, SLOT(CardManageScene_Choose2Clicked()));
    connect(CardManageScene_Button_Card[3], SIGNAL(pressed()), this, SLOT(CardManageScene_Choose3Clicked()));
    connect(CardManageScene_Button_Card[4], SIGNAL(pressed()), this, SLOT(CardManageScene_Choose4Clicked()));
    connect(CardManageScene_Button_Card[5], SIGNAL(pressed()), this, SLOT(CardManageScene_Choose5Clicked()));

    for(int i=0;i<6;++i)
    {
        this->CardManageScene_Label_Card[i] = new QLabel;
        CardManageScene->addWidget( this->CardManageScene_Label_Card[i] );
        CardManageScene_Label_Card[i]->setGeometry(250*(i%3)+70, 230 + 250*(i/3), 140, 15);
        CardManageScene_Label_Card[i]->setText("CARD");
    }

    for(int i=0;i<6;++i)
    {
        this->CardManageScene_PixmapItem_Card[i] = new QGraphicsPixmapItem( QPixmap("./resources/images/DerivedMinion.jpg") );
        CardManageScene->addItem( this->CardManageScene_PixmapItem_Card[i] );
        CardManageScene_PixmapItem_Card[i]->setScale(3);
        CardManageScene_PixmapItem_Card[i]->setPos(250*(i%3) + 65, 20 + 250*(i/3));
    }

    this->CardManageScene_Button_Submit = new QPushButton;
    CardManageScene->addWidget( this->CardManageScene_Button_Submit );
    CardManageScene_Button_Submit->setGeometry(350, 500, 50, 50);
    CardManageScene_Button_Submit->setText("Submit");
    connect(CardManageScene_Button_Submit, SIGNAL(pressed()), this, SLOT(CardManageScene_SubmitClicked()));

    this->CardManageScene_Label = new QLabel;
    CardManageScene->addWidget( this->CardManageScene_Label );
    CardManageScene_Label->setGeometry(10, 565, 790, 25);
    CardManageScene_Label->setText("HelloWorld");
}

void MenuDisplay_t::setupCardBuyScene()
{
    qsrand(QTime::currentTime().msec());

    CardBuyScene = new QGraphicsScene;
    CardBuyScene->setSceneRect(0, 0, 800, 600);

    this->CardBuyScene_Button_CardManageScene = new QPushButton;
    CardBuyScene->addWidget( this->CardBuyScene_Button_CardManageScene );
    CardBuyScene_Button_CardManageScene->setGeometry(700, 0, 100, 50);
    CardBuyScene_Button_CardManageScene->setText("Back");
    connect(CardBuyScene_Button_CardManageScene, SIGNAL(pressed()), this, SLOT(CardBuyScene_CardManageSceneClicked()));

    this->CardBuyScene_Label_Money = new QLabel;
    CardBuyScene->addWidget( this->CardBuyScene_Label_Money );
    CardBuyScene_Label_Money->setGeometry(10, 10, 100, 25);
    CardBuyScene_Label_Money->setText("Money");

    for(int i=0;i<6;++i)
    {
        this->CardBuyScene_Button_Card[i] = new QPushButton;
        CardBuyScene->addWidget( this->CardBuyScene_Button_Card[i] );
        CardBuyScene_Button_Card[i]->setGeometry(40 + 150*(i%3), 60 + (i/3)*200, 100, 50);
    }
    CardBuyScene_Button_Card[0]->setText("5$");
    CardBuyScene_Button_Card[1]->setText("5$");
    CardBuyScene_Button_Card[2]->setText("5$");
    CardBuyScene_Button_Card[3]->setText("5$");
    CardBuyScene_Button_Card[4]->setText("5$");
    CardBuyScene_Button_Card[5]->setText("5$");
    connect(CardBuyScene_Button_Card[0], SIGNAL(pressed()), this, SLOT(CardBuyScene_Choose0Clicked()));
    connect(CardBuyScene_Button_Card[1], SIGNAL(pressed()), this, SLOT(CardBuyScene_Choose1Clicked()));
    connect(CardBuyScene_Button_Card[2], SIGNAL(pressed()), this, SLOT(CardBuyScene_Choose2Clicked()));
    connect(CardBuyScene_Button_Card[3], SIGNAL(pressed()), this, SLOT(CardBuyScene_Choose3Clicked()));
    connect(CardBuyScene_Button_Card[4], SIGNAL(pressed()), this, SLOT(CardBuyScene_Choose4Clicked()));
    connect(CardBuyScene_Button_Card[5], SIGNAL(pressed()), this, SLOT(CardBuyScene_Choose5Clicked()));

    for(int i=0;i<6;++i)
    {
        this->CardBuyScene_Label_CardCount[i] = new QLabel;
        CardBuyScene->addWidget( this->CardBuyScene_Label_CardCount[i] );
        CardBuyScene_Label_CardCount[i]->setGeometry(40+150*(i%3), 130+(i/3)*200, 100, 25);
    }

    this->CardBuyScene_Button_DrawCard = new QPushButton;
    CardBuyScene->addWidget( this->CardBuyScene_Button_DrawCard );
    CardBuyScene_Button_DrawCard->setGeometry(700, 500, 100, 50);
    CardBuyScene_Button_DrawCard->setText("Draw2Cards\r\n25$");
    connect(CardBuyScene_Button_DrawCard, SIGNAL(pressed()), this, SLOT(CardBuyScene_DrawCardClicked()));

    this->CardBuyScene_Button_Combine = new QPushButton;
    CardBuyScene->addWidget( this->CardBuyScene_Button_Combine );
    CardBuyScene_Button_Combine->setGeometry(700, 400, 100, 50);
    CardBuyScene_Button_Combine->setText("Random\r\nCombine\r\n5$");
    connect(CardBuyScene_Button_Combine, SIGNAL(pressed()), this, SLOT(CardBuyScene_CombineClicked()));


    this->CardBuyScene_Label_Status = new QLabel;
    CardBuyScene->addWidget( this->CardBuyScene_Label_Status );
    CardBuyScene_Label_Status->setGeometry(10, 500, 400, 25);
    CardBuyScene_Label_Status->setText("Hello World");

    this->CardBuyScene_Button_BlackJack = new QPushButton;
    CardBuyScene->addWidget( this->CardBuyScene_Button_BlackJack );
    CardBuyScene_Button_BlackJack->setGeometry(700, 250, 100, 50);
    CardBuyScene_Button_BlackJack->setText("BlackJack");
    connect(CardBuyScene_Button_BlackJack, SIGNAL(pressed()), this, SLOT(CardBuyScene_BlackJackClicked()));
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

void MenuDisplay_t::setupBlackJackScene()
{
    BlackJackScene = new QGraphicsScene;
    BlackJackScene->setSceneRect(0, 0, 800, 600);

    this->BlackJackScene_Button_Back = new QPushButton;
    BlackJackScene->addWidget( this->BlackJackScene_Button_Back );
    BlackJackScene_Button_Back->setGeometry(700, 0, 100, 50);
    BlackJackScene_Button_Back->setText("Back");
    connect(BlackJackScene_Button_Back, SIGNAL(pressed()), this, SLOT(BlackJackScene_BackClicked()));

    this->BlackJackScene_Label_Money = new QLabel;
    BlackJackScene->addWidget( this->BlackJackScene_Label_Money );
    BlackJackScene_Label_Money->setGeometry(10, 10, 500, 25);
    BlackJackScene_Label_Money->setText("Money");

    this->BlackJackScene_Button_StartEnd = new QPushButton;
    BlackJackScene->addWidget( this->BlackJackScene_Button_StartEnd );
    BlackJackScene_Button_StartEnd->setGeometry(700, 500, 100, 50);
    BlackJackScene_Button_StartEnd->setText("Start\r\n50$");
    connect(BlackJackScene_Button_StartEnd, SIGNAL(pressed()), this, SLOT(BlackJackScene_StartEndClicked()));

    this->BlackJackScene_Button_MoreCard = new QPushButton;
    BlackJackScene->addWidget( this->BlackJackScene_Button_MoreCard );
    BlackJackScene_Button_MoreCard->setGeometry(700, 300, 100, 50);
    BlackJackScene_Button_MoreCard->setText("MoreCard");
    BlackJackScene_Button_MoreCard->setEnabled(0);
    connect(BlackJackScene_Button_MoreCard, SIGNAL(pressed()), this, SLOT(BlackJackScene_MoreCardClicked()));

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

    this->Account = findRes;
    emit accountLogined(findRes);

    this->changetoCardManageScene();
}

void MenuDisplay_t::LoginScene_CreateClicked()
{
    QString username = LoginScene_Input_Account->toPlainText();
    QString password = LoginScene_Input_Password->toPlainText();

    bool valid = 1;

    if(username.size() ==0 || password.size() == 0)
        valid = 0;
    for(int i=0;i<username.size();++i)
        if( ! username[i].isLetterOrNumber() )
        {
            valid = 0;
            break;
        }
    for(int i=0;i<password.size();++i)
        if( ! password[i].isLetterOrNumber() )
        {
            valid = 0;
            break;
        }

    if( !valid )
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
    for(int i=0;i<6;++i)
    {
        CardManageScene_Label_Card[i]->setText( QString::number(Account->CardCount[i]) );
        if( Account->CardCount[i] == 0)
            CardManageScene_Button_Card[i]->setText("Invalid");
    }

    ParentView->setScene( this->CardManageScene );
}

void MenuDisplay_t::CardManageScene_BuyClicked()
{
    changetoCardBuyScene();
}

void MenuDisplay_t::CardManageScene_SubmitClicked()
{
    int SelectedCnt = 0;
    for(int i=0;i<6;++i)
        if( CardManageScene_Button_Card[i]->text() == "Selected")
            ++SelectedCnt;
    if(SelectedCnt > 4)
    {
        CardManageScene_Label->setText("Too Many Cards Have Been Selected. You Can Select At Most 4 Cards");
        return;
    }
    else if(SelectedCnt == 0)
    {
        CardManageScene_Label->setText("Select At Least One Card");
        return;
    }
    else
    {
        CardManageScene_Label->setText("Selected Succeeded");
    }

}

void MenuDisplay_t::CardManageScene_Choose0Clicked()
{
    if( this->CardManageScene_Button_Card[0]->text() == "Invalid")
        return;
    else if( this->CardManageScene_Button_Card[0]->text() == "Select")
        this->CardManageScene_Button_Card[0]->setText("Selected");
    else
        this->CardManageScene_Button_Card[0]->setText("Select");
}
void MenuDisplay_t::CardManageScene_Choose1Clicked()
{
    if( this->CardManageScene_Button_Card[1]->text() == "Invalid")
        return;
    else if( this->CardManageScene_Button_Card[1]->text() == "Select")
        this->CardManageScene_Button_Card[1]->setText("Selected");
    else
        this->CardManageScene_Button_Card[1]->setText("Select");
}
void MenuDisplay_t::CardManageScene_Choose2Clicked()
{
    if( this->CardManageScene_Button_Card[2]->text() == "Invalid")
        return;
    else if( this->CardManageScene_Button_Card[2]->text() == "Select")
        this->CardManageScene_Button_Card[2]->setText("Selected");
    else
        this->CardManageScene_Button_Card[2]->setText("Select");
}
void MenuDisplay_t::CardManageScene_Choose3Clicked()
{
    if( this->CardManageScene_Button_Card[3]->text() == "Invalid")
        return;
    else if( this->CardManageScene_Button_Card[3]->text() == "Select")
        this->CardManageScene_Button_Card[3]->setText("Selected");
    else
        this->CardManageScene_Button_Card[3]->setText("Select");
}
void MenuDisplay_t::CardManageScene_Choose4Clicked()
{
    if( this->CardManageScene_Button_Card[4]->text() == "Invalid")
        return;
    else if( this->CardManageScene_Button_Card[4]->text() == "Select")
        this->CardManageScene_Button_Card[4]->setText("Selected");
    else
        this->CardManageScene_Button_Card[4]->setText("Select");
}
void MenuDisplay_t::CardManageScene_Choose5Clicked()
{
    if( this->CardManageScene_Button_Card[5]->text() == "Invalid")
        return;
    else if( this->CardManageScene_Button_Card[5]->text() == "Select")
        this->CardManageScene_Button_Card[5]->setText("Selected");
    else
        this->CardManageScene_Button_Card[5]->setText("Select");
}

void MenuDisplay_t::changetoCardBuyScene()
{
    CardBuyScene_Label_Money->setText( QString::number(Account->Money) );
    for(int i=0;i<6;++i)
    {
        CardBuyScene_Label_CardCount[i]->setText( QString::number(Account->CardCount[i]) );
    }

    ParentView->setScene( this->CardBuyScene );
}

void MenuDisplay_t::CardBuyScene_CardManageSceneClicked()
{
    this->changetoCardManageScene();
}

void MenuDisplay_t::CardBuyScene_DrawCardClicked()
{
    if( Account->Money < 25 )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    int rnd[2];
    rnd[0] = qrand()%6;
    rnd[1] = qrand()%6;
    CardBuyScene_Label_Status->setText( QString("You got Card") + QString::number(rnd[0]) + " and Card" + QString::number(rnd[1]) );
    Account->Money -= 25;
    //CardBuyScene_Label_Money->setText( QString::number(Account->Money) );
    Account->CardCount[rnd[0]]++;
    Account->CardCount[rnd[1]]++;
    AccountManager->saveFile();
    this->changetoCardBuyScene();
}

void MenuDisplay_t::CardBuyScene_CombineClicked()
{
    if( Account->Money < 5 )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    int rnd[3];
    int cardcnt[6];
    bool valid;
    do
    {
        valid = 1;
        for(int i=0;i<6;++i)
            cardcnt[i] = Account->CardCount[i];
        rnd[0] = qrand()%6;
        rnd[1] = qrand()%6;
        rnd[2] = qrand()%6;
        cardcnt[rnd[0]]--;
        cardcnt[rnd[1]]--;
        for(int i=0;i<6;++i)
            if(cardcnt[i] < 0)
                valid = 0;
    }while(!valid);
    CardBuyScene_Label_Status->setText( QString("You Combined Card") + QString::number(rnd[0]) + " and Card" + QString::number(rnd[1]) + " to get Card" + QString::number(rnd[2]));
    Account->Money -= 5;
    // CardBuyScene_Label_Money->setText( QString::number(Account->Money) );
    Account->CardCount[rnd[0]]--;
    Account->CardCount[rnd[1]]--;
    Account->CardCount[rnd[2]]++;
    AccountManager->saveFile();
    this->changetoCardBuyScene();
}

void MenuDisplay_t::CardBuyScene_Choose0Clicked()
{
    int cost = CardBuyScene_Button_Card[0]->text().remove('$').toInt();
    if( cost > Account->Money )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    else
    {
        Account->Money -= cost;
        Account->CardCount[0] ++;
        AccountManager->saveFile();
        CardBuyScene_Label_Status->setText("You Bought One Card 0");
    }
    this->changetoCardBuyScene();
}
void MenuDisplay_t::CardBuyScene_Choose1Clicked()
{
    int cost = CardBuyScene_Button_Card[1]->text().remove('$').toInt();
    if( cost > Account->Money )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    else
    {
        Account->Money -= cost;
        Account->CardCount[1] ++;
        AccountManager->saveFile();
        CardBuyScene_Label_Status->setText("You Bought One Card 1");
    }
    this->changetoCardBuyScene();
}
void MenuDisplay_t::CardBuyScene_Choose2Clicked()
{
    int cost = CardBuyScene_Button_Card[2]->text().remove('$').toInt();
    if( cost > Account->Money )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    else
    {
        Account->Money -= cost;
        Account->CardCount[2] ++;
        AccountManager->saveFile();
        CardBuyScene_Label_Status->setText("You Bought One Card 2");
    }
    this->changetoCardBuyScene();
}
void MenuDisplay_t::CardBuyScene_Choose3Clicked()
{
    int cost = CardBuyScene_Button_Card[3]->text().remove('$').toInt();
    if( cost > Account->Money )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    else
    {
        Account->Money -= cost;
        Account->CardCount[3] ++;
        AccountManager->saveFile();
        CardBuyScene_Label_Status->setText("You Bought One Card 3");
    }
    this->changetoCardBuyScene();
}
void MenuDisplay_t::CardBuyScene_Choose4Clicked()
{
    int cost = CardBuyScene_Button_Card[4]->text().remove('$').toInt();
    if( cost > Account->Money )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    else
    {
        Account->Money -= cost;
        Account->CardCount[4] ++;
        AccountManager->saveFile();
        CardBuyScene_Label_Status->setText("You Bought One Card 4");
    }
    this->changetoCardBuyScene();
}
void MenuDisplay_t::CardBuyScene_Choose5Clicked()
{
    int cost = CardBuyScene_Button_Card[5]->text().remove('$').toInt();
    if( cost > Account->Money )
    {
        CardBuyScene_Label_Status->setText("Some Problem With Your Eyes or Math ?");
        return;
    }
    else
    {
        Account->Money -= cost;
        Account->CardCount[5] ++;
        AccountManager->saveFile();
        CardBuyScene_Label_Status->setText("You Bought One Card 5");
    }
    this->changetoCardBuyScene();
}

void MenuDisplay_t::CardBuyScene_BlackJackClicked()
{
    this->changetoBlackJackScene();
}

void MenuDisplay_t::changetoGameOverScene()
{
    ParentView->setScene( this->GameOverScene );
}

void MenuDisplay_t::changetoBlackJackScene()
{
    BlackJackScene_Label_Money->setText( QString::number(Account->Money) );
    ParentView->setScene( this->BlackJackScene );
}

void MenuDisplay_t::BlackJackScene_BackClicked()
{
    changetoCardBuyScene();
}

void MenuDisplay_t::BlackJackScene_StartEndClicked()
{
    if( BlackJackScene_Button_StartEnd->text() == "Start\r\n50$" )
    {
        if( Account->Money < 50 )
        {
            BlackJackScene_Label_Money->setText("Too Poor, Poor You, QQ");
            return;
        }
        Account->Money -= 50;
        AccountManager->saveFile();
        if( BlackJackGame != nullptr )
            delete BlackJackGame;
        for(auto &i : BlackJackScene_PixmapItem_CardList)
            delete i;
        BlackJackScene_PixmapItem_CardList.clear();

        BlackJackGame = new BlackJack_t;

        BlackJackScene_Button_StartEnd->setText( "End" );
        BlackJackScene_Button_MoreCard->setEnabled(1);

        changetoBlackJackScene();
    }
    else
    {
        int player2_sum = 0;
        int cardcnt = 0;
        while( player2_sum < 14 )
        {
            QPair<int, char> card = BlackJackGame->giveCard( BlackJack_t::Player2 );
            player2_sum += card.first;
            QGraphicsPixmapItem* newItem = new QGraphicsPixmapItem( QPixmap( QString("./resources/images/pokers/") + QString::number(card.first) + "_" +  card.second + ".jpg") );
            newItem->setScale(0.3);
            newItem->setPos(20 + 100*cardcnt, 100);
            BlackJackScene_PixmapItem_CardList.push_back( newItem );
            BlackJackScene->addItem( newItem );
            cardcnt++;
        }
        int winner = BlackJackGame->judge();
        if(winner == 0)
            Account->Money += 50;
        else if( winner == BlackJack_t::Player1 )
            Account->Money += 100;
        AccountManager->saveFile();
        BlackJackScene_Button_StartEnd->setText( "Start\r\n50$" );
        BlackJackScene_Button_MoreCard->setEnabled(0);

        changetoBlackJackScene();
    }
}

void MenuDisplay_t::BlackJackScene_MoreCardClicked()
{
    if( BlackJackScene_PixmapItem_CardList.size() >= 5 )
        return;
    QPair<int, char> card = BlackJackGame->giveCard( BlackJack_t::Player1 );
    QGraphicsPixmapItem* newItem = new QGraphicsPixmapItem( QPixmap( QString("./resources/images/pokers/") + QString::number(card.first) + "_" +  card.second + ".jpg") );
    newItem->setScale(0.3);
    newItem->setPos(20 + 100*BlackJackScene_PixmapItem_CardList.size(), 400);
    BlackJackScene_PixmapItem_CardList.push_back( newItem );
    BlackJackScene->addItem( newItem );
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
