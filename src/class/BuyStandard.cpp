#include "User.cpp"

using namespace std;

class BuyStandard : public User
{
private:
    /* data */
public:
    BuyStandard(string name, int accountBalance):User(name, accountBalance, "BS")
    {
    }
    ~BuyStandard();

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};