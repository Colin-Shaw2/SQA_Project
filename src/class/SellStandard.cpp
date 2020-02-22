/*********************************
* sellstandard class is used to process *
* actions done by an sellstandard user  *
* can do the following actions
* advertise
* add credit to self
*********************************/
#pragma once

#include "User.cpp"

using namespace std;

class SellStandard : public User
{
private:
public:
    SellStandard(string name, int accountBalance):User(name, accountBalance, "SS"){
    }

    ~SellStandard();


    //overrides the abstract function in user
    //username does nothing simply calls addCredit(int)
    void addCredit(string username, int amount){
        addCredit(amount);
    };

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
      if (balance + amount < 1000000){
        balance+= amount;
        setBalance(balance);
        cout << "Credit added, Balance is $" << balance << endl;
      }
      else{
        cout << "Error Balance would be too high max value($999999.99)"<<endl;
      }
    };

    /**
     * advertise is called to put up a new item.
     *
     * advertise will create a new Item output a successful message
     * Writes to the items file
     *
     * @param itemName      name of item to be sold
     * @param minimumBid    minimum bid on item
     * @param daysToBid     days to bid
     * @return void
     */
    void advertise(string itemName, int minimumBid, int daysToBid){};

    void bid(string itemName, string username, int amount){};//user is not allowed to bid

    void createNewUser(string username, string userType, int credit){};//user is not allowed to create new users
    void deleteUser(string username){};//user is not allowed to delete users
    void refund(string buyerUsername, string sellerUsername, int amount){};//user is not allowed to refund
};
