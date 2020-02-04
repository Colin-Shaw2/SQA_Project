#include "User.cpp"

using namespace std;

class FullStandard : public User
{
private:
    /* data */
public:
    FullStandard(/* args */)
    {
        userType = "FS";
    }

    ~FullStandard();

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};
