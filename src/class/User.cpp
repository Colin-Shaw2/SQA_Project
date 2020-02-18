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


    /**
     * Calls the transactionCodeMaker to create a transaction code and adds
     * it to the transactions array
     *
     *
     * @return void
     */
    //TODO Method needs review
    void addTransaction(transactionType type){
        string code = "";
        switch(type)
        {
            case CREATE : code = TransactionCodeMaker::makeCreate(userName, userType, balance);
                break;
            case DELETE : code = TransactionCodeMaker::makeDelete(userName, userType, balance);
                break;
            case LOGOUT : code = TransactionCodeMaker::makeLogout(userName, userType, balance);
                break;
            case ADD_CREDIT : code = TransactionCodeMaker::makeAddCredit(userName, userType, balance);
                break;
            case REFUND : code = TransactionCodeMaker::makeRefund(userName,"refunder", 0 /*refundamount*/);
                break;
            case ADVERTISE : code = TransactionCodeMaker::makeAdvertise(userName, 0/*daysToAuction*/ , "Itemname", balance);
                break;
            case BID : code = TransactionCodeMaker::makeBid(userName, "sellerName", "ItemName", /*Bid*/ 0);
                break;
        }
        transactions.push_back(code);
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
