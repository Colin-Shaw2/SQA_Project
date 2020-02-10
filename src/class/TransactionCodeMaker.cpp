#include <string>
#include "TransactionEnums.h"
#include "User.cpp"

using namespace std;

class TransactionCodeMaker
{
private:
    /* data */
    void sorter(User user, TransactionType tranType);

public:
    TransactionCodeMaker(/* args */);
    ~TransactionCodeMaker();
    void makeCreate(User createdUser);
    void makeDelete(User deletedUser);
    void makeLogout(User currentUser);
    void makeAddCredit(User addedUser);
    void makeRefund(User buyer, User seller);
    void makeCreate(Item item, User seller);
    void makeBid(Item item, User seller, User buyer);
};

TransactionCodeMaker::TransactionCodeMaker(/* args */)
{
}

TransactionCodeMaker::~TransactionCodeMaker()
{
}

makeCreate(User createdUser){
/**/
}
