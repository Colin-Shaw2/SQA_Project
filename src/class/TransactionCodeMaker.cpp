/***********************


************/
#pragma once
#include <string>
#include "TransactionEnums.h"

using namespace std;

class TransactionCodeMaker
{
private:
    /* data */
    //void sorter(User &user, transactionType tranType);

public:
    TransactionCodeMaker(/* args */);
    ~TransactionCodeMaker();

    void makeCreate(string username, string userType, int availableCredit);
    void makeDelete(string username, string userType, int availableCredit);
    void makeLogout(string username, string userType, int availableCredit);
    void makeAddCredit(string username, string userType, int availableCredit);
    void makeRefund(string buyerUsername, string sellerUsername, string userType, int availableCredit);
    void makeBid(string buyerUsername, string sellerUsername, string itemName, int bid);
    void makeAdvertise(string buyerUsername, string sellerUsername, string itemName, int minimumBid);
};
