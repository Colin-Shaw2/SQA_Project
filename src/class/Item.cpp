#include "User.cpp"

using namespace std;

class Item
{
private:
    /* data */
    int minimumBid;
    int daysToBid;
    int currentBid;
    User topBidder;
    User seller;
public:
    Item(/* args */);
    ~Item();
};

Item::Item(/* args */)
{
}

Item::~Item()
{
}
