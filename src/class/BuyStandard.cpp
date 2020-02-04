#include "User.cpp"

using namespace std;

class BuyStandard : public User
{
private:
    /* data */
public:
    BuyStandard(/* args */)
    {
        userType = "BS";
    }
    ~BuyStandard();

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};