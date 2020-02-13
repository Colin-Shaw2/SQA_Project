#pragma once
#include <string>
using namespace std;

class Item
{
private:
    /* data */
    int minimumBid;
    int daysToBid;
    int currentBid;
    string topBidder;
    string seller;
public:
    Item(/* args */);
    ~Item();
};
