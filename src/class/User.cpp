//#pragma once
#include "TransactionEnums.h"
#include "TransactionCodeMaker.cpp"
#include "Item.cpp"

#include <string>
#include <vector>

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

    void addTransaction(transactionType transactiontype){
     //    case CREATE : cout << '1'; // CREATE
     //         break;       // and exits the switch
     //    case DELETE : cout << '2';
     //         break;
     //    case LOGOUT : cout << '1'; // DELETE
     //         break;       // and exits the switch
     //    case ADD_CREDIT : cout << '2';
     //         break;
     //    case REFUND : cout << '1'; // prints "1"
     //         break;       // and exits the switch
     //    case ADVERTISE : cout << '2';
     //         break;
     //    case BID : cout << '1'; // prints "1"
     //         break;
    }

public:
    User(string name, int accountBalance, string type){
        this->userName = name;
        this->balance = accountBalance;
        this->userType = type;
    }
    ~User();

    virtual void addCredit() = 0;
    virtual void advertise() = 0;
    virtual void bid() = 0;
    virtual void createNewUser() = 0;
    virtual void deleteUser() = 0;
    virtual void refund() = 0;
    /**
     * logouts the current user
     * writes all transactions in the transactions array to transactions.txt
     * 
     * @return void
     */
    //TODO reaxamine this method once min is done
    void logout()
    {  
     //    addTransaction(LOGOUT);
     //    ofstream transactionFile;
     //    transactionFile.open ("transactions.txt");
     //    transactionFile << transactions;
     //    transactionFile.close();
     //    cout << "Logout successful!" << endl;
    }
};

