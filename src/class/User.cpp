/*
This is an abstract class with all non privileged methods implemented

User class writes all transactions to items.txt, users.txt and/or transactions.txt
*/
#pragma once
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
    vector<string> transactions;
    string userType;


    /**
     * Calls the transactionCodeMaker to create a transaction code and adds
     * it to the transactions array
     *
     * @param   type an enum representing the type of stransaction that just happened
     * @return  void
     */
    // void addTransaction(transactionType type){
    //     string code = "";
    //     switch(type)
    //     {
    //         case CREATE : code = TransactionCodeMaker::makeCreate(username, userType, balance);
    //             break;
    //         case DELETE : code = TransactionCodeMaker::makeDelete(username, userType, balance);
    //             break;
    //         case LOGOUT : code = TransactionCodeMaker::makeLogout(username, userType, balance);
    //             break;
    //         case ADD_CREDIT : code = TransactionCodeMaker::makeAddCredit(username, userType, balance);
    //             break;
    //         case REFUND : code = TransactionCodeMaker::makeRefund(username,"refunder", refundAmount);
    //             break;
    //         case ADVERTISE : code = TransactionCodeMaker::makeAdvertise(username, 0/*daysToAuction*/ , "Itemname", balance);
    //             break;
    //         case BID : code = TransactionCodeMaker::makeBid(username, "sellerName", "ItemName", /*Bid*/ 0);
    //             break;
    //     }
    //     transactions.push_back(code);
    // }

public:
    vector<string> accountsAddedTo;
    vector<int> amountAdded;
    int refundAmount;
    string sellerUserName;
    string buyerUserName;
    string itemName;
    int daysToAuction;
    int minimumBid;
    int newBid;
    string ownerItem;
    int bidItem, daysItem;
    int maxCredit;
    string test1, test2;
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
        this->maxCredit = 0;
    }
    ~User();

    string getName(){return this->username;}
    int getBalance(){return this->balance;}
    //void setBalance(int balance){this->balance = balance;}
    int getMaxCredit(){return this->maxCredit;}
    void setMaxCredit(int credit){this->maxCredit += credit;}
    string getUserType(){return this->userType;}
    string getType(string userType){
      if(userType == "AA"){
        return "Admin";
      }
      if(userType == "FS"){
        return "Full Standard";
      }
      if(userType == "BS"){
        return "Buy Standard";
      }
      if(userType == "SS"){
        return "Sell Standard";
      }
      else{
        return "NULL";
      }
    }
    void setRefund(string sellerUserName,string buyerUsername,int refund){
      this->sellerUserName = sellerUserName;
      this->buyerUserName = buyerUsername;
      this->refundAmount = refund;
    }
    void setAdvertise(string itemName, int daysToAuction, int minimumBid){
      this->itemName = itemName;
      this->daysToAuction = daysToAuction;
      this->minimumBid = minimumBid;
    }
    void setBid(string itemName, string selleUserName, int newBid){
      this->itemName = itemName;
      this->sellerUserName = sellerUserName;
      this->newBid = newBid;
    }

    Item *getItem(string itemName, string itemFileName){
      //buffer username
      for (int i = itemName.length(); i < 25; i++)
      {
        itemName += " ";
      }

      string inString;
      fstream itemFile;

      itemFile.open(itemFileName);

      // read file line by line
      while (getline(itemFile, inString))
      {
        if (inString.substr(0, 25) == itemName)
        {
          ownerItem = inString.substr(26, 15);
          daysItem = stoi(inString.substr(58, 3));
          bidItem = stoi(inString.substr(62, 6));
        }
      }
      itemFile.close();
      return new Item(itemName, daysItem, bidItem, ownerItem);
    }

    string getTransactions(){return this->transactions.back();}
    void setTransactions(string otherTransactions){
      this->transactions.push_back(otherTransactions);
    }
    virtual void addCredit(int amount) = 0;
    virtual void advertise(string itemName, int minimumBid, int daysToBid) = 0;
    virtual void bid(string itemName, string username, int currentBid, int amount) = 0;
    virtual void createNewUser(string username, string userType, int credit) = 0;
    virtual void deleteUser(string username, string UserFileName) = 0;
    virtual void refund(string buyerUsername, string sellerUserName, int amount, string UserFileName) = 0;

    /**
     * logouts the current user
     * writes all transactions in the transactions array to transactions.txt
     *
     * @return void
     */
    void logout(string outputFileName)
    {
      transactions.push_back(TransactionCodeMaker::makeLogout(username, userType, balance));
      ofstream transactionFile;
      transactionFile.open (outputFileName);
      for(string code : transactions){
          transactionFile << code;
          transactionFile << "\n";
      }

      transactionFile.close();
      cout << "Logout successful!" << endl;
    }
};
