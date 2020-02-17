/*********************************
* admin class is used to process *
* actions done by an admin user  *
*********************************/
#include "User.cpp"

using namespace std;

class Admin : public User
{
private:
    /* data */
public:
    Admin(string name, int accountBalance):User(name, accountBalance, "AA")
    {
    }
    ~Admin();


    /*
     * addCredit is used to raise User's accountBalance. The parameter for
     * addCredit is int amount. Before raising User's balance, addCredit
     * checks if the addition of amount to accountBalance is under 1,000,000.
     * If it's over 1,000,000, the attempt is rejected and a message is printed
     * If it's under 1,000,000, the amount is added to accountBalance
     *
     * @return void
     */
    void addCredit(int amount){};


    void addCreditAdmin(string userName, int amount){};
    void advertise(string itemName, int minimumBid, int daysToBid){};

    /*
     * bid is called to raise the current bid on an item. The parameter
     * for bid is string itemName, string userName, and int amount
     * Before raising currentBid, bid checks if amount is 5% higher than the
     * last bid, and that the new bid, does not take the current bid above the
     * limit. It also checks if the current user has sufficient funds
     * If all goes through, bid will raise the currentBid on the item
     * Otherwise, the attempt will be rejected and a message is printed
     *
     * @return void
     */
    void bid(string itemName, string userName, int amount){};

    void createNewUser(string userName, string userType, int credit){};
    void deleteUser(string userName){};
    void refund(string buyerUsername, string sellerUsername, int amount){};
};
