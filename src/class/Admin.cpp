/*********************************
* admin class is used to process *
* actions done by an admin user  *
* can do the following actions
* advertise
* bid
* create new user
* add credit to any user
* delete user
* refund a user
*********************************/
#pragma once
#include "User.cpp"
#include "TransactionCodeMaker.cpp"
#include <fstream>
#include <cmath>

using namespace std;

class Admin : public User
{
private:

public:
    //calls superconstructor with the AA as userType
    Admin(string name, int accountBalance):User(name, accountBalance, "AA")
    {
    }
    ~Admin();


    /**
     * addCredit is used to raise a user's accountBalance. Before raising the user's balance,
     * addCredit checks if the addition of amount to accountBalance is under 1,000,000.
     * If it's over 1,000,000, the attempt is rejected and a message is printed
     * If it's under 1,000,000, the amount is added to accountBalance
     * Writes to the users file
     *
     *
     * @param username  the username that the credit should be added to, this reference itself
     * @param amount    the amount of credit to be added
     * @return void
     */
    //TODO fix this
    void addCredit(int amount){
      int balance = getBalance();
      balance += amount;
      //setBalance(balance);
      setMaxCredit(amount);
      transactions.push_back(TransactionCodeMaker::makeAddCredit(username, userType, balance));
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
    void advertise(string itemName, int minimumBid, int daysToBid){
      transactions.push_back(TransactionCodeMaker::makeAdvertise(username, daysToBid, itemName, minimumBid));
    };

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
    void bid(string itemName, string sellerName, int currentBid, int bid){
      int itemBid = currentBid;
      itemBid += ceil(itemBid * 0.05);
      if(bid < itemBid){
        cout << "Bid too small" << endl;
        return;
      }
      else if(getBalance() < bid){
        cout << "Insufficient Funds" << endl;
        return;
      }else{
        transactions.push_back(TransactionCodeMaker::makeBid(username, sellerName, itemName, bid));
        cout << "Bid Successful!" << endl;
      }
      //setBalance(getBalance() - bid);
      transactions.push_back(TransactionCodeMaker::makeBid(username, sellerName, itemName, bid));
    };
    /**
     * createNewUser is called to create a new User.
     * Writes to the users file
     *
     * @param username name of new user
     * @param userType the privledge level of the new user
     * @param credit the starting credit of the user
     *
     * @return void
     */
    void createNewUser(string username, string userType, int credit){
      transactions.push_back(TransactionCodeMaker::makeCreate(username, userType, credit));
    };

    /**
     * deleteUser is called to delete an existing User.
     *
     * Once the user has been deleted, there will
     * be a successful message
     * Reads the users file
     *
     * @param username the username of the user to be deleted
     * @return void
     */
    void deleteUser(string delusername, string userFileName){
      string deluserType;
      int delbalance;

      //buffer username
      for (int i = delusername.length(); i < 15; i++)
      {
        delusername += " ";
      }

      string inString;
      fstream userFile;

      userFile.open(userFileName);

      // read file line by line
      while (getline(userFile, inString))
      {
        if (inString.substr(0, 15) == delusername)
        {
          deluserType = inString.substr(16, 2);
          delbalance = stoi(inString.substr(19, 9));
          break;
        }
      }
      userFile.close();
      transactions.push_back(TransactionCodeMaker::makeDelete(delusername, deluserType, delbalance));
    };

    /**
     * refund is called to refund an amount from one user to another.
     *
     * Before issuing the refund, this method checks if the seller has
     * sufficient funds for the amount to be removed from his accountBalance,
     * and if the buyer's accountBalance does not go over the limit if the
     * refund of amount is issued.
     * Writes to the users file
     *
     * @param buyerUsername     the username of the buyer
     * @param sellerUsername    the username of the seller
     * @param amount            the amount to transfer from seller to buyer
     * @return void
     */
    void refund(string buyerUsername, string sellerUsername, int amount, string userFileName){
      //buffer username
      for (int i = sellerUsername.length(); i < 15; i++)
      {
        sellerUsername += " ";
      }

      string inString;
      fstream userFile;
      int sellerBalance;

      userFile.open(userFileName);

      // read file line by line
      while (getline(userFile, inString))
      {
        if (inString.substr(0, 15) == sellerUsername)
        {
          sellerBalance = stoi(inString.substr(19, 9));
          break;
        }
      }
      userFile.close();
      transactions.push_back(TransactionCodeMaker::makeRefund(buyerUsername, sellerUsername, amount));
    };
};
