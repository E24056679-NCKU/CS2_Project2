#ifndef BLACKJACK_T_H
#define BLACKJACK_T_H

#include <QObject>
#include <QSet>
#include <QPair>

class BlackJack_t : public QObject
{
    Q_OBJECT

public:
    static const int Player1 = 1;
    static const int Player2 = 2;
    const char suit[4] = {'s', 'h', 'd', 'c'};
    BlackJack_t();
    QSet< QPair<int, char> > CardInDeck;
    QSet< QPair<int, char> > Player1Cards;
    QSet< QPair<int, char> > Player2Cards;

public slots:
    QPair<int, char> giveCard(int player);
    int judge();

signals:
    void gameover(int winner);
};

#endif // BLACKJACK_T_H
