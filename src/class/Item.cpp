/*********************************
 * Item class used to do transactions
 * involving items
*********************************/

#pragma once
#include <string>
using namespace std;

class Item
{
private:
    int minimumBid;
    int daysToBid;
    int currentBid;
    string topBidder;
    const string seller;

public:
    /**
     * Creates an Item that contains all the information required to do transactions on it
     * 
     * @param minimumBid    minimum bid on an item
     * @param daysToBid     number of days you can bid on an item
     * @param currentBid    the current highestbid
     * @param topBidder     the current topbidders username
     * @param seller        the seller of the item
    */
    Item(int minimumBid, int daysToBid, int currentBid, string topBidder, string seller)
    {
        minimumBid = minimumBid;
        daysToBid = daysToBid;
        currentBid = currentBid;
        topBidder = topBidder;
        seller = seller;
    }
    ~Item();
    /**
     * Changes the items currentBid and topBidder
     * 
     * 
     * @param newPrice     the highest bid of the item
     * @param bidder       the highest bidder's username
    */
    void newBid(int newPrice, string bidder)
    {
    }
};
