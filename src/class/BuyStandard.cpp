/*********************************
* buystandard class is used to process *
* actions done by an buystandard user  *
* can do the following actions
* bid
* addcredit to self
*********************************/
#pragma once

#include "User.cpp"

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
    void addCredit(int amount){};

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
     * @param amount the amount to bid
     * @return void
     */
    void bid(string itemName, string username, int amount){};
    
    void createNewUser(string username, string userType, int credit){};//user is not allowed to create new users
    void deleteUser(string username){};//user is not allowed to delete users
    void refund(string buyerUsername, string sellerUsername, int amount){};//user is not allowed to refund
};
