#include "blackjack.h"
#include <QtGlobal>
#include <QTime>

BlackJack_t::BlackJack_t()
{
    qsrand( QTime::currentTime().msec() );
    for(int i=1;i<=13;++i)
    {
        for(int j=0;j<4;++j)
        {
            CardInDeck.insert( qMakePair(i, suit[j]) );
        }
    }
}

QPair<int, char> BlackJack_t::giveCard(int player)
{
    int give = qrand() % CardInDeck.size();
    auto it = CardInDeck.begin();
    for( ; it != CardInDeck.end() && give ; ++it, --give)
            ;
    QPair<int, char> card = *it;
    CardInDeck.erase(it);

    if(player == Player1)
    {
        Player1Cards.insert( card );
    }
    else
    {
        Player2Cards.insert( card );
    }
    return card;
}

int BlackJack_t::judge()
{
    int sum1 = 0, sum2 = 0;
    for(auto &i : Player1Cards)
    {
        sum1 += i.first;
    }

    for(auto &i : Player2Cards)
    {
        sum2 += i.first;
    }

    if(sum1 > 21)
        return Player2;
    else if(sum2 > 21)
        return Player1;

    if(sum1 > sum2)
    {
        emit gameover(Player1);
        return Player1;
    }
    else if(sum1 < sum2)
    {
        emit gameover(Player2);
        return Player2;
    }
    else
    {
        emit gameover(0);
        return 0;
    }
}
