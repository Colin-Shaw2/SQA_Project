/***********************


************/
#pragma once
#include <string>

using namespace std;

class TransactionCodeMaker
{
private:
    static const int userNameLength = 15;//TODO
    static const int creditLength = 9;
    static const int bidLength = 6;
    static const int itemLength = 19;
    static const int auctionLength = 3;

    static string makeBufferedString(string input, int length){
        string outStr = "";
        outStr += input;
        for (int i = input.length(); i <= length; i++)
        {
            outStr += "_";
        }
        return outStr;
    } 
    
    static string makeBufferedString(int input, int length){
        string outStr = "";
        for (int i = to_string(input).length(); i <= length; i++)
        {
            outStr += "0";
        }
        outStr += to_string(input);
        return outStr;
    } 

    static string makeBufferedUserName(string input){
        return makeBufferedString(input, userNameLength);
    } 
    

    static string makeBufferedBid(int input){
        return makeBufferedString(input, bidLength);
    } 

    static string makeBufferedCredit(int input){
        return makeBufferedString(input, creditLength);
    } 
    
    static string makeBufferedItem(string input){
        return makeBufferedString(input, itemLength);
    } 

    static string makeBufferedAuction(int input){
        return makeBufferedString(input, auctionLength);
    } 

public:
    TransactionCodeMaker(/* args */);
    ~TransactionCodeMaker();

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

    static string makeRefund(string buyerUsername, string sellerUsername, string userType, int availableCredit)
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
    
    static string makeAdvertise(string username, int daysToAuction, string itemName, int minimumBid){
        string code = "";
        code += "03_";

        
        code += makeBufferedItem(itemName);

        
        code += makeBufferedUserName(username);
        code += "_";


        
        code += makeBufferedAuction(auctionLength);
        code += to_string(daysToAuction);
        code += "_";

        
        code += makeBufferedCredit(minimumBid);

        return code;
    }
};
