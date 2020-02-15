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

    void addCredit(string userName, string amount){
      /*adds amount credit to User userName*/
    }
    void advertise(string itemName, int minimumBid, int daysToBid){
      /*advertises Item itemName*/
    }
    void bid(string itemName, string userName, int amount){
      /*places amount bid on itemName*/
    }
    void createNewUser(string userName, string userType, int amount){
      /*creates User userName is a userType and has accountBalance amount*/
    }
    void deleteUser(string userName){/*deletes User userName*/};
    void refund(string buyerUsername, string sellerUsername, int amount){
      /*refunds amount from sellerUsername to buyerUsername*/
    }
};
