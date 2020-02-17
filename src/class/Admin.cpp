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

    /*
     * addCreditAdmin is used to raise another User's accountBalance.
     * The parameters for addCreditAdmin are string userName and int amount.
     * Before raising the User's balance, addCredit checks if the addition of
     * amount to accountBalance is under 1,000,000.
     * If it's over 1,000,000, the attempt is rejected and a message is printed
     * If it's under 1,000,000, the amount is added to accountBalance
     *
     * @return void
     */
    void addCreditAdmin(string userName, int amount){};

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

    /*
     * createNewUser is called to create a new User. The parameters for
     * createNewUser are string userName, string userType, and int credit
     *
     *
     * @return void
     */
    void createNewUser(string userName, string userType, int credit){};

    /*
     * deleteUser is called to delete an existing User. The parameter for this
     * method is string userName. Once the user has been deleted, there will
     * be a successful message
     *
     * @return void
     */
    void deleteUser(string userName){};

    /*
     * refund is called to refund an amount from one user to another. The
     * parameters for refund are string buyerUserName, string sellerUsername,
     * and int amount.
     * Before issuing the refund, this method checks if the seller has
     * sufficient funds for the amount to be removed from his accountBalance,
     * and if the buyer's accountBalance does not go over the limit if the
     * refund of amount is issued.
     *
     * @return void
     */
    void refund(string buyerUsername, string sellerUsername, int amount){};
};
