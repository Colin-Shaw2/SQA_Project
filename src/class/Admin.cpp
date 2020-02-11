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

    void addCredit(){
    };
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};
