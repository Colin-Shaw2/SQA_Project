#include "User.cpp"

using namespace std;

class FullStandard : public User
{
private:
    /* data */
public:
    FullStandard(string name, int accountBalance):User(name, accountBalance, "FS")
    {
    }

    ~FullStandard();

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};
