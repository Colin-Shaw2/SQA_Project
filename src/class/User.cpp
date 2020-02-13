//#pragma once
#include "TransactionEnums.h"
#include "TransactionCodeMaker.cpp"
#include "Item.cpp"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

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

    void addTransaction(transactionType type){
        switch(type)
        {
            case CREATE : cout << "CREATE"; // CREATE
                break;       // and exits the switch
            case DELETE : cout << "DELETE";
                break;
            case LOGOUT : cout << "LOGOUT"; // DELETE
                break;       // and exits the switch
            case ADD_CREDIT : cout << "ADD_CREDIT";
                break;
            case REFUND : cout << "REFUND"; // prints "1"
                break;       // and exits the switch
            case ADVERTISE : cout << "ADVERTISE";
                break;
            case BID : cout << "BID"; // prints "1"
                break;
        }
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
        addTransaction(LOGOUT);
        ofstream transactionFile;
        transactionFile.open ("../storage/transactions.txt");
        for(string code : transactions){
            transactionFile << code;
        }
        transactionFile.close();
        cout << "Logout successful!" << endl;
    }
};

