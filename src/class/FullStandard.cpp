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

    void addCredit(int amount){};
    void advertise(string itemName, int minimumBid, int daysToBid){
      /*advertises Item itemName*/
    };
    void bid(string itemName, string userName, int amount){
      /*bids amount on Item itemName*/
    };
    void createNewUser(){};//user is not allowed to create new users
    void deleteUser(){};//user is not allowed to delete users
    void refund(){};//user is not allowed to refund
};
