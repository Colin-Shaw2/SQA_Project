/*
This is an abstract class with all non privileged methods implemented

User class writes all transactions to items.txt, users.txt and/or transactions.txt
*/
#pragma once
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
    string username;
    int balance;
    vector<Item> items;// list of items the user has changed
    vector<string> transactions;
    string userType;


    /**
     * Calls the transactionCodeMaker to create a transaction code and adds
     * it to the transactions array
     *
     * @param   type an enum representing the type of stransaction that just happened
     * @return  void
     */
    //TODO Method needs review
    void addTransaction(transactionType type){
        string code = "";
        switch(type)
        {
            case CREATE : code = TransactionCodeMaker::makeCreate(username, userType, balance);
                break;
            case DELETE : code = TransactionCodeMaker::makeDelete(username, userType, balance);
                break;
            case LOGOUT : code = TransactionCodeMaker::makeLogout(username, userType, balance);
                break;
            case ADD_CREDIT : code = TransactionCodeMaker::makeAddCredit(username, userType, balance);
                break;
            case REFUND : code = TransactionCodeMaker::makeRefund(username,"refunder", 0 /*refundamount*/);
                break;
            case ADVERTISE : code = TransactionCodeMaker::makeAdvertise(username, 0/*daysToAuction*/ , "Itemname", balance);
                break;
            case BID : code = TransactionCodeMaker::makeBid(username, "sellerName", "ItemName", /*Bid*/ 0);
                break;
        }
        transactions.push_back(code);
    }

public:
    /**
     * Creates a user with a name, type and initial account balance
     *
     * @param name
     * @param accountBalance
     * @param type
     */
    User(string name, int accountBalance, string type){
        this->username = name;
        this->balance = accountBalance;
        this->userType = type;
    }
    ~User();

    int getBalance(){return balance;}

    virtual void addCredit(string username, int amount) = 0;
    virtual void advertise(string itemName, int minimumBid, int daysToBid) = 0;
    virtual void bid(string itemName, string username, int amount) = 0;
    virtual void createNewUser(string username, string userType, int credit) = 0;
    virtual void deleteUser(string username) = 0;
    virtual void refund(string buyerUsername, string sellerUsername, int amount) = 0;

    /**
     * logouts the current user
     * writes all transactions in the transactions array to transactions.txt
     * writes and overites all items in the items array to items.txt
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
        //TODO write to items.txt
    }
};
