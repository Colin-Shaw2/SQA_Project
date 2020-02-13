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

    static string makeCreate(string username, string userType, int availableCredit);
    static string makeDelete(string username, string userType, int availableCredit);
    static string makeLogout(string username, string userType, int availableCredit);
    static string makeAddCredit(string username, string userType, int availableCredit);
    static string makeRefund(string buyerUsername, string sellerUsername, string userType, int availableCredit);
    static string makeBid(string buyerUsername, string sellerUsername, string itemName, int bid);
    static string makeAdvertise(string buyerUsername, int daysToAuction, string itemName, int minimumBid);
};
