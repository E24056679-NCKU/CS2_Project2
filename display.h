#ifndef DISPLAY_H
#define DISPLAY_H

#include <cmath>
#include <algorithm>
#include <complex>
#include <QObject>
#include <QSet>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include "account.h"
#include "animation.h"
#include "controller.h"
#include "life.h"
#include "minion.h"
#include "miscellaneous.h"

// Button at the downside of screen
class Button_t : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button_t(int _ID);
    ~Button_t();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void selectedByMouse(int ID);

private:
    int ID;

};


// for BlackScreen and overriding mousePressEvent
class MyQGraphicsScene : public QGraphicsScene
{
    friend class System;
    Q_OBJECT
public:
    MyQGraphicsScene();
    ~MyQGraphicsScene();

public slots:
    // rendering the BlackScreen(QImage) and update PixmapItem
    void updateBlackScreen();
    // !! Source's x and y must be floored
    // void renderFlashlightEffect(QImage &Image, QPointF Source, double Light_Theta, int R, double Rotate_Theta);

signals:
    void positionSelected(QPointF Position);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    QImage* BlackScreen;
    QGraphicsPixmapItem* BlackScreenItem;
    QTimer* Timer; // for updating BlackScreen
    const static int Hz = 20; // frequecy for updating BlackScreen, i.e., run updateBlackScreen()
};

// for all menu
class MenuDisplay_t : public QObject
{
    friend class Display_t;
    Q_OBJECT
public:
    MenuDisplay_t(QGraphicsView* ParentView);
    ~MenuDisplay_t();

    QGraphicsView* ParentView;
    AccountManager_t* AccountManager;
    Account_t* Account;

    QGraphicsScene* GameOverScene;

    QGraphicsScene* LoginScene;
    QPushButton* LoginScene_Button_Submit;
    QPushButton* LoginScene_Button_Create;
    QPushButton* LoginScene_Button_Rank;
    QTextEdit* LoginScene_Input_Account;
    QTextEdit* LoginScene_Input_Password;
    QLabel* LoginScene_Label;


    QGraphicsScene* RankScene;
    QPushButton* RankScene_Button_LoginScene;


    QGraphicsScene* CardManageScene;
    QPushButton* CardManageScene_Button_BuyCard;
    QPushButton* CardManageScene_Button_Card[6];
    QLabel* CardManageScene_Label_Card[6];
    QGraphicsPixmapItem* CardManageScene_PixmapItem_Card[6];
    QPushButton* CardManageScene_Button_Submit;
    QLabel* CardManageScene_Label;


    QGraphicsScene* CardBuyScene;
    QPushButton* CardBuyScene_Button_CardManageScene;
    QLabel* CardBuyScene_Label_Money;
    QPushButton* CardBuyScene_Button_Card[6];
    QPushButton* CardBuyScene_Button_DrawCard;
    QPushButton* CardBuyScene_Button_Combine;
    QPushButton* CardBuyScene_Button_Trade;
    QLabel* CardBuyScene_Label_Status;
    QLabel* CardBuyScene_Label_CardCount[6];
    QPushButton* CardBuyScene_Button_BlackJack;


    QGraphicsScene* BlackJackScene;


    void setupLoginScene();
    void setupCardManageScene();
    void setupCardBuyScene();
    void setupGameOverScene();
    void setupRankScene();
    void setupBlackJackScene();

public slots:
    void changetoLoginScene();
    void LoginScene_SubmitClicked();
    void LoginScene_CreateClicked();
    void LoginScene_RankClicked();


    void changetoRankScene();
    void RankScene_LoginSceneClicked();


    void changetoCardManageScene();
    void CardManageScene_BuyClicked();
    void CardManageScene_SubmitClicked();
    void CardManageScene_Choose0Clicked();
    void CardManageScene_Choose1Clicked();
    void CardManageScene_Choose2Clicked();
    void CardManageScene_Choose3Clicked();
    void CardManageScene_Choose4Clicked();
    void CardManageScene_Choose5Clicked();


    void changetoCardBuyScene();
    void CardBuyScene_CardManageSceneClicked();
    void CardBuyScene_DrawCardClicked();
    void CardBuyScene_CombineClicked();
    void CardBuyScene_Choose0Clicked();
    void CardBuyScene_Choose1Clicked();
    void CardBuyScene_Choose2Clicked();
    void CardBuyScene_Choose3Clicked();
    void CardBuyScene_Choose4Clicked();
    void CardBuyScene_Choose5Clicked();
    void CardBuyScene_BlackJackClicked();


    void changetoGameOverScene();


    void changetoBlackJackScene();

signals:
    void setupCompleted();
    void accountLogined(Account_t*);
};

class Display_t
{
    friend class System;
public:
    Display_t();
    virtual ~Display_t();

    void setupGameScene();

    void changetoGameScene();
    void changetoLoginScene();
    void changetoCardManageScene();
    void changetoGameOverScene();

    void addItem(QGraphicsItem* Item);
    void removeItem(QGraphicsItem* Item);

    void addAnimation(QPointF center, int period, QList<QString> &pathList);

protected:
    MyQGraphicsScene* Scene; // GameScene
    QGraphicsView* View;
    Button_t* Button[4]; // GameButton
    MenuDisplay_t* MenuDisplay;

private:


};


// ControllableDisplay is like a touchscreen, it's an output source and also a input source
class ControllableDisplay_t : public ControllerSlot_t, public Display_t // ControllerSlot_t (which is a QObject) must be inherited first
{
    Q_OBJECT
public:
    ControllableDisplay_t();
    ~ControllableDisplay_t();

public slots:
    void minionSelected(Minion_t* selMinion);
    void positionSelected(QPointF Position);

protected:

private:

};

#endif // DISPLAY_H
