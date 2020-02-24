/*************************************
  * Main class is used to process the  *
  * inputs into their proper functions *
  * and passed into proper classes     *
  *************************************/

#include "Admin.cpp"
#include "FullStandard.cpp"
#include "BuyStandard.cpp"
#include "SellStandard.cpp"
#include "Item.cpp"
#include "TransactionCodeMaker.cpp"
#include "FileIOHandler.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string line;
ifstream itemFile;
ifstream userFile;


//global variables
const int usernameLength = 15;

enum inputState
{
  STATE_LOGGED_OUT,
  STATE_WAITING,
  STATE_CREATE,
  STATE_DELETE,
  STATE_LOGOUT,
  STATE_ADD_CREDIT,
  STATE_REFUND,
  STATE_ADVERTISE,
  STATE_BID
};



/**
 * isValidUsername is called to validate string username inputs. isValidUsername
 * takes in a string parameter, checks if it's not empty and it's less than 15
 * characters. If all tests pass, it returns true, and if they fail
 * it returns false
 *
 * @param variable   user name to be checked
 * @return boolean
 */
bool isValidUsername(string variable)
{
  if (!variable.empty())
  {
    if (variable.length() < usernameLength)
    {
      while(getline(userFile, line)){
        if(line.find(variable)){
          return true;
        }
      }
      userFile.close();
      cout << "We could not find that username" << endl;
      return false;
    }
    cout << "That is an invalid username" << endl;
    return false;
  }
  else
  {
    cout << "That is an invalid username" << endl;
    return false;
  }
}

/**
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
  if (!variable.empty())
  {
    if (variable.length() < 25)
    {
      while(getline(itemFile, line)){
        if(line.find(variable)){
          return true;
        }
      }
      itemFile.close();
      cout << "We could not find that username" << endl;
      return false;
    }
    return false;
  }
  else
  {
    return false;
  }
}

/**
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
  if (variable < 1 || variable > 1000000)
  {
    return false;
  }
  return true;
}

/**
 * checkAdvertise is called to validate inputs for advertise. The parameters
 * for checkAdvertise are string itemName, int minimumBid, and int daysToBid.
 * First, checkAdvertise calls isValidItemName, isValidUsername and isValidInt
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

/**
 * checkRefund is called to validate inputs for Refund. The parameters
 * for checkRefund are string buyerUsername, string sellerUsername, and
 * int amount
 * First checkRefund calls isValidUsername and isValidInt for the parameters.
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

/**
 * checkDeleteUser is called to validate inputs for DeleteUser. The parameter
 * for checkDeleteUser is string username.
 * isValidUsername is called to validate username.
 * If isValidUsername fails, it will output a message in regards to the input.
 * Otherwise, deleteUser is called.
 *
 * @param username  user to be deleted
 * @return void
 */
void checkDeleteUser(string username){};

/**
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

/**
 * checkCreateNewUser is called to validate inputs for CreateNewUser. The parameter
 * for checkCreateNewUser are string username, string userType, and int credit
 * First isValidUsername and isValidInt is called to validate the parameters
 * Next, it checks if the username already exists, and if userType fits the
 * four possibilities.
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, createNewUser is called.
 *
 * @param username    name of the new user
 * @param userType    type of the new user
 * @param credit      starting credit on the user
 * @return void
 */
void checkCreateNewUser(string username, string userType, int credit){};

/**
 * checkBid is called to validate inputs for Bid. The parameter
 * for checkBid is string itemName, string username, and int amount
 * First isValidItemName, isValidUsername and isValidInt is called to validate
 * the parameters
 * Next, it checks if the item exists, if the user exists, and if the item and
 * user match
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, bid is called.
 *
 * @param itemName  name of the item to place the bid on
 * @param username  name of the user that placed the item
 * @param amount    amount of the new bid
 * @return void
 */
void checkBid(string itemName, string username, int amount){};


/**
 * main uses a loop on cin to take in the inputs
 *
 */

int main(int argc, char const *argv[])
{
  //get the input and putput file names from command line
  if (argc < 4)
  {
    cout << "not enough command line arguments" << endl;
    exit(-1);
  }

  FileIOHandler ioHandler = FileIOHandler(argv[1], argv[2], argv[3]);
  itemFile.open(argv[1]);
  userFile.open(argv[2]);
  // string transactionFile = argv[3];

  inputState currentState = STATE_LOGGED_OUT;
  bool quit = false;
  string input = "";
  User *currentUser;

  while (!quit)
  {
    input = "";
    switch (currentState)
    {
    case STATE_LOGGED_OUT:
      cout << "Please enter your username:" << endl;
      break;
    case STATE_WAITING:
      cout << "Enter a command:" << endl;
      break;
    default:
      cout << "Please Enter an input (default)" << endl;
      break;
    }
    cin >> input;

    //commented code below is for debugging
    if (input == "q")
    {
      quit = true;
      break;
    }

    //If waiting get next command
    if (currentState == STATE_WAITING)
    {
      if (input == "logout")
      {
        currentState = STATE_LOGOUT;
      }
      else if (input == "addcredit")
      {
        currentState = STATE_ADD_CREDIT;
      }
      else if (input == "advertise")
      {
        currentState = STATE_ADVERTISE;
      }
      else if (input == "bid")
      {
        currentState = STATE_BID;
      }
      else if (input == "create")
      {
        currentState = STATE_CREATE;
      }
      else if (input == "delete")
      {
        currentState = STATE_DELETE;
      }
      else if (input == "refund")
      {
        currentState = STATE_REFUND;
      }
    }

    switch (currentState)
    {
    //Not yet logged in
    case STATE_LOGGED_OUT:
    {
      if (isValidUsername(input))
      {
        currentUser = ioHandler.getUser(input);
        if (currentUser != NULL)
        {
          currentState = STATE_WAITING;
        }
      }
      break;
    }
    //No valid command was given
    case STATE_WAITING:
    {
      break;
    }

    case STATE_CREATE:
    {
      string username;
      string userType;
      int credit;

      cout << "Please Enter User Name:" << endl;
      cin >> username;
      cout << "Type of user?(Admin(AA)/BuyAndSell(FS)/Buy(BS)/Sell(SS))" << endl;
      cin >> userType;
      cout << "Starting Balance?" << endl;
      cin >> credit;
      currentUser->createNewUser(username,userType,credit);

      cout << "Created User \"" <<  username <<  "\" as " << userType << " with $" << credit << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_DELETE:
    {
      string username;

      cout << "Please enter a user name to be deleted" << endl;
      cin >> username;

      currentUser->deleteUser(username);

      cout << "User is deleted!" << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_LOGOUT:
    {
      currentUser->logout();
      cout << "Logout successful!" << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_ADD_CREDIT:
    {
      string username;
      int amount;


      cout << "Please enter a username:" << endl;
      cin >> username;
      //get user
      cout << "Current Balance $" << 100 /*place holder*/ << endl;
      cout << "How much would you like to add?" << endl;
      cin >> amount;
      currentUser->addCredit(username, amount);

      cout << "Created added, Balance is $" <</*placeHolder*/ currentUser->getBalance() << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_REFUND:
    {
      string buyerUsername;
      string sellerUsername;
      int amount;


      cout << "Please enter the buyer's username:" << endl;
      cin >> buyerUsername;
      cout << "Please enter the seller's username:" << endl;
      cin >> sellerUsername;
      cout << "Please enter the refund amount:" << endl;
      cin >> amount;
      currentUser->refund(buyerUsername, sellerUsername, amount);

      cout << "Refund successsful!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_ADVERTISE:
    {
      string itemName;
      int minimumBid;
      int daysToBid;


      cout << "Name of product:" << endl;
      cin >> itemName;
      cout << "Minimum Bid(CAD$ 00.01-999.99):" << endl;
      cin >> minimumBid;
      cout << "Number of days:" << endl;
      cin >> daysToBid;
      currentUser->advertise(itemName, minimumBid, daysToBid);

      cout << "Item added successfully!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_BID:
    {
      string itemName;
      string username;
      int amount;


      cout << "Enter Product Name:" << endl;
      cin >> itemName;
      cout << "Enter Username:" << endl;
      cin >> username;
      cout << "Current Bid $" << 50 << endl;
      cin >> amount;
      currentUser->bid(itemName, username, amount);

      cout << "Bid Successful!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    default:
    {
      cout << "ERROR Do stuff switch is (default)" << endl;
      break;
    }
    }
  }

  return 0;
}
