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
    const string seller;

public:
    Item(int minimumBid, int daysToBid, int currentBid, string topBidder, string seller)
    {
        minimumBid = minimumBid;
        daysToBid = daysToBid;
        currentBid = currentBid;
        topBidder = topBidder;
        seller = seller;
    }
    ~Item();
};

void newBid(Item item, int newPrice){
  
}
