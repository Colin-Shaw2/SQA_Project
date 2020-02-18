/*********************************
* fullstandard class is used to process *
* actions done by an fullstandard user  *
*********************************/

#include "User.cpp"

using namespace std;

class SellStandard : public User
{
private:
    /* data */
public:
    SellStandard(string name, int accountBalance):User(name, accountBalance, "SS"){
    }

    ~SellStandard();


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

    void bid(){};//user is not allowed to bid
    void createNewUser(){};//user is not allowed to create new users
    void deleteUser(){};//user is not allowed to delete users
    void refund(){};//user is not allowed to refund
};
