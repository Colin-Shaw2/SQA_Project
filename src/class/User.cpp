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
    User(/* args */){

    }
    ~User();

    void addCredit() = 0;
    void advertise() = 0;
    void bid() = 0;
    void createNewUser() = 0;
    void deleteUser() = 0;
    void refund() = 0;
    void login()
    {
    }
    void logout()
    {
    }
};
}
