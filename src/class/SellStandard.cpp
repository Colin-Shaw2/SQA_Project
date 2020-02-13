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

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};
