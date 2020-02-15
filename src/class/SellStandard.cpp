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

    void addCredit(int amount){/*adds amount credit to current user*/};
    void advertise(string itemName, int minimumBid, int daysToBid){
      /*advertises Item itemName*/
    };
    void bid(){};//user is not allowed to bid
    void createNewUser(){};//user is not allowed to create new users
    void deleteUser(){};//user is not allowed to delete users
    void refund(){};//user is not allowed to refund
};
