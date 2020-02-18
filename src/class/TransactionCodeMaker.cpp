/***********************


************/
#pragma once
#include <string>

using namespace std;

class TransactionCodeMaker
{
private:

    //the number of characters allocaded in each field
    static const int userNameLength = 15;
    static const int creditLength = 9;
    static const int bidLength = 6;
    static const int itemLength = 25;
    static const int auctionLength = 3;
    
    /**
     * takes in an input string and pads it with trailing '_' until it is equal to length
     * 
     * this method should not be called directly from a public method in this class
     * but from a private wrapper metod
     * 
     * @param input a string to be buffered
     * @param length that should be returned
     * @return a string that is length long padded with trailing '_'
     */
    static string makeBufferedString(string input, int length){
        string outStr = "";
        outStr += input;
        for (int i = input.length(); i <= length; i++)
        {
            outStr += "_";
        }
        return outStr;
    } 
    
    
    /**
     * takes in an input integer and returns a sttring padded
     * with leading '0' until it is equal to length
     * 
     * this method should not be called directly from a public method in this class
     * but from a private wrapper metod
     * 
     * @param input an int to be buffered and converted to string
     * @param length that should be returned
     * @return a string that is length long padded with leading '0'
     */
    static string makeBufferedString(int input, int length){
        string outStr = "";
        for (int i = to_string(input).length(); i <= length; i++)
        {
            outStr += "0";
        }
        outStr += to_string(input);
        return outStr;
    } 
    
    /**
     * takes in a itemName and pads it
     * 
     * uses itemLength to determine final string length
     * 
     * @param itemName an item name to be buffered
     * @return a string that is itemLength long padded with trailing '_'
     */
    static string makeBufferedItem(string itemName){
        return makeBufferedString(itemName, itemLength);
    } 

    /**
     * takes in a username and pads it
     * 
     * uses userNameLength to determine final string length
     * 
     * @param username a username to be buffered
     * @return a string that is userNameLength long padded with trailing '_'
     */
    static string makeBufferedUserName(string username){
        return makeBufferedString(username, userNameLength);
    } 
    
    /**
     * takes in a bid and pads it
     * 
     * uses bidLength to determine final string length
     * 
     * @param bid a bid to be buffered
     * @return a string that is bidLength long padded with leading '0'
     */
    static string makeBufferedBid(int bid){
        return makeBufferedString(bid, bidLength);
    } 

    /**
     * takes in a credit and pads it
     * 
     * uses creditLength to determine final string length
     * 
     * @param credit a credit to be buffered
     * @return a string that is creditLength long padded with leading '0'
     */
    static string makeBufferedCredit(int credit){
        return makeBufferedString(credit, creditLength);
    } 

    /**
     * takes in a auction and pads it
     * 
     * uses auctionLength to determine final string length
     * 
     * @param auction number of days of an aution to be buffered
     * @return a string that is auctionLength long padded with leading '0'
     */
    static string makeBufferedAuction(int auction){
        return makeBufferedString(auction, auctionLength);
    }

public:
    //this class is static and should never need to call a constructor
    TransactionCodeMaker();
    ~TransactionCodeMaker();


    /*** creates a transaction code for the Create action
     * 
     * returns a string in the form 01_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
     * U is username 
     * T is type 
     * C is credit
     * 
     * @param username          user involved in the transaction
     * @param userType          the type of user involved
     * @param availableCredit   credit available on the account
     * @return the transaction code
     */
    static string makeCreate(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "01_";

        code += makeBufferedUserName(username);
        code += "_";
        
        code += userType;
        code += "_";
        
        
        code += makeBufferedCredit(availableCredit);
        return code;
    }


    /** creates a transaction code for the Delete action
     * 
     * returns a string in the form 02_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
     * U is username 
     * T is type 
     * C is credit
     * 
     * @param username          user involved in the transaction
     * @param userType          the type of user involved
     * @param availableCredit   credit available on the account
     * @return the transaction code
     */
    static string makeDelete(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "02_";

        code += makeBufferedUserName(username);
        code += "_";

        code += userType;
        code += "_";

        
        code += makeBufferedCredit(availableCredit);
        return code;
    }

    /** creates a transaction code for the Logout action
     * 
     * returns a string in the form 00_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
     * U is username 
     * T is type 
     * C is credit
     * 
     * @param username          user involved in the transaction
     * @param userType          the type of user involved
     * @param availableCredit   credit available on the account
     * @return the transaction code
     */
    static string makeLogout(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "00_";
        
        code += makeBufferedUserName(username);
        code += "_";

        code += userType;
        code += "_";
        
        
        code += makeBufferedCredit(availableCredit);
        return code;
    }

    /** creates a transaction code for the AddCredit action
     * 
     * returns a string in the form 06_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
     * U is username 
     * T is type 
     * C is credit
     * 
     * @param username          user involved in the transaction
     * @param userType          the type of user involved
     * @param availableCredit   credit available on the account after addition
     * @return the transaction code
     */
    static string makeAddCredit(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "06_";
        
        code += makeBufferedUserName(username);
        code += "_";

        code += userType;
        code += "_";
        
        
        code += makeBufferedCredit(availableCredit);
        return code;
    }

    
    /** creates a transaction code for the Refund action
     * 
     * returns a string in the form 05_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
     * U is user getting credit 
     * S is user losing credit
     * C is credit
     * 
     * @param buyerUsername     user gaining credit
     * @param sellerUsername    user losing credit
     * @param availableCredit   credit available on buyer the account after refund
     * @return the transaction code
     */
    static string makeRefund(string buyerUsername, string sellerUsername, int availableCredit)
    {
        string code = "";
        code += "05_";

        
        code += makeBufferedUserName(buyerUsername);
        code += "_";

        
        code += makeBufferedUserName(sellerUsername);
        code += "_";

        
        code += makeBufferedCredit(availableCredit);
        return code;
    }

    /** creates a transaction code for the Bid action
     * 
     * returns a string in the form 04_IIIIIIIIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSSS_UUUUUUUUUUUUUU_PPPPPP
     * I is item name
     * S is user selling the item
     * U is user biddding on the item 
     * P is new bid
     * 
     * @param buyerUsername     user making bid
     * @param sellerUsername    user that owns the item
     * @param itemName          name of item being bid on
     * @param bid               new bid on the item
     * @return the transaction code
     */
    static string makeBid(string buyerUsername, string sellerUsername, string itemName, int bid){
        string code = "";
        code += "04_";

        
        
        code += makeBufferedItem(itemName);
        code += "_";

        
        code += makeBufferedUserName(buyerUsername);
        code += "_";

        
        code += makeBufferedUserName(sellerUsername);
        code += "_";
        
        code += makeBufferedCredit(bid);

        return code;
    }
    
    /** creates a transaction code for the Advertise action
     * 
     * returns a string in the form 03_IIIIIIIIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSSS_DDD_PPPPPP
     * I is item name
     * S is user selling the item
     * D is the number of days to auction the item for 
     * P is the minimum starting bid
     * 
     * @param username          user selling item
     * @param daysToAustion     number of days to auction the item for
     * @param itemName          name of item being bid on
     * @param bid               minimum bid on the item
     * @return the transaction code
     */
    static string makeAdvertise(string username, int daysToAuction, string itemName, int minimumBid){
        string code = "";
        code += "03_";

        
        code += makeBufferedItem(itemName);
        code += "_";

        
        code += makeBufferedUserName(username);
        code += "_";


        
        code += makeBufferedAuction(auctionLength);
        code += to_string(daysToAuction);
        code += "_";

        
        code += makeBufferedCredit(minimumBid);

        return code;
    }
};
