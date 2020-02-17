/*********************************
* fullstandard class is used to process *
* actions done by an fullstandard user  *
*********************************/

#include "User.cpp"

using namespace std;

class FullStandard : public User
{
private:
    /* data */
public:
    /*initializes user*/
    FullStandard(string name, int accountBalance):User(name, accountBalance, "FS")
    {
    }

    ~FullStandard();


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

    /*
     * advertise is called to put up a new item. The parameters for advertise
     * are string itemName, int minimumBid, and int daysToBid.
     * advertise will create a new Item and and output a successful message
     *
     * @return void
     */
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

    void createNewUser(){};//user is not allowed to create new users
    void deleteUser(){};//user is not allowed to delete users
    void refund(){};//user is not allowed to refund
};
