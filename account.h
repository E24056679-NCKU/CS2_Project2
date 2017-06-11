#ifndef ACCOUNT_T_H
#define ACCOUNT_T_H

#include <QString>
#include <QMap>

class Account_t
{
public:
    Account_t(QString Username, QString Password, int Money, int CardCount[]);

    QString Username;
    QString Password;
    int Money;
    int CardCount[6];
};

class AccountManager_t
{
public:
    AccountManager_t();
    ~AccountManager_t();
    void loadFile();
    void saveFile();
    void addAccount(Account_t account);
    Account_t* selectAccount(QString username);

    QMap<QString, Account_t*> AccountList;

};

#endif // ACCOUNT_T_H
