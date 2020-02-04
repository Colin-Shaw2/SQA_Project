#include "User.cpp"

using namespace std;

class SellStandard : public User
{
private:
    /* data */
public:
    SellStandard(/* args */)
    {
        userType = "SS";
    }

    ~SellStandard();

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};
}
