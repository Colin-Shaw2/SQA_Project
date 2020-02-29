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
    string itemName;
    int daysToBid;
    int currentBid;
    string seller;

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
    Item(string itemName, int daysToBid, int currentBid, string seller)
    {
        this->itemName = itemName;
        this->daysToBid = daysToBid;
        this->currentBid = currentBid;
        this->seller = seller;
    }

    /**
     * The get functions return information from Item
     *
     *
    */
    string getItemName(){
      return this->itemName;
    }
    int getDaysToBid(){return this->daysToBid;}
    int getCurrentBid(){return this->currentBid;}
    string getSeller(){return this->seller;}
};
