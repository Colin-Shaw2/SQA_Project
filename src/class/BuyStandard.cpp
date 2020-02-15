/*********************************
* buystandard class is used to process *
* actions done by an buystandard user  *
*********************************/

#include "User.cpp"

using namespace std;

class BuyStandard : public User
{
private:
    /* data */
public:
    /*initializes user*/
    BuyStandard(string name, int accountBalance):User(name, accountBalance, "BS")
    {
    }
    ~BuyStandard();


    void addCredit(int amount){/*adds amount credit to current user*/};
    void advertise(){};//user is not allowed to advertise
    void bid(string itemName, string userName, int amount){
      /*bids amount on Item itemName*/
    };
    void createNewUser(){};//user is not allowed to create new users
    void deleteUser(){};//user is not allowed to delete users
    void refund(){};//user is not allowed to refund
};
