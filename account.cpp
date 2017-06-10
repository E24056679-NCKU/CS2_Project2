#include "account.h"
#include <fstream>
#include <string>
#include <QDebug>

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

    std::fstream fin;
    fin.open("./saves/account.txt", std::ios::in);

    std::string username;
    std::string password;
    int money;
    int card[6];
    while(fin >> username)
    {
        fin >> password;
        fin >> money;
        for(int i=0;i<6;++i)
            fin >> card[i];
        AccountList.insert( QString::fromStdString(username), new Account_t(QString::fromStdString(username), QString::fromStdString(password), money, card) );
    }

    for(auto &i : AccountList)
    {
        qDebug() << i->Username << i->Password;
    }
}

void AccountManager_t::saveFile()
{
    std::fstream fout;
    fout.open("./saves/account.txt", std::ios::out);
    for(auto &i : AccountList)
    {
        fout << i->Username.toStdString() << std::endl;
        fout << i->Password.toStdString() << std::endl;
        fout << i->Money << std::endl;
        for(int t=0;t<6;++t)
            fout << i->CardCount[t] << ' ';
        fout << std::endl << std::endl;
    }
}

void AccountManager_t::addAccount(Account_t account)
{
    Account_t* newAccount = new Account_t(account);
    AccountList.insert(account.Username, newAccount);
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

