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

/*
 * main uses a loop on cin to take in the inputs
 *
 */
int main(int argc, char const *argv[])
{

  bool quit = false;
  while (!quit)
  {
    string input = "";
    cout << "Please Enter an input" << endl;
    cin >> input;
    //commented code below is for debugging
    /*if (input == "q")
    {
      quit = true;
    }*/

  }

  return 0;
}


/*
 * isValidUserName is called to validate string userName inputs. isValidUserName
 * takes in a string parameter, checks if it's not empty and it's less than 15
 * characters. If all tests pass, it returns true, and if they fail
 * it returns false
 *
 * @param variable   user name to be checked
 * @return boolean
 */
bool isValidUserName(string variable)
{
  if(!variable.empty()){
    if(variable.length() < 15){
      return true;
    }
    return false;
  }
  else{
  return false;
  }
}


/*
 * isValidItemName is called to validate string itemName inputs. isValidItemName
 * takes in a string parameter, checks if it's not empty and it's less than 25
 * characters. If all tests pass, it returns true, and if they fail
 * it returns false
 *
 * @param variable   item name to be checked
 * @return boolean
 */
bool isValidItemName(string variable)
{
  if(!variable.empty()){
    if(variable.length() < 25){
      return true;
    }
    return false;
  }
  else{
  return false;
  }
}


/*
 * isValidInt is called to validate integer inputs. isValidInt takes in
 * an int parameter, checks if it's between bigger than 0 and smaller than
 * 1000000. If the input satisfies the range, it returns true. Otherwise,
 * it returns false
 *
 * @param variable     amount input to be checked if it's between 0 and 1000000
 * @return boolean
 */
bool isValidInt(int variable)
{
  if(variable < 1 || variable > 1000000){
    return false;
  }
}

/*
 * checkAdvertise is called to validate inputs for advertise. The parameters
 * for checkAdvertise are string itemName, int minimumBid, and int daysToBid.
 * First, checkAdvertise calls isValidItemName, isValidUserName and isValidInt
 * for the parameters.
 * Next it checks if userType is not BS as BuyStandard cannot advertise
 * itemName is the test on if it contains any special characters.
 * Next, it checks if daysToBid is less than 100 and minimumBid is
 * less than 1000.
 * If any test fails, it will output a message to the corresponding failure.
 * If all these tests pass, advertise is called.
 *
 *
 * @param itemName    name for the item to be posted
 * @param minimumBid  starting bid for the items
 * @param daysToBid   days left on the auction of the item
 * @return void
 */
void checkAdvertise(string itemName, int minimumBid, int daysToBid){};

/*
 * checkRefund is called to validate inputs for Refund. The parameters
 * for checkRefund are string buyerUserName, string sellerUsername, and
 * int amount
 * First checkRefund calls isValidUserName and isValidInt for the parameters.
 * Next, it checks if the user has permission to apply a refund and if
 * the seller and buyer users exist.
 * If any test fails, it will output a message to the corresponding failure.
 * If all these tests pass, refund is called.
 *
 * @param buyerUsername   user refund is going to
 * @param sellerUsername  user refund is coming from
 * @param amount          amount of refund
 * @return void
 */
void checkRefund(string buyerUsername, string sellerUsername, int amount){};

/*
 * checkDeleteUser is called to validate inputs for DeleteUser. The parameter
 * for checkDeleteUser is string userName.
 * isValidUserName is called to validate userName.
 * If isValidUserName fails, it will output a message in regards to the input.
 * Otherwise, deleteUser is called.
 *
 * @param userName  user to be deleted
 * @return void
 */
void checkDeleteUser(string userName){};

/*
 * checkAddCredit is called to validate inputs for AddCredit. The parameter
 * for checkAddCredit is int amount.
 * isValidInt is called to validate amount inputted.
 * If isValidInt fails, it will output a message in regards to the input.
 * Otherwise, addCredit is called.
 *
 * @param amount  amount to be added to current user
 * @return void
 */
void checkAddCredit(int amount){};

/*
 * checkCreateNewUser is called to validate inputs for CreateNewUser. The parameter
 * for checkCreateNewUser are string userName, string userType, and int credit
 * First isValidUserName and isValidInt is called to validate the parameters
 * Next, it checks if the username already exists, and if userType fits the
 * four possibilities.
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, createNewUser is called.
 *
 * @param userName    name of the new user
 * @param userType    type of the new user
 * @param credit      starting credit on the user
 * @return void
 */
void checkCreateNewUser(string userName, string userType, int credit){};

/*
 * checkBid is called to validate inputs for Bid. The parameter
 * for checkBid is string itemName, string userName, and int amount
 * First isValidItemName, isValidUserName and isValidInt is called to validate
 * the parameters
 * Next, it checks if the item exists, if the user exists, and if the item and
 * user match
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, bid is called.
 *
 * @param itemName  name of the item to place the bid on
 * @param userName  name of the user that placed the item
 * @param amount    amount of the new bid
 * @return void
 */
void checkBid(string itemName, string userName, int amount){};
