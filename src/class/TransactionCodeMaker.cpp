/***********************


************/
#pragma once
#include <string>
#include "TransactionEnums.h"

using namespace std;

class TransactionCodeMaker
{
private:
    /* data */
    //void sorter(User &user, transactionType tranType);

public:
    TransactionCodeMaker(/* args */);
    ~TransactionCodeMaker();

    static string makeCreate(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "01_";
        code += username;
        //assuming username length of 15
        for (int i = username.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";
        code += userType;
        code += "_";
        for (int i = to_string(availableCredit).length(); i <= 9; i++)
        {
            code += "0";
        }
        code += to_string(availableCredit);
        return code;
    }

    static string makeDelete(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "02_";
        code += username;
        //assuming username length of 15
        for (int i = username.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";
        code += userType;
        code += "_";
        for (int i = to_string(availableCredit).length(); i <= 9; i++)
        {
            code += "0";
        }
        code += to_string(availableCredit);
        return code;
    }

    static string makeLogout(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "00_";
        code += username;
        //assuming username length of 15
        for (int i = username.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";
        code += userType;
        code += "_";
        for (int i = to_string(availableCredit).length(); i <= 9; i++)
        {
            code += "0";
        }
        code += to_string(availableCredit);
        return code;
    }

    static string makeAddCredit(string username, string userType, int availableCredit)
    {
        string code = "";
        code += "06_";
        code += username;
        //assuming username length of 15
        for (int i = username.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";
        code += userType;
        code += "_";
        for (int i = to_string(availableCredit).length(); i <= 9; i++)
        {
            code += "0";
        }
        code += to_string(availableCredit);
        return code;
    }

    static string makeRefund(string buyerUsername, string sellerUsername, string userType, int availableCredit)
    {
        string code = "";
        code += "05_";

        code += buyerUsername;
        //assuming username length of 15
        for (int i = buyerUsername.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";

        code += sellerUsername;
        //assuming username length of 15
        for (int i = sellerUsername.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";

        for (int i = to_string(availableCredit).length(); i <= 9; i++)
        {
            code += "0";
        }
        code += to_string(availableCredit);
        return code;
    }

    static string makeBid(string buyerUsername, string sellerUsername, string itemName, int bid){
        string code = "";
        code += "04_";


        code += itemName;
        //assuming username length of 19
        for (int i = itemName.length(); i <= 19; i++)
        {
            code += "_";
        }
        code += "_";

        code += buyerUsername;
        //assuming username length of 15
        for (int i = buyerUsername.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";

        code += sellerUsername;
        //assuming username length of 15
        for (int i = sellerUsername.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";


        for (int i = to_string(bid).length(); i <= 6; i++)
        {
            code += "0";
        }
        code += to_string(bid);

        return code;
    }
    static string makeAdvertise(string username, int daysToAuction, string itemName, int minimumBid){
        string code = "";
        code += "03_";


        code += itemName;
        //assuming username length of 19
        for (int i = itemName.length(); i <= 19; i++)
        {
            code += "_";
        }
        code += "_";

        code += username;
        //assuming username length of 15
        for (int i = username.length(); i <= 15; i++)
        {
            code += "_";
        }
        code += "_";


        //assuming length of 3
        for (int i = to_string(daysToAuction).length(); i <= 3; i++)
        {
            code += "0";
        }
        code += to_string(daysToAuction);
        code += "_";


        //assuming length of 3
        for (int i = to_string(minimumBid).length(); i <= 6; i++)
        {
            code += "0";
        }
        code += to_string(minimumBid);

        return code;
    }
};
