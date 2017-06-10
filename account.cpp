#include "account.h"
#include <QDebug>
#include<QFile>
#include<QString>

Account_t::Account_t(QString Username, QString Password, int Money, int CardCount[])
{
    this->Username = Username;
    this->Password = Password;
    this->Money = Money;
    for(int i=0;i<6;++i)
        this->CardCount[i] = CardCount[i];
}

AccountManager_t::AccountManager_t()
{
    this->loadFile();
}

AccountManager_t::~AccountManager_t()
{
    this->saveFile();
}

void AccountManager_t::loadFile()
{
    AccountList.clear();

    QFile fin("./saves/account.txt");
    fin.open(QIODevice::ReadWrite);
    QTextStream in(&fin);

    QString username;
    QString password;
    int money;
    int card[6];
    while(!in.atEnd())
    {
        in >> username;
        in >> password;
        if(username == "")
            break;
        in >> money;
        for(int i=0;i<6;++i)
            in >> card[i];
        AccountList.insert( username, new Account_t(username, password, money, card) );
    }

    for(auto &i : AccountList)
    {
        qDebug() << i->Username << i->Password;
    }
}

void AccountManager_t::saveFile()
{
    QFile fout("./saves/account.txt");
    fout.open(QIODevice::ReadWrite);
    QTextStream out(&fout);
    for(auto &i : AccountList)
    {
        out << i->Username << "\n";
        out << i->Password << "\n";
        out << i->Money << "\n";
        for(int t=0;t<6;++t)
           out << i->CardCount[t] << ' ';
        out << "\n" << "\n";
    }
    out.flush();
}

void AccountManager_t::addAccount(Account_t account)
{
    Account_t* newAccount = new Account_t(account);
    AccountList.insert(newAccount->Username, newAccount);
    this->saveFile();
}

Account_t* AccountManager_t::selectAccount(QString username)
{
    QMap<QString, Account_t*>::iterator res = this->AccountList.find(username);
    if( res == this->AccountList.end() )
        return nullptr;
    else
        return res.value();
}
