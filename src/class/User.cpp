#include <string>
#include <vector>
#include "Item.cpp"
#include "TransactionCodeMaker.cpp"
#include "TransactionEnums.h"

using namespace std;

class User
{
protected:
    /* data */
    string userName;
    int balance;
    vector<Item> items;
    vector<string> transactions;
    string userType;

    void addTransaction(TransactionType tranType);

public:
    User(/* args */);
    ~User();

    void addCredit();
    void advertise();
    void bid();
    void createNewUser();
    void deleteUser();
    void login();
    void logout();
    void refund();

};

User::User(/* args */)
{
}

User::~User()
{
}
