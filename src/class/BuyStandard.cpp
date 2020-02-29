/*********************************
* buystandard class is used to process *
* actions done by an buystandard user  *
* can do the following actions
* bid
* addcredit to self
*********************************/
#pragma once

#include "User.cpp"
#include <cmath>

using namespace std;

class BuyStandard : public User
{
private:

public:
    //calls superconstructor with the BS as userType
    BuyStandard(string name, int accountBalance):User(name, accountBalance, "BS")
    {
    }
    ~BuyStandard();

    /**
     * addCredit is used to raise this user's accountBalance. Before raising this user's balance,
     * addCredit checks if the addition of amount to accountBalance is under 1,000,000.
     * If it's over 1,000,000, the attempt is rejected and a message is printed
     * If it's under 1,000,000, the amount is added to accountBalance
     * Writes to the users file
     *
     * @param amount    the amount of credit to be added
     * @return void
     */
    void addCredit(int amount){
      int balance = getBalance();
      balance += amount;
      //setBalance(balance);
      setMaxCredit(amount);
      transactions.push_back(TransactionCodeMaker::makeAddCredit(username, userType, balance));
    };

    void advertise(string itemName, int minimumBid, int daysToBid){};//user is not allowed to advertise

    /**
     * bid is called to raise the current bid on an item.
     *
     * Before raising currentBid, bid checks if amount is 5% higher than the
     * last bid, and that the new bid, does not take the current bid above the
     * limit. It also checks if the current user has sufficient funds
     * If all goes through, bid will raise the currentBid on the item
     * Otherwise, the attempt will be rejected and a message is printed
     * Writes to the items file
     *
     * @param itemName the name of the item
     * @param username the user selling the item
     * @param amount   the amount to bid
     * @param item      
     * @return void
     */
    void bid(string itemName, string sellerName, int currentBid, int bid){
      int itemBid = currentBid;
      itemBid += ceil(itemBid * 0.05);
      if(bid < itemBid){
        cout << "Bid too small" << endl;
        return;
      }
      else if(getBalance() < itemBid){
        cout << "Insufficient funds" << endl;
        return;
      }else{
        //setBalance(getBalance() - bid);
        transactions.push_back(TransactionCodeMaker::makeBid(username, sellerName, itemName, bid));
        cout << "Bid Successful!" << endl;
      }
    };


    void createNewUser(string username, string userType, int credit){};//user is not allowed to create new users
    void deleteUser(string username, string UserFileName){};//user is not allowed to delete users
    void refund(string buyerUsername, string sellerUsername, int amount, string UserFileName){};//user is not allowed to refund
};
