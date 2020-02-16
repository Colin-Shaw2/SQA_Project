  /*************************************
  * Main class is used to process the  *
  * inputs into their proper functions *
  * and passed into proper classes     *
  *************************************/

#include "User.cpp"
#include "Item.cpp"
#include "TransactionCodeMaker.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  bool quit = false;
  while (!quit)
  {
    string input = "";
    cout << "Please Enter an input" << endl;
    cin >> input;
    if (input == "q")
    {
      quit = true;
    }

  }

  return 0;
}

bool isValidString(string variable)
{
  /*isValidString is used to validate the Strings that are inputted*/
  if(!variable.empty()){//checks if it is a string and not a null
    if(variable.length() > 15){// checks if variable is shorter than 15 characters
      return false;
    }
  }
  else{
  return false;
  }
}
bool isValidInt(int variable)
{
  /*isValidInt is used to validate the integers inputted */
  if(variable < 1 && variable > 1000000){//checks if variable is in range
    return false;
  }
}

void checkAdvertise(string itemName, int minimumBid, int daysToBid)
{
  /*checkAdvertise is used to validate the inputs for advertising
  an item before an item is put up*/

}

void checkRefund(string buyerUsername, string sellerUsername, int amount){
/*checkRefund is used to validate the inputs for refunding to a user
before a user is refunded*/

}

void checkDeleteUser(string userName){
/*checkDeleteUser is used to validate the inputs for deleting a user
before a user is deleted*/

}

void checkAddCredit(string amount){
/*checkAddCredit is used to validate the inputs for adding credit to a user
before credit is added to a user*/

}

void checkCreateNewUser(string userName, string userType, int amount){
/*checkCreateNewUser is used to validate the inputs for creating a new user
before a new user is created*/

}

void checkBid(string itemName, string userName, int amount){
/*checkBid is used to validate the inputs for a bid before new bid is placed*/

}
