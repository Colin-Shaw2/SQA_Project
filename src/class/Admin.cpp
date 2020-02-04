#include "User.cpp"

using namespace std;

class Admin : public User
{
private:
    /* data */
public:
    Admin(/* args */)
    {
        userType = "AA";
    };
    ~Admin();

    void addCredit(){};
    void advertise(){};
    void bid(){};
    void createNewUser(){};
    void deleteUser(){};
    void refund(){};
};
