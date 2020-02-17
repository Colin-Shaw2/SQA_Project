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
 *
 *
 *
 *
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
    if (input == "q")
    {
      quit = true;
    }

  }

  return 0;
}


/*
 * isValidString is called to validate string inputs. isValidString takes in
 * a string parameter, checks if it's not empty and if it's less than 15
 * characters. If all tests pass, it returns true, and if they fail
 * it returns false
 *
 * @return boolean
 */
bool isValidString(string variable)
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
 * isValidInt is called to validate integer inputs. isValidInt takes in
 * an int parameter, checks if it's between bigger than 0 and smaller than
 * 1000000. If the input satisfies the range, it returns true. Otherwise,
 * it returns false
 *
 * @return boolean
 */

bool isValidInt(int variable)
{
  if(variable < 1 && variable > 1000000){
    return false;
  }
}

/*
 * checkAdvertise is called to validate inputs for advertise. The parameters
 * for checkAdvertise are string itemName, int minimumBid, and int daysToBid.
 * First, checkAdvertise calls isValidString and isValidInt for the parameters.
 * Next it checks if userType is not BS as BuyStandard cannot advertise
 * itemName is the test on if it contains any special characters.
 * Next, it checks if daysToBid is less than 100 and minimumBid is
 * less than 1000.
 * If any test fails, it will output a message to the corresponding failure.
 * If all these tests pass, advertise is called.
 *
 * @return void
 */

void checkAdvertise(string itemName, int minimumBid, int daysToBid){};

/*
 * checkRefund is called to validate inputs for Refund. The parameters
 * for checkRefund are string buyerUserName, string sellerUsername, and
 * int amount
 * First checkRefund calls isValidString and isValidInt for the parameters.
 * Next, it checks if the users exist.
 * If any test fails, it will output a message to the corresponding failure.
 * If all these tests pass, refund is called.
 *
 * @return void
 */
void checkRefund(string buyerUsername, string sellerUsername, int amount){};

/*
 * checkDeleteUser is called to validate inputs for DeleteUser. The parameter
 * for checkDeleteUser is string userName.
 * isValidString is called to validate userName.
 * If isValidString fails, it will output a message in regards to the input.
 * Otherwise, deleteUser is called.
 *
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
 * @return void
 */

void checkAddCredit(int amount){};

/*
 * checkCreateNewUser is called to validate inputs for CreateNewUser. The parameter
 * for checkCreateNewUser is string userName, string userType, and int credit
 * First isValidString and isValidInt is called to validate the parameters
 * Next, it checks if the username already exists, and if userType fits the
 * four possibilities.
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, createNewUser is called.
 *
 * @return void
 */

void checkCreateNewUser(string userName, string userType, int credit){};

/*
 * checkBid is called to validate inputs for Bid. The parameter
 * for checkBid is string itemName, string userName, and int amount
 * First isValidString and isValidInt is called to validate the parameters
 * Next, it checks if the item exists, if the user exists, and if the item and
 * user match
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, bid is called.
 *
 * @return void
 */

void checkBid(string itemName, string userName, int amount){};
